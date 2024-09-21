// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPHUDWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPHUDWidget() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UYPHUDWidget();
YPP_API UClass* Z_Construct_UClass_UYPHUDWidget_NoRegister();
// End Cross Module References

// Begin Class UYPHUDWidget
void UYPHUDWidget::StaticRegisterNativesUYPHUDWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPHUDWidget);
UClass* Z_Construct_UClass_UYPHUDWidget_NoRegister()
{
	return UYPHUDWidget::StaticClass();
}
struct Z_Construct_UClass_UYPHUDWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YPHUDWidget.h" },
		{ "ModuleRelativePath", "Public/YPHUDWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HPBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPHUDWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExpBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPHUDWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPHUDWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerLevel_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPHUDWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentScore_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPHUDWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighScore_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPHUDWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HPBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExpBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerLevel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentScore;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HighScore;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPHUDWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_HPBar = { "HPBar", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPHUDWidget, HPBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HPBar_MetaData), NewProp_HPBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_ExpBar = { "ExpBar", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPHUDWidget, ExpBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExpBar_MetaData), NewProp_ExpBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_PlayerName = { "PlayerName", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPHUDWidget, PlayerName), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerName_MetaData), NewProp_PlayerName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_PlayerLevel = { "PlayerLevel", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPHUDWidget, PlayerLevel), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerLevel_MetaData), NewProp_PlayerLevel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_CurrentScore = { "CurrentScore", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPHUDWidget, CurrentScore), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentScore_MetaData), NewProp_CurrentScore_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_HighScore = { "HighScore", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPHUDWidget, HighScore), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighScore_MetaData), NewProp_HighScore_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYPHUDWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_HPBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_ExpBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_PlayerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_PlayerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_CurrentScore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPHUDWidget_Statics::NewProp_HighScore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPHUDWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UYPHUDWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPHUDWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPHUDWidget_Statics::ClassParams = {
	&UYPHUDWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UYPHUDWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UYPHUDWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPHUDWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPHUDWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPHUDWidget()
{
	if (!Z_Registration_Info_UClass_UYPHUDWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPHUDWidget.OuterSingleton, Z_Construct_UClass_UYPHUDWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPHUDWidget.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UYPHUDWidget>()
{
	return UYPHUDWidget::StaticClass();
}
UYPHUDWidget::UYPHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPHUDWidget);
UYPHUDWidget::~UYPHUDWidget() {}
// End Class UYPHUDWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPHUDWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPHUDWidget, UYPHUDWidget::StaticClass, TEXT("UYPHUDWidget"), &Z_Registration_Info_UClass_UYPHUDWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPHUDWidget), 708185392U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPHUDWidget_h_2389678479(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPHUDWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPHUDWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
