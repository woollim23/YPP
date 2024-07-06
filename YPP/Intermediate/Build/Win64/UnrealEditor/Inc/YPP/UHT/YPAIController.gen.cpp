// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/YPAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPAIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPAIController();
YPP_API UClass* Z_Construct_UClass_AYPAIController_NoRegister();
// End Cross Module References

// Begin Class AYPAIController
void AYPAIController::StaticRegisterNativesAYPAIController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYPAIController);
UClass* Z_Construct_UClass_AYPAIController_NoRegister()
{
	return AYPAIController::StaticClass();
}
struct Z_Construct_UClass_AYPAIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "YPAIController.h" },
		{ "ModuleRelativePath", "YPAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BTAsset_MetaData[] = {
		{ "ModuleRelativePath", "YPAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BBAsset_MetaData[] = {
		{ "ModuleRelativePath", "YPAIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BTAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BBAsset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYPAIController_Statics::NewProp_BTAsset = { "BTAsset", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPAIController, BTAsset), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BTAsset_MetaData), NewProp_BTAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYPAIController_Statics::NewProp_BBAsset = { "BBAsset", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPAIController, BBAsset), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BBAsset_MetaData), NewProp_BBAsset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYPAIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPAIController_Statics::NewProp_BTAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPAIController_Statics::NewProp_BBAsset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPAIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AYPAIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPAIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AYPAIController_Statics::ClassParams = {
	&AYPAIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AYPAIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AYPAIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYPAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AYPAIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AYPAIController()
{
	if (!Z_Registration_Info_UClass_AYPAIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYPAIController.OuterSingleton, Z_Construct_UClass_AYPAIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AYPAIController.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<AYPAIController>()
{
	return AYPAIController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AYPAIController);
AYPAIController::~AYPAIController() {}
// End Class AYPAIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPAIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPAIController, AYPAIController::StaticClass, TEXT("AYPAIController"), &Z_Registration_Info_UClass_AYPAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPAIController), 260569696U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPAIController_h_1691730319(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPAIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
