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
	virtual void PostInitializeComponents() override;

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
	// 공격 함수
	void Attack();

	// 애니메이션 몽타주 재생이 끝나면 발동하는 함수
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void AttackStartComboState(); // 공격 시작할 때 관련 속성 지정
	void AttackEndComboState(); // 공격 종료할 때 사용

private:
	// 현재 공격중인지 아닌지 파악하는 불 변수
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta=(AllowPrivateAccess = true))
	bool IsAttacking;
	// 다음 콤보로 이동가능 여부
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool CanNextCombo;
	// 콤보 입력 여부 
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsComboInputOn;
	// 현재 실행중인 콤보 카운터
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 CurrentCombo;
	// 콤보 카운터 최대치
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 MaxCombo;

	// 애님 인스턴스를 자주 사용할 예정이므로 멤버 변수로 선언
	UPROPERTY()
	class UYPAnimInstance* YPAnim;
};
