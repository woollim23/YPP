// Fill out your copyright notice in the Description page of Project Settings.


#include "YPUIPlayerController.h"
#include "Blueprint/UserWidget.h"

void AYPUIPlayerController::BeginPlay()
{
	Super::BeginPlay();

	YPCHECK(nullptr != UIWidgetClass);

	// �÷��̾� ��Ʈ�ѷ��� ������ ������ �����ϸ� �ش� Ŭ�����κ��� UI �ν��Ͻ��� ����
	UIWidgetInstance = CreateWidget<UUserWidget>(this, UIWidgetClass);
	YPCHECK(nullptr != UIWidgetInstance);
	// �̸� ����Ʈ�� ���
	UIWidgetInstance->AddToViewport();
	// �Է��� UI���� ���޵ǵ��� ��
	FInputModeUIOnly Mode;
	Mode.SetWidgetToFocus(UIWidgetInstance->GetCachedWidget());
	SetInputMode(Mode);
	bShowMouseCursor = true;
}
