// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "YPAIController.h"
#include "YPCharacter.h"

UBTTask_Attack::UBTTask_Attack()
{
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto YPCharacter = Cast<AYPCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == YPCharacter)
		return EBTNodeResult::Failed;

	YPCharacter->Attack();
	IsAttacking = true;
	
	// 태스크에서 람다 함수를 해당 델리게이트에 등록하고 틱 함수로직에서 이를 파악
	// FinishLatenTask 함수를 호출하여 태스크 종료하도록 함
	YPCharacter->OnAttackEnd.AddLambda([this]()->void {
		IsAttacking = false;
	});

	// 일단 InProgress를 반환하고 공격이 끝났을 때 태스크가 끝났다고 알려줘야함
	// 끝난걸 알려주는 함수는 VinishLatenTask
	return EBTNodeResult::InProgress; // 태스크를 계속 수행하고 있다는 반환값.
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (!IsAttacking)
	{
		// 공격이 끝났을때 태스크가 끝났다고 알려주는 함수
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
