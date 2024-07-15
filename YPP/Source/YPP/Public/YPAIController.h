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

	// npc 생성 위치 변수
	static const FName HomePosKey;
	// npc가 이동할 위치 변수
	static const FName PatrolPosKey;
	// 플레이어 캐릭터를 탐지하는 변수
	static const FName TargetKey;

	void RunAI();
	void StopAI();

private:
	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;

};
