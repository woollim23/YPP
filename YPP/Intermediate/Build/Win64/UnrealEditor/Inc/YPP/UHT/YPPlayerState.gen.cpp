// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPPlayerState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPPlayerState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPPlayerState();
YPP_API UClass* Z_Construct_UClass_AYPPlayerState_NoRegister();
// End Cross Module References

// Begin Class AYPPlayerState
void AYPPlayerState::StaticRegisterNativesAYPPlayerState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYPPlayerState);
UClass* Z_Construct_UClass_AYPPlayerState_NoRegister()
{
	return AYPPlayerState::StaticClass();
}
struct Z_Construct_UClass_AYPPlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "YPPlayerState.h" },
		{ "ModuleRelativePath", "Public/YPPlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameScore_MetaData[] = {
		{ "ModuleRelativePath", "Public/YPPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterLevel_MetaData[] = {
		{ "ModuleRelativePath", "Public/YPPlayerState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_GameScore;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CharacterLevel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPPlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AYPPlayerState_Statics::NewProp_GameScore = { "GameScore", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPPlayerState, GameScore), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameScore_MetaData), NewProp_GameScore_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AYPPlayerState_Statics::NewProp_CharacterLevel = { "CharacterLevel", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPPlayerState, CharacterLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterLevel_MetaData), NewProp_CharacterLevel_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYPPlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPPlayerState_Statics::NewProp_GameScore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPPlayerState_Statics::NewProp_CharacterLevel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPPlayerState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AYPPlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPPlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AYPPlayerState_Statics::ClassParams = {
	&AYPPlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AYPPlayerState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AYPPlayerState_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYPPlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_AYPPlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AYPPlayerState()
{
	if (!Z_Registration_Info_UClass_AYPPlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYPPlayerState.OuterSingleton, Z_Construct_UClass_AYPPlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AYPPlayerState.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<AYPPlayerState>()
{
	return AYPPlayerState::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AYPPlayerState);
AYPPlayerState::~AYPPlayerState() {}
// End Class AYPPlayerState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPPlayerState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPPlayerState, AYPPlayerState::StaticClass, TEXT("AYPPlayerState"), &Z_Registration_Info_UClass_AYPPlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPPlayerState), 2957343648U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPPlayerState_h_2214761631(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPPlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPPlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
