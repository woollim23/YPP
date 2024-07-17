// Fill out your copyright notice in the Description page of Project Settings.


#include "YPPlayerController.h"
#include "YPHUDWidget.h"
#include "YPPlayerState.h"
#include "YPCharacter.h"

AYPPlayerController::AYPPlayerController()
{
	static ConstructorHelpers::FClassFinder<UYPHUDWidget> UI_HUD_C(TEXT("/Game/Book/UI/UI_HUD.UI_HUD_C"));
	if (UI_HUD_C.Succeeded())
	{
		HUDWidgetClass = UI_HUD_C.Class;
	}
}

void AYPPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AYPPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
}

UYPHUDWidget* AYPPlayerController::GetHUDWidget() const
{
	return HUDWidget;
}

void AYPPlayerController::NPCKill(AYPCharacter* KilledNPC) const
{
	YPPlayerState->AddExp(KilledNPC->GetExp());
}

void AYPPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	
	HUDWidget = CreateWidget<UYPHUDWidget>(this, HUDWidgetClass);
	HUDWidget->AddToViewport();


	// HUD 위젝과 플레이어 스테이트를 연결
	YPPlayerState = Cast<AYPPlayerState>(PlayerState);
	YPCHECK(nullptr != YPPlayerState);
	HUDWidget->BindPlayerState(YPPlayerState);
	YPPlayerState->OnPlayerStateChanged.Broadcast();
	
}
