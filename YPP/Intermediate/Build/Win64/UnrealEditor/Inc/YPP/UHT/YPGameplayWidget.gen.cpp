// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPGameplayWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPGameplayWidget() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UYPGameplayWidget();
YPP_API UClass* Z_Construct_UClass_UYPGameplayWidget_NoRegister();
// End Cross Module References

// Begin Class UYPGameplayWidget Function OnResumeClicked
struct Z_Construct_UFunction_UYPGameplayWidget_OnResumeClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YPGameplayWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYPGameplayWidget_OnResumeClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYPGameplayWidget, nullptr, "OnResumeClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYPGameplayWidget_OnResumeClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYPGameplayWidget_OnResumeClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UYPGameplayWidget_OnResumeClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYPGameplayWidget_OnResumeClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UYPGameplayWidget::execOnResumeClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnResumeClicked();
	P_NATIVE_END;
}
// End Class UYPGameplayWidget Function OnResumeClicked

// Begin Class UYPGameplayWidget Function OnRetryGameClicked
struct Z_Construct_UFunction_UYPGameplayWidget_OnRetryGameClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YPGameplayWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYPGameplayWidget_OnRetryGameClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYPGameplayWidget, nullptr, "OnRetryGameClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYPGameplayWidget_OnRetryGameClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYPGameplayWidget_OnRetryGameClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UYPGameplayWidget_OnRetryGameClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYPGameplayWidget_OnRetryGameClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UYPGameplayWidget::execOnRetryGameClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRetryGameClicked();
	P_NATIVE_END;
}
// End Class UYPGameplayWidget Function OnRetryGameClicked

// Begin Class UYPGameplayWidget Function OnReturnToTitleClicked
struct Z_Construct_UFunction_UYPGameplayWidget_OnReturnToTitleClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YPGameplayWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYPGameplayWidget_OnReturnToTitleClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYPGameplayWidget, nullptr, "OnReturnToTitleClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYPGameplayWidget_OnReturnToTitleClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYPGameplayWidget_OnReturnToTitleClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UYPGameplayWidget_OnReturnToTitleClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYPGameplayWidget_OnReturnToTitleClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UYPGameplayWidget::execOnReturnToTitleClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnReturnToTitleClicked();
	P_NATIVE_END;
}
// End Class UYPGameplayWidget Function OnReturnToTitleClicked

// Begin Class UYPGameplayWidget
void UYPGameplayWidget::StaticRegisterNativesUYPGameplayWidget()
{
	UClass* Class = UYPGameplayWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnResumeClicked", &UYPGameplayWidget::execOnResumeClicked },
		{ "OnRetryGameClicked", &UYPGameplayWidget::execOnRetryGameClicked },
		{ "OnReturnToTitleClicked", &UYPGameplayWidget::execOnReturnToTitleClicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPGameplayWidget);
UClass* Z_Construct_UClass_UYPGameplayWidget_NoRegister()
{
	return UYPGameplayWidget::StaticClass();
}
struct Z_Construct_UClass_UYPGameplayWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YPGameplayWidget.h" },
		{ "ModuleRelativePath", "Public/YPGameplayWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResumeButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPGameplayWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnToTitleButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPGameplayWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RetryGameButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPGameplayWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ResumeButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnToTitleButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RetryGameButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UYPGameplayWidget_OnResumeClicked, "OnResumeClicked" }, // 2024013524
		{ &Z_Construct_UFunction_UYPGameplayWidget_OnRetryGameClicked, "OnRetryGameClicked" }, // 3949618288
		{ &Z_Construct_UFunction_UYPGameplayWidget_OnReturnToTitleClicked, "OnReturnToTitleClicked" }, // 3672422083
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPGameplayWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPGameplayWidget_Statics::NewProp_ResumeButton = { "ResumeButton", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPGameplayWidget, ResumeButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResumeButton_MetaData), NewProp_ResumeButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPGameplayWidget_Statics::NewProp_ReturnToTitleButton = { "ReturnToTitleButton", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPGameplayWidget, ReturnToTitleButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnToTitleButton_MetaData), NewProp_ReturnToTitleButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPGameplayWidget_Statics::NewProp_RetryGameButton = { "RetryGameButton", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPGameplayWidget, RetryGameButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RetryGameButton_MetaData), NewProp_RetryGameButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYPGameplayWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPGameplayWidget_Statics::NewProp_ResumeButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPGameplayWidget_Statics::NewProp_ReturnToTitleButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPGameplayWidget_Statics::NewProp_RetryGameButton,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameplayWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UYPGameplayWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameplayWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPGameplayWidget_Statics::ClassParams = {
	&UYPGameplayWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UYPGameplayWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameplayWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameplayWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPGameplayWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPGameplayWidget()
{
	if (!Z_Registration_Info_UClass_UYPGameplayWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPGameplayWidget.OuterSingleton, Z_Construct_UClass_UYPGameplayWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPGameplayWidget.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UYPGameplayWidget>()
{
	return UYPGameplayWidget::StaticClass();
}
UYPGameplayWidget::UYPGameplayWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPGameplayWidget);
UYPGameplayWidget::~UYPGameplayWidget() {}
// End Class UYPGameplayWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPGameplayWidget, UYPGameplayWidget::StaticClass, TEXT("UYPGameplayWidget"), &Z_Registration_Info_UClass_UYPGameplayWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPGameplayWidget), 944566060U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_4037324133(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameplayWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
