// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_Detect.h"
#include "YPAIController.h"
#include "YPCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_Detect::UBTService_Detect()
{
	// 셀렉트에 끼워넣을 데코레이트 Detect를 만듬
	// 첫번째 분기
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
	
	
	// 결과를 배열로 받아옴
	TArray<FOverlapResult> OverlapResults;
	
	// 나 자신은 무시한채로 서칭하기위한 인자들을 받음
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	// 충돌 서치
	// OverlapMultiByChannel : 반경내 모든 캐릭터를 감지하는 함수. 
	// 반경 내에 감지된 모든 캐릭터 정보는 목록으로 관리하는 데 적합한 언리얼 엔진의 자료구조인 TArray로 전달됨.
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults, // 결과 받는 곳
		Center, // 현재 위치
		FQuat::Identity, // 회전 안함
		ECollisionChannel::ECC_GameTraceChannel2, // 트레이스 채널을 2번으로
		FCollisionShape::MakeSphere(DetectRadius), // 충돌 판별 구 모양
		CollisionQueryParam // 어떤식으로 서칭할 것인지
	);

	if (bResult) // 찾았을경우
	{
		// 배열에 저장된 오버랩 결과를 하나씩 스캔
		for (auto const& OverlapResult : OverlapResults)
		{
			// 탐색 범위내에 있는 캐릭터(플레이어) 값을 받아옴
			AYPCharacter* YPCharacter = Cast<AYPCharacter>(OverlapResult.GetActor());
			// IsPlayerController -> 플레이어 콘트롤러 인지 확인하는 함수
			// 진짜로 원하던 타겟(유저)인지 확인
			// 크로스 체킹, 위에서 한번 아래서 한번 총 두번 체크한셈
			if (YPCharacter && YPCharacter->GetController()->IsPlayerController())
			{
				// 타겟을 서치 범위안에 들어온 캐릭터(유저)로 바꿔치기
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AYPAIController::TargetKey, YPCharacter);
				// 초록색으로 0.2초동안 범위를 그림
				DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);
				DrawDebugPoint(World, YPCharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), YPCharacter->GetActorLocation(), FColor::Blue, false, 0.2f);
				return;
			}
		}
	}
	
	// 못찾고 있을경우 빨강색으로 0.2초 동안 범위를 그림
	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
	
}
