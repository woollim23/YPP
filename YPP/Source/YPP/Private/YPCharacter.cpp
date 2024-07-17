  // Fill out your copyright notice in the Description page of Project Settings.


#include "YPCharacter.h"
#include "YPAnimInstance.h"
#include "YPWeapon.h"
#include "YPCharacterStatComponent.h"
#include "YPCharacterWidget.h"
#include "YPAIController.h"
#include "YPCharacterSetting.h"
#include "YPGameInstance.h"
#include "YPPlayerController.h"
#include "YPPlayerState.h"
#include "YPHUDWidget.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"
#include "Components/WidgetComponent.h"

// Sets default values
AYPCharacter::AYPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	CharacterStat = CreateDefaultSubobject<UYPCharacterStatComponent>(TEXT("CHARACTERSTAT"));
	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);
	HPBarWidget->SetupAttachment(GetMesh());

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

	IsAttacking = false;
	MaxCombo = 4;
	AttackEndComboState();

	// ĸ�� ������Ʈ�� �ݸ��� ������ ����
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("YPCharacter"));
	// AttackCheck �Լ��� SweepSingleByChannel�� ���
	// if ENABLE_DRAW_DEBUG���� ���
	AttackRange = 200.0f; // ���� ����
	AttackRadius = 50.0f; // ������

	// ü�¹� UI ����
	HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 180.0f));
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_HUD(TEXT("/Game/Book/UI/UI_HPBar.UI_HPBar_C"));
	if (UI_HUD.Succeeded())
	{
		HPBarWidget->SetWidgetClass(UI_HUD.Class);
		HPBarWidget->SetDrawSize(FVector2D(150.0f, 50.0f));
	}

	AIControllerClass = AYPAIController::StaticClass();
	// ������ �����Ǵ� �÷��̾ �����ϴ� �� ���� ��� ĳ���ʹ� YPAIController�� ���踦 ����
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	

	AssetIndex = 4;

	SetActorHiddenInGame(true);
	HPBarWidget->SetHiddenInGame(true);
	SetCanBeDamaged(false);

	DeadTimer = 5.0f;
}

void AYPCharacter::SetCharacterState(ECharacterState NewState)
{
	YPCHECK(CurrentState != NewState);
	CurrentState = NewState;

	switch (CurrentState)
	{
	case ECharacterState::LOADING:
	{
		if (bIsPlayer)
		{
			DisableInput(YPPlayerController);

			// HUD������ ĳ���� ���� ������Ʈ�� ����
			YPPlayerController->GetHUDWidget()->BindCharacterStat(CharacterStat);

			// �÷��̾� ���� �����ͼ� ���� ����(�ʱ�ȭ)
			auto YPPlayerState = Cast<AYPPlayerState>(GetPlayerState());
			YPCHECK(nullptr != YPPlayerState);
			CharacterStat->SetNewLevel(YPPlayerState->GetCharacterLevel());
		}
		SetActorHiddenInGame(true);
		HPBarWidget->SetHiddenInGame(true);
		SetCanBeDamaged(false);
		break;
	}
	case ECharacterState::READY:
	{
		SetActorHiddenInGame(false);
		HPBarWidget->SetHiddenInGame(false);
		SetCanBeDamaged(true);

		CharacterStat->OnHPIsZero.AddLambda([this]()->void {
			SetCharacterState(ECharacterState::DEAD);
		});
		// ĳ���� ������Ʈ�� UI ������ ������
		auto CharacterWidget = Cast<UYPCharacterWidget>(HPBarWidget->GetUserWidgetObject());
		if (nullptr != CharacterWidget)
		{
			CharacterWidget->BindCharacterStat(CharacterStat);
		}

		if (bIsPlayer)
		{
			SetControlMode(EControlMode::DIABLO);
			GetCharacterMovement()->MaxWalkSpeed = 600.0f;
			EnableInput(YPPlayerController);
		}
		else
		{
			SetControlMode(EControlMode::NPC);
			GetCharacterMovement()->MaxWalkSpeed = 400.0f;
			YPAIController->RunAI();
		}

		break;
	}
	case ECharacterState::DEAD:
	{
		SetActorHiddenInGame(false);
		GetMesh()->SetHiddenInGame(false);
		HPBarWidget->SetHiddenInGame(true);
		YPAnim->SetDeadAnim();
		SetCanBeDamaged(false);

		if (bIsPlayer)
		{
			DisableInput(YPPlayerController);
		}
		else
		{
			YPAIController->StopAI();
		}

		GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda([this]()-> void {
			if (bIsPlayer)
			{
				YPPlayerController->RestartLevel();
			}
			else
			{
				Destroy();
			}
			}), DeadTimer, false);
		break;
	}
	}
}

ECharacterState AYPCharacter::GetCharacterState() const
{
	return CurrentState;
}

int32 AYPCharacter::GetExp() const
{
	return CharacterStat->GetDropExp();
}

