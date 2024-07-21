// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameplayWidget.h"
#include "Components/Button.h"
#include "YPPlayerController.h"

void UYPGameplayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ResumeButton = Cast<UButton>(GetWidgetFromName(TEXT("btnResume")));
	if (nullptr != ResumeButton)
	{
		ResumeButton->OnClicked.AddDynamic(this, &UYPGameplayWidget::OnResumeClicked);
	}

	ReturnToTitleButton = Cast<UButton>(GetWidgetFromName(TEXT("btnReturnToTitle")));
	if (nullptr != ReturnToTitleButton)
	{
		ReturnToTitleButton->OnClicked.AddDynamic(this, &UYPGameplayWidget::OnReturnToTitleClicked);
	}

	RetryGameButton = Cast<UButton>(GetWidgetFromName(TEXT("btnRetryGame")));
	if (nullptr != RetryGameButton)
	{
		RetryGameButton->OnClicked.AddDynamic(this, &UYPGameplayWidget::OnRetryGameClicked);
	}
}

void UYPGameplayWidget::OnResumeClicked()
{
	auto YPPlayerController = Cast<AYPPlayerController>(GetOwningPlayer());
	YPCHECK(nullptr != YPPlayerController);

	RemoveFromParent();
	YPPlayerController->ChangeInputMode(true);
	YPPlayerController->SetPause(false);
}

void UYPGameplayWidget::OnReturnToTitleClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Title"));
}

void UYPGameplayWidget::OnRetryGameClicked()
{
	auto YPPlayerController = Cast<AYPPlayerController>(GetOwningPlayer());
	YPCHECK(nullptr != YPPlayerController);
	YPPlayerController->RestartLevel();
}
