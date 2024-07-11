// Fill out your copyright notice in the Description page of Project Settings.


#include "YPItemBox.h"
#include "YPCharacter.h"
#include "YPWeapon.h"


// Sets default values
AYPItemBox::AYPItemBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOX"));
	Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EFFECT"));

	RootComponent = Trigger;
	Box->SetupAttachment(RootComponent);
	Effect->SetupAttachment(RootComponent);
	

	// �ڽ� �ݸ��� ������Ʈ�� Extent ���� ��ü �ڽ� ���� ũ���� ���� ���� �ǹ�
	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BOX(TEXT("/Game/InfinityBladeGrassLands/Environments/Breakables/StaticMesh/Box/SM_Env_Breakables_Box1.SM_Env_Breakables_Box1"));
	if (SM_BOX.Succeeded())
	{
		Box->SetStaticMesh(SM_BOX.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> P_CHESTOPEN(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Treasure/Chest/P_TreasureChest_Open_Mesh.P_TreasureChest_Open_Mesh"));
	if (P_CHESTOPEN.Succeeded())
	{
		Effect->SetTemplate(P_CHESTOPEN.Object);
		Effect->bAutoActivate = false;
	}

	Box->SetRelativeLocation(FVector(0.0f, -3.5f, -30.0f));

	Trigger->SetCollisionProfileName(TEXT("ItemBox")); // �ݸ��������� ����
	Box->SetCollisionProfileName(TEXT("NoCollision"));

	// Ŭ���� ������ �����ϴ� ����, ������ ���ڿ� �̸� ������ Ŭ���� ��ϸ� �� �� �ֵ��� ������ �� ����
	WeaponItemClass = AYPWeapon::StaticClass();
}

// Called when the game starts or when spawned
void AYPItemBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AYPItemBox::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	// ��Ƽĳ��Ʈ ���̳��� ��������Ʈ
	// Overlap �̺�Ʈ�� �߻��Ҷ����� ���ε��� ����Լ��� ȣ��� -> OnCharacterOverlap �Լ�
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AYPItemBox::OnCharacterOverlap);
}

void AYPItemBox::OnCharacterOverlap(UPrimitiveComponent* overlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	YPLOG_S(Warning);

	auto YPCharacter = Cast<AYPCharacter>(OtherActor);
	YPCHECK(nullptr != YPCharacter);

	if (nullptr != YPCharacter && nullptr != WeaponItemClass)
	{
		if (YPCharacter->CanSetWeapon())
		{
			// ĳ���Ͱ� ���⸦ ��� ���� �ʴٸ� ���⸦ ���������ش�.
			auto NewWeapon = GetWorld()->SpawnActor<AYPWeapon>(WeaponItemClass, FVector::ZeroVector, FRotator::ZeroRotator);
			YPCharacter->SetWeapon(NewWeapon);
			// ����Ʈ ���
			Effect->Activate(true);
			// �ڽ� ����ƽ�޽õ� ���Ͱ� ���ŵ� ������ ����� �����
			Box->SetHiddenInGame(true, true);
			// ����Ʈ ������� ������ �浹����� ������, �ι� ���� ����
			SetActorEnableCollision(false);
			// ����Ʈ ����� ������ �ߵ��ϴ� ��������Ʈ, OnEffectFinished �Լ��� ���ε��ϰ� ����
			Effect->OnSystemFinished.AddDynamic(this, &AYPItemBox::OnEffectFinished);
		}
		else
		{
			// ĳ���Ͱ� �̹� ���⸦ ��� ������ ���� ���
			YPLOG(Warning, TEXT("%s can't equip weapon currently."), *YPCharacter->GetName());
		}
	}
}

// ����Ʈ ����� ����Ǹ� ������ ���� ����
void AYPItemBox::OnEffectFinished(UParticleSystemComponent* pSystem)
{
	Destroy();
}
