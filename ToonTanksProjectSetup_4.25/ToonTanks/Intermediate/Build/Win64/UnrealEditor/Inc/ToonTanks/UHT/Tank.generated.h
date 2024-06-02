// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Tank.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOONTANKS_Tank_generated_h
#error "Tank.generated.h already included, missing '#pragma once' in Tank.h"
#endif
#define TOONTANKS_Tank_generated_h

#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_SPARSE_DATA
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void MulticastTurn_Implementation(FRotator const& NewRotation); \
	virtual void MulticastMove_Implementation(FVector const& NewLocation); \
	virtual bool ServerTurn_Validate(float ); \
	virtual void ServerTurn_Implementation(float Value); \
	virtual bool ServerMove_Validate(float ); \
	virtual void ServerMove_Implementation(float Value); \
 \
	DECLARE_FUNCTION(execOnRep_CurrentRotation); \
	DECLARE_FUNCTION(execOnRep_CurrentLocation); \
	DECLARE_FUNCTION(execMulticastTurn); \
	DECLARE_FUNCTION(execMulticastMove); \
	DECLARE_FUNCTION(execServerTurn); \
	DECLARE_FUNCTION(execServerMove);


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_ACCESSORS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_CALLBACK_WRAPPERS
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATank(); \
	friend struct Z_Construct_UClass_ATank_Statics; \
public: \
	DECLARE_CLASS(ATank, ABasePawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(ATank) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentLocation=NETFIELD_REP_START, \
		CurrentRotation, \
		NETFIELD_REP_END=CurrentRotation	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATank(ATank&&); \
	NO_API ATank(const ATank&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATank); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATank); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATank) \
	NO_API virtual ~ATank();


#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_7_PROLOG
#define FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_SPARSE_DATA \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_ACCESSORS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_CALLBACK_WRAPPERS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_INCLASS_NO_PURE_DECLS \
	FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOONTANKS_API UClass* StaticClass<class ATank>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Kursach_TankTeory_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_Tank_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
