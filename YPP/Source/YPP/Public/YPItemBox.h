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
	// 플레이어를 감지하는 콜리전 박스
	UPROPERTY(VisibleAnywhere, Category = Box)
	UBoxComponent* Trigger;
	// 아이템 상자를 시각화해주는 스태틱메시
	UPROPERTY(VisibleAnywhere, Category = Box)
	UStaticMeshComponent* Box;
	// 상자 습득 이펙트
	UPROPERTY(VisibleAnywhere, Category = Effect)
	UParticleSystemComponent* Effect;

	// 클래스 정보를 저장하는 변수, 아이템 상자와 이를 선언한 클래스 목록만 볼 수 있도록 한정할 수 있음
	UPROPERTY(EditInstanceOnly, Category = Box)
	TSubclassOf<class AYPWeapon> WeaponItemClass;

private:
	// 상자와 캐릭터가 겹칠시 발생하는 이벤트 함수
	UFUNCTION()
	void OnCharacterOverlap(UPrimitiveComponent* overlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// 이펙트가 끝나면 발생하는 함수, 이펙트 재생이 종료되면 아이템 상자 제거
	UFUNCTION()
	void OnEffectFinished(class UParticleSystemComponent* pSystem);
};