// Fill out your copyright notice in the Description page of Project Settings.


#include "YPWeapon.h"

// Sets default values
AYPWeapon::AYPWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WEAPON"));
	RootComponent = Weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_WEAPON(TEXT("/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight"));
	if (SK_WEAPON.Succeeded())
	{
		Weapon->SetSkeletalMesh(SK_WEAPON.Object);
	}

	// 무기의 충돌 설정을 끔
	Weapon->SetCollisionProfileName(TEXT("NoCollision"));

	AttackRange = 150.0f;
	AttackDamageMin = -2.5;
	AttackDamageMax = 10.0f;
	AttackModifierMin = 0.85f;
	AttackModifierMax = 1.25f;
}

float AYPWeapon::GetAttackRange() const
{
	return AttackRange;
}

float AYPWeapon::GetAttackDamage() const
{
	return AttackDamage;
}

float AYPWeapon::GetAttackModifier() const
{
	return AttackModifier;
}

// Called when the game starts or when spawned
void AYPWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	AttackDamage = FMath::RandRange(AttackDamageMin, AttackDamageMax);
	AttackModifier = FMath::RandRange(AttackModifierMin, AttackModifierMax);
	YPLOG(Warning, TEXT("Weapon Damage : %f, Modifier : %f"), AttackDamage, AttackModifier);
}
