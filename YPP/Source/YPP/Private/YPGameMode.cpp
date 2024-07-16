// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameMode.h"
#include "YPCharacter.h"
#include "YPPlayerController.h"
#include "YPPlayerState.h"

AYPGameMode::AYPGameMode()
{
	DefaultPawnClass = AYPCharacter::StaticClass();
	PlayerControllerClass = AYPPlayerController::StaticClass();
	PlayerStateClass = AYPPlayerState::StaticClass();
}

void AYPGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	auto YPPlayerState = Cast<AYPPlayerState>(NewPlayer->PlayerState);
	YPCHECK(nullptr != YPPlayerState);
	YPPlayerState->InitPlayerData();
}
