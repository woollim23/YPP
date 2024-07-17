// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPPlayerController() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPPlayerController();
YPP_API UClass* Z_Construct_UClass_AYPPlayerController_NoRegister();
YPP_API UClass* Z_Construct_UClass_AYPPlayerState_NoRegister();
YPP_API UClass* Z_Construct_UClass_UYPHUDWidget_NoRegister();
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
		{ "ModuleRelativePath", "Public/YPPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//virtual void SetupInputComponent() override;\n" },
#endif
		{ "ModuleRelativePath", "Public/YPPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "virtual void SetupInputComponent() override;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YPPlayerState_MetaData[] = {
		{ "ModuleRelativePath", "Public/YPPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_HUDWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HUDWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_YPPlayerState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AYPPlayerController_Statics::NewProp_HUDWidgetClass = { "HUDWidgetClass", nullptr, (EPropertyFlags)0x0024080000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPPlayerController, HUDWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UYPHUDWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetClass_MetaData), NewProp_HUDWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYPPlayerController_Statics::NewProp_HUDWidget = { "HUDWidget", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPPlayerController, HUDWidget), Z_Construct_UClass_UYPHUDWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidget_MetaData), NewProp_HUDWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYPPlayerController_Statics::NewProp_YPPlayerState = { "YPPlayerState", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPPlayerController, YPPlayerState), Z_Construct_UClass_AYPPlayerState_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YPPlayerState_MetaData), NewProp_YPPlayerState_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYPPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPPlayerController_Statics::NewProp_HUDWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPPlayerController_Statics::NewProp_HUDWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPPlayerController_Statics::NewProp_YPPlayerState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPPlayerController_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_AYPPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AYPPlayerController_Statics::PropPointers),
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
DEFINE_VTABLE_PTR_HELPER_CTOR(AYPPlayerController);
AYPPlayerController::~AYPPlayerController() {}
// End Class AYPPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPPlayerController, AYPPlayerController::StaticClass, TEXT("AYPPlayerController"), &Z_Registration_Info_UClass_AYPPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPPlayerController), 2381310744U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPPlayerController_h_470017542(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
