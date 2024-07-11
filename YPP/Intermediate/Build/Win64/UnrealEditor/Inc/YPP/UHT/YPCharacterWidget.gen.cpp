// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPCharacterWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPCharacterWidget() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UYPCharacterWidget();
YPP_API UClass* Z_Construct_UClass_UYPCharacterWidget_NoRegister();
// End Cross Module References

// Begin Class UYPCharacterWidget
void UYPCharacterWidget::StaticRegisterNativesUYPCharacterWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPCharacterWidget);
UClass* Z_Construct_UClass_UYPCharacterWidget_NoRegister()
{
	return UYPCharacterWidget::StaticClass();
}
struct Z_Construct_UClass_UYPCharacterWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YPCharacterWidget.h" },
		{ "ModuleRelativePath", "Public/YPCharacterWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HPProgressBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPCharacterWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HPProgressBar;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPCharacterWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPCharacterWidget_Statics::NewProp_HPProgressBar = { "HPProgressBar", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterWidget, HPProgressBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HPProgressBar_MetaData), NewProp_HPProgressBar_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYPCharacterWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterWidget_Statics::NewProp_HPProgressBar,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UYPCharacterWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPCharacterWidget_Statics::ClassParams = {
	&UYPCharacterWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UYPCharacterWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPCharacterWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPCharacterWidget()
{
	if (!Z_Registration_Info_UClass_UYPCharacterWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPCharacterWidget.OuterSingleton, Z_Construct_UClass_UYPCharacterWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPCharacterWidget.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UYPCharacterWidget>()
{
	return UYPCharacterWidget::StaticClass();
}
UYPCharacterWidget::UYPCharacterWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPCharacterWidget);
UYPCharacterWidget::~UYPCharacterWidget() {}
// End Class UYPCharacterWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPCharacterWidget, UYPCharacterWidget::StaticClass, TEXT("UYPCharacterWidget"), &Z_Registration_Info_UClass_UYPCharacterWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPCharacterWidget), 2056493544U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterWidget_h_3510134137(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
