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
	virtual void InitializeComponent() override;

public :
	void SetNewLevel(int32 NewLevel);
	void SetDamage(float NewDamage);
	void SetHP(float NewHP);
	// ���ݵ����� ������ ��������
	float GetAttack() const;
	float GetHPRatio() const;
	int32 GetDropExp() const;

	FOnHPIsZeroDelegate OnHPIsZero;
	FOnHPChangedDelegate OnHpChanged;


private:
	struct FYPCharacterData* CurrentStatData = nullptr;
	
	UPROPERTY(EditInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Level;
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	float CurrentHP;
};
