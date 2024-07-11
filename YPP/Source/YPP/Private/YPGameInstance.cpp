// Fill out your copyright notice in the Description page of Project Settings.


#include "YPGameInstance.h"

UYPGameInstance::UYPGameInstance()
{
	// 테이블 데이터를 관리하는 언리얼 오브젝트
	// 게임 인스턴스의 멤버변수로 선언하고 데이터 애셋의 레퍼런스를 복사한 후,
	// 데이터 불러들이는 기능을 구현함
	FString CharacterDataPath = TEXT("/Game/Book/GameData/YPCharacterData.YPCharacterData");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_YPCHARACTER(*CharacterDataPath);
	YPCHECK(DT_YPCHARACTER.Succeeded());
	YPCharacterTable = DT_YPCHARACTER.Object;
	YPCHECK(YPCharacterTable->GetRowMap().Num() > 0);

}

void UYPGameInstance::Init()
{
	Super::Init();
	YPLOG(Warning,TEXT("DropExp of Level 20 YPCharacter : %d"), GetYPCharacterData(20)->DropExp);
}

FYPCharacterData* UYPGameInstance::GetYPCharacterData(int32 Level)
{
	return YPCharacterTable->FindRow<FYPCharacterData>(*FString::FromInt(Level),TEXT(""));
}
