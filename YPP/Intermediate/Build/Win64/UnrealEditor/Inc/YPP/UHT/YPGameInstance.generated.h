// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YPGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef YPP_YPGameInstance_generated_h
#error "YPGameInstance.generated.h already included, missing '#pragma once' in YPGameInstance.h"
#endif
#define YPP_YPGameInstance_generated_h

#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_13_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FYPCharacterData_Statics; \
	YPP_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> YPP_API UScriptStruct* StaticStruct<struct FYPCharacterData>();

#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_40_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYPGameInstance(); \
	friend struct Z_Construct_UClass_UYPGameInstance_Statics; \
public: \
	DECLARE_CLASS(UYPGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/YPP"), NO_API) \
	DECLARE_SERIALIZER(UYPGameInstance)


#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_40_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UYPGameInstance(UYPGameInstance&&); \
	UYPGameInstance(const UYPGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYPGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYPGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UYPGameInstance) \
	NO_API virtual ~UYPGameInstance();


#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_37_PROLOG
#define FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_40_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_40_INCLASS_NO_PURE_DECLS \
	FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_40_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YPP_API UClass* StaticClass<class UYPGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
