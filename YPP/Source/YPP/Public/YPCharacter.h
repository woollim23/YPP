// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/Character.h"
#include "YPCharacter.generated.h"

// �÷��̾��� ������ ����Ǹ� ���� �½�ũ���� �ش� �˸��� ���� �� �ֵ��� �ϴ� ��������Ʈ
// ������ ����� �� �̸� ȣ���ϰ� ��
DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class YPP_API AYPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AYPCharacter();
	// ĳ���� ������Ʈ ����
	void SetCharacterState(ECharacterState NewState);
	// ĳ���� ������Ʈ ��������
	ECharacterState GetCharacterState() const;
	
	int32 GetExp() const;
	float GetFinalAttackRange() const;
	float GetFinalAttackDamage() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ���� ��� ���
	enum class EControlMode
	{
		GTA,
		DIABLO,
		NPC
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
	virtual void PostInitializeComponents() override;
	// TakeDamage �Լ��� �������̵��� ���Ͱ� ���� ������� ó���ϴ� ������ �߰���
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void PossessedBy(AController* NewController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ���⸦ ������ �� �ִ��� Ȯ���ϴ� �Լ�
	bool CanSetWeapon();
	// ĳ���Ϳ� ���⸦ ������Ű�� �Լ�
	void SetWeapon(class AYPWeapon* NewWeapon);
	// ���� ���� ���� ����
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AYPWeapon* CurrentWeapon;

	// ĳ���� ���� ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = Stat)
	class UYPCharacterStatComponent* CharacterStat;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = UI)
	class UWidgetComponent* HPBarWidget;

	// ���� �Լ�
	void Attack();

	// �÷��̾��� ������ ����Ǹ� ���� �½�ũ���� �ش� �˸��� ���� �� �ֵ��� �ϴ� ��������Ʈ
	// ������ ����� �� �̸� ȣ���ϰ� ��
	// �½�ũ���� ���� �Լ��� �ش� ��������Ʈ�� ����ϰ� ƽ �Լ��������� �̸� �ľ�
	// FinishLatenTask �Լ��� ȣ���Ͽ� �½�ũ �����ϵ��� ��
	FOnAttackEndDelegate OnAttackEnd;

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

	// �ִϸ��̼� ��Ÿ�� ����� ������ �ߵ��ϴ� �Լ�
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	// ���� ������ �� ���� �Ӽ� ����
	void AttackStartComboState();
	// ���� ������ �� ���
	void AttackEndComboState();
	// ���� ��ȿ Ÿ�� Ž�� �Լ�
	void AttackCheck();
	//
	void OnAssetLoadCompleted();

private:
	// ���� ���������� �ƴ��� �ľ��ϴ� �� ����
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta=(AllowPrivateAccess = true))
	bool IsAttacking;
	// ���� �޺��� �̵����� ����
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool CanNextCombo;
	// �޺� �Է� ���� 
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsComboInputOn;
	// ���� �������� �޺� ī����
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 CurrentCombo;
	// �޺� ī���� �ִ�ġ
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 MaxCombo;

	// �ִ� �ν��Ͻ��� ���� ����� �����̹Ƿ� ��� ������ ����
	UPROPERTY()
	class UYPAnimInstance* YPAnim;

	// ���� ����
	// AttackCheck �Լ��� SweepSingleByChannel�� ���
	// if ENABLE_DRAW_DEBUG���� ���
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRange;
	// ������
	// AttackCheck �Լ��� SweepSingleByChannel�� ���
	// if ENABLE_DRAW_DEBUG���� ���
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRadius;

	int32 AssetIndex = 0;

	// npc ���� �ּ�
	FSoftObjectPath CharacterAssetToLoad = FSoftObjectPath(nullptr);
	TSharedPtr<struct FStreamableHandle> AssetStreamingHandle;

	// ���� ĳ���� ������Ʈ
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = State, Meta = (AllowPrivateAccess = true))
	ECharacterState CurrentState;
	// �÷��̾� ĳ���Ͱ� �´���
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = State, Meta = (AllowPrivateAccess = true))
	bool bIsPlayer;
	// AI��Ʈ�ѷ�
	UPROPERTY()
	class AYPAIController* YPAIController;
	// �÷��̾� ��Ʈ�ѷ�
	UPROPERTY()
	class AYPPlayerController* YPPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State, Meta = (AllowPrivateAccess = true))
	float DeadTimer;

	FTimerHandle DeadTimerHandle = {};
};
