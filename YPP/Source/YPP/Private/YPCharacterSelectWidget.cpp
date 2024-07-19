// Fill out your copyright notice in the Description page of Project Settings.


#include "YPCharacterSelectWidget.h"
#include "YPCharacterSetting.h"
#include "YPGameInstance.h"
#include "EngineUtils.h"
#include "Animation/SkeletalMeshActor.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "YPSaveGame.h"
#include "YPPlayerState.h"


void UYPCharacterSelectWidget::NextCharacter(bool bForward)
{
	bForward ? CurrentIndex++ : CurrentIndex--;

	if (CurrentIndex == -1) CurrentIndex = MaxIndex - 1;
	if (CurrentIndex == MaxIndex) CurrentIndex = 0;

	auto CharacterSetting = GetDefault<UYPCharacterSetting>();
	auto AssetRef = CharacterSetting->CharacterAssets[CurrentIndex];

	auto YPGameInstance = GetWorld()->GetGameInstance<UYPGameInstance>();
	YPCHECK(nullptr != YPGameInstance);
	YPCHECK(TargetComponent.IsValid());

	USkeletalMesh* Asset = YPGameInstance->StreamableManager.LoadSynchronous<USkeletalMesh>(AssetRef);
	if (nullptr != Asset)
	{
		TargetComponent->SetSkeletalMesh(Asset);
	}
}

void UYPCharacterSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CurrentIndex = 0;
	auto CharacterSetting = GetDefault<UYPCharacterSetting>();
	MaxIndex = CharacterSetting->CharacterAssets.Num();

	for (TActorIterator<ASkeletalMeshActor> It(GetWorld()); It; ++It)
	{
		TargetComponent = It->GetSkeletalMeshComponent();
		break;
	}

	PrevButton = Cast<UButton>(GetWidgetFromName(TEXT("btnPrev")));
	YPCHECK(nullptr != PrevButton);

	NextButton = Cast<UButton>(GetWidgetFromName(TEXT("btnNext")));
	YPCHECK(nullptr != NextButton);

	TextBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("edtPlayerName")));
	YPCHECK(nullptr != TextBox);

	ConfirmButton = Cast<UButton>(GetWidgetFromName(TEXT("btnConfirm")));
	YPCHECK(nullptr != ConfirmButton);

	PrevButton->OnClicked.AddDynamic(this, &UYPCharacterSelectWidget::OnPrevClicked);
	NextButton->OnClicked.AddDynamic(this, &UYPCharacterSelectWidget::OnNextClicked);
	ConfirmButton->OnClicked.AddDynamic(this, &UYPCharacterSelectWidget::OnConfirmClicked);
}

void UYPCharacterSelectWidget::OnPrevClicked()
{
	NextCharacter(false);
}

void UYPCharacterSelectWidget::OnNextClicked()
{
	NextCharacter(true);
}

void UYPCharacterSelectWidget::OnConfirmClicked()
{
	FString CharacterName = TextBox->GetText().ToString();
	if (CharacterName.Len() <= 0 || CharacterName.Len() > 10) return;

	UYPSaveGame* NewPlayerData = NewObject<UYPSaveGame>();
	NewPlayerData->PlayerName = CharacterName;
	NewPlayerData->Level = 1;
	NewPlayerData->Exp = 0;
	NewPlayerData->HighScore = 0;
	NewPlayerData->CharacterIndex = CurrentIndex;

	auto YPPlayerState = GetDefault<AYPPlayerState>();
	if (UGameplayStatics::SaveGameToSlot(NewPlayerData, YPPlayerState->SaveSlotName, 0))
	{
		UGameplayStatics::OpenLevel(GetWorld(), TEXT("Gameplay"));
	}
	else
	{
		YPLOG(Error, TEXT("SaveGame Error!"));
	}
}
