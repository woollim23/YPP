// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
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
	
	// ������ ���۵� �� ���� ���� ȣ���
	virtual void Init() override;
	FYPCharacterData* GetYPCharacterData(int32 Level);

private:
	// ���̺� �����͸� �����ϴ� �𸮾� ������Ʈ
	// ���� �ν��Ͻ��� ��������� �����ϰ� ������ �ּ��� ���۷����� ������ ��,
	// ������ �ҷ����̴� ����� ������
	UPROPERTY()
	class UDataTable* YPCharacterTable;
	
};
