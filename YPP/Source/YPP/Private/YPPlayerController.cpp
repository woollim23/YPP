// Fill out your copyright notice in the Description page of Project Settings.


#include "YPPlayerController.h"
#include "YPHUDWidget.h"
#include "YPPlayerState.h"
#include "YPCharacter.h"
#include "YPGameplayWidget.h"
#include "YPGameplayResultWidget.h"
#include "YPGameState.h"

AYPPlayerController::AYPPlayerController()
{
	static ConstructorHelpers::FClassFinder<UYPHUDWidget> UI_HUD_C(TEXT("/Game/Book/UI/UI_HUD.UI_HUD_C"));
	if (UI_HUD_C.Succeeded())
	{
		HUDWidgetClass = UI_HUD_C.Class;
	}

	static ConstructorHelpers::FClassFinder<UYPGameplayWidget> UI_MENU_C(TEXT("/Game/Book/UI/UI_Menu.UI_Menu_C"));
	if (UI_MENU_C.Succeeded())
	{
		MenuWidgetClass = UI_MENU_C.Class;
	}

	static ConstructorHelpers::FClassFinder<UYPGameplayResultWidget> UI_RESULT_C(TEXT("/Game/Book/UI/UI_Result.UI_Result_C"));
	if (UI_RESULT_C.Succeeded())
	{
		ResultWidgetClass = UI_RESULT_C.Class;
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

void AYPPlayerController::AddGameScore() const
{
	YPPlayerState->AddGameScore();
}

void AYPPlayerController::ChangeInputMode(bool bGameMode)
{
	if (bGameMode)
	{
		SetInputMode(GameInputMode);
		bShowMouseCursor = false;
	}
	else
	{
		SetInputMode(UIInputMode);
		bShowMouseCursor = true;
	}
}

void AYPPlayerController::ShowResultUI()
{
	auto YPGameState = Cast<AYPGameState>(UGameplayStatics::GetGameState(this));
	YPCHECK(nullptr != YPGameState);
	ResultWidget->BindGameState(YPGameState);

	ResultWidget->AddToViewport();
	ChangeInputMode(false);
}


void AYPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ChangeInputMode(true);
	
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	
	HUDWidget = CreateWidget<UYPHUDWidget>(this, HUDWidgetClass);
	YPCHECK(nullptr != HUDWidget);
	HUDWidget->AddToViewport();

	ResultWidget = CreateWidget<UYPGameplayResultWidget>(this, ResultWidgetClass);
	YPCHECK(nullptr != ResultWidget);

	// HUD 위젝과 플레이어 스테이트를 연결
	YPPlayerState = Cast<AYPPlayerState>(PlayerState);
	YPCHECK(nullptr != YPPlayerState);
	HUDWidget->BindPlayerState(YPPlayerState);
	YPPlayerState->OnPlayerStateChanged.Broadcast();
	
}

void AYPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction(TEXT("GamePause"), EInputEvent::IE_Pressed, this, &AYPPlayerController::OnGamePause);
}

void AYPPlayerController::OnGamePause()
{
	MenuWidget = CreateWidget<UYPGameplayWidget>(this, MenuWidgetClass);
	YPCHECK(nullptr != MenuWidget);
	MenuWidget->AddToViewport(3);

	SetPause(true);
	ChangeInputMode(false);
}