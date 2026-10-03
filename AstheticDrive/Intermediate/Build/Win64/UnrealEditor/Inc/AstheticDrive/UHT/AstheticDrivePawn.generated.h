// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AstheticDrivePawn.h"

#ifdef ASTHETICDRIVE_AstheticDrivePawn_generated_h
#error "AstheticDrivePawn.generated.h already included, missing '#pragma once' in AstheticDrivePawn.h"
#endif
#define ASTHETICDRIVE_AstheticDrivePawn_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AAstheticDrivePawn *******************************************************
#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFlippedCheck); \
	DECLARE_FUNCTION(execDoResetVehicle); \
	DECLARE_FUNCTION(execDoToggleCamera); \
	DECLARE_FUNCTION(execDoLookAround); \
	DECLARE_FUNCTION(execDoHandbrakeStop); \
	DECLARE_FUNCTION(execDoHandbrakeStart); \
	DECLARE_FUNCTION(execDoBrakeStop); \
	DECLARE_FUNCTION(execDoBrakeStart); \
	DECLARE_FUNCTION(execDoBrake); \
	DECLARE_FUNCTION(execDoThrottle); \
	DECLARE_FUNCTION(execDoSteering);


#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AAstheticDrivePawn_Statics;
ASTHETICDRIVE_API UClass* Z_Construct_UClass_AAstheticDrivePawn(ETypeConstructPhase);

#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AAstheticDrivePawn_Statics; \
	friend ASTHETICDRIVE_API UClass* ::Z_Construct_UClass_AAstheticDrivePawn(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AAstheticDrivePawn, AWheeledVehiclePawn, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/AstheticDrive"), Z_Construct_UClass_AAstheticDrivePawn) \
	DECLARE_SERIALIZER(AAstheticDrivePawn)


#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AAstheticDrivePawn(AAstheticDrivePawn&&) = delete; \
	AAstheticDrivePawn(const AAstheticDrivePawn&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAstheticDrivePawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAstheticDrivePawn); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AAstheticDrivePawn) \
	NO_API virtual ~AAstheticDrivePawn();


#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_22_PROLOG
#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_CALLBACK_WRAPPERS \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_INCLASS_NO_PURE_DECLS \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AAstheticDrivePawn;

// ********** End Class AAstheticDrivePawn *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
