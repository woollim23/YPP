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
#include "YPGameMode.h"
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

	// 스켈레탈 메시 불러오기
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));
	if (SK_CARDBOARD.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	// 애님블루프린트 불러오기
	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Book/Animation/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

	// 초기 조작 모드를 디아블로 초기화
	SetControlMode(EControlMode::DIABLO);

	ArmLengthSpeed = 3.0f;
	ArmRotationSpeed = 10.0f;

	// 점프 높이 기본값을 800으로 수정
	GetCharacterMovement()->JumpZVelocity = 800.0f;

	IsAttacking = false;
	MaxCombo = 4;
	AttackEndComboState();

	// 캡슐 컴포넌트의 콜리전 프로필 지정
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("YPCharacter"));
	// AttackCheck 함수의 SweepSingleByChannel에 사용
	// if ENABLE_DRAW_DEBUG에도 사용
	AttackRange = 80.0f; // 공격 범위
	AttackRadius = 50.0f; // 반지름

	// 체력바 UI 설정
	HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 180.0f));
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_HUD(TEXT("/Game/Book/UI/UI_HPBar.UI_HPBar_C"));
	if (UI_HUD.Succeeded())
	{
		HPBarWidget->SetWidgetClass(UI_HUD.Class);
		HPBarWidget->SetDrawSize(FVector2D(150.0f, 50.0f));
	}

	AIControllerClass = AYPAIController::StaticClass();
	// 앞으로 생성되는 플레이어가 조종하는 것 외의 모든 캐릭터는 YPAIController의 지배를 받음
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

			// HUD위젯과 캐릭터 스탯 컴포넌트를 연결
			YPPlayerController->GetHUDWidget()->BindCharacterStat(CharacterStat);

			// 플레이어 상태 가져와서 레벨 설정(초기화)
			auto YPPlayerState = Cast<AYPPlayerState>(GetPlayerState());
			YPCHECK(nullptr != YPPlayerState);
			CharacterStat->SetNewLevel(YPPlayerState->GetCharacterLevel());
		}
		else
		{
			// 스코어 오를때마다 NPC 레벨을 상승시킴
			// 게임 실행 중에 게임모드의 포인터를 가져올 떄는 월드의 GetAuthGameMode() 라는 함수를 사용함
			auto YPGameMode = Cast<AYPGameMode>(GetWorld()->GetAuthGameMode());
			YPCHECK(nullptr != YPGameMode);
			// CeilToInt : 소수점 올림 내림
			int32 TargetLevel = FMath::CeilToInt(((float)YPGameMode->GetScore() * 0.8f));
			// Clamp : min 및 max포함 범위로 고정된 value 반환
			int32 FinalLevel = FMath::Clamp<int32>(TargetLevel, 1, 20);
			YPLOG(Warning, TEXT("New Npc Level : %d"), FinalLevel);
			CharacterStat->SetNewLevel(FinalLevel);
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
		// 캐릭터 컴포넌트와 UI 위젯을 연결함
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
				YPPlayerController->ShowResultUI();
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

float AYPCharacter::GetFinalAttackRange() const
{
	return (nullptr != CurrentWeapon) ? CurrentWeapon->GetAttackRange() : AttackRange;
}

float AYPCharacter::GetFinalAttackDamage() const
{
	float AttackDamage = (nullptr != CurrentWeapon) ? (CharacterStat->GetAttack() + CurrentWeapon->GetAttackDamage()) : CharacterStat->GetAttack();
	float AttackModifier = (nullptr != CurrentWeapon) ? CurrentWeapon->GetAttackModifier() : 1.0f;

	return AttackDamage * AttackModifier;
}

// Called when the game starts or when spawned
void AYPCharacter::BeginPlay()
{
	Super::BeginPlay();


	bIsPlayer = IsPlayerControlled();
	if (bIsPlayer)
	{
		// 플레이어 컨트롤러 저장 변수
		YPPlayerController = Cast<AYPPlayerController>(GetController());
		YPCHECK(nullptr != YPPlayerController);
	}
	else
	{
		// AI 컨트롤러 저장 변수
		YPAIController = Cast<AYPAIController>(GetController());
		YPCHECK(nullptr != YPAIController);
	}

	auto DefaultSetting = GetDefault<UYPCharacterSetting>();

	// 플레이어가 캐릭터를 조종하는 경우에는 임시로 4번 INDEX의 캐릭터 에셋을 사용
	// AI가 조종하는 NPC인 경우 캐릭터 애셋 목록에서 랜덤으로 가져온다
	if (bIsPlayer)
	{
		// 저장된 플레이어 캐릭터 인덱스를 불러옴
		auto YPPlayerState = Cast<AYPPlayerState>(GetPlayerState());
		YPCHECK(nullptr != YPPlayerState);
		AssetIndex = YPPlayerState->GetCharacterIndex();
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

// 컨트롤 모드 세팅 함수
void AYPCharacter::SetControlMode(EControlMode NewControlMode)
{
	// 새 컨트롤 모드에 맞게 모드 설정값 변경
	CurrentControlMode = NewControlMode;

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// 캐릭터는 회전하지 않고 캐릭터를 기준으로 카메라가 회전
		// 카메라 방향으로 캐릭터가 회전해서 이동
		// 카메라 지지대 길이 450cm
		//SpringArm->TargetArmLength = 450.0f;
		//SpringArm->SetRelativeRotation(FRotator::ZeroRotator); // 액터 움직임 카메라에 영향 X
		ArmLengthTo = 450.0f;
		SpringArm->bUsePawnControlRotation = true; // 폰의 회전 허용
		SpringArm->bInheritPitch = true; // 마우스의 움직임 반영, y축 마우스
		SpringArm->bInheritRoll = true; // x축 마우스
		SpringArm->bInheritYaw = true; // z축 마우스
		SpringArm->bDoCollisionTest = true; // 벽에 충돌시 카메라 확대 줌
		bUseControllerRotationYaw = false; // 이 설정을 하면 마우스를 좌우로 움직이면 캐릭터가 z축으로 회전하지만, 상하이동은 폰이 회전하지 않도록 막는다	
		GetCharacterMovement()->bOrientRotationToMovement = true; // 캐릭터가 움직이는 방향으로 캐릭터를 자동으로 회전시켜줌
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // 캐릭터 회전속도 지정
		break;
	case EControlMode::DIABLO:
		// 카메라 길이 800, 45도에서 시점 고정
		// 마우스 입력 전부 해제(키보드 입력만 받음)
		//SpringArm->TargetArmLength = 800.0f;
		//SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
		ArmLengthTo = 800.0f;
		ArmRotationTo = FRotator(-45.0f, 0.0f, 0.0f);
		SpringArm->bUsePawnControlRotation = false;
		SpringArm->bInheritPitch = false;
		SpringArm->bInheritRoll = false;
		SpringArm->bInheritYaw = false;
		SpringArm->bDoCollisionTest = false;
		// 회전 끊김 방지 => 속성 해제 후 회전 보완 코드 작성
		// bOrientRotationToMovement 로 대체됨(UE4.26이상)
		bUseControllerRotationYaw = false;
		// 캐릭터 자동 회전 (키보드로 캐릭터 회전시키므로 해제)
		GetCharacterMovement()->bOrientRotationToMovement = false;
		// 컨트롤 회전이 가리키는 방향으로 캐릭터 회전
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		// 캐릭터가 부드럽게 회전하도록 보완 (회전 속도 지정)
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
		// SpringArm의 길이와 회전값이 목표 지점까지 변경
		// 변경 속도: ArmRotationSpeed
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
	YPCHECK(nullptr != YPAnim); // 매크로 조건 안이 참이 아닐 경우 붉은 로그
	
	// 애님인스탠스에 몽타주재생이 끝나면 실행되는 델리게이트, OnAttackMontageEnded 함수가 자동으로 실행되도록 연결함
	YPAnim->OnMontageEnded.AddDynamic(this, &AYPCharacter::OnAttackMontageEnded);

	// 람다 함수 지정, 헤더에 선언 필요x
	YPAnim->OnNextAttackCheck.AddLambda([this]() -> void {
		CanNextCombo = false;

		if (IsComboInputOn)
		{
			AttackStartComboState();
			// 현재 콤보에 맞는 몽타주 섹션으로 이동함
			YPAnim->JumpToAttackMontageSection(CurrentCombo);
		}
	});
	
	// OnAttackHitCheck 애니메이션 노티파이가 발생할 때마다 YPCharacter에 이를 전달하는 델리게이트
	YPAnim->OnAttackHitCheck.AddUObject(this, &AYPCharacter::AttackCheck);

	// 브로드캐스트로 발동하는 체력 0 감지 델리게이트
	CharacterStat->OnHPIsZero.AddLambda([this]() -> void {
		YPLOG(Warning, TEXT("OnHPIsZero"));
		// 죽는 애니메이션 재생
		YPAnim->SetDeadAnim();
		// 충돌 끔
		SetActorEnableCollision(false);
	});

}

// TakeDamage 함수를 오버라이드해 액터가 받은 대미지를 처리하는 로직을 추가함
// Super 키워드를 사용해 부모 클래스의 로직을 먼저 실행 시켜줘야 함
float AYPCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	YPLOG(Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);

	// 피해입은 데미지 전달
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

	// 버튼을 누른 직후 ViewChange함수 호출
	// BindAction, 액션 매핑 입력 설정과 연동하는 함수
	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AYPCharacter::ViewChange);
	// 점프 입력 바인딩
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	// 공격 입력 바인딩
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AYPCharacter::Attack);

	// 언리얼은 InputComponent를 사용해 입력 설정을 연결 시키면,
	// 입력 신호는 자동으로 캐릭터의 멤버 함수의 인자로 전달 됨
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AYPCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AYPCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AYPCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AYPCharacter::LookUp);
}

