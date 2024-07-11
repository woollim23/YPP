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
	

	// 박스 콜리전 컴포넌트의 Extent 값은 전체 박스 영역 크기의 절반 값을 의미
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

	Trigger->SetCollisionProfileName(TEXT("ItemBox")); // 콜리전프로필 설정
	Box->SetCollisionProfileName(TEXT("NoCollision"));

	// 클래스 정보를 저장하는 변수, 아이템 상자와 이를 선언한 클래스 목록만 볼 수 있도록 한정할 수 있음
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
	// 멀티캐스트 다이내믹 델리게이트
	// Overlap 이벤트가 발생할때마다 바인딩한 멤버함수가 호출됨 -> OnCharacterOverlap 함수
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
			// 캐릭터가 무기를 들고 있지 않다면 무기를 장착시켜준다.
			auto NewWeapon = GetWorld()->SpawnActor<AYPWeapon>(WeaponItemClass, FVector::ZeroVector, FRotator::ZeroRotator);
			YPCharacter->SetWeapon(NewWeapon);
			// 이펙트 재생
			Effect->Activate(true);
			// 박스 스테틱메시도 액터가 제거될 때까지 모습을 감춰둠
			Box->SetHiddenInGame(true, true);
			// 이펙트 재생동안 액터의 충돌기능을 제거해, 두번 습득 방지
			SetActorEnableCollision(false);
			// 이펙트 재생이 끝나면 발동하는 델리게이트, OnEffectFinished 함수를 바인딩하고 있음
			Effect->OnSystemFinished.AddDynamic(this, &AYPItemBox::OnEffectFinished);
		}
		else
		{
			// 캐릭터가 이미 무기를 들고 있으면 문구 출력
			YPLOG(Warning, TEXT("%s can't equip weapon currently."), *YPCharacter->GetName());
		}
	}
}

// 이펙트 재생이 종료되면 아이템 상자 제거
void AYPItemBox::OnEffectFinished(UParticleSystemComponent* pSystem)
{
	Destroy();
}
