// Fill out your copyright notice in the Description page of Project Settings.


#include "YPAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

// ���� ������ ����, npc ���� ��ġ ����
const FName AYPAIController::HomePosKey(TEXT("HomePos"));
// npc�� �̵��� ��ġ ����
const FName AYPAIController::PatrolPosKey(TEXT("PatrolPos"));
// �÷��̾� ĳ���͸� Ž���ϴ� ����
const FName AYPAIController::TargetKey(TEXT("Target"));

AYPAIController::AYPAIController()
{
	// ������ ������ ������ �ҷ���
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/Book/AI/BB_YPCharacter.BB_YPCharacter"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	// ������ ������Ʈ�� �ҷ���
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/Book/AI/BT_YPCharacter.BT_YPCharacter"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}
}

void AYPAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AYPAIController::RunAI()
{
	UBlackboardComponent* BlackboardComp = Blackboard.Get();
	if (UseBlackboard(BBAsset, BlackboardComp))
	{
		BlackboardComp->SetValueAsVector(HomePosKey, GetPawn()->GetActorLocation());
		if (!RunBehaviorTree(BTAsset))
		{
			YPLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
}

void AYPAIController::StopAI()
{
	auto BehaviorTreeComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (nullptr != BehaviorTreeComponent)
	{
		BehaviorTreeComponent->StopTree(EBTStopMode::Safe);
	}
}
