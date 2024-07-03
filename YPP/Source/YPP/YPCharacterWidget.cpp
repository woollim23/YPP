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

// UI �ý����� �غ�Ǹ� ȣ��Ǵ� �Լ�, ���� ������ ������Ʈ��
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