// Called when the game starts or when spawned
void AYPCharacter::BeginPlay()
{
	Super::BeginPlay();


	bIsPlayer = IsPlayerControlled();
	if (bIsPlayer)
	{
		// �÷��̾� ��Ʈ�ѷ� ���� ����
		YPPlayerController = Cast<AYPPlayerController>(GetController());
		YPCHECK(nullptr != YPPlayerController);
	}
	else
	{
		// AI ��Ʈ�ѷ� ���� ����
		YPAIController = Cast<AYPAIController>(GetController());
		YPCHECK(nullptr != YPAIController);
	}

	auto DefaultSetting = GetDefault<UYPCharacterSetting>();

	// �÷��̾ ĳ���͸� �����ϴ� ��쿡�� �ӽ÷� 4�� INDEX�� ĳ���� ������ ���
	// AI�� �����ϴ� NPC�� ��� ĳ���� �ּ� ��Ͽ��� �������� �����´�
	if (bIsPlayer)
	{
		AssetIndex = 4;
	}
	else
	{
		AssetIndex = FMath::RandRange(0, DefaultSetting->CharacterAssets.Num() - 1);
	}

	CharacterAssetToLoad = DefaultSetting->CharacterAssets[AssetIndex];
	auto YPGameInstance = Cast<UYPGameInstance>(GetGameInstance());
	YPCHECK(nullptr != YPGameInstance);
	AssetStreamingHandle = YPGameInstance->StreamableManager.RequestAsyncLoad(CharacterAssetToLoad, FStreamableDelegate::CreateUObject(this, &AYPCharacter::OnAssetLoadCompleted));
	SetCharacterState(ECharacterState::LOADING);
	
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
	case EControlMode::NPC:
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f);
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

void AYPCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	YPAnim = Cast<UYPAnimInstance>(GetMesh()->GetAnimInstance());
	YPCHECK(nullptr != YPAnim); // ��ũ�� ���� ���� ���� �ƴ� ��� ���� �α�
	
	// �ִ��ν��Ľ��� ��Ÿ������� ������ ����Ǵ� ��������Ʈ, OnAttackMontageEnded �Լ��� �ڵ����� ����ǵ��� ������
	YPAnim->OnMontageEnded.AddDynamic(this, &AYPCharacter::OnAttackMontageEnded);

	// ���� �Լ� ����, ����� ���� �ʿ�x
	YPAnim->OnNextAttackCheck.AddLambda([this]() -> void {
		CanNextCombo = false;

		if (IsComboInputOn)
		{
			AttackStartComboState();
			// ���� �޺��� �´� ��Ÿ�� �������� �̵���
			YPAnim->JumpToAttackMontageSection(CurrentCombo);
		}
	});
	
	// OnAttackHitCheck �ִϸ��̼� ��Ƽ���̰� �߻��� ������ YPCharacter�� �̸� �����ϴ� ��������Ʈ
	YPAnim->OnAttackHitCheck.AddUObject(this, &AYPCharacter::AttackCheck);

	// ��ε�ĳ��Ʈ�� �ߵ��ϴ� ü�� 0 ���� ��������Ʈ
	CharacterStat->OnHPIsZero.AddLambda([this]() -> void {
		YPLOG(Warning, TEXT("OnHPIsZero"));
		// �״� �ִϸ��̼� ���
		YPAnim->SetDeadAnim();
		// �浹 ��
		SetActorEnableCollision(false);
	});

}

// TakeDamage �Լ��� �������̵��� ���Ͱ� ���� ������� ó���ϴ� ������ �߰���
// Super Ű���带 ����� �θ� Ŭ������ ������ ���� ���� ������� ��
float AYPCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	YPLOG(Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);

	// �������� ������ ����
	CharacterStat->SetDamage(FinalDamage);
	if (CurrentState == ECharacterState::DEAD)
	{
		if (EventInstigator->IsPlayerController())
		{
			auto PlayerController = Cast<AYPPlayerController>(EventInstigator);
			YPCHECK(nullptr != PlayerController, 0.0f);
			PlayerController->NPCKill(this);
		}
	}

	return FinalDamage;
}

void AYPCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (IsPlayerControlled())
	{
		SetControlMode(EControlMode::DIABLO);
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	}
	else
	{
		SetControlMode(EControlMode::NPC);
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
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
	// ���� �Է� ���ε�
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AYPCharacter::Attack);

	// �𸮾��� InputComponent�� ����� �Է� ������ ���� ��Ű��,
	// �Է� ��ȣ�� �ڵ����� ĳ������ ��� �Լ��� ���ڷ� ���� ��
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AYPCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AYPCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AYPCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AYPCharacter::LookUp);
}

// ���⸦ ������ �� �ִ��� Ȯ���ϴ� �Լ�
bool AYPCharacter::CanSetWeapon()
{
	return (nullptr == CurrentWeapon);
}

