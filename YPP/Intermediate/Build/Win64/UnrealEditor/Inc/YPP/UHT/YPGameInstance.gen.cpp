// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YPP/Public/YPGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYPGameInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
UPackage* Z_Construct_UPackage__Script_YPP();
YPP_API UClass* Z_Construct_UClass_UYPGameInstance();
YPP_API UClass* Z_Construct_UClass_UYPGameInstance_NoRegister();
YPP_API UScriptStruct* Z_Construct_UScriptStruct_FYPCharacterData();
// End Cross Module References

// Begin ScriptStruct FYPCharacterData
static_assert(std::is_polymorphic<FYPCharacterData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FYPCharacterData cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_YPCharacterData;
class UScriptStruct* FYPCharacterData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_YPCharacterData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_YPCharacterData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FYPCharacterData, (UObject*)Z_Construct_UPackage__Script_YPP(), TEXT("YPCharacterData"));
	}
	return Z_Registration_Info_UScriptStruct_YPCharacterData.OuterSingleton;
}
template<> YPP_API UScriptStruct* StaticStruct<FYPCharacterData>()
{
	return FYPCharacterData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FYPCharacterData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/YPGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/YPGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHP_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/YPGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/YPGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DropExp_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/YPGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextExp_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/YPGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHP;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Attack;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DropExp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NextExp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FYPCharacterData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FYPCharacterData, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_MaxHP = { "MaxHP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FYPCharacterData, MaxHP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHP_MetaData), NewProp_MaxHP_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FYPCharacterData, Attack), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack_MetaData), NewProp_Attack_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_DropExp = { "DropExp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FYPCharacterData, DropExp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DropExp_MetaData), NewProp_DropExp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_NextExp = { "NextExp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FYPCharacterData, NextExp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextExp_MetaData), NewProp_NextExp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FYPCharacterData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_MaxHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_DropExp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewProp_NextExp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FYPCharacterData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FYPCharacterData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"YPCharacterData",
	Z_Construct_UScriptStruct_FYPCharacterData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FYPCharacterData_Statics::PropPointers),
	sizeof(FYPCharacterData),
	alignof(FYPCharacterData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FYPCharacterData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FYPCharacterData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FYPCharacterData()
{
	if (!Z_Registration_Info_UScriptStruct_YPCharacterData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_YPCharacterData.InnerSingleton, Z_Construct_UScriptStruct_FYPCharacterData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_YPCharacterData.InnerSingleton;
}
// End ScriptStruct FYPCharacterData

// Begin Class UYPGameInstance
void UYPGameInstance::StaticRegisterNativesUYPGameInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYPGameInstance);
UClass* Z_Construct_UClass_UYPGameInstance_NoRegister()
{
	return UYPGameInstance::StaticClass();
}
struct Z_Construct_UClass_UYPGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YPGameInstance.h" },
		{ "ModuleRelativePath", "Public/YPGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_YPCharacterTable_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xba\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xb8\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb4\xef\xbf\xbd \xef\xbf\xbd\xf0\xb8\xae\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xce\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xdb\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd,\n// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/YPGameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xba\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xb8\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb4\xef\xbf\xbd \xef\xbf\xbd\xf0\xb8\xae\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xce\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xdb\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd,\n\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd2\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_YPCharacterTable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYPGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYPGameInstance_Statics::NewProp_YPCharacterTable = { "YPCharacterTable", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYPGameInstance, YPCharacterTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_YPCharacterTable_MetaData), NewProp_YPCharacterTable_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYPGameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYPGameInstance_Statics::NewProp_YPCharacterTable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UYPGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_YPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UYPGameInstance_Statics::ClassParams = {
	&UYPGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UYPGameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYPGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UYPGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UYPGameInstance()
{
	if (!Z_Registration_Info_UClass_UYPGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYPGameInstance.OuterSingleton, Z_Construct_UClass_UYPGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UYPGameInstance.OuterSingleton;
}
template<> YPP_API UClass* StaticClass<UYPGameInstance>()
{
	return UYPGameInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UYPGameInstance);
UYPGameInstance::~UYPGameInstance() {}
// End Class UYPGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FYPCharacterData::StaticStruct, Z_Construct_UScriptStruct_FYPCharacterData_Statics::NewStructOps, TEXT("YPCharacterData"), &Z_Registration_Info_UScriptStruct_YPCharacterData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FYPCharacterData), 2422058695U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UYPGameInstance, UYPGameInstance::StaticClass, TEXT("UYPGameInstance"), &Z_Registration_Info_UClass_UYPGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYPGameInstance), 1630283530U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_1442868229(TEXT("/Script/YPP"),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_YPP_YPP_Source_YPP_Public_YPGameInstance_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
