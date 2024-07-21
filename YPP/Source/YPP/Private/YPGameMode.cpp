// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameMode.h"
#include "YPCharacter.h"
#include "YPPlayerController.h"
#include "YPPlayerState.h"
#include "YPGameState.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"

AYPGameMode::AYPGameMode()
{
	DefaultPawnClass = AYPCharacter::StaticClass();
	PlayerControllerClass = AYPPlayerController::StaticClass();
	PlayerStateClass = AYPPlayerState::StaticClass();
	GameStateClass = AYPGameState::StaticClass();

	ScoreToClear = 1;
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

	if (GetScore() >= ScoreToClear)
	{
		YPGameState->SetGameCleared();
		
		UWorld* World = GetWorld();
		if (!World) return;
		//
		for (APawn* Pawn : TActorRange<APawn>(World))
		{
			if (Pawn)
			{
				Pawn->TurnOff();
			}
		}
		//
		for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
		{
			const auto YPPlayerController = Cast<AYPPlayerController>(It->Get());
			if (nullptr != YPPlayerController)
			{
				YPPlayerController->ShowResultUI();
			}
		}
	}
}

int32 AYPGameMode::GetScore() const
{
	return YPGameState->GetTotalGameScore();
}
