// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Components/ActorComponent.h"
#include "YPCharacterStatComponent.generated.h"

// 체력 0을 감지하는 델리게이트
DECLARE_MULTICAST_DELEGATE(FOnHPIsZeroDelegate);
// 체력 변화 감지 델리게이트
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
	// 액터의 PostInitializeComponents에 대응 하는 컴포넌트 함수, PostInitializeComponents 함수가 호출되기 전에 호출됨
	// 이 함수가 호출되려면 생성자에서 bWantsInitializeComponent 값을 true로 설정해줘야 함
	virtual void InitializeComponent() override;

public :
	// 데이터는 모두 프라이빗으로 선언하고
	// 이 함수를 통해서만 변경할 수 있도록 설계
	void SetNewLevel(int32 NewLevel);
	// 받은 데미지 체력 설정
	void SetDamage(float NewDamage);
	// 체력 설정 
	void SetHP(float NewHP);
	// 공격데미지 스탯을 리턴해줌
	float GetAttack() const;
	// 체력바 비율
	float GetHPRatio() const;
	// 경험치바 비율
	int32 GetDropExp() const;

	// 체력 0을 감지하는 델리게이트
	FOnHPIsZeroDelegate OnHPIsZero;
	// 체력 변화 감지 델리게이트
	FOnHPChangedDelegate OnHpChanged;


private:
	struct FYPCharacterData* CurrentStatData = nullptr;
	
	UPROPERTY(EditInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Level;
	// Transient : 데이터 직렬화에서 제외시킴
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	float CurrentHP;
};
