// Fill out your copyright notice in the Description page of Project Settings.


#include "YPHUDWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "YPCharacterStatComponent.h"
#include "YPPlayerState.h"


void UYPHUDWidget::BindCharacterStat(UYPCharacterStatComponent* CharacterStat)
{
	YPCHECK(nullptr != CharacterStat);
	CurrentCharacterStat = CharacterStat;
	// 체력 변화 델리게이트 -> &UYPHUDWidget::UpdateCharacterStat 함수 연결
	CharacterStat->OnHpChanged.AddUObject(this, &UYPHUDWidget::UpdateCharacterStat);

}

void UYPHUDWidget::BindPlayerState(AYPPlayerState* PlayerState)
{
	YPCHECK(nullptr != PlayerState);
	CurrentPlayerState = PlayerState;
	// 캐릭터 상태변화 델리게이트 -> &UYPHUDWidget::UpdatePlayerState 함수 연결
	PlayerState->OnPlayerStateChanged.AddUObject(this, &UYPHUDWidget::UpdatePlayerState);
}

// AddToViewport 시 호출된다. NativeOnInitialized 와 달리, Viewport 에 Add 될 때마다 불린다!
void UYPHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	HPBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("pbHP")));
	YPCHECK(nullptr != HPBar);

	ExpBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("pbExp")));
	YPCHECK(nullptr != ExpBar);

	PlayerName = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtPlayerName")));
	YPCHECK(nullptr != PlayerName);

	PlayerLevel = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtLevel")));
	YPCHECK(nullptr != PlayerLevel);

	CurrentScore = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtCurrentScore")));
	YPCHECK(nullptr != CurrentScore);

	HighScore = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtHighScore")));
	YPCHECK(nullptr != HighScore);
}

void UYPHUDWidget::UpdateCharacterStat()
{
	YPCHECK(CurrentCharacterStat.IsValid());

	HPBar->SetPercent(CurrentCharacterStat->GetHPRatio());
}

void UYPHUDWidget::UpdatePlayerState()
{
	YPCHECK(CurrentPlayerState.IsValid());

	ExpBar->SetPercent(CurrentPlayerState->GetExpRatio());
	PlayerName->SetText(FText::FromString(CurrentPlayerState->GetPlayerName()));
	PlayerLevel->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetCharacterLevel())));
	CurrentScore->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetGameScore())));
	HighScore->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetGameHighScore())));
}
