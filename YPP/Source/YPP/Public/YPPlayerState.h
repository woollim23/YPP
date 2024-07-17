// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/PlayerState.h"
#include "YPPlayerState.generated.h"

// �÷��̾� �����Ͱ� ����ɶ� HUD�� ��ȣ�� ���� HUD�� ���� UI ������ ������Ʈ �ϵ��� �ϴ� ��������Ʈ
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
	int32 GetCharacterLevel() const;
	float GetExpRatio() const;
	bool AddExp(int32 IncomeExp);
	void AddGameScore();

	void InitPlayerData();

	FOnPlayerStateChangedDelegate OnPlayerStateChanged;

protected:
	UPROPERTY(Transient)
	int32 GameScore;

	UPROPERTY(Transient)
	int32 CharacterLevel;

	UPROPERTY(Transient)
	int32 Exp;

private:
	void SetCharacterLevel(int32 NewCharacterLevel);
	struct FYPCharacterData* CurrentStatData;
};
