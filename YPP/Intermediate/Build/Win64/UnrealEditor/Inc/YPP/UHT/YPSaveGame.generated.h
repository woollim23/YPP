// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPSaveGame.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef YPP_YPSaveGame_generated_h
#error "YPSaveGame.generated.h already included, missing '#pragma once' in YPSaveGame.h"
#endif
#define YPP_YPSaveGame_generated_h

#define FID_Git_YPP_YPP_Source_YPP_Public_YPSaveGame_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYPSaveGame(); \
	friend struct Z_Construct_UClass_UYPSaveGame_Statics; \
public: \
	DECLARE_CLASS(UYPSaveGame, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(UYPSaveGame)


#define FID_Git_YPP_YPP_Source_YPP_Public_YPSaveGame_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UYPSaveGame(UYPSaveGame&&); \
	UYPSaveGame(const UYPSaveGame&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYPSaveGame); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYPSaveGame); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UYPSaveGame) \
	NO_API virtual ~UYPSaveGame();


#define FID_Git_YPP_YPP_Source_YPP_Public_YPSaveGame_h_12_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_Public_YPSaveGame_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_Public_YPSaveGame_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_Public_YPSaveGame_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class UYPSaveGame>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_Public_YPSaveGame_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
