// Fill out your copyright notice in the Description page of Project Settings.


#include "YPSection.h"
#include "YPCharacter.h"
#include "YPItemBox.h"
#include "YPPlayerController.h"
#include "YPGameMode.h"

// Sets default values
AYPSection::AYPSection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;

	// �� �Ž�
	FString AssetPath = TEXT("/Game/Book/StaticMesh/SM_SQUARE.SM_SQUARE");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_SQUARE(*AssetPath);
	if (SM_SQUARE.Succeeded())
	{
		Mesh->SetStaticMesh(SM_SQUARE.Object);
	}
	else
	{
		YPLOG(Error, TEXT("Failed to load staticmesh asset. : %s"), *AssetPath);
	}

	// �� �浹 Ʈ���� ����(�ڽ�)
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Trigger->SetBoxExtent(FVector(775.0f, 775.0f, 300.0f));
	Trigger->SetupAttachment(RootComponent);
	Trigger->SetRelativeLocation(FVector(0.0f, 0.0f, 250.0f));
	Trigger->SetCollisionProfileName(TEXT("YPTrigger"));

	// Ʈ���� ��������Ʈ - &AYPSection::OnTriggerBeginOverlap �Լ��� ����
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AYPSection::OnTriggerBeginOverlap);

	// ����Ʈ �Ž�
	FString GateAssetPath = TEXT("/Game/Book/StaticMesh/SM_GATE.SM_GATE");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_GATE(*GateAssetPath);
	if (!SM_GATE.Succeeded())
	{
		YPLOG(Error, TEXT("Failed to load staticmesh asset. : %s"), *GateAssetPath);
	}
	// ����Ʈ ���� ��� ����, ������ ö���� ������ ����� �����Ƿ� TArray�� ���� ����
	static FName GateSockets[] = { {TEXT("+XGate")},{TEXT("-XGate")},{TEXT("+YGate")},{TEXT("-YGate")} };
	for (FName GateSocket : GateSockets)
	{
		YPCHECK(Mesh->DoesSocketExist(GateSocket));
		UStaticMeshComponent* NewGate = CreateDefaultSubobject<UStaticMeshComponent>(*GateSocket.ToString());
		NewGate->SetStaticMesh(SM_GATE.Object);
		NewGate->SetupAttachment(RootComponent, GateSocket);
		NewGate->SetRelativeLocation(FVector(0.0f, -80.5f, 0.0f));
		GateMeshes.Add(NewGate);

		// ����Ʈ �浹 Ʈ���� ����(�ڽ�) - ���� �������� �迭�� ���� �� ����Ʈ Ʈ���ſ� �߰�
		UBoxComponent* NewGateTrigger = CreateDefaultSubobject<UBoxComponent>(*GateSocket.ToString().Append(TEXT("Trigger")));
		NewGateTrigger->SetBoxExtent(FVector(100.0f, 100.0f, 300.0f));
		NewGateTrigger->SetupAttachment(RootComponent, GateSocket);
		NewGateTrigger->SetRelativeLocation(FVector(70.0f, 0.0f, 250.0f));
		NewGateTrigger->SetCollisionProfileName(TEXT("YPTrigger"));
		GateTriggers.Add(NewGateTrigger);

		// Ʈ���� ��������Ʈ - &AYPSection::OnGateTriggerBeginOverlap �Լ��� ����
		NewGateTrigger->OnComponentBeginOverlap.AddDynamic(this, &AYPSection::OnGateTriggerBeginOverlap);
		NewGateTrigger->ComponentTags.Add(GateSocket);
	}

	bNoBattle = false;

	EnemySpawnTime = 2.0f;
	ItemBoxSpawnTime = 5.0f;
}

// �����Ϳ� �����Ǵ� �Լ�, ������ �۾����� ������ ������ �Ӽ��̳� Ʈ������ ������ ����ɶ� ���� �Ǵ� �Լ�
void AYPSection::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

