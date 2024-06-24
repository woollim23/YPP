// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/YPGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPGameMode();
YPP_API UClass* Z_Construct_UClass_AYPGameMode_NoRegister();
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
		{ "ModuleRelativePath", "YPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPGameMode, AYPGameMode::StaticClass, TEXT("AYPGameMode"), &Z_Registration_Info_UClass_AYPGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPGameMode), 4230727013U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPGameMode_h_3315807733(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