// 무기를 장착할 수 있는지 확인하는 함수
bool AYPCharacter::CanSetWeapon()
{
	return true;
}

// 캐릭터에 무기를 장착시키는 함수
void AYPCharacter::SetWeapon(AYPWeapon* NewWeapon)
{
	YPCHECK(nullptr != NewWeapon);

	if (nullptr != CurrentWeapon)
	{
		CurrentWeapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		CurrentWeapon->Destroy();
		CurrentWeapon = nullptr;
	}

	FName WeaponSocket(TEXT("hand_rSocket"));
	if (nullptr != NewWeapon)
	{
		// 현재 무기가 없으면 핸드 소켓에 무기를 장착시키고
		NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
		// 무기 액터의 소유자를 캐릭터로 변경함
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
		// 함수 AddMovementInput() -> -1 ~ 1 사이의 입력 값을 폰 무브먼트 컴포넌트에 전달 해, 캐릭터를 움직이게 
		// 회전 값으로부터 시선 방향(X)의 벡터값 가져옴
		// 언리얼엔진에서 시선방향은 x축
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
		// 함수 AddMovementInput() -> -1 ~ 1 사이의 입력 값을 폰 무브먼트 컴포넌트에 전달 해, 캐릭터를 움직이게 
		// 회전 값으로부터 우측 방향(Y)의 벡터값 가져옴
		// 언리얼엔진에서 우측방향은 y축, z축은 캐릭터의 하늘 방향
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
		// 캐릭터 y축 회전 값 받음
		AddControllerPitchInput(NewAxisValue);
		break;
	}
}

