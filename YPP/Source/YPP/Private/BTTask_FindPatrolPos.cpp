// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPatrolPos.h"
#include "YPAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UBTTask_FindPatrolPos::UBTTask_FindPatrolPos()
{
	NodeName = TEXT("FindePatrolPos");
}

EBTNodeResult::Type UBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// 오너 컴포넌트와, 노드 메모리를 전달
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	// 폰(NPC)을 가져옴
	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	// 폰이 없으면 실패 반환
	if (nullptr == ControllingPawn)
		return EBTNodeResult::Failed;
	// 네비도 못가져오면 실패 반환
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem)
		return EBTNodeResult::Failed;

	// NPC의 현재 위치 저장
	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AYPAIController::HomePosKey);
	FNavLocation NextPatrol;

	// 현재 갈수 있는 곳중 랜덤 포인트를 집어주겠다
	// 500 거리 안
	// true면 갈 수 있는 곳이 있는 것
	if (NavSystem->GetRandomPointInNavigableRadius(Origin, 500.0f, NextPatrol))
	{
		// 블랙보드에다가 패트롤 포지션으로 바꿔치기 해줌
		// NextPatrol 값을 전달하여 랜덤 다음 위치 전달
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(AYPAIController::PatrolPosKey, NextPatrol.Location);
		// 성공 여부 반환
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
