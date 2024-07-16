// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/PlayerState.h"
#include "YPPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API AYPPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AYPPlayerState();

	int32 GetGameScore() const;
	int32 GetCharacterLevel() const;

	void InitPlayerData();

protected:
	UPROPERTY(Transient)
	int32 GameScore;

	UPROPERTY(Transient)
	int32 CharacterLevel;
};
