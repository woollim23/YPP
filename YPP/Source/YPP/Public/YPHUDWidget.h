// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Blueprint/UserWidget.h"
#include "YPHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API UYPHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindCharacterStat(class UYPCharacterStatComponent* CharacterStat);
	void BindPlayerState(class AYPPlayerState* PlayerState);

protected:
	// AddToViewport 시 호출된다. NativeOnInitialized 와 달리, Viewport 에 Add 될 때마다 불린다!
	virtual void NativeConstruct() override;
	void UpdateCharacterStat();
	void UpdatePlayerState();

private:
	// 스마트 포인터
	TWeakObjectPtr<class UYPCharacterStatComponent> CurrentCharacterStat;
	TWeakObjectPtr<class AYPPlayerState> CurrentPlayerState;

	UPROPERTY()
	class UProgressBar* HPBar;

	UPROPERTY()
	class UProgressBar* ExpBar;

	UPROPERTY()
	class UTextBlock* PlayerName;

	UPROPERTY()
	class UTextBlock* PlayerLevel;

	UPROPERTY()
	class UTextBlock* CurrentScore;

	UPROPERTY()
	class UTextBlock* HighScore;
};
