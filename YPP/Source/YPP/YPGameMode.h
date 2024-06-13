// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/GameModeBase.h"
#include "YPGameMode.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API AYPGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AYPGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
};
