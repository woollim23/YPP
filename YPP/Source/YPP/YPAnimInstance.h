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
	// ���� �ӵ��� ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
	// ���� ���߿� ���ִ� ���� ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

};
