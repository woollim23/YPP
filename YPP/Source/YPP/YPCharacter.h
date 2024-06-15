// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/Character.h"
#include "YPCharacter.generated.h"

UCLASS()
class YPP_API AYPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AYPCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ���� ��� ���
	enum class EControlMode
	{
		GTA,
		DIABLO
	};

	// ���� ��� ��ȯ�� ���� ���ִ� 
	void SetControlMode(EControlMode NewControlMode);
	EControlMode CurrentControlMode = EControlMode::GTA;

	// UPROPERTY�� ������� �ʴ� �� Ÿ�� �������� �ʱⰪ �̸� ����
	FVector DirectionToMove = FVector::ZeroVector;

	// ViewChange Ű �Է� �� ���� �ε巴�� ��ȯ
	// SetControlMode �Լ����� ���� �� Tick �Լ��� ���ڷ� ����
	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

private:
	// ���Ʒ� ����Ű �Է� �Լ�
	void UpDown(float NewAxisValue);
	// ���ʿ����� ����Ű �Է� �Լ�
	void LeftRight(float NewAxisValue);
	// ĳ���� z�� ȸ��
	void LookUp(float NewAxisValue);
	// ĳ���� y�� ȸ��
	void Turn(float NewAxisValue);

	// ���۸�� ���� ��ȯ
	void ViewChange();
};
