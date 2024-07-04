// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameMode.h"
#include "YPCharacter.h"
#include "YPPlayerController.h"

AYPGameMode::AYPGameMode()
{
	DefaultPawnClass = AYPCharacter::StaticClass();
	PlayerControllerClass = AYPPlayerController::StaticClass();
}

void AYPGameMode::PostLogin(APlayerController* NewPlayer)
{
	//YPLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	//YPLOG(Warning, TEXT("PostLogin End"));
}
