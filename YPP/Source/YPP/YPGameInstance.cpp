// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameInstance.h"

UYPGameInstance::UYPGameInstance()
{
	// ���̺� �����͸� �����ϴ� �𸮾� ������Ʈ
	// ���� �ν��Ͻ��� ��������� �����ϰ� ������ �ּ��� ���۷����� ������ ��,
	// ������ �ҷ����̴� ����� ������
	FString CharacterDataPath = TEXT("/Game/Book/GameData/YPCharacterData.YPCharacterData");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_YPCHARACTER(*CharacterDataPath);
	YPCHECK(DT_YPCHARACTER.Succeeded());
	YPCharacterTable = DT_YPCHARACTER.Object;
	YPCHECK(YPCharacterTable->GetRowMap().Num() > 0);

}

void UYPGameInstance::Init()
{
	Super::Init();
	ABLOG(Warning,TEXT("DropExp of Level 20 YPCharacter : %d"), GetYPCharacterData(20)->DropExp);
}

FYPCharacterData* UYPGameInstance::GetYPCharacterData(int32 Level)
{
	return YPCharacterTable->FindRow<FYPCharacterData>(*FString::FromInt(Level),TEXT(""));
}
