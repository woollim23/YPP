// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/YPPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPPlayerController();
YPP_API UClass* Z_Construct_UClass_AYPPlayerController_NoRegister();
// End Cross Module References

// Begin Class AYPPlayerController
void AYPPlayerController::StaticRegisterNativesAYPPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYPPlayerController);
UClass* Z_Construct_UClass_AYPPlayerController_NoRegister()
{
	return AYPPlayerController::StaticClass();
}
struct Z_Construct_UClass_AYPPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "YPPlayerController.h" },
		{ "ModuleRelativePath", "YPPlayerController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AYPPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AYPPlayerController_Statics::ClassParams = {
	&AYPPlayerController::StaticClass,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYPPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AYPPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AYPPlayerController()
{
	if (!Z_Registration_Info_UClass_AYPPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYPPlayerController.OuterSingleton, Z_Construct_UClass_AYPPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AYPPlayerController.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<AYPPlayerController>()
{
	return AYPPlayerController::StaticClass();
}
AYPPlayerController::AYPPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AYPPlayerController);
AYPPlayerController::~AYPPlayerController() {}
// End Class AYPPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPPlayerController, AYPPlayerController::StaticClass, TEXT("AYPPlayerController"), &Z_Registration_Info_UClass_AYPPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPPlayerController), 2676018449U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPPlayerController_h_239226057(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
