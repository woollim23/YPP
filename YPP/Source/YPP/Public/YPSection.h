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
	// 에디터와 연동되는 함수, 에디터 작업에서 선택한 액터의 속성이나 트랜스폼 정보가 변경될때 실행 되는 함수
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// (READY, BATTLE, COMPLETE) 스테이트 열거형 -> 문 여닫 여부 결정
	enum class ESectionState :uint8
	{
		READY = 0,
		BATTLE,
		COMPLETE
	};

	// 섹션 액터의 로직을 스테이트 머신으로 설계(READY, BATTLE, COMPLETE)
	void SetState(ESectionState NewState);
	// 현재 스테이트
	ESectionState CurrentState = ESectionState::READY;

	// 게이트 문 여닫이 주문
	void OperateGates(bool bOpen = true);

	// 트리거 델리게이트 - &AYPSection::OnTriggerBeginOverlap 함수와 연결
	UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// 트리거 델리게이트 - &AYPSection::OnGateTriggerBeginOverlap 함수와 연결
	UFUNCTION()
	void OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// 엔피씨 생성 함수
	void OnNPCSpawn();

	UFUNCTION()
	void OnKeyNPCDestroyed(AActor* DestroyedActor);

private:
	// 게이트 매쉬
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	TArray<UStaticMeshComponent*> GateMeshes;
	// 게이트 충돌 트리거
	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
	TArray<UBoxComponent*> GateTriggers;
	// 맵 매쉬
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;
	// 충돌 트리거
	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
	UBoxComponent* Trigger;
	// 전투 확인 부울
	UPROPERTY(EditAnywhere, Category = State, Meta = (AllowPrivateAccess = true))
	bool bNoBattle;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float EnemySpawnTime;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float ItemBoxSpawnTime;

	FTimerHandle SpawnNPCTimeHandle = {};
	FTimerHandle SpawnItemBoxTimerHandle = {};
};
