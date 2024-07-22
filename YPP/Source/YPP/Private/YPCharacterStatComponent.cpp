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

// ������ PostInitializeComponents�� ���� �ϴ� ������Ʈ �Լ�, PostInitializeComponents �Լ��� ȣ��Ǳ� ���� ȣ���
// �� �Լ��� ȣ��Ƿ��� �����ڿ��� bWantsInitializeComponent ���� true�� ��������� ��
void UYPCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
	// ���� ���� ����
	SetNewLevel(Level);
}

// �����ʹ� ��� �����̺����� �����ϰ�
// �� �Լ��� ���ؼ��� ������ �� �ֵ��� ����
void UYPCharacterStatComponent::SetNewLevel(int32 NewLevel)
{
	// ���� �ν��Ͻ����� �����͸� ������ �ʱ�ȭ��
	// ������ ����Ǹ� �ش� ������ �ٲ�� ����
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

// ���� ������ ü�� ����
void UYPCharacterStatComponent::SetDamage(float NewDamage)
{
	YPCHECK(nullptr != CurrentStatData);
	// ���� ü�¿��� ���� ������ ��ŭ ��
	SetHP(FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP));

}

void UYPCharacterStatComponent::SetHP(float NewHP)
{
	CurrentHP = NewHP;
	// ü�� ��ȭ ���� �ϸ� ��ε�ĳ��Ʈ �ϴ� ��������Ʈ
	OnHpChanged.Broadcast();
	//
	if (CurrentHP <= KINDA_SMALL_NUMBER)
	{
		// ü���� 0���� ����
		CurrentHP = 0.0f;
		// ü�� 0�� �����ϴ� ��������Ʈ �ߵ�
		OnHPIsZero.Broadcast();
	}
}

float UYPCharacterStatComponent::GetAttack() const
{
	YPCHECK(nullptr != CurrentStatData, 0.0f);
	// ���� ���� �������� ��������
	return CurrentStatData->Attack;
}

float UYPCharacterStatComponent::GetHPRatio() const
{
	YPCHECK(nullptr != CurrentStatData, 0.0f);
	// 0 �̳� ���� ü�� ���� ����
	return (CurrentStatData->MaxHP < KINDA_SMALL_NUMBER) ? 0.0f : (CurrentHP / CurrentStatData->MaxHP);
}

int32 UYPCharacterStatComponent::GetDropExp() const
{
	return CurrentStatData->DropExp;
}
