// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "YPGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FYPCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FYPCharacterData() :Level(1), MaxHP(100.0f), Attack(10.0), DropExp(10), NextExp(30) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 DropExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 NextExp;
};

/**
 * 
 */
UCLASS()
class YPP_API UYPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UYPGameInstance();
	
	// 게임이 시작될 때 가장 먼저 호출됨
	virtual void Init() override;
	// book->gamedata -> 캐릭터 데이터 파일
	FYPCharacterData* GetYPCharacterData(int32 Level);
	// 언리얼 엔진에서 게임 진행 중에도 비동기 방식으로 애셋을 로딩하는 클래스
	FStreamableManager StreamableManager;

private:
	// 테이블 데이터를 관리하는 언리얼 오브젝트
	// 게임 인스턴스의 멤버변수로 선언하고 데이터 애셋의 레퍼런스를 복사한 후,
	// 데이터 불러들이는 기능을 구현함
	UPROPERTY()
	class UDataTable* YPCharacterTable;
	
};
