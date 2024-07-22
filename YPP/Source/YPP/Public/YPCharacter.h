// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/Character.h"
#include "YPCharacter.generated.h"

// 플레이어의 공격이 종료되면 공격 태스크에서 해당 알림을 받을 수 있도록 하는 델리게이트
// 공격이 종료될 때 이를 호출하게 함
DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class YPP_API AYPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AYPCharacter();
	// 캐릭터 스테이트 설정
	void SetCharacterState(ECharacterState NewState);
	// 캐릭터 스테이트 가져오기
	ECharacterState GetCharacterState() const;
	
	int32 GetExp() const;
	float GetFinalAttackRange() const;
	float GetFinalAttackDamage() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 조작 모드 목록
	enum class EControlMode
	{
		GTA,
		DIABLO,
		NPC
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
	// TakeDamage 함수를 오버라이드해 액터가 받은 대미지를 처리하는 로직을 추가함
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void PossessedBy(AController* NewController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 무기를 장착할 수 있는지 확인하는 함수
	bool CanSetWeapon();
	// 캐릭터에 무기를 장착시키는 함수
	void SetWeapon(class AYPWeapon* NewWeapon);
	// 공격 함수
	void Attack();

	// 플레이어의 공격이 종료되면 공격 태스크에서 해당 알림을 받을 수 있도록 하는 델리게이트
	// 공격이 종료될 때 이를 호출하게 함
	// 태스크에서 람다 함수를 해당 델리게이트에 등록하고 틱 함수로직에서 이를 파악
	// FinishLatenTask 함수를 호출하여 태스크 종료하도록 함
	FOnAttackEndDelegate OnAttackEnd;

	// 현재 무기 정보 변수
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AYPWeapon* CurrentWeapon;

	// 캐릭터 스탯 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Stat)
	class UYPCharacterStatComponent* CharacterStat;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = UI)
	class UWidgetComponent* HPBarWidget;




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

	// 애니메이션 몽타주 재생이 끝나면 발동하는 함수
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	// 공격 시작할 때 관련 속성 지정
	void AttackStartComboState();
	// 공격 종료할 때 사용
	void AttackEndComboState();
	// 공격 유효 타격 탐지 함수
	void AttackCheck();
	void OnAssetLoadCompleted();

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

	// 공격 범위
	// AttackCheck 함수의 SweepSingleByChannel에 사용
	// if ENABLE_DRAW_DEBUG에도 사용
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRange;
	// 반지름
	// AttackCheck 함수의 SweepSingleByChannel에 사용
	// if ENABLE_DRAW_DEBUG에도 사용
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRadius;

	int32 AssetIndex = 0;

	// npc 애셋 주소
	FSoftObjectPath CharacterAssetToLoad = FSoftObjectPath(nullptr);
	TSharedPtr<struct FStreamableHandle> AssetStreamingHandle;

	// 현재 캐릭터 스테이트
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = State, Meta = (AllowPrivateAccess = true))
	ECharacterState CurrentState;
	// 플레이어 캐릭터가 맞는지
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = State, Meta = (AllowPrivateAccess = true))
	bool bIsPlayer;
	// AI컨트롤러
	UPROPERTY()
	class AYPAIController* YPAIController;
	// 플레이어 컨트롤러
	UPROPERTY()
	class AYPPlayerController* YPPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State, Meta = (AllowPrivateAccess = true))
	float DeadTimer;

	FTimerHandle DeadTimerHandle = {};
};
