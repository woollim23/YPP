// Fill out your copyright notice in the Description page of Project Settings.


#include "YPAnimInstance.h"

UYPAnimInstance::UYPAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;

	// 어택 몽타주 불러오기
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("/Script/Engine.AnimMontage'/Game/Book/Animation/SK_Mannequin_Skeleton_Montage.SK_Mannequin_Skeleton_Montage'"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		// 변수에 대입
		AttackMontage = ATTACK_MONTAGE.Object;
	}
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

void UYPAnimInstance::PlayAttackMontage()
{
	
	 Montage_Play(AttackMontage, 1.0f);
	
}

void UYPAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	//
	ABCHECK(Montage_IsPlaying(AttackMontage));
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

void UYPAnimInstance::AnimNotify_AttackHitCheck()
{
	//
	OnAttackHitCheck.Broadcast();
}

void UYPAnimInstance::AnimNotify_NextAttackCheck()
{
	//
	OnNextAttackCheck.Broadcast();
}

FName UYPAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	//
	ABCHECK(FMath::IsWithinInclusive<int32>(Section, 1, 4), NAME_None);
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}
