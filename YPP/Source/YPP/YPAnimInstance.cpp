// Fill out your copyright notice in the Description page of Project Settings.


#include "YPAnimInstance.h"

UYPAnimInstance::UYPAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
}

// 틱마다 호출되는 함수
void UYPAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// 애니메이션 시스템의 틱에서 폰에 접근해 폰의 속력 값을 얻어옴
	auto Pawn = TryGetPawnOwner(); // 폰 객체가 유효한지 검사
	if (::IsValid(Pawn))
	{ 
		CurrentPawnSpeed = Pawn->GetVelocity().Size(); // 속력을 가져와 변수에 저장
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) // 캐릭터인지 확인
		{
			IsInAir = Character->GetMovementComponent()->IsFalling(); // 상태 저장
		}
	}
}
