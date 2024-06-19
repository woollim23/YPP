// Fill out your copyright notice in the Description page of Project Settings.


#include "YPAnimInstance.h"

UYPAnimInstance::UYPAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
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
