// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/BTTask_FindPatrolPos.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_FindPatrolPos() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UBTTask_FindPatrolPos();
YPP_API UClass* Z_Construct_UClass_UBTTask_FindPatrolPos_NoRegister();
// End Cross Module References

// Begin Class UBTTask_FindPatrolPos
void UBTTask_FindPatrolPos::StaticRegisterNativesUBTTask_FindPatrolPos()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTTask_FindPatrolPos);
UClass* Z_Construct_UClass_UBTTask_FindPatrolPos_NoRegister()
{
	return UBTTask_FindPatrolPos::StaticClass();
}
struct Z_Construct_UClass_UBTTask_FindPatrolPos_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTTask_FindPatrolPos.h" },
		{ "ModuleRelativePath", "BTTask_FindPatrolPos.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_FindPatrolPos>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTTask_FindPatrolPos_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_FindPatrolPos_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_FindPatrolPos_Statics::ClassParams = {
	&UBTTask_FindPatrolPos::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_FindPatrolPos_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_FindPatrolPos_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTTask_FindPatrolPos()
{
	if (!Z_Registration_Info_UClass_UBTTask_FindPatrolPos.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_FindPatrolPos.OuterSingleton, Z_Construct_UClass_UBTTask_FindPatrolPos_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTTask_FindPatrolPos.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UBTTask_FindPatrolPos>()
{
	return UBTTask_FindPatrolPos::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_FindPatrolPos);
UBTTask_FindPatrolPos::~UBTTask_FindPatrolPos() {}
// End Class UBTTask_FindPatrolPos

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTTask_FindPatrolPos_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_FindPatrolPos, UBTTask_FindPatrolPos::StaticClass, TEXT("UBTTask_FindPatrolPos"), &Z_Registration_Info_UClass_UBTTask_FindPatrolPos, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_FindPatrolPos), 3258127652U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTTask_FindPatrolPos_h_1455279200(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTTask_FindPatrolPos_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTTask_FindPatrolPos_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
