// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsInAttackRange.h"
#include "YPAIController.h"
#include "YPCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange()
{
	// 셀렉트에 끼워넣을 데코레이트 CanAttack를 만듬
	// 두번째 분기
	NodeName = TEXT("CanAttack");
}

// 데코레이터 클래스는 이 함수를 상속 받아 원하는 조건이 달성됐는지 파악하도록 설계됨
bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = Cast<AYPCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if(nullptr == ControllingPawn)
		return false;

	// 목표물(플레이어 캐릭터) 오브젝트를 저장
	auto Target = Cast<AYPCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AYPAIController::TargetKey));
	if (nullptr == Target)
		return false;

	// 타겟과의 거리가 200 이하인지 여부 확인
	bResult = (Target->GetDistanceTo(ControllingPawn) <= ControllingPawn->GetFinalAttackRange());
	return bResult;
}
