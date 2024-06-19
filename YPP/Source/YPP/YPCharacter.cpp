// Fill out your copyright notice in the Description page of Project Settings.


#include "YPCharacter.h"

// Sets default values
AYPCharacter::AYPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	// ���̷�Ż �޽� �ҷ�����
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'"));
	if (SK_CARDBOARD.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	// �ִԺ������Ʈ �ҷ�����
	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Book/Animation/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

	// �ʱ� ���� ��带 ��ƺ�� �ʱ�ȭ
	SetControlMode(EControlMode::DIABLO);

	ArmLengthSpeed = 3.0f;
	ArmRotationSpeed = 10.0f;

	// ���� ���� �⺻���� 800���� ����
	GetCharacterMovement()->JumpZVelocity = 800.0f;
}

// Called when the game starts or when spawned
void AYPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// ��Ʈ�� ��� ���� �Լ�
void AYPCharacter::SetControlMode(EControlMode NewControlMode)
{
	// �� ��Ʈ�� ��忡 �°� ��� ������ ����
	CurrentControlMode = NewControlMode;

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// ĳ���ʹ� ȸ������ �ʰ� ĳ���͸� �������� ī�޶� ȸ��
		// ī�޶� �������� ĳ���Ͱ� ȸ���ؼ� �̵�
		// ī�޶� ������ ���� 450cm
		//SpringArm->TargetArmLength = 450.0f;
		//SpringArm->SetRelativeRotation(FRotator::ZeroRotator); // ���� ������ ī�޶� ���� X
		ArmLengthTo = 450.0f;
		SpringArm->bUsePawnControlRotation = true; // ���� ȸ�� ���
		SpringArm->bInheritPitch = true; // ���콺�� ������ �ݿ�, y�� ���콺
		SpringArm->bInheritRoll = true; // x�� ���콺
		SpringArm->bInheritYaw = true; // z�� ���콺
		SpringArm->bDoCollisionTest = true; // ���� �浹�� ī�޶� Ȯ�� ��
		bUseControllerRotationYaw = false; // �� ������ �ϸ� ���콺�� �¿�� �����̸� ĳ���Ͱ� z������ ȸ��������, �����̵��� ���� ȸ������ �ʵ��� ���´�	
		GetCharacterMovement()->bOrientRotationToMovement = true; // ĳ���Ͱ� �����̴� �������� ĳ���͸� �ڵ����� ȸ��������
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ĳ���� ȸ���ӵ� ����
		break;
	case EControlMode::DIABLO:
		// ī�޶� ���� 800, 45������ ���� ����
		// ���콺 �Է� ���� ����(Ű���� �Է¸� ����)
		//SpringArm->TargetArmLength = 800.0f;
		//SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
		ArmLengthTo = 800.0f;
		ArmRotationTo = FRotator(-45.0f, 0.0f, 0.0f);
		SpringArm->bUsePawnControlRotation = false;
		SpringArm->bInheritPitch = false;
		SpringArm->bInheritRoll = false;
		SpringArm->bInheritYaw = false;
		SpringArm->bDoCollisionTest = false;
		// ȸ�� ���� ���� => �Ӽ� ���� �� ȸ�� ���� �ڵ� �ۼ�
		// bOrientRotationToMovement �� ��ü��(UE4.26�̻�)
		bUseControllerRotationYaw = false;
		// ĳ���� �ڵ� ȸ�� (Ű����� ĳ���� ȸ����Ű�Ƿ� ����)
		GetCharacterMovement()->bOrientRotationToMovement = false;
		// ��Ʈ�� ȸ���� ����Ű�� �������� ĳ���� ȸ��
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		// ĳ���Ͱ� �ε巴�� ȸ���ϵ��� ���� (ȸ�� �ӵ� ����)
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;
	}
}

// Called every frame
void AYPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);

	switch (CurrentControlMode)
	{
	case EControlMode::DIABLO:
		// SpringArm�� ���̿� ȸ������ ��ǥ �������� ����
		// ���� �ӵ�: ArmRotationSpeed
		SpringArm->GetRelativeRotation() = FMath::RInterpTo(SpringArm->GetRelativeRotation(), ArmRotationTo, DeltaTime, ArmRotationSpeed);
		break;
	}

	switch (CurrentControlMode)
	{
	case EControlMode::DIABLO:
		if (DirectionToMove.SizeSquared() > 0.0f)
		{
			GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
			AddMovementInput(DirectionToMove);
		}
		break;
	}
}

// Called to bind functionality to input
void AYPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// ��ư�� ���� ���� ViewChange�Լ� ȣ��
	// BindAction, �׼� ���� �Է� ������ �����ϴ� �Լ�
	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AYPCharacter::ViewChange);
	// ���� �Է� ���ε�
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);

	// �𸮾��� InputComponent�� ����� �Է� ������ ���� ��Ű��,
	// �Է� ��ȣ�� �ڵ����� ĳ������ ��� �Լ��� ���ڷ� ���� ��
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AYPCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AYPCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AYPCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AYPCharacter::LookUp);
}

void AYPCharacter::UpDown(float NewAxisValue)
{

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// �Լ� AddMovementInput() -> -1 ~ 1 ������ �Է� ���� �� �����Ʈ ������Ʈ�� ���� ��, ĳ���͸� �����̰� 
		// ȸ�� �����κ��� �ü� ����(X)�� ���Ͱ� ������
		// �𸮾������� �ü������� x��
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
		break;
	case EControlMode::DIABLO:
		DirectionToMove.X = NewAxisValue;
		break;
	}
}

void AYPCharacter::LeftRight(float NewAxisValue)
{

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// �Լ� AddMovementInput() -> -1 ~ 1 ������ �Է� ���� �� �����Ʈ ������Ʈ�� ���� ��, ĳ���͸� �����̰� 
		// ȸ�� �����κ��� ���� ����(Y)�� ���Ͱ� ������
		// �𸮾������� ���������� y��, z���� ĳ������ �ϴ� ����
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), NewAxisValue);
		break;
	case EControlMode::DIABLO:
		DirectionToMove.Y = NewAxisValue;
		break;
	}
}

void AYPCharacter::LookUp(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// ĳ���� y�� ȸ�� �� ����
		AddControllerPitchInput(NewAxisValue);
		break;
	}
}

void AYPCharacter::Turn(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// ĳ���� z�� ȸ�� �� ����
		AddControllerYawInput(NewAxisValue);
		break;
	}
}

void AYPCharacter::ViewChange()
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// ���� ������ �ڿ��������� ȸ�� �� �̸� �ο�
		// GTA->DIABLO�̹Ƿ� ĳ������ ȸ���� ����
		GetController()->SetControlRotation(GetActorRotation());
		SetControlMode(EControlMode::DIABLO);
		break;
	case EControlMode::DIABLO:
		// DIABLO->GTA�̹Ƿ� SpringArm ȸ���� ����
		// UE4.24�̻���� RelativeRotation->GetRelativeRotation()���� ����
		GetController()->SetControlRotation(SpringArm->GetRelativeRotation());
		SetControlMode(EControlMode::GTA);
		break;
	}
}