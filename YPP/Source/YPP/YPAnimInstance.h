// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Animation/AnimInstance.h"
#include "YPAnimInstance.generated.h"

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

private:
	// 폰의 속도를 저장할 변수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
	// 폰이 공중에 떠있는 상태 저장할 변수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

};
