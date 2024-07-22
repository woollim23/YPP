// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/PlayerState.h"
#include "YPPlayerState.generated.h"

// 플레이어 데이터가 변경될때 HUD에 신호를 보내 HUD가 관련 UI 위젯을 업데이트 하도록 하는 델리게이트
DECLARE_MULTICAST_DELEGATE(FOnPlayerStateChangedDelegate);

/**
 * 
 */
UCLASS()
class YPP_API AYPPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AYPPlayerState();

	int32 GetGameScore() const;
	int32 GetGameHighScore() const;
	int32 GetCharacterLevel() const;
	int32 GetCharacterIndex() const;
	float GetExpRatio() const;
	FString SaveSlotName;

	bool AddExp(int32 IncomeExp);
	void AddGameScore();

	void InitPlayerData();
	void SavePlayerData();

	FOnPlayerStateChangedDelegate OnPlayerStateChanged;

protected:
	UPROPERTY(Transient)
	int32 GameScore;
	UPROPERTY(Transient)
	int32 GameHighScore;
	UPROPERTY(Transient)
	int32 CharacterLevel;
	UPROPERTY(Transient)
	int32 Exp;
	UPROPERTY(Transient)
	int32 CharacterIndex;

private:
	void SetCharacterLevel(int32 NewCharacterLevel);
	struct FYPCharacterData* CurrentStatData;
};
