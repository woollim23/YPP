// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/YPPGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPPGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPPGameMode();
YPP_API UClass* Z_Construct_UClass_AYPPGameMode_NoRegister();
// End Cross Module References

// Begin Class AYPPGameMode
void AYPPGameMode::StaticRegisterNativesAYPPGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYPPGameMode);
UClass* Z_Construct_UClass_AYPPGameMode_NoRegister()
{
	return AYPPGameMode::StaticClass();
}
struct Z_Construct_UClass_AYPPGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "YPPGameMode.h" },
		{ "ModuleRelativePath", "YPPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPPGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AYPPGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPPGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AYPPGameMode_Statics::ClassParams = {
	&AYPPGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYPPGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AYPPGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AYPPGameMode()
{
	if (!Z_Registration_Info_UClass_AYPPGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYPPGameMode.OuterSingleton, Z_Construct_UClass_AYPPGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AYPPGameMode.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<AYPPGameMode>()
{
	return AYPPGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AYPPGameMode);
AYPPGameMode::~AYPPGameMode() {}
// End Class AYPPGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPPGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPPGameMode, AYPPGameMode::StaticClass, TEXT("AYPPGameMode"), &Z_Registration_Info_UClass_AYPPGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPPGameMode), 3663618358U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPPGameMode_h_3052961031(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPPGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPPGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
