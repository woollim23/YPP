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
	
	// �½�ũ���� ���� �Լ��� �ش� ��������Ʈ�� ����ϰ� ƽ �Լ��������� �̸� �ľ�
	// FinishLatenTask �Լ��� ȣ���Ͽ� �½�ũ �����ϵ��� ��
	YPCharacter->OnAttackEnd.AddLambda([this]()->void {
		IsAttacking = false;
	});

	// �ϴ� InProgress�� ��ȯ�ϰ� ������ ������ �� �½�ũ�� �����ٰ� �˷������
	// ������ �˷��ִ� �Լ��� VinishLatenTask
	return EBTNodeResult::InProgress; // �½�ũ�� ��� �����ϰ� �ִٴ� ��ȯ��.
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (!IsAttacking)
	{
		// ������ �������� �½�ũ�� �����ٰ� �˷��ִ� �Լ�
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
