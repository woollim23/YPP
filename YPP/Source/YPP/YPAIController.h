// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "AIController.h"
#include "YPAIController.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API AYPAIController : public AAIController
{
	GENERATED_BODY()
	

public:
	AYPAIController();
	virtual void OnPossess(APawn* InPawn) override;

	// npc ���� ��ġ ����
	static const FName HomePosKey;
	// npc�� �̵��� ��ġ ����
	static const FName PatrolPosKey;
	// �÷��̾� ĳ���͸� Ž���ϴ� ����
	static const FName TargetKey;


private:
	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;

};
