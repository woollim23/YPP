// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameMode.h"
#include "YPCharacter.h"
#include "YPPlayerController.h"
#include "YPPlayerState.h"
#include "YPGameState.h"

AYPGameMode::AYPGameMode()
{
	DefaultPawnClass = AYPCharacter::StaticClass();
	PlayerControllerClass = AYPPlayerController::StaticClass();
	PlayerStateClass = AYPPlayerState::StaticClass();
	GameStateClass = AYPGameState::StaticClass();
}

void AYPGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	YPGameState = Cast<AYPGameState>(GameState);
}

void AYPGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	auto YPPlayerState = Cast<AYPPlayerState>(NewPlayer->PlayerState);
	YPCHECK(nullptr != YPPlayerState);
	YPPlayerState->InitPlayerData();
}

void AYPGameMode::AddScore(AYPPlayerController* ScoredPlayer)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		const auto YPPlayerController = Cast<AYPPlayerController>(It->Get());
		if ((nullptr != YPPlayerController) && (ScoredPlayer == YPPlayerController))
		{
			YPPlayerController->AddGameScore();
			break;
		}
	}

	YPGameState->AddGameScore();
}

int32 AYPGameMode::GetScore() const
{
	return YPGameState->GetTotalGameScore();
}