// Called when the game starts or when spawned
void AYPSection::BeginPlay()
{
	Super::BeginPlay();
	
	// ������Ʈ ���� �Լ� - ���� ���۽� ������Ʈ ����
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

// ������Ʈ ���� �Լ� -> �浹 Ʈ���ſ� �ݸ��������� ����
void AYPSection::SetState(ESectionState NewState)
{
	switch (NewState)
	{
	case ESectionState::READY:
	{
		// �� Ʈ���ſ� -> YPTrigger
		Trigger->SetCollisionProfileName(TEXT("YPTrigger"));
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			// ����Ʈ Ʈ���� �浹����X�� ����
			GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
		}

		// �������
		OperateGates(true);
		break;
	}
	case ESectionState::BATTLE:
	{
		// �����߿� ���������� ���ϵ��� �浹���� ����
		// �� Ʈ���� �浹����X�� ����
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			// ����Ʈ Ʈ���� �浹����X�� ����
			GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
		}
		// �� �ݾƵ�
		OperateGates(false);

		// ���ص� �ð� �ڿ� NPC, ������ �ڽ� ����
		GetWorld()->GetTimerManager().SetTimer(SpawnNPCTimeHandle, FTimerDelegate::CreateUObject(this, &AYPSection::OnNPCSpawn), EnemySpawnTime, false);
		GetWorld()->GetTimerManager().SetTimer(SpawnItemBoxTimerHandle, FTimerDelegate::CreateLambda([this]()->void {
			FVector2D RandXY = FMath::RandPointInCircle(600.0f);
			GetWorld()->SpawnActor<AYPItemBox>(GetActorLocation() + FVector(RandXY, 30.0f), FRotator::ZeroRotator);
			}), ItemBoxSpawnTime, false);
		break;
	}
	case ESectionState::COMPLETE:
	{
		// �������� �����Ƿ� �ڽ��� npc�� �������� �ʵ��� �� Ʈ���� �浹 ��
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			// ����Ʈ Ʈ���� On
			GateTrigger->SetCollisionProfileName(TEXT("YPTrigger"));
		}

		OperateGates(true);
		break;
	}
	}

	CurrentState = NewState;
}

void AYPSection::OperateGates(bool bOpen)
{
	for (UStaticMeshComponent* Gate : GateMeshes)
	{
		Gate->SetRelativeRotation(bOpen ? FRotator(0.0f, -90.0f, 0.0f) : FRotator::ZeroRotator);
	}
}

// �� Ʈ���� ��������Ʈ ���� �Լ�
void AYPSection::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ���� ���°� �غ� �ܰ� -> ��Ʋ ���·� ����
	if (CurrentState == ESectionState::READY)
	{
		SetState(ESectionState::BATTLE);
	}
}

// ����Ʈ Ʈ���� ��������Ʈ ���� �Լ�
void AYPSection::OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	YPCHECK(OverlappedComponent->ComponentTags.Num() == 1);

	FName ComponentTag = OverlappedComponent->ComponentTags[0];
	FName SocketName = FName(*ComponentTag.ToString().Left(2));
	if (!Mesh->DoesSocketExist(SocketName))
		return;

	FVector NewLocation = Mesh->GetSocketLocation(SocketName);

	// ����Ʈ�� Ƽ��̿� ����
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, this);
	FCollisionObjectQueryParams ObjectQueryParam(FCollisionObjectQueryParams::InitType::AllObjects);
	bool bResult = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,
		NewLocation,
		FQuat::Identity,
		ObjectQueryParam,
		FCollisionShape::MakeSphere(775.0f),
		CollisionQueryParam
	);

	if (!bResult)
	{
		// ���ο� ���� �����
		auto NewSection = GetWorld()->SpawnActor<AYPSection>(NewLocation, FRotator::ZeroRotator);
	}
	else
	{
		YPLOG(Warning, TEXT("New Section area is not empty"));
	}
}

void AYPSection::OnNPCSpawn()
{
	//GetWorld()->GetTimerManager().ClearTimer(SpawnNPCTimerHandle);
	// ���ο� NPC ����
	auto KeyNPC = GetWorld()->SpawnActor<AYPCharacter>(GetActorLocation() + FVector::UpVector * 88.0f, FRotator::ZeroRotator);
	if (nullptr != KeyNPC)
	{
		KeyNPC->OnDestroyed.AddDynamic(this, &AYPSection::OnKeyNPCDestroyed);
	}
}

void AYPSection::OnKeyNPCDestroyed(AActor* DestroyedActor)
{
	auto YPCharacter = Cast<AYPCharacter>(DestroyedActor);
	YPCHECK(nullptr != YPCharacter);

	// NPC�� ���ŵɶ� ���������� ������� ���� ��Ʈ�ѷ��� �����  LastHitBy �Ӽ��� �����
	// �̸� �̿��� ���Ͱ� ���ŵ� �� �������� �ǰ��� ���� �÷��̾��� ������ �ٷ� ��� �ü� �ֵ�
	auto YPPlayerController = Cast<AYPPlayerController>(YPCharacter->LastHitBy);
	YPCHECK(nullptr != YPPlayerController);

	// ���� �ø���
	auto YPGameMode = Cast<AYPGameMode>(GetWorld()->GetAuthGameMode());
	YPCHECK(nullptr != YPGameMode);
	YPGameMode->AddScore(YPPlayerController);

	SetState(ESectionState::COMPLETE);
}
