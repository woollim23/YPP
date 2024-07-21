// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameplayResultWidget.h"
#include "Components/TextBlock.h"
#include "YPGameState.h"

void UYPGameplayResultWidget::BindGameState(AYPGameState* GameState)
{
	YPCHECK(nullptr != GameState);
	CurrentGameState = GameState;
}

void UYPGameplayResultWidget::NativeConstruct()
{
	Super::NativeConstruct();

	YPCHECK(CurrentGameState.IsValid());

	auto Result = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtResult")));
	YPCHECK(nullptr!=Result);
	Result->SetText(FText::FromString(CurrentGameState->IsGameCleared() ? TEXT("Mission Complete") : TEXT("Mission Failed")));

	auto TotalScore = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtTotalScore")));
	YPCHECK(nullptr != TotalScore);
	TotalScore->SetText(FText::FromString(FString::FromInt(CurrentGameState->GetTotalGameScore())));
}
