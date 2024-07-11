// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Components/ActorComponent.h"
#include "YPCharacterStatComponent.generated.h"

// ü�� 0�� �����ϴ� ��������Ʈ
DECLARE_MULTICAST_DELEGATE(FOnHPIsZeroDelegate);
// ü�� ��ȭ ���� ��������Ʈ
DECLARE_MULTICAST_DELEGATE(FOnHPChangedDelegate);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class YPP_API UYPCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UYPCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// ������ PostInitializeComponents�� ���� �ϴ� ������Ʈ �Լ�, PostInitializeComponents �Լ��� ȣ��Ǳ� ���� ȣ���
	// �� �Լ��� ȣ��Ƿ��� �����ڿ��� bWantsInitializeComponent ���� true�� ��������� ��
	virtual void InitializeComponent() override;

public :
	// �����ʹ� ��� �����̺����� �����ϰ�
	// �� �Լ��� ���ؼ��� ������ �� �ֵ��� ����
	void SetNewLevel(int32 NewLevel);
	// ���� ������ ü�� ����
	void SetDamage(float NewDamage);
	// ü�� ���� 
	void SetHP(float NewHP);
	// ���ݵ����� ������ ��������
	float GetAttack();
	// ü�¹� ����
	float GetHPRatio();

	// ü�� 0�� �����ϴ� ��������Ʈ
	FOnHPIsZeroDelegate OnHPIsZero;
	// ü�� ��ȭ ���� ��������Ʈ
	FOnHPChangedDelegate OnHpChanged;


private:
	struct FYPCharacterData* CurrentStatData = nullptr;
	
	UPROPERTY(EditInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Level;
	// Transient : ������ ����ȭ���� ���ܽ�Ŵ
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	float CurrentHP;
};
