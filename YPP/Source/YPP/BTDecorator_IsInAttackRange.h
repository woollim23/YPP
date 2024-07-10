// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsInAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class YPP_API UBTDecorator_IsInAttackRange : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTDecorator_IsInAttackRange();

protected:
	// 데코레이터 클래스는 이 함수를 상속 받아 원하는 조건이 달성됐는지 파악하도록 설계됨
	// const로 선언되어 멤버 변수 변경이 불가능
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
