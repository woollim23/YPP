// Fill out your copyright notice in the Description page of Project Settings.


#include "YPPlayerState.h"
#include "YPGameInstance.h"
#include "YPSaveGame.h"

AYPPlayerState::AYPPlayerState()
{
	CharacterLevel = 1;
	GameScore = 0;
	GameHighScore = 0;
	Exp = 0;
	SaveSlotName = TEXT("Player1");
	CharacterIndex = 0;
}

int32 AYPPlayerState::GetGameScore() const
{
	return GameScore;
}

int32 AYPPlayerState::GetGameHighScore() const
{
	return GameHighScore;
}

int32 AYPPlayerState::GetCharacterLevel() const
{
	return CharacterLevel;
}

int32 AYPPlayerState::GetCharacterIndex() const
{
	return CharacterIndex;
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
	SavePlayerData();
	return DidLevelUp;
}

void AYPPlayerState::AddGameScore()
{
	GameScore++;
	if (GameScore >= GameHighScore)
	{
		GameHighScore = GameScore;
	}
	OnPlayerStateChanged.Broadcast();
	SavePlayerData();
}

void AYPPlayerState::InitPlayerData()
{
	auto YPSaveGame = Cast<UYPSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (nullptr == YPSaveGame)
	{
		YPSaveGame = GetMutableDefault<UYPSaveGame>();
	}

	SetPlayerName(YPSaveGame->PlayerName);
	SetCharacterLevel(YPSaveGame->Level);
	GameScore = 0;
	GameHighScore = YPSaveGame->HighScore;
	Exp = YPSaveGame->Exp;
	CharacterIndex = YPSaveGame->CharacterIndex;
	SavePlayerData();
}

void AYPPlayerState::SavePlayerData()
{
	UYPSaveGame* NewPlayerData = NewObject<UYPSaveGame>();
	NewPlayerData->PlayerName = GetPlayerName();
	NewPlayerData->Level = CharacterLevel;
	NewPlayerData->Exp = Exp;
	NewPlayerData->HighScore = GameHighScore;
	NewPlayerData->CharacterIndex = CharacterIndex;

	if (!UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		YPLOG(Error, TEXT("SaveGame Error!"));
	}
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
