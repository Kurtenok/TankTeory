// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToonTanks/Tower.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTower() {}
// Cross Module References
	TOONTANKS_API UClass* Z_Construct_UClass_ABasePawn();
	TOONTANKS_API UClass* Z_Construct_UClass_ATower();
	TOONTANKS_API UClass* Z_Construct_UClass_ATower_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ToonTanks();
// End Cross Module References
	void ATower::StaticRegisterNativesATower()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATower);
	UClass* Z_Construct_UClass_ATower_NoRegister()
	{
		return ATower::StaticClass();
	}
	struct Z_Construct_UClass_ATower_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATower_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABasePawn,
		(UObject* (*)())Z_Construct_UPackage__Script_ToonTanks,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATower_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATower_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Tower.h" },
		{ "ModuleRelativePath", "Tower.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATower_Statics::NewProp_AttackRange_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Tower.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATower_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATower, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATower_Statics::NewProp_AttackRange_MetaData), Z_Construct_UClass_ATower_Statics::NewProp_AttackRange_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATower_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATower_Statics::NewProp_AttackRange,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATower_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATower>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATower_Statics::ClassParams = {
		&ATower::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATower_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATower_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATower_Statics::Class_MetaDataParams), Z_Construct_UClass_ATower_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATower_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATower()
	{
		if (!Z_Registration_Info_UClass_ATower.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATower.OuterSingleton, Z_Construct_UClass_ATower_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATower.OuterSingleton;
	}
	template<> TOONTANKS_API UClass* StaticClass<ATower>()
	{
		return ATower::StaticClass();
	}
	ATower::ATower() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATower);
	ATower::~ATower() {}
	struct Z_CompiledInDeferFile_FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tower_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tower_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATower, ATower::StaticClass, TEXT("ATower"), &Z_Registration_Info_UClass_ATower, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATower), 4067957851U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tower_h_3299224578(TEXT("/Script/ToonTanks"),
		Z_CompiledInDeferFile_FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tower_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tower_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
