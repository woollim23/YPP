// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef YPP_YPPlayerController_generated_h
#error "YPPlayerController.generated.h already included, missing '#pragma once' in YPPlayerController.h"
#endif
#define YPP_YPPlayerController_generated_h

#define FID_Git_YPP_YPP_Source_YPP_YPPlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAYPPlayerController(); \
	friend struct Z_Construct_UClass_AYPPlayerController_Statics; \
public: \
	DECLARE_CLASS(AYPPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(AYPPlayerController)


#define FID_Git_YPP_YPP_Source_YPP_YPPlayerController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AYPPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AYPPlayerController(AYPPlayerController&&); \
	AYPPlayerController(const AYPPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AYPPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AYPPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AYPPlayerController) \
	NO_API virtual ~AYPPlayerController();


#define FID_Git_YPP_YPP_Source_YPP_YPPlayerController_h_12_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_YPPlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_YPPlayerController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_YPPlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class AYPPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_YPPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
