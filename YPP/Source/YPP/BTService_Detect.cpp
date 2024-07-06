// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_Detect.h"
#include "YPAIController.h"
#include "YPCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_Detect::UBTService_Detect()
{
	// Detect 태스크 노드를 만듬
	NodeName = TEXT("Detect");
	// 시간간격을 1초로
	Interval = 1.0f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// 몬스터(AI에 조종당하는 중인) 폰
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return;

	// 몬스터가 어느 월드에 있는지 불러옴
	UWorld* World = ControllingPawn->GetWorld();
	// 몬스터의 위치 가져옴
	FVector Center = ControllingPawn->GetActorLocation();
	// 서치 반경 지정
	float DetectRadius = 600.0f;
	if (nullptr == World) return;
	
	/*
	// 결과를 배열로 받아옴
	TArray<FOverlapResult> OverlapResults;
	
	// 나 자신은 무시한채로 서칭하기위한 인자들을 받음
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	// 충돌 서치
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults, // 결과 받는 곳
		Center, // 현재 위치
		FQuat::Identity, // 회전 안함
		ECollisionChannel::ECC_GameTraceChannel2, // 트레이스 채널을 2번으로
		FCollisionShape::MakeSphere(DetectRadius), // 충돌 판별 구 모양
		CollisionQueryParam // 어떤식으로 서칭할 것인지
	);

	// 못찾고 있을경우 빨강색으로 0.2초 동안 범위를 그림
	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
	*/
}
