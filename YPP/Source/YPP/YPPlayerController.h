// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/PlayerController.h"
#include "YPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API AYPPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess() override;
};
