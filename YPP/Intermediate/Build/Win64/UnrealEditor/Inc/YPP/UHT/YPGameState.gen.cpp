// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPGameState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPGameState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPGameState();
YPP_API UClass* Z_Construct_UClass_AYPGameState_NoRegister();
// End Cross Module References

// Begin Class AYPGameState
void AYPGameState::StaticRegisterNativesAYPGameState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYPGameState);
UClass* Z_Construct_UClass_AYPGameState_NoRegister()
{
	return AYPGameState::StaticClass();
}
struct Z_Construct_UClass_AYPGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "YPGameState.h" },
		{ "ModuleRelativePath", "Public/YPGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalGameScore_MetaData[] = {
		{ "ModuleRelativePath", "Public/YPGameState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalGameScore;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPGameState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AYPGameState_Statics::NewProp_TotalGameScore = { "TotalGameScore", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPGameState, TotalGameScore), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalGameScore_MetaData), NewProp_TotalGameScore_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYPGameState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPGameState_Statics::NewProp_TotalGameScore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPGameState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AYPGameState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameStateBase,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPGameState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AYPGameState_Statics::ClassParams = {
	&AYPGameState::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AYPGameState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AYPGameState_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYPGameState_Statics::Class_MetaDataParams), Z_Construct_UClass_AYPGameState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AYPGameState()
{
	if (!Z_Registration_Info_UClass_AYPGameState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYPGameState.OuterSingleton, Z_Construct_UClass_AYPGameState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AYPGameState.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<AYPGameState>()
{
	return AYPGameState::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AYPGameState);
AYPGameState::~AYPGameState() {}
// End Class AYPGameState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPGameState, AYPGameState::StaticClass, TEXT("AYPGameState"), &Z_Registration_Info_UClass_AYPGameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPGameState), 1711069475U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameState_h_3882099504(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
