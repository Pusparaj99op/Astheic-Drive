// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Variant_TimeTrial/TimeTrialPlayerController.h"

#ifdef ASTHETICDRIVE_TimeTrialPlayerController_generated_h
#error "TimeTrialPlayerController.generated.h already included, missing '#pragma once' in TimeTrialPlayerController.h"
#endif
#define ASTHETICDRIVE_TimeTrialPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;

// ********** Begin Class ATimeTrialPlayerController ***********************************************
#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnPawnDestroyed); \
	DECLARE_FUNCTION(execStartRace);


struct Z_Construct_UClass_ATimeTrialPlayerController_Statics;
ASTHETICDRIVE_API UClass* Z_Construct_UClass_ATimeTrialPlayerController(ETypeConstructPhase);

#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h_21_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ATimeTrialPlayerController_Statics; \
	friend ASTHETICDRIVE_API UClass* ::Z_Construct_UClass_ATimeTrialPlayerController(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ATimeTrialPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/AstheticDrive"), Z_Construct_UClass_ATimeTrialPlayerController) \
	DECLARE_SERIALIZER(ATimeTrialPlayerController)


#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATimeTrialPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ATimeTrialPlayerController(ATimeTrialPlayerController&&) = delete; \
	ATimeTrialPlayerController(const ATimeTrialPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATimeTrialPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATimeTrialPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATimeTrialPlayerController) \
	NO_API virtual ~ATimeTrialPlayerController();


#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h_18_PROLOG
#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h_21_INCLASS_NO_PURE_DECLS \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ATimeTrialPlayerController;

// ********** End Class ATimeTrialPlayerController *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
