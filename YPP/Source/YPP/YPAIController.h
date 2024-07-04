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
	virtual void OnUnPossess() override;

private:
	void OnRepeatTimer();

	FTimerHandle RepeatTimerHandle;
	float RepeatInterval;
};
