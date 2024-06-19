// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Animation/AnimInstance.h"
#include "YPAnimInstance.generated.h"

//
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);

/**
 *
 */
UCLASS()
class YPP_API UYPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UYPAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// 어택 몽타주 플레이 함수
	void PlayAttackMontage();
	void JumpToAttackMontageSection(int32 NewSection);

public:
	//
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	//
	FOnAttackHitCheckDelegate OnAttackHitCheck;

private:
	// 노티파이 멤버 함수
	UFUNCTION()
	void AnimNotify_AttackHitCheck();

	//
	UFUNCTION()
	void AnimNotify_NextAttackCheck();

	//
	FName GetAttackMontageSectionName(int32 Section);

private:
	// 폰의 속도를 저장할 변수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
	// 폰이 공중에 떠있는 상태 저장할 변수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;
	// 어택 몽타주 저장할 변수
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;
};
