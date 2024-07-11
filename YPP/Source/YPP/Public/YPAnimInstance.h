// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Animation/AnimInstance.h"
#include "YPAnimInstance.generated.h"

// �ִ� �ν��Ͻ��� ������ ��������Ʈ�� ����ϴ� ��ü�� ������� ���� ��������Ʈ�� ����� �Լ��� ȣ���ϸ� �ǹǷ�,
// �ٸ� Ŭ������ ������� �ʴ� ������ ���� ���踦 �� �� �ִٴ� ������ ����
// NextAttackCheck �ִϸ��̼� ��Ƽ���̰� �߻��� ������ YPCharacter�� �̸� �����ϴ� ��������Ʈ ����
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
// OnAttackHitCheck �ִϸ��̼� ��Ƽ���̰� �߻��� ������ YPCharacter�� �̸� �����ϴ� ��������Ʈ ����
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
	// NextAttackCheck �ִϸ��̼� ��Ƽ���̰� �߻��� ������ YPCharacter�� �̸� �����ϴ� ��������Ʈ
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	// OnAttackHitCheck �ִϸ��̼� ��Ƽ���̰� �߻��� ������ YPCharacter�� �̸� �����ϴ� ��������Ʈ
	FOnAttackHitCheckDelegate OnAttackHitCheck;
	// ���� Ȯ�� �Ӽ��� Ʈ���
	void SetDeadAnim() { IsDead = true; }

private:
	// ��Ƽ���� ��� �Լ� - ���� ��Ʈ üũ
	UFUNCTION()
	void AnimNotify_AttackHitCheck();
	 
	// ��Ƽ���� ��� �Լ� - ���� ���� üũ
	UFUNCTION()
	void AnimNotify_NextAttackCheck();

	// ��Ÿ�� ���� �̸� ��� �Լ�
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
	// �״� �ִϸ��̼� ����� ���� �Ӽ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsDead;
};
