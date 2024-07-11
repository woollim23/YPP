// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/Actor.h"
#include "YPItemBox.generated.h"

UCLASS()
class YPP_API AYPItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AYPItemBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	// �÷��̾ �����ϴ� �ݸ��� �ڽ�
	UPROPERTY(VisibleAnywhere, Category = Box)
	UBoxComponent* Trigger;
	// ������ ���ڸ� �ð�ȭ���ִ� ����ƽ�޽�
	UPROPERTY(VisibleAnywhere, Category = Box)
	UStaticMeshComponent* Box;
	// ���� ���� ����Ʈ
	UPROPERTY(VisibleAnywhere, Category = Effect)
	UParticleSystemComponent* Effect;

	// Ŭ���� ������ �����ϴ� ����, ������ ���ڿ� �̸� ������ Ŭ���� ��ϸ� �� �� �ֵ��� ������ �� ����
	UPROPERTY(EditInstanceOnly, Category = Box)
	TSubclassOf<class AYPWeapon> WeaponItemClass;

private:
	// ���ڿ� ĳ���Ͱ� ��ĥ�� �߻��ϴ� �̺�Ʈ �Լ�
	UFUNCTION()
	void OnCharacterOverlap(UPrimitiveComponent* overlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// ����Ʈ�� ������ �߻��ϴ� �Լ�, ����Ʈ ����� ����Ǹ� ������ ���� ����
	UFUNCTION()
	void OnEffectFinished(class UParticleSystemComponent* pSystem);
};