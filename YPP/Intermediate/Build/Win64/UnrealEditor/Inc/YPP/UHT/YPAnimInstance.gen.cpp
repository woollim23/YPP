// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/YPAnimInstance.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPAnimInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UYPAnimInstance();
YPP_API UClass* Z_Construct_UClass_UYPAnimInstance_NoRegister();
// End Cross Module References

// Begin Class UYPAnimInstance
void UYPAnimInstance::StaticRegisterNativesUYPAnimInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPAnimInstance);
UClass* Z_Construct_UClass_UYPAnimInstance_NoRegister()
{
	return UYPAnimInstance::StaticClass();
}
struct Z_Construct_UClass_UYPAnimInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "YPAnimInstance.h" },
		{ "ModuleRelativePath", "YPAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPawnSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Pawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "YPAnimInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsInAir_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Pawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xdf\xbf\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "YPAnimInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xdf\xbf\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentPawnSpeed;
	static void NewProp_IsInAir_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsInAir;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPAnimInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYPAnimInstance_Statics::NewProp_CurrentPawnSpeed = { "CurrentPawnSpeed", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPAnimInstance, CurrentPawnSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPawnSpeed_MetaData), NewProp_CurrentPawnSpeed_MetaData) };
void Z_Construct_UClass_UYPAnimInstance_Statics::NewProp_IsInAir_SetBit(void* Obj)
{
	((UYPAnimInstance*)Obj)->IsInAir = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYPAnimInstance_Statics::NewProp_IsInAir = { "IsInAir", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYPAnimInstance), &Z_Construct_UClass_UYPAnimInstance_Statics::NewProp_IsInAir_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsInAir_MetaData), NewProp_IsInAir_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYPAnimInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPAnimInstance_Statics::NewProp_CurrentPawnSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPAnimInstance_Statics::NewProp_IsInAir,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPAnimInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UYPAnimInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPAnimInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPAnimInstance_Statics::ClassParams = {
	&UYPAnimInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UYPAnimInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UYPAnimInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPAnimInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPAnimInstance()
{
	if (!Z_Registration_Info_UClass_UYPAnimInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPAnimInstance.OuterSingleton, Z_Construct_UClass_UYPAnimInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPAnimInstance.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UYPAnimInstance>()
{
	return UYPAnimInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPAnimInstance);
UYPAnimInstance::~UYPAnimInstance() {}
// End Class UYPAnimInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPAnimInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPAnimInstance, UYPAnimInstance::StaticClass, TEXT("UYPAnimInstance"), &Z_Registration_Info_UClass_UYPAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPAnimInstance), 2371992827U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPAnimInstance_h_2245206671(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Yelim_Documents_GitHub_YPP_YPP_Source_YPP_YPAnimInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
