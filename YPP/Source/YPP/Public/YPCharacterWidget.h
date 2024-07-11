// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "Blueprint/UserWidget.h"
#include "YPCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API UYPCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindCharacterStat(class UYPCharacterStatComponent* NewCharacterStat);

protected:
	// UI �ý����� �غ�Ǹ� ȣ��Ǵ� �Լ�, ���� ������ ������Ʈ��
	virtual void NativeConstruct() override;
	void UpdateHPWidget();

private:
	// �������͸� �̿��Ͽ� ������Ʈ�� ����
	TWeakObjectPtr<class UYPCharacterStatComponent> CurrentCharacterStat;
	
	UPROPERTY()
	class UProgressBar* HPProgressBar;
};
