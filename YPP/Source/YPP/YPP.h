// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(YPP, Log, All);
#define YPLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define YPLOG_S(Verbosity) UE_LOG(YPP, Verbosity, TEXT("%s"), *YPLOG_CALLINFO)
#define YPLOG(Verbosity, Format, ...) UE_LOG(YPP, Verbosity, TEXT("%s %s"), *YPLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
// ��ũ�� ���� ������ ���� �ƴҰ�� �αװ� �Ӱ� ��
#define YPCHECK(Expr, ...){ if(!(Expr)) { YPLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; } }