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
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Script/AIModule.BlackboardData'/Game/Book/AI/BB_YPCharacter.BB_YPCharacter'"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	// ������ ������Ʈ�� �ҷ���
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Script/AIModule.BehaviorTree'/Game/Book/AI/BT_YPCharacter.BT_YPCharacter'"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}
}

void AYPAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	UBlackboardComponent* BlackboardComp = Blackboard.Get();
	if (UseBlackboard(BBAsset, BlackboardComp))
	{
		// HomePosKey�� ��ġ���� ���� �ʱ� ��ġ�� ����
		BlackboardComp->SetValueAsVector(HomePosKey, InPawn->GetActorLocation()); 
		if (!RunBehaviorTree(BTAsset))
		{
			YPLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
	this->Blackboard = BlackboardComp;
}
