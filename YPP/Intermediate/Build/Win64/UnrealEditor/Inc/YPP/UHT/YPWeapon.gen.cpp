// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPWeapon.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPWeapon() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_AYPWeapon();
YPP_API UClass* Z_Construct_UClass_AYPWeapon_NoRegister();
// End Cross Module References

// Begin Class AYPWeapon
void AYPWeapon::StaticRegisterNativesAYPWeapon()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYPWeapon);
UClass* Z_Construct_UClass_AYPWeapon_NoRegister()
{
	return AYPWeapon::StaticClass();
}
struct Z_Construct_UClass_AYPWeapon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "YPWeapon.h" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Weapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[] = {
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackDamageMin_MetaData[] = {
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackDamageMax_MetaData[] = {
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackModifierMin_MetaData[] = {
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackModifierMax_MetaData[] = {
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackDamage_MetaData[] = {
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackModifier_MetaData[] = {
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/YPWeapon.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Weapon;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackDamageMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackDamageMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackModifierMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackModifierMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackModifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYPWeapon>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYPWeapon_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPWeapon, Weapon), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Weapon_MetaData), NewProp_Weapon_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPWeapon, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRange_MetaData), NewProp_AttackRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackDamageMin = { "AttackDamageMin", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPWeapon, AttackDamageMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackDamageMin_MetaData), NewProp_AttackDamageMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackDamageMax = { "AttackDamageMax", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPWeapon, AttackDamageMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackDamageMax_MetaData), NewProp_AttackDamageMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackModifierMin = { "AttackModifierMin", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPWeapon, AttackModifierMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackModifierMin_MetaData), NewProp_AttackModifierMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackModifierMax = { "AttackModifierMax", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPWeapon, AttackModifierMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackModifierMax_MetaData), NewProp_AttackModifierMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackDamage = { "AttackDamage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPWeapon, AttackDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackDamage_MetaData), NewProp_AttackDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackModifier = { "AttackModifier", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYPWeapon, AttackModifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackModifier_MetaData), NewProp_AttackModifier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYPWeapon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPWeapon_Statics::NewProp_Weapon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackDamageMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackDamageMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackModifierMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackModifierMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYPWeapon_Statics::NewProp_AttackModifier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPWeapon_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AYPWeapon_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYPWeapon_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AYPWeapon_Statics::ClassParams = {
	&AYPWeapon::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AYPWeapon_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AYPWeapon_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYPWeapon_Statics::Class_MetaDataParams), Z_Construct_UClass_AYPWeapon_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AYPWeapon()
{
	if (!Z_Registration_Info_UClass_AYPWeapon.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYPWeapon.OuterSingleton, Z_Construct_UClass_AYPWeapon_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AYPWeapon.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<AYPWeapon>()
{
	return AYPWeapon::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AYPWeapon);
AYPWeapon::~AYPWeapon() {}
// End Class AYPWeapon

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPWeapon_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYPWeapon, AYPWeapon::StaticClass, TEXT("AYPWeapon"), &Z_Registration_Info_UClass_AYPWeapon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYPWeapon), 4125772945U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPWeapon_h_4127195451(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPWeapon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPWeapon_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
