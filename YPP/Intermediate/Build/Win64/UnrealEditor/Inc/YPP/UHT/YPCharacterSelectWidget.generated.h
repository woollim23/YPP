// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPCharacterSelectWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef YPP_YPCharacterSelectWidget_generated_h
#error "YPCharacterSelectWidget.generated.h already included, missing '#pragma once' in YPCharacterSelectWidget.h"
#endif
#define YPP_YPCharacterSelectWidget_generated_h

#define FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnConfirmClicked); \
	DECLARE_FUNCTION(execOnNextClicked); \
	DECLARE_FUNCTION(execOnPrevClicked); \
	DECLARE_FUNCTION(execNextCharacter);


#define FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYPCharacterSelectWidget(); \
	friend struct Z_Construct_UClass_UYPCharacterSelectWidget_Statics; \
public: \
	DECLARE_CLASS(UYPCharacterSelectWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(UYPCharacterSelectWidget)


#define FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UYPCharacterSelectWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UYPCharacterSelectWidget(UYPCharacterSelectWidget&&); \
	UYPCharacterSelectWidget(const UYPCharacterSelectWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYPCharacterSelectWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYPCharacterSelectWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UYPCharacterSelectWidget) \
	NO_API virtual ~UYPCharacterSelectWidget();


#define FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_12_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class UYPCharacterSelectWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
