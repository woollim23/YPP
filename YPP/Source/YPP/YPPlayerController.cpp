// Fill out your copyright notice in the Description page of Project Settings.


#include "YPPlayerController.h"

void AYPPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//ABLOG_S(Warning);
}

void AYPPlayerController::OnPossess(APawn* aPawn)
{
	//ABLOG_S(Warning);
	Super::OnPossess(aPawn);
}

void AYPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
