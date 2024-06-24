// Fill out your copyright notice in the Description page of Project Settings.


#include "YPAnimInstance.h"

UYPAnimInstance::UYPAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;

	// ���� ��Ÿ�� �ҷ�����
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("/Script/Engine.AnimMontage'/Game/Book/Animation/SK_Mannequin_Skeleton_Montage.SK_Mannequin_Skeleton_Montage'"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		// ������ ����
		AttackMontage = ATTACK_MONTAGE.Object;
	}
}

// ƽ���� ȣ��Ǵ� �Լ�
void UYPAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// �ִϸ��̼� �ý����� ƽ���� ���� ������ ���� �ӷ� ���� ����
	auto Pawn = TryGetPawnOwner(); // �� ��ü�� ��ȿ���� �˻�
	if (::IsValid(Pawn))
	{ 
		CurrentPawnSpeed = Pawn->GetVelocity().Size(); // �ӷ��� ������ ������ ����
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) // ĳ�������� Ȯ��
		{
			IsInAir = Character->GetMovementComponent()->IsFalling(); // ���� ����
		}
	}
}

void UYPAnimInstance::PlayAttackMontage()
{
	// ��Ÿ�긦 ����ϴ� �Լ�
	 Montage_Play(AttackMontage, 1.0f);
	
}

void UYPAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	// ���� ���� �̸����� <- Ư�� �������� �̵��Ѵ�
	ABCHECK(Montage_IsPlaying(AttackMontage));
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

void UYPAnimInstance::AnimNotify_AttackHitCheck()
{
	// NextAttackCheck �ִϸ��̼� ��Ƽ���̰� �߻��� ������ YPCharacter�� �̸� �����ϴ� ��������Ʈ
	OnAttackHitCheck.Broadcast();
}

void UYPAnimInstance::AnimNotify_NextAttackCheck()
{
	// OnAttackHitCheck �ִϸ��̼� ��Ƽ���̰� �߻��� ������ YPCharacter�� �̸� �����ϴ� ��������Ʈ
	OnNextAttackCheck.Broadcast();
}

FName UYPAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	// ���� ��ȣ�� �̿��ؼ� �̸��� ��
	ABCHECK(FMath::IsWithinInclusive<int32>(Section, 1, 4), NAME_None);
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}
