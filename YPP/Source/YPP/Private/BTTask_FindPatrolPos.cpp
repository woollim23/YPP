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
	// ���� ������Ʈ��, ��� �޸𸮸� ����
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	// ��(NPC)�� ������
	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	// ���� ������ ���� ��ȯ
	if (nullptr == ControllingPawn)
		return EBTNodeResult::Failed;
	// �׺� ���������� ���� ��ȯ
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem)
		return EBTNodeResult::Failed;

	// NPC�� ���� ��ġ ����
	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AYPAIController::HomePosKey);
	FNavLocation NextPatrol;

	// ���� ���� �ִ� ���� ���� ����Ʈ�� �����ְڴ�
	// 500 �Ÿ� ��
	// true�� �� �� �ִ� ���� �ִ� ��
	if (NavSystem->GetRandomPointInNavigableRadius(Origin, 500.0f, NextPatrol))
	{
		// �����忡�ٰ� ��Ʈ�� ���������� �ٲ�ġ�� ����
		// NextPatrol ���� �����Ͽ� ���� ���� ��ġ ����
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(AYPAIController::PatrolPosKey, NextPatrol.Location);
		// ���� ���� ��ȯ
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
