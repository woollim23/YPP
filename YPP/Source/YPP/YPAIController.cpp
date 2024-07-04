// Fill out your copyright notice in the Description page of Project Settings.


#include "YPAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AYPAIController::AYPAIController()
{
	// 탐색 타이머
	RepeatInterval = 3.0f;
}

void AYPAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	// AI컨트롤러에 타이머를 설치, 3초로 타이머를 맞춤, 3초마다 목적지로 이동
	GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &AYPAIController::OnRepeatTimer, RepeatInterval, true);
}

void AYPAIController::OnUnPossess()
{
	Super::OnUnPossess();
	GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle);
}

void AYPAIController::OnRepeatTimer()
{
	auto CurrentPawn = GetPawn();
	YPCHECK(nullptr != CurrentPawn);


	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (nullptr == NavSystem) return;

	// 반경 500 이내로 랜덤으로 목적지를 가져옴
	FNavLocation NextLocation;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation))
	{
		// 목적지로 폰을 이동시킴
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation);
		YPLOG(Warning, TEXT("Next Location : %s"), *NextLocation.Location.ToString());
	}
}
