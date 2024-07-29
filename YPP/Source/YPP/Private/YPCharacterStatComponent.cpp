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
}

// 액터의 PostInitializeComponents에 대응 하는 컴포넌트 함수, PostInitializeComponents 함수가 호출되기 전에 호출됨
// 이 함수가 호출되려면 생성자에서 bWantsInitializeComponent 값을 true로 설정해줘야 함
void UYPCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetNewLevel(Level);
}

void UYPCharacterStatComponent::SetNewLevel(int32 NewLevel)
{
	auto YPGameInstance = Cast<UYPGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	YPCHECK(nullptr != YPGameInstance);
	CurrentStatData = YPGameInstance->GetYPCharacterData(NewLevel);

	if (nullptr != CurrentStatData)
	{
		Level = NewLevel;
		SetHP(CurrentStatData->MaxHP);
	}
	else
	{
		YPLOG(Error, TEXT("Level (%d) data doesn't exist"), NewLevel);
	}
}

// 받은 데미지 체력 설정
void UYPCharacterStatComponent::SetDamage(float NewDamage)
{
	YPCHECK(nullptr != CurrentStatData);
	SetHP(FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP));

}

void UYPCharacterStatComponent::SetHP(float NewHP)
{
	CurrentHP = NewHP;
	OnHpChanged.Broadcast();
	if (CurrentHP <= KINDA_SMALL_NUMBER)
	{
		CurrentHP = 0.0f;
		OnHPIsZero.Broadcast();
	}
}

float UYPCharacterStatComponent::GetAttack() const
{
	YPCHECK(nullptr != CurrentStatData, 0.0f);
	return CurrentStatData->Attack;
}

float UYPCharacterStatComponent::GetHPRatio() const
{
	YPCHECK(nullptr != CurrentStatData, 0.0f);
	return (CurrentStatData->MaxHP < KINDA_SMALL_NUMBER) ? 0.0f : (CurrentHP / CurrentStatData->MaxHP);
}

int32 UYPCharacterStatComponent::GetDropExp() const
{
	return CurrentStatData->DropExp;
}
