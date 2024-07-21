// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPGameplayWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef YPP_YPGameplayWidget_generated_h
#error "YPGameplayWidget.generated.h already included, missing '#pragma once' in YPGameplayWidget.h"
#endif
#define YPP_YPGameplayWidget_generated_h

#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRetryGameClicked); \
	DECLARE_FUNCTION(execOnReturnToTitleClicked); \
	DECLARE_FUNCTION(execOnResumeClicked);


#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYPGameplayWidget(); \
	friend struct Z_Construct_UClass_UYPGameplayWidget_Statics; \
public: \
	DECLARE_CLASS(UYPGameplayWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(UYPGameplayWidget)


#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UYPGameplayWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UYPGameplayWidget(UYPGameplayWidget&&); \
	UYPGameplayWidget(const UYPGameplayWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYPGameplayWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYPGameplayWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UYPGameplayWidget) \
	NO_API virtual ~UYPGameplayWidget();


#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_12_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class UYPGameplayWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
