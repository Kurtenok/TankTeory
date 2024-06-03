// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HealthComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AController;
class UDamageType;
#ifdef TOONTANKS_HealthComponent_generated_h
#error "HealthComponent.generated.h already included, missing '#pragma once' in HealthComponent.h"
#endif
#define TOONTANKS_HealthComponent_generated_h

#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_SPARSE_DATA
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_Health); \
	DECLARE_FUNCTION(execDamageTaken);


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHealthComponent(); \
	friend struct Z_Construct_UClass_UHealthComponent_Statics; \
public: \
	DECLARE_CLASS(UHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(UHealthComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		NETFIELD_REP_END=Health	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHealthComponent(UHealthComponent&&); \
	NO_API UHealthComponent(const UHealthComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHealthComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHealthComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHealthComponent) \
	NO_API virtual ~UHealthComponent();


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_7_PROLOG
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_SPARSE_DATA \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_INCLASS_NO_PURE_DECLS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOONTANKS_API UClass* StaticClass<class UHealthComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_HealthComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
