// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AstheticDrivePawn.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeAstheticDrivePawn() {}

// ********** Begin Cross Module References ********************************************************
CHAOSVEHICLES_API UClass* Z_Construct_UClass_AWheeledVehiclePawn(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent(ETypeConstructPhase);
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_AAstheticDrivePawn(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_AAstheticDrivePawn(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class AAstheticDrivePawn Function BrakeLights **********************************
struct AstheticDrivePawn_eventBrakeLights_Parms
{
	bool bBraking;
};
static FName NAME_AAstheticDrivePawn_BrakeLights = FName(TEXT("BrakeLights"));
void AAstheticDrivePawn::BrakeLights(bool bBraking)
{
	AstheticDrivePawn_eventBrakeLights_Parms Parms;
	Parms.bBraking=bBraking ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AAstheticDrivePawn_BrakeLights);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_BrakeLights_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Vehicle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when the brake lights are turned on or off */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when the brake lights are turned on or off" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BrakeLights constinit property declarations ***************************
	static void NewProp_bBraking_SetBit(void* Obj)
	{
		((AstheticDrivePawn_eventBrakeLights_Parms*)Obj)->bBraking = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBraking;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BrakeLights constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BrakeLights Property Definitions **************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bBraking = { "bBraking", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AstheticDrivePawn_eventBrakeLights_Parms), &UHT_STATICS::NewProp_bBraking_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bBraking,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BrakeLights Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "BrakeLights", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<AstheticDrivePawn_eventBrakeLights_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(AstheticDrivePawn_eventBrakeLights_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_BrakeLights(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class AAstheticDrivePawn Function BrakeLights ************************************

// ********** Begin Class AAstheticDrivePawn Function DoBrake **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoBrake_Statics
struct UHT_STATICS
{
	struct AstheticDrivePawn_eventDoBrake_Parms
	{
		float BrakeValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle brake input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle brake input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoBrake constinit property declarations *******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakeValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoBrake constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoBrake Property Definitions ******************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BrakeValue = { "BrakeValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AstheticDrivePawn_eventDoBrake_Parms, BrakeValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BrakeValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function DoBrake Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoBrake", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AstheticDrivePawn_eventDoBrake_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AstheticDrivePawn_eventDoBrake_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoBrake(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoBrake)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_BrakeValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoBrake(Z_Param_BrakeValue);
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoBrake ****************************************

// ********** Begin Class AAstheticDrivePawn Function DoBrakeStart *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoBrakeStart_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle brake start input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle brake start input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoBrakeStart constinit property declarations **************************
// ********** End Function DoBrakeStart constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoBrakeStart", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoBrakeStart(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoBrakeStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoBrakeStart();
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoBrakeStart ***********************************

// ********** Begin Class AAstheticDrivePawn Function DoBrakeStop **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoBrakeStop_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle brake stop input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle brake stop input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoBrakeStop constinit property declarations ***************************
// ********** End Function DoBrakeStop constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoBrakeStop", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoBrakeStop(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoBrakeStop)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoBrakeStop();
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoBrakeStop ************************************

// ********** Begin Class AAstheticDrivePawn Function DoHandbrakeStart *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoHandbrakeStart_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle handbrake start input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle handbrake start input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoHandbrakeStart constinit property declarations **********************
// ********** End Function DoHandbrakeStart constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoHandbrakeStart", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoHandbrakeStart(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoHandbrakeStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoHandbrakeStart();
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoHandbrakeStart *******************************

// ********** Begin Class AAstheticDrivePawn Function DoHandbrakeStop ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoHandbrakeStop_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle handbrake stop input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle handbrake stop input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoHandbrakeStop constinit property declarations ***********************
// ********** End Function DoHandbrakeStop constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoHandbrakeStop", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoHandbrakeStop(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoHandbrakeStop)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoHandbrakeStop();
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoHandbrakeStop ********************************

// ********** Begin Class AAstheticDrivePawn Function DoLookAround *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoLookAround_Statics
struct UHT_STATICS
{
	struct AstheticDrivePawn_eventDoLookAround_Parms
	{
		float YawDelta;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle look input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle look input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoLookAround constinit property declarations **************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_YawDelta;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoLookAround constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoLookAround Property Definitions *************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_YawDelta = { "YawDelta", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AstheticDrivePawn_eventDoLookAround_Parms, YawDelta), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_YawDelta,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function DoLookAround Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoLookAround", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AstheticDrivePawn_eventDoLookAround_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AstheticDrivePawn_eventDoLookAround_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoLookAround(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoLookAround)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_YawDelta);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoLookAround(Z_Param_YawDelta);
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoLookAround ***********************************

// ********** Begin Class AAstheticDrivePawn Function DoResetVehicle *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoResetVehicle_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle reset vehicle input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle reset vehicle input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoResetVehicle constinit property declarations ************************
// ********** End Function DoResetVehicle constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoResetVehicle", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoResetVehicle(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoResetVehicle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoResetVehicle();
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoResetVehicle *********************************

// ********** Begin Class AAstheticDrivePawn Function DoSteering ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoSteering_Statics
struct UHT_STATICS
{
	struct AstheticDrivePawn_eventDoSteering_Parms
	{
		float SteeringValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle steering input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle steering input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoSteering constinit property declarations ****************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SteeringValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoSteering constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoSteering Property Definitions ***************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SteeringValue = { "SteeringValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AstheticDrivePawn_eventDoSteering_Parms, SteeringValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SteeringValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function DoSteering Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoSteering", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AstheticDrivePawn_eventDoSteering_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AstheticDrivePawn_eventDoSteering_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoSteering(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoSteering)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_SteeringValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoSteering(Z_Param_SteeringValue);
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoSteering *************************************

// ********** Begin Class AAstheticDrivePawn Function DoThrottle ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoThrottle_Statics
struct UHT_STATICS
{
	struct AstheticDrivePawn_eventDoThrottle_Parms
	{
		float ThrottleValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle throttle input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle throttle input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoThrottle constinit property declarations ****************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrottleValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoThrottle constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoThrottle Property Definitions ***************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ThrottleValue = { "ThrottleValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AstheticDrivePawn_eventDoThrottle_Parms, ThrottleValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ThrottleValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function DoThrottle Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoThrottle", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AstheticDrivePawn_eventDoThrottle_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AstheticDrivePawn_eventDoThrottle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoThrottle(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoThrottle)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ThrottleValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoThrottle(Z_Param_ThrottleValue);
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoThrottle *************************************

// ********** Begin Class AAstheticDrivePawn Function DoToggleCamera *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_DoToggleCamera_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle toggle camera input by input actions or mobile interface */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle toggle camera input by input actions or mobile interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoToggleCamera constinit property declarations ************************
// ********** End Function DoToggleCamera constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "DoToggleCamera", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_DoToggleCamera(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execDoToggleCamera)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoToggleCamera();
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function DoToggleCamera *********************************

// ********** Begin Class AAstheticDrivePawn Function FlippedCheck *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AAstheticDrivePawn_FlippedCheck_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Checks if the car is flipped upside down and automatically resets it */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks if the car is flipped upside down and automatically resets it" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FlippedCheck constinit property declarations **************************
// ********** End Function FlippedCheck constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn, nullptr, "FlippedCheck", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AAstheticDrivePawn_FlippedCheck(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AAstheticDrivePawn::execFlippedCheck)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FlippedCheck();
	P_NATIVE_END;
}
// ********** End Class AAstheticDrivePawn Function FlippedCheck ***********************************

// ********** Begin Class AAstheticDrivePawn *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AAstheticDrivePawn_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Vehicle Pawn class\n *  Handles common functionality for all vehicle types,\n *  including input handling and camera management.\n *  \n *  Specific vehicle configurations are handled in subclasses.\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AstheticDrivePawn.h" },
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Vehicle Pawn class\nHandles common functionality for all vehicle types,\nincluding input handling and camera management.\n\nSpecific vehicle configurations are handled in subclasses." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrontSpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spring Arm for the front camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring Arm for the front camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrontCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Front Camera component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Front Camera component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackSpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spring Arm for the back camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring Arm for the back camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Back Camera component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Back Camera component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SteeringAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Steering Action */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Steering Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrottleAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Throttle Action */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Throttle Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrakeAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Brake Action */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Brake Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HandbrakeAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handbrake Action */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handbrake Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAroundAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Around Action */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Around Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleCameraAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Toggle Camera Action */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggle Camera Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResetVehicleAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reset Vehicle Action */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reset Vehicle Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlipCheckTime_MetaData[] = {
		{ "Category", "Flip Check" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time between automatic flip checks */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time between automatic flip checks" },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlipCheckMinDot_MetaData[] = {
		{ "Category", "Flip Check" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum dot product value for the vehicle's up direction that we still consider upright */" },
#endif
		{ "ModuleRelativePath", "AstheticDrivePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum dot product value for the vehicle's up direction that we still consider upright" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AAstheticDrivePawn constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FrontSpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FrontCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BackSpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BackCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SteeringAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThrottleAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BrakeAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HandbrakeAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAroundAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToggleCameraAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ResetVehicleAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FlipCheckTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FlipCheckMinDot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AAstheticDrivePawn constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DoBrake"), .Pointer = &AAstheticDrivePawn::execDoBrake },
		{ .NameUTF8 = UTF8TEXT("DoBrakeStart"), .Pointer = &AAstheticDrivePawn::execDoBrakeStart },
		{ .NameUTF8 = UTF8TEXT("DoBrakeStop"), .Pointer = &AAstheticDrivePawn::execDoBrakeStop },
		{ .NameUTF8 = UTF8TEXT("DoHandbrakeStart"), .Pointer = &AAstheticDrivePawn::execDoHandbrakeStart },
		{ .NameUTF8 = UTF8TEXT("DoHandbrakeStop"), .Pointer = &AAstheticDrivePawn::execDoHandbrakeStop },
		{ .NameUTF8 = UTF8TEXT("DoLookAround"), .Pointer = &AAstheticDrivePawn::execDoLookAround },
		{ .NameUTF8 = UTF8TEXT("DoResetVehicle"), .Pointer = &AAstheticDrivePawn::execDoResetVehicle },
		{ .NameUTF8 = UTF8TEXT("DoSteering"), .Pointer = &AAstheticDrivePawn::execDoSteering },
		{ .NameUTF8 = UTF8TEXT("DoThrottle"), .Pointer = &AAstheticDrivePawn::execDoThrottle },
		{ .NameUTF8 = UTF8TEXT("DoToggleCamera"), .Pointer = &AAstheticDrivePawn::execDoToggleCamera },
		{ .NameUTF8 = UTF8TEXT("FlippedCheck"), .Pointer = &AAstheticDrivePawn::execFlippedCheck },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AAstheticDrivePawn_BrakeLights, "BrakeLights" }, // da2320c331b9f967b0d9e9f0df7bbd5d02a08585
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoBrake, "DoBrake" }, // 1c418b7ff9b8a9c7a8725e3aece29ef58d9e17d8
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoBrakeStart, "DoBrakeStart" }, // 6c181f199e2414579c5e3f4b181a2efd87c13b21
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoBrakeStop, "DoBrakeStop" }, // 439b2dca00f20c96feb8add651d69dfb19e62744
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoHandbrakeStart, "DoHandbrakeStart" }, // a653f37d542be7a82e525180121b5839f5b13a5d
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoHandbrakeStop, "DoHandbrakeStop" }, // 58d8e6a1e89dc77dd299b459889ac893a39ebcc4
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoLookAround, "DoLookAround" }, // db8cb3bd94d7807daffce410baff33b250740653
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoResetVehicle, "DoResetVehicle" }, // ee7ed3f9dfc76a955dd22d52c4131bf2e832414e
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoSteering, "DoSteering" }, // c6085f02a70374d9c1eb31af12e6b97af47d3b6f
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoThrottle, "DoThrottle" }, // 3e0f70b34475db16cabe0cfa9c7d39e31030e261
		{ &Z_Construct_UFunction_AAstheticDrivePawn_DoToggleCamera, "DoToggleCamera" }, // e9bd35d9ae5bb2a4a3e18c1e1b0c153f7925e498
		{ &Z_Construct_UFunction_AAstheticDrivePawn_FlippedCheck, "FlippedCheck" }, // 190231ab87d95a49c543f311447f3922889495bb
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAstheticDrivePawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AAstheticDrivePawn Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FrontSpringArm = { "FrontSpringArm", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, FrontSpringArm), Z_Construct_UClass_USpringArmComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrontSpringArm_MetaData), NewProp_FrontSpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FrontCamera = { "FrontCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, FrontCamera), Z_Construct_UClass_UCameraComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrontCamera_MetaData), NewProp_FrontCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BackSpringArm = { "BackSpringArm", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, BackSpringArm), Z_Construct_UClass_USpringArmComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackSpringArm_MetaData), NewProp_BackSpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BackCamera = { "BackCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, BackCamera), Z_Construct_UClass_UCameraComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackCamera_MetaData), NewProp_BackCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SteeringAction = { "SteeringAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, SteeringAction), Z_Construct_UClass_UInputAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SteeringAction_MetaData), NewProp_SteeringAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ThrottleAction = { "ThrottleAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, ThrottleAction), Z_Construct_UClass_UInputAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrottleAction_MetaData), NewProp_ThrottleAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BrakeAction = { "BrakeAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, BrakeAction), Z_Construct_UClass_UInputAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrakeAction_MetaData), NewProp_BrakeAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HandbrakeAction = { "HandbrakeAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, HandbrakeAction), Z_Construct_UClass_UInputAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HandbrakeAction_MetaData), NewProp_HandbrakeAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_LookAroundAction = { "LookAroundAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, LookAroundAction), Z_Construct_UClass_UInputAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAroundAction_MetaData), NewProp_LookAroundAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ToggleCameraAction = { "ToggleCameraAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, ToggleCameraAction), Z_Construct_UClass_UInputAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleCameraAction_MetaData), NewProp_ToggleCameraAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ResetVehicleAction = { "ResetVehicleAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, ResetVehicleAction), Z_Construct_UClass_UInputAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResetVehicleAction_MetaData), NewProp_ResetVehicleAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FlipCheckTime = { "FlipCheckTime", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, FlipCheckTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlipCheckTime_MetaData), NewProp_FlipCheckTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FlipCheckMinDot = { "FlipCheckMinDot", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDrivePawn, FlipCheckMinDot), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlipCheckMinDot_MetaData), NewProp_FlipCheckMinDot_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FrontSpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FrontCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BackSpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BackCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SteeringAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ThrottleAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BrakeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HandbrakeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LookAroundAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToggleCameraAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ResetVehicleAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FlipCheckTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FlipCheckMinDot,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AAstheticDrivePawn Property Definitions ************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AWheeledVehiclePawn,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AAstheticDrivePawn,
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
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void AAstheticDrivePawn_StaticRegisterNativesAAstheticDrivePawn()
{
	UClass* Class = AAstheticDrivePawn::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AAstheticDrivePawn;
UClass* Z_Construct_UClass_AAstheticDrivePawn(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AAstheticDrivePawn;
		if (!Z_Registration_Info_UClass_AAstheticDrivePawn.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("AstheticDrivePawn"),
				Z_Registration_Info_UClass_AAstheticDrivePawn.InnerSingleton,
				AAstheticDrivePawn_StaticRegisterNativesAAstheticDrivePawn,
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
		return Z_Registration_Info_UClass_AAstheticDrivePawn.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AAstheticDrivePawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAstheticDrivePawn.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AAstheticDrivePawn.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AAstheticDrivePawn);
AAstheticDrivePawn::~AAstheticDrivePawn() {}
// ********** End Class AAstheticDrivePawn *********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAstheticDrivePawn, TEXT("AAstheticDrivePawn"), &Z_Registration_Info_UClass_AAstheticDrivePawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAstheticDrivePawn), 2914253189U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDrivePawn_h__Script_AstheticDrive_a9ebf1c82ce1629f2622f54cbbeb880dad8eaf53{
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
