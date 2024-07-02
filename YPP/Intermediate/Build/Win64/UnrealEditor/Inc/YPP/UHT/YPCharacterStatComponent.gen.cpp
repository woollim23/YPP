// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/YPCharacterStatComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPCharacterStatComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UYPCharacterStatComponent();
YPP_API UClass* Z_Construct_UClass_UYPCharacterStatComponent_NoRegister();
// End Cross Module References

// Begin Class UYPCharacterStatComponent
void UYPCharacterStatComponent::StaticRegisterNativesUYPCharacterStatComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPCharacterStatComponent);
UClass* Z_Construct_UClass_UYPCharacterStatComponent_NoRegister()
{
	return UYPCharacterStatComponent::StaticClass();
}
struct Z_Construct_UClass_UYPCharacterStatComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "YPCharacterStatComponent.h" },
		{ "ModuleRelativePath", "YPCharacterStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "YPCharacterStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHP_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Transient : \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xad\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xdc\xbd\xef\xbf\xbd\xc5\xb4\n" },
#endif
		{ "ModuleRelativePath", "YPCharacterStatComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Transient : \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xad\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xdc\xbd\xef\xbf\xbd\xc5\xb4" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHP;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPCharacterStatComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UYPCharacterStatComponent_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0040000000000801, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterStatComponent, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYPCharacterStatComponent_Statics::NewProp_CurrentHP = { "CurrentHP", nullptr, (EPropertyFlags)0x0040000000022801, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPCharacterStatComponent, CurrentHP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHP_MetaData), NewProp_CurrentHP_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYPCharacterStatComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterStatComponent_Statics::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPCharacterStatComponent_Statics::NewProp_CurrentHP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterStatComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UYPCharacterStatComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterStatComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPCharacterStatComponent_Statics::ClassParams = {
	&UYPCharacterStatComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UYPCharacterStatComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterStatComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPCharacterStatComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPCharacterStatComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPCharacterStatComponent()
{
	if (!Z_Registration_Info_UClass_UYPCharacterStatComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPCharacterStatComponent.OuterSingleton, Z_Construct_UClass_UYPCharacterStatComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPCharacterStatComponent.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UYPCharacterStatComponent>()
{
	return UYPCharacterStatComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPCharacterStatComponent);
UYPCharacterStatComponent::~UYPCharacterStatComponent() {}
// End Class UYPCharacterStatComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPCharacterStatComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPCharacterStatComponent, UYPCharacterStatComponent::StaticClass, TEXT("UYPCharacterStatComponent"), &Z_Registration_Info_UClass_UYPCharacterStatComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPCharacterStatComponent), 3257044213U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPCharacterStatComponent_h_3532848142(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPCharacterStatComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_YPCharacterStatComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
