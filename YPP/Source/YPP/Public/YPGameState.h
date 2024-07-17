// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/GameStateBase.h"
#include "YPGameState.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API AYPGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AYPGameState();

public:
	int32 GetTotalGameScore() const;
	void AddGameScore();

private:
	UPROPERTY(Transient)
	int32 TotalGameScore;
	
};
