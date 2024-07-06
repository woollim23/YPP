// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPItemBox.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UParticleSystemComponent;
class UPrimitiveComponent;
struct FHitResult;
#ifdef YPP_YPItemBox_generated_h
#error "YPItemBox.generated.h already included, missing '#pragma once' in YPItemBox.h"
#endif
#define YPP_YPItemBox_generated_h

#define FID_Git_YPP_YPP_Source_YPP_YPItemBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnEffectFinished); \
	DECLARE_FUNCTION(execOnCharacterOverlap);


#define FID_Git_YPP_YPP_Source_YPP_YPItemBox_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAYPItemBox(); \
	friend struct Z_Construct_UClass_AYPItemBox_Statics; \
public: \
	DECLARE_CLASS(AYPItemBox, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(AYPItemBox)


#define FID_Git_YPP_YPP_Source_YPP_YPItemBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AYPItemBox(AYPItemBox&&); \
	AYPItemBox(const AYPItemBox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AYPItemBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AYPItemBox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AYPItemBox) \
	NO_API virtual ~AYPItemBox();


#define FID_Git_YPP_YPP_Source_YPP_YPItemBox_h_9_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_YPItemBox_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_YPItemBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_YPItemBox_h_12_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_YPItemBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class AYPItemBox>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_YPItemBox_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
