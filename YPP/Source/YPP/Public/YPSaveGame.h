// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/SaveGame.h"
#include "YPSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API UYPSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UYPSaveGame();

	UPROPERTY()
	int32 Level;

	UPROPERTY()
	int32 Exp;

	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	int32 HighScore;

	UPROPERTY()
	int32 CharacterIndex;
};
