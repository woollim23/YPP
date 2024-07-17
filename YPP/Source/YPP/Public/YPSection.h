// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YPP.h"
#include "GameFramework/Actor.h"
#include "YPSection.generated.h"

UCLASS()
class YPP_API AYPSection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AYPSection();
	// �����Ϳ� �����Ǵ� �Լ�, ������ �۾����� ������ ������ �Ӽ��̳� Ʈ������ ������ ����ɶ� ���� �Ǵ� �Լ�
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// (READY, BATTLE, COMPLETE) ������Ʈ ������ -> �� ���� ���� ����
	enum class ESectionState :uint8
	{
		READY = 0,
		BATTLE,
		COMPLETE
	};

	// ���� ������ ������ ������Ʈ �ӽ����� ����(READY, BATTLE, COMPLETE)
	void SetState(ESectionState NewState);
	// ���� ������Ʈ
	ESectionState CurrentState = ESectionState::READY;

	// ����Ʈ �� ������ �ֹ�
	void OperateGates(bool bOpen = true);

	// Ʈ���� ��������Ʈ - &AYPSection::OnTriggerBeginOverlap �Լ��� ����
	UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// Ʈ���� ��������Ʈ - &AYPSection::OnGateTriggerBeginOverlap �Լ��� ����
	UFUNCTION()
	void OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// ���Ǿ� ���� �Լ�
	void OnNPCSpawn();

	UFUNCTION()
	void OnKeyNPCDestroyed(AActor* DestroyedActor);

private:
	// ����Ʈ �Ž�
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	TArray<UStaticMeshComponent*> GateMeshes;
	// ����Ʈ �浹 Ʈ����
	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
	TArray<UBoxComponent*> GateTriggers;
	// �� �Ž�
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;
	// �浹 Ʈ����
	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
	UBoxComponent* Trigger;
	// ���� Ȯ�� �ο�
	UPROPERTY(EditAnywhere, Category = State, Meta = (AllowPrivateAccess = true))
	bool bNoBattle;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float EnemySpawnTime;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float ItemBoxSpawnTime;

	FTimerHandle SpawnNPCTimeHandle = {};
	FTimerHandle SpawnItemBoxTimerHandle = {};
};
