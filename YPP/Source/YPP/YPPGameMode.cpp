// Copyright Epic Games, Inc. All Rights Reserved.

#include "YPPGameMode.h"
#include "YPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AYPPGameMode::AYPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
