// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/BTTask_Attack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_Attack() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UBTTask_Attack();
YPP_API UClass* Z_Construct_UClass_UBTTask_Attack_NoRegister();
// End Cross Module References

// Begin Class UBTTask_Attack
void UBTTask_Attack::StaticRegisterNativesUBTTask_Attack()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTTask_Attack);
UClass* Z_Construct_UClass_UBTTask_Attack_NoRegister()
{
	return UBTTask_Attack::StaticClass();
}
struct Z_Construct_UClass_UBTTask_Attack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTTask_Attack.h" },
		{ "ModuleRelativePath", "BTTask_Attack.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_Attack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTTask_Attack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_Attack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_Attack_Statics::ClassParams = {
	&UBTTask_Attack::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_Attack_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_Attack_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTTask_Attack()
{
	if (!Z_Registration_Info_UClass_UBTTask_Attack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_Attack.OuterSingleton, Z_Construct_UClass_UBTTask_Attack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTTask_Attack.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UBTTask_Attack>()
{
	return UBTTask_Attack::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_Attack);
UBTTask_Attack::~UBTTask_Attack() {}
// End Class UBTTask_Attack

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTTask_Attack_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_Attack, UBTTask_Attack::StaticClass, TEXT("UBTTask_Attack"), &Z_Registration_Info_UClass_UBTTask_Attack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_Attack), 2521921653U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTTask_Attack_h_4098846769(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTTask_Attack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTTask_Attack_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
