// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Animation/AnimInstance.h"
#include "YPAnimInstance.generated.h"

// 애님 인스턴스는 자인의 델리게이트를 사용하는 객체가 어떤것인지 몰라도 델리게이트에 연결된 함수만 호출하면 되므로,
// 다른 클래스와 연결되지 않는 의존성 없는 설계를 할 수 있다는 장점이 있음
// NextAttackCheck 애니메이션 노티파이가 발생할 때마다 YPCharacter에 이를 전달하는 델리게이트 선언
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
// OnAttackHitCheck 애니메이션 노티파이가 발생할 때마다 YPCharacter에 이를 전달하는 델리게이트 선언
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
	// NextAttackCheck 애니메이션 노티파이가 발생할 때마다 YPCharacter에 이를 전달하는 델리게이트
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	// OnAttackHitCheck 애니메이션 노티파이가 발생할 때마다 YPCharacter에 이를 전달하는 델리게이트
	FOnAttackHitCheckDelegate OnAttackHitCheck;
	// 죽음 확인 속성을 트루로
	void SetDeadAnim() { IsDead = true; }

private:
	// 노티파이 멤버 함수 - 어택 히트 체크
	UFUNCTION()
	void AnimNotify_AttackHitCheck();
	 
	// 노티파이 멤버 함수 - 다음 공격 체크
	UFUNCTION()
	void AnimNotify_NextAttackCheck();
	// 몽타주 섹션 이름 얻는 함수
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
	// 죽는 애니메이션 재생을 위한 속성
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsDead;
};
