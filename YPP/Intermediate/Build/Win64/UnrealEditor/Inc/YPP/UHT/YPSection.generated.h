// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPSection.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef YPP_YPSection_generated_h
#error "YPSection.generated.h already included, missing '#pragma once' in YPSection.h"
#endif
#define YPP_YPSection_generated_h

#define FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnGateTriggerBeginOverlap); \
	DECLARE_FUNCTION(execOnTriggerBeginOverlap);


#define FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAYPSection(); \
	friend struct Z_Construct_UClass_AYPSection_Statics; \
public: \
	DECLARE_CLASS(AYPSection, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(AYPSection)


#define FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AYPSection(AYPSection&&); \
	AYPSection(const AYPSection&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AYPSection); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AYPSection); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AYPSection) \
	NO_API virtual ~AYPSection();


#define FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h_9_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h_12_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class AYPSection>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_Public_YPSection_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
