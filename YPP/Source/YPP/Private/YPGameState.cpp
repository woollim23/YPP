// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameState.h"

AYPGameState::AYPGameState()
{
	TotalGameScore = 0;
}

int32 AYPGameState::GetTotalGameScore() const
{
	return TotalGameScore;
}

void AYPGameState::AddGameScore()
{
	TotalGameScore++;
}
