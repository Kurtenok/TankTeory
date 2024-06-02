// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BasePawn.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOONTANKS_BasePawn_generated_h
#error "BasePawn.generated.h already included, missing '#pragma once' in BasePawn.h"
#endif
#define TOONTANKS_BasePawn_generated_h

#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_SPARSE_DATA
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void MulticastRotateTurret_Implementation(FRotator TurretRotation); \
	virtual bool ServerRotateTurret_Validate(FVector ); \
	virtual void ServerRotateTurret_Implementation(FVector LookAtTarget); \
	virtual void MulticastFire_Implementation(); \
	virtual bool ServerFire_Validate(); \
	virtual void ServerFire_Implementation(); \
 \
	DECLARE_FUNCTION(execMulticastRotateTurret); \
	DECLARE_FUNCTION(execServerRotateTurret); \
	DECLARE_FUNCTION(execMulticastFire); \
	DECLARE_FUNCTION(execServerFire);


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_CALLBACK_WRAPPERS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABasePawn(); \
	friend struct Z_Construct_UClass_ABasePawn_Statics; \
public: \
	DECLARE_CLASS(ABasePawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(ABasePawn)


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABasePawn(ABasePawn&&); \
	NO_API ABasePawn(const ABasePawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasePawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasePawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABasePawn) \
	NO_API virtual ~ABasePawn();


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_7_PROLOG
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_SPARSE_DATA \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_CALLBACK_WRAPPERS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_INCLASS_NO_PURE_DECLS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOONTANKS_API UClass* StaticClass<class ABasePawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_BasePawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
