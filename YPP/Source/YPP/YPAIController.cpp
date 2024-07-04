// Fill out your copyright notice in the Description page of Project Settings.


#include "YPAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AYPAIController::AYPAIController()
{
	// Ž�� Ÿ�̸�
	RepeatInterval = 3.0f;
}

void AYPAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	// AI��Ʈ�ѷ��� Ÿ�̸Ӹ� ��ġ, 3�ʷ� Ÿ�̸Ӹ� ����, 3�ʸ��� �������� �̵�
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

	// �ݰ� 500 �̳��� �������� �������� ������
	FNavLocation NextLocation;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation))
	{
		// �������� ���� �̵���Ŵ
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation);
		YPLOG(Warning, TEXT("Next Location : %s"), *NextLocation.Location.ToString());
	}
}
