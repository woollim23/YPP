// Fill out your copyright notice in the Description page of Project Settings.


#include "YPCharacterWidget.h"
#include "YPCharacterStatComponent.h"
#include "Components/ProgressBar.h"

void UYPCharacterWidget::BindCharacterStat(UYPCharacterStatComponent* NewCharacterStat)
{
	YPCHECK(nullptr != NewCharacterStat);

	CurrentCharacterStat = NewCharacterStat;
	NewCharacterStat->OnHpChanged.AddUObject(this, &UYPCharacterWidget::UpdateHPWidget);
}

// UI 시스템이 준비되면 호출되는 함수, 위젯 내용을 업데이트함
void UYPCharacterWidget::NativeConstruct()
{
	Super::NativeConstruct();
	HPProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HPBar")));
	YPCHECK(nullptr != HPProgressBar);
	UpdateHPWidget();
}

void UYPCharacterWidget::UpdateHPWidget()
{
	if (CurrentCharacterStat.IsValid())
	{
		HPProgressBar->SetPercent(CurrentCharacterStat->GetHPRatio());
	}
}
