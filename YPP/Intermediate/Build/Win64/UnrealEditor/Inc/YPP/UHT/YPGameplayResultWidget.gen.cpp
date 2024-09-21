// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPGameplayResultWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPGameplayResultWidget() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UYPGameplayResultWidget();
YPP_API UClass* Z_Construct_UClass_UYPGameplayResultWidget_NoRegister();
YPP_API UClass* Z_Construct_UClass_UYPGameplayWidget();
// End Cross Module References

// Begin Class UYPGameplayResultWidget
void UYPGameplayResultWidget::StaticRegisterNativesUYPGameplayResultWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPGameplayResultWidget);
UClass* Z_Construct_UClass_UYPGameplayResultWidget_NoRegister()
{
	return UYPGameplayResultWidget::StaticClass();
}
struct Z_Construct_UClass_UYPGameplayResultWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YPGameplayResultWidget.h" },
		{ "ModuleRelativePath", "Public/YPGameplayResultWidget.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPGameplayResultWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UYPGameplayResultWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UYPGameplayWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameplayResultWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPGameplayResultWidget_Statics::ClassParams = {
	&UYPGameplayResultWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameplayResultWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPGameplayResultWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPGameplayResultWidget()
{
	if (!Z_Registration_Info_UClass_UYPGameplayResultWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPGameplayResultWidget.OuterSingleton, Z_Construct_UClass_UYPGameplayResultWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPGameplayResultWidget.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UYPGameplayResultWidget>()
{
	return UYPGameplayResultWidget::StaticClass();
}
UYPGameplayResultWidget::UYPGameplayResultWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPGameplayResultWidget);
UYPGameplayResultWidget::~UYPGameplayResultWidget() {}
// End Class UYPGameplayResultWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayResultWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPGameplayResultWidget, UYPGameplayResultWidget::StaticClass, TEXT("UYPGameplayResultWidget"), &Z_Registration_Info_UClass_UYPGameplayResultWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPGameplayResultWidget), 3018560126U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayResultWidget_h_2867159920(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayResultWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayResultWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
