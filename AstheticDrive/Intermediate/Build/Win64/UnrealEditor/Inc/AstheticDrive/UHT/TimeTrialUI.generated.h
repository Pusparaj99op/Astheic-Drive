// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Variant_TimeTrial/UI/TimeTrialUI.h"

#ifdef ASTHETICDRIVE_TimeTrialUI_generated_h
#error "TimeTrialUI.generated.h already included, missing '#pragma once' in TimeTrialUI.h"
#endif
#define ASTHETICDRIVE_TimeTrialUI_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UTimeTrialUI *************************************************************
#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetLapStartTime); \
	DECLARE_FUNCTION(execGetBestLapTime); \
	DECLARE_FUNCTION(execGetCurrentLap); \
	DECLARE_FUNCTION(execStartRace);


#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UTimeTrialUI_Statics;
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UTimeTrialUI(ETypeConstructPhase);

#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UTimeTrialUI_Statics; \
	friend ASTHETICDRIVE_API UClass* ::Z_Construct_UClass_UTimeTrialUI(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UTimeTrialUI, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/AstheticDrive"), Z_Construct_UClass_UTimeTrialUI) \
	DECLARE_SERIALIZER(UTimeTrialUI)


#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTimeTrialUI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTimeTrialUI(UTimeTrialUI&&) = delete; \
	UTimeTrialUI(const UTimeTrialUI&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTimeTrialUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTimeTrialUI); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTimeTrialUI) \
	NO_API virtual ~UTimeTrialUI();


#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_18_PROLOG
#define FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_CALLBACK_WRAPPERS \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_INCLASS_NO_PURE_DECLS \
	FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTimeTrialUI;

// ********** End Class UTimeTrialUI ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
