// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/BTDecorator_IsInAttackRange.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTDecorator_IsInAttackRange() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTDecorator();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UBTDecorator_IsInAttackRange();
YPP_API UClass* Z_Construct_UClass_UBTDecorator_IsInAttackRange_NoRegister();
// End Cross Module References

// Begin Class UBTDecorator_IsInAttackRange
void UBTDecorator_IsInAttackRange::StaticRegisterNativesUBTDecorator_IsInAttackRange()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTDecorator_IsInAttackRange);
UClass* Z_Construct_UClass_UBTDecorator_IsInAttackRange_NoRegister()
{
	return UBTDecorator_IsInAttackRange::StaticClass();
}
struct Z_Construct_UClass_UBTDecorator_IsInAttackRange_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTDecorator_IsInAttackRange.h" },
		{ "ModuleRelativePath", "BTDecorator_IsInAttackRange.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTDecorator_IsInAttackRange>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTDecorator_IsInAttackRange_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTDecorator,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_IsInAttackRange_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTDecorator_IsInAttackRange_Statics::ClassParams = {
	&UBTDecorator_IsInAttackRange::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_IsInAttackRange_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTDecorator_IsInAttackRange_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTDecorator_IsInAttackRange()
{
	if (!Z_Registration_Info_UClass_UBTDecorator_IsInAttackRange.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTDecorator_IsInAttackRange.OuterSingleton, Z_Construct_UClass_UBTDecorator_IsInAttackRange_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTDecorator_IsInAttackRange.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UBTDecorator_IsInAttackRange>()
{
	return UBTDecorator_IsInAttackRange::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTDecorator_IsInAttackRange);
UBTDecorator_IsInAttackRange::~UBTDecorator_IsInAttackRange() {}
// End Class UBTDecorator_IsInAttackRange

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTDecorator_IsInAttackRange_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTDecorator_IsInAttackRange, UBTDecorator_IsInAttackRange::StaticClass, TEXT("UBTDecorator_IsInAttackRange"), &Z_Registration_Info_UClass_UBTDecorator_IsInAttackRange, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTDecorator_IsInAttackRange), 1796894293U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTDecorator_IsInAttackRange_h_2893673795(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTDecorator_IsInAttackRange_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTDecorator_IsInAttackRange_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
