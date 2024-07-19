// Fill out your copyright notice in the Description page of Project Settings.


#include "YPUIPlayerController.h"
#include "Blueprint/UserWidget.h"

void AYPUIPlayerController::BeginPlay()
{
	Super::BeginPlay();

	YPCHECK(nullptr != UIWidgetClass);

	// 플레이어 컨트롤러의 로직은 게임을 시작하면 해당 클래스로부터 UI 인스턴스를 생성
	UIWidgetInstance = CreateWidget<UUserWidget>(this, UIWidgetClass);
	YPCHECK(nullptr != UIWidgetInstance);
	// 이를 뷰포트에 띄움
	UIWidgetInstance->AddToViewport();
	// 입력은 UI에만 전달되도록 함
	FInputModeUIOnly Mode;
	Mode.SetWidgetToFocus(UIWidgetInstance->GetCachedWidget());
	SetInputMode(Mode);
	bShowMouseCursor = true;
}
