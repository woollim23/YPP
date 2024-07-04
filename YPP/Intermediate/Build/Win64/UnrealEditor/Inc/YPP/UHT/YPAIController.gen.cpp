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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
		{ Z_Construct_UClass_AYPAIController, AYPAIController::StaticClass, TEXT("AYPAIController"), &Z_Registration_Info_UClass_AYPAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPAIController), 121839586U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPAIController_h_2269145264(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPAIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
