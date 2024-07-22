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

	// 맵 매쉬
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

	// 맵 충돌 트리거 생성(박스)
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Trigger->SetBoxExtent(FVector(775.0f, 775.0f, 300.0f));
	Trigger->SetupAttachment(RootComponent);
	Trigger->SetRelativeLocation(FVector(0.0f, 0.0f, 250.0f));
	Trigger->SetCollisionProfileName(TEXT("YPTrigger"));

	// 트리거 델리게이트 - &AYPSection::OnTriggerBeginOverlap 함수와 연결
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AYPSection::OnTriggerBeginOverlap);

	// 게이트 매쉬
	FString GateAssetPath = TEXT("/Game/Book/StaticMesh/SM_GATE.SM_GATE");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_GATE(*GateAssetPath);
	if (!SM_GATE.Succeeded())
	{
		YPLOG(Error, TEXT("Failed to load staticmesh asset. : %s"), *GateAssetPath);
	}
	// 게이트 소켓 목록 생성, 각각의 철문은 동일한 기능을 가지므로 TArray로 묶어 관리
	static FName GateSockets[] = { {TEXT("+XGate")},{TEXT("-XGate")},{TEXT("+YGate")},{TEXT("-YGate")} };
	for (FName GateSocket : GateSockets)
	{
		YPCHECK(Mesh->DoesSocketExist(GateSocket));
		UStaticMeshComponent* NewGate = CreateDefaultSubobject<UStaticMeshComponent>(*GateSocket.ToString());
		NewGate->SetStaticMesh(SM_GATE.Object);
		NewGate->SetupAttachment(RootComponent, GateSocket);
		NewGate->SetRelativeLocation(FVector(0.0f, -80.5f, 0.0f));
		GateMeshes.Add(NewGate);

		// 게이트 충돌 트리거 생성(박스) - 문이 여러개라서 배열에 저장 후 게이트 트리거에 추가
		UBoxComponent* NewGateTrigger = CreateDefaultSubobject<UBoxComponent>(*GateSocket.ToString().Append(TEXT("Trigger")));
		NewGateTrigger->SetBoxExtent(FVector(100.0f, 100.0f, 300.0f));
		NewGateTrigger->SetupAttachment(RootComponent, GateSocket);
		NewGateTrigger->SetRelativeLocation(FVector(70.0f, 0.0f, 250.0f));
		NewGateTrigger->SetCollisionProfileName(TEXT("YPTrigger"));
		GateTriggers.Add(NewGateTrigger);

		// 트리거 델리게이트 - &AYPSection::OnGateTriggerBeginOverlap 함수와 연결
		NewGateTrigger->OnComponentBeginOverlap.AddDynamic(this, &AYPSection::OnGateTriggerBeginOverlap);
		NewGateTrigger->ComponentTags.Add(GateSocket);
	}

	bNoBattle = false;

	EnemySpawnTime = 2.0f;
	ItemBoxSpawnTime = 5.0f;
}

// 에디터와 연동되는 함수, 에디터 작업에서 선택한 액터의 속성이나 트랜스폼 정보가 변경될때 실행 되는 함수
void AYPSection::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

// Called when the game starts or when spawned
void AYPSection::BeginPlay()
{
	Super::BeginPlay();
	
	// 스테이트 설정 함수 - 게임 시작시 스테이트 설정
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

// 스테이트 설정 함수 -> 충돌 트리거에 콜리전프로필 연결
void AYPSection::SetState(ESectionState NewState)
{
	switch (NewState)
	{
	case ESectionState::READY:
	{
		// 맵 트리거에 -> YPTrigger
		Trigger->SetCollisionProfileName(TEXT("YPTrigger"));
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			// 게이트 트리거 충돌감지X로 변경
			GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
		}

		// 문열어둠
		OperateGates(true);
		break;
	}
	case ESectionState::BATTLE:
	{
		// 전투중엔 문조작하지 못하도록 충돌감지 끄기
		// 맵 트리거 충돌감지X로 변경
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			// 게이트 트리거 충돌감지X로 변경
			GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
		}
		// 문 닫아둠
		OperateGates(false);

		// 정해둔 시간 뒤에 NPC, 아이템 박스 생성
		GetWorld()->GetTimerManager().SetTimer(SpawnNPCTimeHandle, FTimerDelegate::CreateUObject(this, &AYPSection::OnNPCSpawn), EnemySpawnTime, false);
		GetWorld()->GetTimerManager().SetTimer(SpawnItemBoxTimerHandle, FTimerDelegate::CreateLambda([this]()->void {
			FVector2D RandXY = FMath::RandPointInCircle(600.0f);
			GetWorld()->SpawnActor<AYPItemBox>(GetActorLocation() + FVector(RandXY, 30.0f), FRotator::ZeroRotator);
			}), ItemBoxSpawnTime, false);
		break;
	}
	case ESectionState::COMPLETE:
	{
		// 전투종료 됐으므로 박스와 npc가 생성되지 않도록 맵 트리거 충돌 끔
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			// 게이트 트리거 On
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

// 맵 트리거 델리게이트 연동 함수
void AYPSection::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 현재 상태가 준비 단계 -> 배틀 상태로 변경
	if (CurrentState == ESectionState::READY)
	{
		SetState(ESectionState::BATTLE);
	}
}

// 게이트 트리거 델리게이트 연동 함수
void AYPSection::OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	YPCHECK(OverlappedComponent->ComponentTags.Num() == 1);

	FName ComponentTag = OverlappedComponent->ComponentTags[0];
	FName SocketName = FName(*ComponentTag.ToString().Left(2));
	if (!Mesh->DoesSocketExist(SocketName))
		return;

	FVector NewLocation = Mesh->GetSocketLocation(SocketName);

	// 게이트들 티어레이에 저장
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
		// 새로운 섹션 만들기
		auto NewSection = GetWorld()->SpawnActor<AYPSection>(NewLocation, FRotator::ZeroRotator);
	}
	else
	{
		YPLOG(Warning, TEXT("New Section area is not empty"));
	}
}

void AYPSection::OnNPCSpawn()
{
	// 새로운 NPC 생성
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

	// NPC가 제거될때 마지막으로 대미지를 입힌 컨트롤러의 기록은  LastHitBy 속성에 저장됨
	// 이를 이용해 액터가 제거될 때 마지막에 피격을 가한 플레이어의 정보를 바로 얻어 올수 있따
	auto YPPlayerController = Cast<AYPPlayerController>(YPCharacter->LastHitBy);
	YPCHECK(nullptr != YPPlayerController);

	// 점수 올리기
	auto YPGameMode = Cast<AYPGameMode>(GetWorld()->GetAuthGameMode());
	YPCHECK(nullptr != YPGameMode);
	YPGameMode->AddScore(YPPlayerController);

	SetState(ESectionState::COMPLETE);
}
