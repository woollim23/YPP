// Fill out your copyright notice in the Description page of Project Settings.


#include "YPCharacterStatComponent.h"
#include "YPGameInstance.h"

// Sets default values for this component's properties
UYPCharacterStatComponent::UYPCharacterStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;

	Level = 1;
}

// Called when the game starts
void UYPCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// 액터의 PostInitializeComponents에 대응 하는 컴포넌트 함수, PostInitializeComponents 함수가 호출되기 전에 호출됨
// 이 함수가 호출되려면 생성자에서 bWantsInitializeComponent 값을 true로 설정해줘야 함
void UYPCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
	// 레벨 스탯 적용
	SetNewLevel(Level);
}

// 데이터는 모두 프라이빗으로 선언하고
// 이 함수를 통해서만 변경할 수 있도록 설계
void UYPCharacterStatComponent::SetNewLevel(int32 NewLevel)
{
	// 게임 인스턴스에서 데이터를 가져와 초기화함
	// 레벨이 변경되면 해당 스탯이 바뀌도록 제작
	auto YPGameInstance = Cast<UYPGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	YPCHECK(nullptr != YPGameInstance);
	CurrentStatData = YPGameInstance->GetYPCharacterData(NewLevel);

	if (nullptr != CurrentStatData)
	{
		Level = NewLevel;
		CurrentHP = CurrentStatData->MaxHP;
	}
	else
	{
		ABLOG(Error, TEXT("Level (%d) data doesn't exist"), NewLevel);
	}
}

// 받은 데미지 체력 설정
void UYPCharacterStatComponent::SetDamage(float NewDamage)
{
	YPCHECK(nullptr != CurrentStatData);
	// 현재 체력에서 받은 데미지 만큼 뺌
	CurrentHP = FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP);

	if (CurrentHP <= 0.0f)
	{
		// 체력 0을 감지하는 델리게이트 발동
		OnHPIsZero.Broadcast();
	}
}

float UYPCharacterStatComponent::GetAttack()
{
	YPCHECK(nullptr != CurrentStatData, 0.0f);
	// 현재 공격 데미지를 리턴해줌
	return CurrentStatData->Attack;
}
