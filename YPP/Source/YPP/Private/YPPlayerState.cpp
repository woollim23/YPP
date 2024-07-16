// Fill out your copyright notice in the Description page of Project Settings.


#include "YPPlayerState.h"

AYPPlayerState::AYPPlayerState()
{
	CharacterLevel = 1;
	GameScore = 0;
}

int32 AYPPlayerState::GetGameScore() const
{
	return GameScore;
}

int32 AYPPlayerState::GetCharacterLevel() const
{
	return CharacterLevel;
}

void AYPPlayerState::InitPlayerData()
{
	SetPlayerName(TEXT("Destiny"));
	CharacterLevel = 5;
	GameScore = 0;
}
