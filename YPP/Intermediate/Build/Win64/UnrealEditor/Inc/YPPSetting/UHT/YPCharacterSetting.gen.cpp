// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPPSetting/Public/YPCharacterSetting.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPCharacterSetting() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
UPackage* Z_Construct_UPackage__Script_YPPSetting();
YPPSETTING_API UClass* Z_Construct_UClass_UYPCharacterSetting();
YPPSETTING_API UClass* Z_Construct_UClass_UYPCharacterSetting_NoRegister();
// End Cross Module References

// Begin Class UYPCharacterSetting
void UYPCharacterSetting::StaticRegisterNativesUYPCharacterSetting()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPCharacterSetting);
UClass* Z_Construct_UClass_UYPCharacterSetting_NoRegister()
{
	return UYPCharacterSetting::StaticClass();
}
struct Z_Construct_UClass_UYPCharacterSetting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YPCharacterSetting.h" },
		{ "ModuleRelativePath", "Public/YPCharacterSetting.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterAssets_MetaData[] = {
		{ "ModuleRelativePath", "Public/YPCharacterSetting.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterAssets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CharacterAssets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPCharacterSetting>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UYPCharacterSetting_Statics::NewProp_CharacterAssets_Inner = { "CharacterAssets", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UYPCharacterSetting_Statics::NewProp_CharacterAssets = { "CharacterAssets", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterSetting, CharacterAssets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterAssets_MetaData), NewProp_CharacterAssets_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYPCharacterSetting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterSetting_Statics::NewProp_CharacterAssets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterSetting_Statics::NewProp_CharacterAssets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterSetting_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UYPCharacterSetting_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_YPPSetting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterSetting_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPCharacterSetting_Statics::ClassParams = {
	&UYPCharacterSetting::StaticClass,
	"YPP",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UYPCharacterSetting_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterSetting_Statics::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterSetting_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPCharacterSetting_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPCharacterSetting()
{
	if (!Z_Registration_Info_UClass_UYPCharacterSetting.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPCharacterSetting.OuterSingleton, Z_Construct_UClass_UYPCharacterSetting_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPCharacterSetting.OuterSingleton;
}
template<> YPPSETTING_API UClass* StaticClass<UYPCharacterSetting>()
{
	return UYPCharacterSetting::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPCharacterSetting);
UYPCharacterSetting::~UYPCharacterSetting() {}
// End Class UYPCharacterSetting

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPPSetting_Public_YPCharacterSetting_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPCharacterSetting, UYPCharacterSetting::StaticClass, TEXT("UYPCharacterSetting"), &Z_Registration_Info_UClass_UYPCharacterSetting, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPCharacterSetting), 569123040U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPPSetting_Public_YPCharacterSetting_h_2519460322(TEXT("/Script/YPPSetting"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPPSetting_Public_YPCharacterSetting_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPPSetting_Public_YPCharacterSetting_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