// ĳ���Ϳ� ���⸦ ������Ű�� �Լ�
void AYPCharacter::SetWeapon(AYPWeapon* NewWeapon)
{
	YPCHECK(nullptr != NewWeapon && nullptr == CurrentWeapon);
	FName WeaponSocket(TEXT("hand_rSocket"));
	if (nullptr != NewWeapon)
	{
		// ���� ���Ⱑ ������ �ڵ� ���Ͽ� ���⸦ ������Ű��
		NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
		// ���� ������ �����ڸ� ĳ���ͷ� ������
		NewWeapon->SetOwner(this);
		CurrentWeapon = NewWeapon;
	}
}

void AYPCharacter::Attack()
{
	if (IsAttacking)
	{
		YPCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 1, MaxCombo));
		if (CanNextCombo)
		{
			IsComboInputOn = true;
		}
	}
	else
	{
		YPCHECK(CurrentCombo == 0);
		AttackStartComboState();
		YPAnim->PlayAttackMontage();
		YPAnim->JumpToAttackMontageSection(CurrentCombo);
		IsAttacking = true;
	}
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



// ���� ��Ÿ�ְ� ������ ȣ��Ǵ� �Լ�
void AYPCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	YPCHECK(IsAttacking);
	// ���ݻ��¸� ���� �Ƚ�
	YPCHECK(CurrentCombo > 0);
	IsAttacking = false;
	AttackEndComboState();

	// �÷��̾��� ������ ����Ǹ� ���� �½�ũ���� �ش� �˸��� ���� �� �ֵ��� �ϴ� ��������Ʈ
	// ������ ����� �� �̸� ȣ���ϰ� ��
	// �½�ũ���� ���� �Լ��� �ش� ��������Ʈ�� ����ϰ� ƽ �Լ��������� �̸� �ľ�
	// FinishLatenTask �Լ��� ȣ���Ͽ� �½�ũ �����ϵ��� ��
	OnAttackEnd.Broadcast();
}

// ���� ������ �� ���� �Ӽ� ����
void AYPCharacter::AttackStartComboState()
{
	CanNextCombo = true;
	IsComboInputOn = false;
	YPCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1));
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

// ���� ������ �� ���
void AYPCharacter::AttackEndComboState()
{
	IsComboInputOn = false;
	CanNextCombo = false;
	CurrentCombo = 0;
}

// ���� ��ȿ Ÿ�� Ž�� �Լ�
void AYPCharacter::AttackCheck()
{
	// �浹 ������ �浹�� ���Ϳ� ���õ� ������ ��� ���� ����ü
	FHitResult HitResult;
	
	// ä���� �̿��Ͽ� ���� ���� Ư�� ����������� �۾��� Ž���Ѵ�(��Ʈüũ)
	// ���� ����� ������ �ڽ��� Ž���� �������� �ʵ��� ������ this�� ������ ���� ��Ͽ� ���Խ�Ŵ
	FCollisionQueryParams Params(NAME_None, false, this);
	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult, // �浹�� ���Ϳ� ���õ� ������ ��� ���� ����ü
		GetActorLocation(), // Ž�� ���� ��ġ
		GetActorLocation() + GetActorForwardVector() * AttackRange, // Ž�� ���� ��ġ
		FQuat::Identity, // �ǰ������� ������ ȸ�� ��, ȸ�� ��� X
		ECollisionChannel::ECC_GameTraceChannel2, // �ݸ��� ä�� �Ҵ�
		FCollisionShape::MakeSphere(AttackRadius), // Ž���� ���� ����
		Params // ������ ���� �߰����� �Ű�����, ����ü �⺻������ ����
		);

#if ENABLE_DRAW_DEBUG
	FVector TraceVec = GetActorForwardVector() * AttackRange; // �ü� ���� ����
	FVector Center = GetActorLocation() + TraceVec * 0.5f; // ������ ����
	float HalfHeight = AttackRange * 0.5f + AttackRadius; //  ���� ������ ����
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat(); // ĸ���� Z���͸� ĳ���� �ü��������� ȸ��
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	float DebugLifeTime = 5.0f;

	DrawDebugCapsule(GetWorld(),
		Center,
		HalfHeight,
		AttackRadius,
		CapsuleRot,
		DrawColor,
		false,
		DebugLifeTime);


#endif
	if (bResult)
	{
		if (HitResult.HasValidHitObjectHandle())
		{
			YPLOG(Warning, TEXT("Hit Actor Name : %s"), *HitResult.ToString());

			FDamageEvent DamageEvent;
			// ���Ϳ� ������� �����ϴ� �Լ�
			// ������ ����� ����, ����� ����, ���� ����� ���� ������, ����� ������ ���� ����� ����
			HitResult.GetActor()->TakeDamage(CharacterStat->GetAttack(), DamageEvent, GetController(), this);
		}
	}
}

void AYPCharacter::OnAssetLoadCompleted()
{
	USkeletalMesh* AssetLoaded = Cast<USkeletalMesh>(AssetStreamingHandle->GetLoadedAsset());
	AssetStreamingHandle.Reset();
	YPCHECK(nullptr != AssetLoaded);
	GetMesh()->SetSkeletalMesh(AssetLoaded);
	
	SetCharacterState(ECharacterState::READY);
}
