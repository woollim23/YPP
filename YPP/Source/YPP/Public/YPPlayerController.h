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

	AYPPlayerController();
	
public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* aPawn) override;

	class UYPHUDWidget* GetHUDWidget() const;
	void NPCKill(class AYPCharacter* KilledNPC) const;

protected:
	virtual void BeginPlay() override;
	//virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UYPHUDWidget> HUDWidgetClass;

private:
	UPROPERTY()
	class UYPHUDWidget* HUDWidget;
	UPROPERTY()
	class AYPPlayerState* YPPlayerState;
};
