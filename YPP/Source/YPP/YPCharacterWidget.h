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
	// UI 시스템이 준비되면 호출되는 함수, 위젯 내용을 업데이트함
	virtual void NativeConstruct() override;
	void UpdateHPWidget();

private:
	// 약포인터를 이용하여 컴포넌트를 참조
	TWeakObjectPtr<class UYPCharacterStatComponent> CurrentCharacterStat;
	
	UPROPERTY()
	class UProgressBar* HPProgressBar;
};
