// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
#ifdef YPP_YPCharacter_generated_h
#error "YPCharacter.generated.h already included, missing '#pragma once' in YPCharacter.h"
#endif
#define YPP_YPCharacter_generated_h

#define FID_Git_YPP_YPP_Source_YPP_YPCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnAttackMontageEnded);


#define FID_Git_YPP_YPP_Source_YPP_YPCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAYPCharacter(); \
	friend struct Z_Construct_UClass_AYPCharacter_Statics; \
public: \
	DECLARE_CLASS(AYPCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(AYPCharacter)


#define FID_Git_YPP_YPP_Source_YPP_YPCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AYPCharacter(AYPCharacter&&); \
	AYPCharacter(const AYPCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AYPCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AYPCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AYPCharacter) \
	NO_API virtual ~AYPCharacter();


#define FID_Git_YPP_YPP_Source_YPP_YPCharacter_h_9_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_YPCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_YPCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_YPCharacter_h_12_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_YPCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class AYPCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_YPCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
