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
	// ü�� ��ȭ ��������Ʈ -> &UYPHUDWidget::UpdateCharacterStat �Լ� ����
	CharacterStat->OnHpChanged.AddUObject(this, &UYPHUDWidget::UpdateCharacterStat);

}

void UYPHUDWidget::BindPlayerState(AYPPlayerState* PlayerState)
{
	YPCHECK(nullptr != PlayerState);
	CurrentPlayerState = PlayerState;
	// ĳ���� ���º�ȭ ��������Ʈ -> &UYPHUDWidget::UpdatePlayerState �Լ� ����
	PlayerState->OnPlayerStateChanged.AddUObject(this, &UYPHUDWidget::UpdatePlayerState);
}

// AddToViewport �� ȣ��ȴ�. NativeOnInitialized �� �޸�, Viewport �� Add �� ������ �Ҹ���!
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
