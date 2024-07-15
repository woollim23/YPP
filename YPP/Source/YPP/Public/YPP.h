// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

// 캐릭터의 스테이트
UENUM(BlueprintType)
enum class ECharacterState :uint8
{
	PREINIT,
	LOADING,
	READY,
	DEAD
};

DECLARE_LOG_CATEGORY_EXTERN(YPP, Log, All);
#define YPLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define YPLOG_S(Verbosity) UE_LOG(YPP, Verbosity, TEXT("%s"), *YPLOG_CALLINFO)
#define YPLOG(Verbosity, Format, ...) UE_LOG(YPP, Verbosity, TEXT("%s %s"), *YPLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
// 매크로 안의 조건이 참이 아닐경우 로그가 붉게 뜸
#define YPCHECK(Expr, ...){ if(!(Expr)) { YPLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; } }