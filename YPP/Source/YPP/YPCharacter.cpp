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

	// 스켈레탈 메시 불러오기
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'"));
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

}

// Called when the game starts or when spawned
void AYPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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
		//SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		ArmLengthTo = 450.0f;
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
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

// Called to bind functionality to input
void AYPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 버튼을 누른 직후 ViewChange함수 호출
	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AYPCharacter::ViewChange);

	// 언리얼은 InputComponent를 사용해 입력 설정을 연결 시키면,
	// 입력 신호는 자동으로 캐릭터의 멤버 함수의 인자로 전달 됨
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AYPCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AYPCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AYPCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AYPCharacter::LookUp);
}

void AYPCharacter::UpDown(float NewAxisValue)
{
	// 함수 AddMovementInput() -> -1 ~ 1 사이의 입력 값을 폰 무브먼트 컴포넌트에 전달 해, 캐릭터를 움직이게 함
	// 함수 GetActorForwardVector() 전진 후진 입력 값 받음
	//AddMovementInput(GetActorForwardVector(), NewAxisValue);

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// 회전 값으로부터 시선 방향(X)의 벡터값 가져옴
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
		break;
	case EControlMode::DIABLO:
		DirectionToMove.X = NewAxisValue;
		break;
	}
}

void AYPCharacter::LeftRight(float NewAxisValue)
{
	// 함수 GetActorRightVector() 왼쪽 오른쪽 입력 값 받음
	//AddMovementInput(GetActorRightVector(), NewAxisValue);

	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// 회전 값으로부터 우측 방향(Y)의 벡터값 가져옴
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
		// 캐릭터 z축 회전 값 받음
		AddControllerPitchInput(NewAxisValue);
		break;
	}
}

void AYPCharacter::Turn(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::GTA:
		// 캐릭터 y축 회전 값 받음
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