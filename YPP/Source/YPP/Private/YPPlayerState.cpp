// Fill out your copyright notice in the Description page of Project Settings.


#include "YPPlayerState.h"
#include "YPGameInstance.h"

AYPPlayerState::AYPPlayerState()
{
	CharacterLevel = 1;
	GameScore = 0;
	Exp = 0;
}

int32 AYPPlayerState::GetGameScore() const
{
	return GameScore;
}

int32 AYPPlayerState::GetCharacterLevel() const
{
	return CharacterLevel;
}

float AYPPlayerState::GetExpRatio() const
{
	if (CurrentStatData->NextExp <= KINDA_SMALL_NUMBER)
		return 0.0f;

	float Result = (float)Exp / (float)CurrentStatData->NextExp;
	YPLOG(Warning, TEXT("Ratio : %f, Current : %d, Next : %d"), Result, Exp, CurrentStatData->NextExp);
	return Result;
}

bool AYPPlayerState::AddExp(int32 IncomeExp)
{
	if (CurrentStatData->NextExp == -1)
		return false;

	bool DidLevelUp = false;
	Exp = Exp + IncomeExp;
	if (Exp >= CurrentStatData->NextExp)
	{
		Exp -= CurrentStatData->NextExp;
		SetCharacterLevel(CharacterLevel + 1);
		DidLevelUp = true;
	}

	// 캐릭터 상태 변경 델리게이트 브로드캐스트
	OnPlayerStateChanged.Broadcast();
	return DidLevelUp;
}

void AYPPlayerState::AddGameScore()
{
	GameScore++;
	OnPlayerStateChanged.Broadcast();
}

void AYPPlayerState::InitPlayerData()
{
	SetPlayerName(TEXT("Destiny"));
	SetCharacterLevel(5);
	CharacterLevel = 5;
	GameScore = 0;
	Exp = 0;
}

// 캐릭터 레벨, 스탯 데이터 설정
void AYPPlayerState::SetCharacterLevel(int32 NewCharacterLevel)
{
	auto YPGameInstance = Cast<UYPGameInstance>(GetGameInstance());
	YPCHECK(nullptr != YPGameInstance);

	CurrentStatData = YPGameInstance->GetYPCharacterData(NewCharacterLevel);
	YPCHECK(nullptr != CurrentStatData);

	CharacterLevel = NewCharacterLevel;
}
