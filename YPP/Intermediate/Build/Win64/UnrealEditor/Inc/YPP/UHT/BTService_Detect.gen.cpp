// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/BTService_Detect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_Detect() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTService();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UBTService_Detect();
YPP_API UClass* Z_Construct_UClass_UBTService_Detect_NoRegister();
// End Cross Module References

// Begin Class UBTService_Detect
void UBTService_Detect::StaticRegisterNativesUBTService_Detect()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_Detect);
UClass* Z_Construct_UClass_UBTService_Detect_NoRegister()
{
	return UBTService_Detect::StaticClass();
}
struct Z_Construct_UClass_UBTService_Detect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTService_Detect.h" },
		{ "ModuleRelativePath", "BTService_Detect.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_Detect>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTService_Detect_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTService,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_Detect_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_Detect_Statics::ClassParams = {
	&UBTService_Detect::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_Detect_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_Detect_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTService_Detect()
{
	if (!Z_Registration_Info_UClass_UBTService_Detect.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_Detect.OuterSingleton, Z_Construct_UClass_UBTService_Detect_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTService_Detect.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UBTService_Detect>()
{
	return UBTService_Detect::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_Detect);
UBTService_Detect::~UBTService_Detect() {}
// End Class UBTService_Detect

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTService_Detect_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_Detect, UBTService_Detect::StaticClass, TEXT("UBTService_Detect"), &Z_Registration_Info_UClass_UBTService_Detect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_Detect), 2269297323U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTService_Detect_h_3547257941(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTService_Detect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_BTService_Detect_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
