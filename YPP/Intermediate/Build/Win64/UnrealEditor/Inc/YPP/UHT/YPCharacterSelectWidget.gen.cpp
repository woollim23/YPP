// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPCharacterSelectWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPCharacterSelectWidget() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UYPCharacterSelectWidget();
YPP_API UClass* Z_Construct_UClass_UYPCharacterSelectWidget_NoRegister();
// End Cross Module References

// Begin Class UYPCharacterSelectWidget Function NextCharacter
struct Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics
{
	struct YPCharacterSelectWidget_eventNextCharacter_Parms
	{
		bool bForward;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CPP_Default_bForward", "true" },
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bForward_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForward;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::NewProp_bForward_SetBit(void* Obj)
{
	((YPCharacterSelectWidget_eventNextCharacter_Parms*)Obj)->bForward = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::NewProp_bForward = { "bForward", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(YPCharacterSelectWidget_eventNextCharacter_Parms), &Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::NewProp_bForward_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::NewProp_bForward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYPCharacterSelectWidget, nullptr, "NextCharacter", nullptr, nullptr, Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::YPCharacterSelectWidget_eventNextCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::YPCharacterSelectWidget_eventNextCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UYPCharacterSelectWidget::execNextCharacter)
{
	P_GET_UBOOL(Z_Param_bForward);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->NextCharacter(Z_Param_bForward);
	P_NATIVE_END;
}
// End Class UYPCharacterSelectWidget Function NextCharacter

// Begin Class UYPCharacterSelectWidget Function OnConfirmClicked
struct Z_Construct_UFunction_UYPCharacterSelectWidget_OnConfirmClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYPCharacterSelectWidget_OnConfirmClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYPCharacterSelectWidget, nullptr, "OnConfirmClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYPCharacterSelectWidget_OnConfirmClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYPCharacterSelectWidget_OnConfirmClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UYPCharacterSelectWidget_OnConfirmClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYPCharacterSelectWidget_OnConfirmClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UYPCharacterSelectWidget::execOnConfirmClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnConfirmClicked();
	P_NATIVE_END;
}
// End Class UYPCharacterSelectWidget Function OnConfirmClicked

// Begin Class UYPCharacterSelectWidget Function OnNextClicked
struct Z_Construct_UFunction_UYPCharacterSelectWidget_OnNextClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYPCharacterSelectWidget_OnNextClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYPCharacterSelectWidget, nullptr, "OnNextClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYPCharacterSelectWidget_OnNextClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYPCharacterSelectWidget_OnNextClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UYPCharacterSelectWidget_OnNextClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYPCharacterSelectWidget_OnNextClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UYPCharacterSelectWidget::execOnNextClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnNextClicked();
	P_NATIVE_END;
}
// End Class UYPCharacterSelectWidget Function OnNextClicked

// Begin Class UYPCharacterSelectWidget Function OnPrevClicked
struct Z_Construct_UFunction_UYPCharacterSelectWidget_OnPrevClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYPCharacterSelectWidget_OnPrevClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYPCharacterSelectWidget, nullptr, "OnPrevClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYPCharacterSelectWidget_OnPrevClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYPCharacterSelectWidget_OnPrevClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UYPCharacterSelectWidget_OnPrevClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYPCharacterSelectWidget_OnPrevClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UYPCharacterSelectWidget::execOnPrevClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPrevClicked();
	P_NATIVE_END;
}
// End Class UYPCharacterSelectWidget Function OnPrevClicked

// Begin Class UYPCharacterSelectWidget
void UYPCharacterSelectWidget::StaticRegisterNativesUYPCharacterSelectWidget()
{
	UClass* Class = UYPCharacterSelectWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "NextCharacter", &UYPCharacterSelectWidget::execNextCharacter },
		{ "OnConfirmClicked", &UYPCharacterSelectWidget::execOnConfirmClicked },
		{ "OnNextClicked", &UYPCharacterSelectWidget::execOnNextClicked },
		{ "OnPrevClicked", &UYPCharacterSelectWidget::execOnPrevClicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPCharacterSelectWidget);
UClass* Z_Construct_UClass_UYPCharacterSelectWidget_NoRegister()
{
	return UYPCharacterSelectWidget::StaticClass();
}
struct Z_Construct_UClass_UYPCharacterSelectWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YPCharacterSelectWidget.h" },
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentIndex_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxIndex_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrevButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfirmButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PrevButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NextButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TextBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ConfirmButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UYPCharacterSelectWidget_NextCharacter, "NextCharacter" }, // 1625991670
		{ &Z_Construct_UFunction_UYPCharacterSelectWidget_OnConfirmClicked, "OnConfirmClicked" }, // 1720190471
		{ &Z_Construct_UFunction_UYPCharacterSelectWidget_OnNextClicked, "OnNextClicked" }, // 1856274521
		{ &Z_Construct_UFunction_UYPCharacterSelectWidget_OnPrevClicked, "OnPrevClicked" }, // 3339054066
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPCharacterSelectWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_CurrentIndex = { "CurrentIndex", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterSelectWidget, CurrentIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentIndex_MetaData), NewProp_CurrentIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_MaxIndex = { "MaxIndex", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterSelectWidget, MaxIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxIndex_MetaData), NewProp_MaxIndex_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_PrevButton = { "PrevButton", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterSelectWidget, PrevButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrevButton_MetaData), NewProp_PrevButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_NextButton = { "NextButton", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterSelectWidget, NextButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextButton_MetaData), NewProp_NextButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_TextBox = { "TextBox", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterSelectWidget, TextBox), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextBox_MetaData), NewProp_TextBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_ConfirmButton = { "ConfirmButton", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterSelectWidget, ConfirmButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfirmButton_MetaData), NewProp_ConfirmButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYPCharacterSelectWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_CurrentIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_MaxIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_PrevButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_NextButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_TextBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterSelectWidget_Statics::NewProp_ConfirmButton,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterSelectWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UYPCharacterSelectWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterSelectWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPCharacterSelectWidget_Statics::ClassParams = {
	&UYPCharacterSelectWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UYPCharacterSelectWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterSelectWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterSelectWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPCharacterSelectWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPCharacterSelectWidget()
{
	if (!Z_Registration_Info_UClass_UYPCharacterSelectWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPCharacterSelectWidget.OuterSingleton, Z_Construct_UClass_UYPCharacterSelectWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPCharacterSelectWidget.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UYPCharacterSelectWidget>()
{
	return UYPCharacterSelectWidget::StaticClass();
}
UYPCharacterSelectWidget::UYPCharacterSelectWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPCharacterSelectWidget);
UYPCharacterSelectWidget::~UYPCharacterSelectWidget() {}
// End Class UYPCharacterSelectWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPCharacterSelectWidget, UYPCharacterSelectWidget::StaticClass, TEXT("UYPCharacterSelectWidget"), &Z_Registration_Info_UClass_UYPCharacterSelectWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPCharacterSelectWidget), 3216742686U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_2370335320(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPCharacterSelectWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
