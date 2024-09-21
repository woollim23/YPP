// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPGameMode();
YPP_API UClass* Z_Construct_UClass_AYPGameMode_NoRegister();
YPP_API UClass* Z_Construct_UClass_AYPGameState_NoRegister();
// End Cross Module References

// Begin Class AYPGameMode
void AYPGameMode::StaticRegisterNativesAYPGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYPGameMode);
UClass* Z_Construct_UClass_AYPGameMode_NoRegister()
{
	return AYPGameMode::StaticClass();
}
struct Z_Construct_UClass_AYPGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "YPGameMode.h" },
		{ "ModuleRelativePath", "Public/YPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YPGameState_MetaData[] = {
		{ "ModuleRelativePath", "Public/YPGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScoreToClear_MetaData[] = {
		{ "ModuleRelativePath", "Public/YPGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_YPGameState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ScoreToClear;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYPGameMode_Statics::NewProp_YPGameState = { "YPGameState", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPGameMode, YPGameState), Z_Construct_UClass_AYPGameState_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YPGameState_MetaData), NewProp_YPGameState_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AYPGameMode_Statics::NewProp_ScoreToClear = { "ScoreToClear", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPGameMode, ScoreToClear), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScoreToClear_MetaData), NewProp_ScoreToClear_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYPGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPGameMode_Statics::NewProp_YPGameState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPGameMode_Statics::NewProp_ScoreToClear,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPGameMode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AYPGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AYPGameMode_Statics::ClassParams = {
	&AYPGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AYPGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AYPGameMode_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYPGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AYPGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AYPGameMode()
{
	if (!Z_Registration_Info_UClass_AYPGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYPGameMode.OuterSingleton, Z_Construct_UClass_AYPGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AYPGameMode.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<AYPGameMode>()
{
	return AYPGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AYPGameMode);
AYPGameMode::~AYPGameMode() {}
// End Class AYPGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPGameMode, AYPGameMode::StaticClass, TEXT("AYPGameMode"), &Z_Registration_Info_UClass_AYPGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPGameMode), 1274773192U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameMode_h_1925234751(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
