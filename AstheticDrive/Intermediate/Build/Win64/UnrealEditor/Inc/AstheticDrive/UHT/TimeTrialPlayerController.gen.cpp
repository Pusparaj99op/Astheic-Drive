// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeTrialPlayerController.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeTimeTrialPlayerController() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerController(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_ATimeTrialPlayerController(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_AAstheticDrivePawn(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveUI(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_ATimeTrialPlayerController(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UTimeTrialUI(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ATimeTrialPlayerController Function OnPawnDestroyed **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ATimeTrialPlayerController_OnPawnDestroyed_Statics
struct UHT_STATICS
{
	struct TimeTrialPlayerController_eventOnPawnDestroyed_Parms
	{
		AActor* DestroyedPawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles pawn destruction and respawning */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles pawn destruction and respawning" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnPawnDestroyed constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DestroyedPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnPawnDestroyed constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnPawnDestroyed Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DestroyedPawn = { "DestroyedPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(TimeTrialPlayerController_eventOnPawnDestroyed_Parms, DestroyedPawn), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DestroyedPawn,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnPawnDestroyed Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ATimeTrialPlayerController, nullptr, "OnPawnDestroyed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeTrialPlayerController_eventOnPawnDestroyed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeTrialPlayerController_eventOnPawnDestroyed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATimeTrialPlayerController_OnPawnDestroyed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ATimeTrialPlayerController::execOnPawnDestroyed)
{
	P_GET_OBJECT(AActor,Z_Param_DestroyedPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPawnDestroyed(Z_Param_DestroyedPawn);
	P_NATIVE_END;
}
// ********** End Class ATimeTrialPlayerController Function OnPawnDestroyed ************************

// ********** Begin Class ATimeTrialPlayerController Function StartRace ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ATimeTrialPlayerController_StartRace_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets up the race start */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets up the race start" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StartRace constinit property declarations *****************************
// ********** End Function StartRace constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ATimeTrialPlayerController, nullptr, "StartRace", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ATimeTrialPlayerController_StartRace(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ATimeTrialPlayerController::execStartRace)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartRace();
	P_NATIVE_END;
}
// ********** End Class ATimeTrialPlayerController Function StartRace ******************************

// ********** Begin Class ATimeTrialPlayerController ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ATimeTrialPlayerController_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A simple PlayerController for a Time Trial racing game\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple PlayerController for a Time Trial racing game" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContexts_MetaData[] = {
		{ "Category", "Input|Input Mappings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Mapping Contexts */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Mapping Contexts" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MobileExcludedMappingContexts_MetaData[] = {
		{ "Category", "Input|Input Mappings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Mapping Contexts */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Mapping Contexts" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MobileControlsWidgetClass_MetaData[] = {
		{ "Category", "Input|Touch Controls" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mobile controls widget to spawn */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mobile controls widget to spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MobileControlsWidget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pointer to the mobile controls widget */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pointer to the mobile controls widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceTouchControls_MetaData[] = {
		{ "Category", "Input|Touch Controls" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, the player will use UMG touch controls even if not playing on mobile platforms */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, the player will use UMG touch controls even if not playing on mobile platforms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseSteeringWheelControls_MetaData[] = {
		{ "Category", "Input|Steering Wheel Controls" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, the optional steering wheel input mapping context will be registered */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, the optional steering wheel input mapping context will be registered" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SteeringWheelInputMappingContext_MetaData[] = {
		{ "Category", "Input|Steering Wheel Controls" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional Input Mapping Context to be used for steering wheel input.\n\x09 *  This is added alongside the default Input Mapping Context and does not block other forms of input.\n\x09 */" },
#endif
		{ "EditCondition", "bUseSteeringWheelControls" },
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional Input Mapping Context to be used for steering wheel input.\nThis is added alongside the default Input Mapping Context and does not block other forms of input." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIWidgetClass_MetaData[] = {
		{ "Category", "Time Trial|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of UI widget to spawn*/" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of UI widget to spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIWidget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pointer to the UI Widget */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pointer to the UI Widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VehicleUIClass_MetaData[] = {
		{ "Category", "Vehicle|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of the UI to spawn */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of the UI to spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VehicleUI_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pointer to the UI widget */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pointer to the UI widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VehiclePawnClass_MetaData[] = {
		{ "Category", "Vehicle|Respawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of vehicle to automatically respawn when it's destroyed */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of vehicle to automatically respawn when it's destroyed" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ATimeTrialPlayerController constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContexts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DefaultMappingContexts;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MobileExcludedMappingContexts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MobileExcludedMappingContexts;
	static const UECodeGen_Private::FClassPropertyParams NewProp_MobileControlsWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MobileControlsWidget;
	static void NewProp_bForceTouchControls_SetBit(void* Obj)
	{
		((ATimeTrialPlayerController*)Obj)->bForceTouchControls = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceTouchControls;
	static void NewProp_bUseSteeringWheelControls_SetBit(void* Obj)
	{
		((ATimeTrialPlayerController*)Obj)->bUseSteeringWheelControls = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseSteeringWheelControls;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SteeringWheelInputMappingContext;
	static const UECodeGen_Private::FClassPropertyParams NewProp_UIWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UIWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_VehicleUIClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VehicleUI;
	static const UECodeGen_Private::FClassPropertyParams NewProp_VehiclePawnClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ATimeTrialPlayerController constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnPawnDestroyed"), .Pointer = &ATimeTrialPlayerController::execOnPawnDestroyed },
		{ .NameUTF8 = UTF8TEXT("StartRace"), .Pointer = &ATimeTrialPlayerController::execStartRace },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATimeTrialPlayerController_OnPawnDestroyed, "OnPawnDestroyed" }, // 7a88830ff4cd68cc8b751fad03515d7b6d817399
		{ &Z_Construct_UFunction_ATimeTrialPlayerController_StartRace, "StartRace" }, // 29dc8617293fec0e0477ba88e3d4954a8fd09233
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATimeTrialPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ATimeTrialPlayerController Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DefaultMappingContexts_Inner = { "DefaultMappingContexts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInputMappingContext, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_DefaultMappingContexts = { "DefaultMappingContexts", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, DefaultMappingContexts), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContexts_MetaData), NewProp_DefaultMappingContexts_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MobileExcludedMappingContexts_Inner = { "MobileExcludedMappingContexts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInputMappingContext, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_MobileExcludedMappingContexts = { "MobileExcludedMappingContexts", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, MobileExcludedMappingContexts), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MobileExcludedMappingContexts_MetaData), NewProp_MobileExcludedMappingContexts_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_MobileControlsWidgetClass = { "MobileControlsWidgetClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, MobileControlsWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MobileControlsWidgetClass_MetaData), NewProp_MobileControlsWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MobileControlsWidget = { "MobileControlsWidget", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, MobileControlsWidget), Z_Construct_UClass_UUserWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MobileControlsWidget_MetaData), NewProp_MobileControlsWidget_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bForceTouchControls = { "bForceTouchControls", nullptr, (EPropertyFlags)0x0020080000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ATimeTrialPlayerController), &UHT_STATICS::NewProp_bForceTouchControls_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceTouchControls_MetaData), NewProp_bForceTouchControls_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUseSteeringWheelControls = { "bUseSteeringWheelControls", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ATimeTrialPlayerController), &UHT_STATICS::NewProp_bUseSteeringWheelControls_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseSteeringWheelControls_MetaData), NewProp_bUseSteeringWheelControls_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SteeringWheelInputMappingContext = { "SteeringWheelInputMappingContext", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, SteeringWheelInputMappingContext), Z_Construct_UClass_UInputMappingContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SteeringWheelInputMappingContext_MetaData), NewProp_SteeringWheelInputMappingContext_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_UIWidgetClass = { "UIWidgetClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, UIWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UTimeTrialUI, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIWidgetClass_MetaData), NewProp_UIWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_UIWidget = { "UIWidget", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, UIWidget), Z_Construct_UClass_UTimeTrialUI, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIWidget_MetaData), NewProp_UIWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_VehicleUIClass = { "VehicleUIClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, VehicleUIClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UAstheticDriveUI, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VehicleUIClass_MetaData), NewProp_VehicleUIClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VehicleUI = { "VehicleUI", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, VehicleUI), Z_Construct_UClass_UAstheticDriveUI, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VehicleUI_MetaData), NewProp_VehicleUI_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_VehiclePawnClass = { "VehiclePawnClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialPlayerController, VehiclePawnClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AAstheticDrivePawn, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VehiclePawnClass_MetaData), NewProp_VehiclePawnClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultMappingContexts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultMappingContexts,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MobileExcludedMappingContexts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MobileExcludedMappingContexts,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MobileControlsWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MobileControlsWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bForceTouchControls,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUseSteeringWheelControls,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SteeringWheelInputMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UIWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UIWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VehicleUIClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VehicleUI,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VehiclePawnClass,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ATimeTrialPlayerController Property Definitions ****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_APlayerController,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ATimeTrialPlayerController,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x008002A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void ATimeTrialPlayerController_StaticRegisterNativesATimeTrialPlayerController()
{
	UClass* Class = ATimeTrialPlayerController::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ATimeTrialPlayerController;
UClass* Z_Construct_UClass_ATimeTrialPlayerController(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ATimeTrialPlayerController;
		if (!Z_Registration_Info_UClass_ATimeTrialPlayerController.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("TimeTrialPlayerController"),
				Z_Registration_Info_UClass_ATimeTrialPlayerController.InnerSingleton,
				ATimeTrialPlayerController_StaticRegisterNativesATimeTrialPlayerController,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_ATimeTrialPlayerController.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ATimeTrialPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATimeTrialPlayerController.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ATimeTrialPlayerController.OuterSingleton;
}
#undef UHT_STATICS
ATimeTrialPlayerController::ATimeTrialPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATimeTrialPlayerController);
ATimeTrialPlayerController::~ATimeTrialPlayerController() {}
// ********** End Class ATimeTrialPlayerController *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATimeTrialPlayerController, TEXT("ATimeTrialPlayerController"), &Z_Registration_Info_UClass_ATimeTrialPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATimeTrialPlayerController), 291174400U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialPlayerController_h__Script_AstheticDrive_c5fe98a47a7b321bae406bdd2c1570c6afa2bf3b{
	TEXT("/Script/AstheticDrive"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
