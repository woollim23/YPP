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

	// 조작 모드 목록
	enum class EControlMode
	{
		GTA,
		DIABLO
	};

	// 조작 모드 전환을 쉽게 해주는 
	void SetControlMode(EControlMode NewControlMode);
	EControlMode CurrentControlMode = EControlMode::GTA;

	// UPROPERTY를 사용하지 않는 값 타입 변수들은 초기값 미리 지정
	FVector DirectionToMove = FVector::ZeroVector;

	// ViewChange 키 입력 시 시점 부드럽게 전환
	// SetControlMode 함수에서 정의 후 Tick 함수의 인자로 쓰임
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
	// 위아래 방향키 입력 함수
	void UpDown(float NewAxisValue);
	// 왼쪽오른쪽 방향키 입력 함수
	void LeftRight(float NewAxisValue);
	// 캐릭터 z축 회전
	void LookUp(float NewAxisValue);
	// 캐릭터 y축 회전
	void Turn(float NewAxisValue);

	// 조작모드 시점 전환
	void ViewChange();
};
