// Fill out your copyright notice in the Description page of Project Settings.


#include "YPAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

// 정적 변수로 선언, npc 생성 위치 변수
const FName AYPAIController::HomePosKey(TEXT("HomePos"));
// npc가 이동할 위치 변수
const FName AYPAIController::PatrolPosKey(TEXT("PatrolPos"));
// 플레이어 캐릭터를 탐지하는 변수
const FName AYPAIController::TargetKey(TEXT("Target"));

AYPAIController::AYPAIController()
{
	// 만들어둔 블랙보드 데이터 불러옴
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Script/AIModule.BlackboardData'/Game/Book/AI/BB_YPCharacter.BB_YPCharacter'"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	// 만들어둔 비헤비어트리 불러옴
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
		// HomePosKey의 위치값을 폰의 초기 위치로 설정
		BlackboardComp->SetValueAsVector(HomePosKey, InPawn->GetActorLocation()); 
		if (!RunBehaviorTree(BTAsset))
		{
			YPLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
	this->Blackboard = BlackboardComp;
}