void AYPCharacter::Turn(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// 캐릭터 z축 회전 값 받음
		AddControllerYawInput(NewAxisValue);
		break;
	}
}

void AYPCharacter::ViewChange()
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// 시점 변경이 자연스럽도록 회전 값 미리 부여
		// GTA->DIABLO이므로 캐릭터의 회전값 지정
		GetController()->SetControlRotation(GetActorRotation());
		SetControlMode(EControlMode::DIABLO);
		break;
	case EControlMode::DIABLO:
		// DIABLO->GTA이므로 SpringArm 회전값 지정
		// UE4.24이상부터 RelativeRotation->GetRelativeRotation()으로 변경
		GetController()->SetControlRotation(SpringArm->GetRelativeRotation());
		SetControlMode(EControlMode::GTA);
		break;
	}
}

// 공격 몽타주가 끝나면 호출되는 함수
void AYPCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	YPCHECK(IsAttacking);
	// 공격상태를 도로 팔스
	YPCHECK(CurrentCombo > 0);
	IsAttacking = false;
	AttackEndComboState();

	// 플레이어의 공격이 종료되면 공격 태스크에서 해당 알림을 받을 수 있도록 하는 델리게이트
	// 공격이 종료될 때 이를 호출하게 함
	// 태스크에서 람다 함수를 해당 델리게이트에 등록하고 틱 함수로직에서 이를 파악
	// FinishLatenTask 함수를 호출하여 태스크 종료하도록 함
	OnAttackEnd.Broadcast();
}

// 공격 시작할 때 관련 속성 지정
void AYPCharacter::AttackStartComboState()
{
	CanNextCombo = true;
	IsComboInputOn = false;
	YPCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1));
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

// 공격 종료할 때 사용
void AYPCharacter::AttackEndComboState()
{
	IsComboInputOn = false;
	CanNextCombo = false;
	CurrentCombo = 0;
}

// 공격 유효 타격 탐지 함수
void AYPCharacter::AttackCheck()
{
	float FinalAttackRange = GetFinalAttackRange();

	// 충돌 감지시 충돌된 액터에 관련된 정보를 얻기 위한 구조체
	FHitResult HitResult;
	// 채널을 이용하여 범위 내를 특정 도형모양으로 휩쓸어 탐색한다(히트체크)
	// 공격 명령을 내리는 자신은 탐지에 감지되지 않도록 포인터 this를 무시할 액터 목록에 포함시킴
	FCollisionQueryParams Params(NAME_None, false, this);
	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult, // 충돌된 액터에 관련된 정보를 얻기 위한 구조체
		GetActorLocation(), // 탐색 시작 위치
		GetActorLocation() + GetActorForwardVector() * FinalAttackRange, // 탐색 종료 위치
		FQuat::Identity, // 피격판정할 도형의 회전 값, 회전 사용 X
		ECollisionChannel::ECC_GameTraceChannel2, // 콜리전 채널 할당
		FCollisionShape::MakeSphere(AttackRadius), // 탐지할 도형 제작
		Params // 스윕에 대한 추가적인 매개변수, 구조체 기본값으로 설정
		);

#if ENABLE_DRAW_DEBUG
	FVector TraceVec = GetActorForwardVector() * FinalAttackRange; // 시선 방향 벡터
	FVector Center = GetActorLocation() + TraceVec * 0.5f; // 벡터의 중점
	float HalfHeight = FinalAttackRange * 0.5f + AttackRadius; //  벡터 길이의 절반
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat(); // 캡슐의 Z벡터를 캐릭터 시선방향으로 회전
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
			// 액터에 대미지를 전달하는 함수
			// 전달할 대미지 세기, 대미지 종류, 공격 명령을 내린 가해자, 대미지 전달을 위해 사용한 도구
			HitResult.GetActor()->TakeDamage(GetFinalAttackDamage(), DamageEvent, GetController(), this);
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
