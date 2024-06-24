// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPAnimInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef YPP_YPAnimInstance_generated_h
#error "YPAnimInstance.generated.h already included, missing '#pragma once' in YPAnimInstance.h"
#endif
#define YPP_YPAnimInstance_generated_h

#define FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAnimNotify_NextAttackCheck); \
	DECLARE_FUNCTION(execAnimNotify_AttackHitCheck);


#define FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYPAnimInstance(); \
	friend struct Z_Construct_UClass_UYPAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UYPAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(UYPAnimInstance)


#define FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UYPAnimInstance(UYPAnimInstance&&); \
	UYPAnimInstance(const UYPAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYPAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYPAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UYPAnimInstance) \
	NO_API virtual ~UYPAnimInstance();


#define FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h_19_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h_22_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class UYPAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_YPAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
