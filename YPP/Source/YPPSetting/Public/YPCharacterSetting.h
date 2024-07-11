// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "YPCharacterSetting.generated.h"

/**
 * 
 */
UCLASS(config= YPP)
class YPPSETTING_API UYPCharacterSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UYPCharacterSetting();

	UPROPERTY(config);
	TArray<FSoftObjectPath> CharacterAssets;
};
