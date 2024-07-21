// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "YPGameplayWidget.h"
#include "YPGameplayResultWidget.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API UYPGameplayResultWidget : public UYPGameplayWidget
{
	GENERATED_BODY()
	
public:
	void BindGameState(class AYPGameState* GameState);

protected:
	virtual void NativeConstruct() override;

private:
	TWeakObjectPtr<class AYPGameState> CurrentGameState;
};
