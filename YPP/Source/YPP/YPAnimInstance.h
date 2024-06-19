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

	// ���� ��Ÿ�� �÷��� �Լ�
	void PlayAttackMontage();
	void JumpToAttackMontageSection(int32 NewSection);

public:
	//
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	//
	FOnAttackHitCheckDelegate OnAttackHitCheck;

private:
	// ��Ƽ���� ��� �Լ�
	UFUNCTION()
	void AnimNotify_AttackHitCheck();

	//
	UFUNCTION()
	void AnimNotify_NextAttackCheck();

	//
	FName GetAttackMontageSectionName(int32 Section);

private:
	// ���� �ӵ��� ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
	// ���� ���߿� ���ִ� ���� ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;
	// ���� ��Ÿ�� ������ ����
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;
};
