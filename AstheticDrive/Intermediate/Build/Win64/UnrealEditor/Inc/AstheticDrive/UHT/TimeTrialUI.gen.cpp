// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeTrialUI.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeTimeTrialUI() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UFunction* Z_Construct_UDelegateFunction_AstheticDrive_StartRaceDelegate__DelegateSignature(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UTimeTrialUI(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UTimeTrialStartUI(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UTimeTrialUI(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FStartRaceDelegate ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_AstheticDrive_StartRaceDelegate__DelegateSignature_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FStartRaceDelegate constinit property declarations ********************
// ********** End Delegate FStartRaceDelegate constinit property declarations **********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive, nullptr, "StartRaceDelegate__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UDelegateFunction_AstheticDrive_StartRaceDelegate__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FStartRaceDelegate ******************************************************

// ********** Begin Class UTimeTrialUI Function BP_UpdateLaps **************************************
static FName NAME_UTimeTrialUI_BP_UpdateLaps = FName(TEXT("BP_UpdateLaps"));
void UTimeTrialUI::BP_UpdateLaps()
{
	UFunction* Func = FindFunctionChecked(NAME_UTimeTrialUI_BP_UpdateLaps);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeTrialUI_BP_UpdateLaps_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Trial" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Allows Blueprint control to update the lap tracker widgets */" },
#endif
		{ "DisplayName", "Update Laps" },
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allows Blueprint control to update the lap tracker widgets" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_UpdateLaps constinit property declarations *************************
// ********** End Function BP_UpdateLaps constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeTrialUI, nullptr, "BP_UpdateLaps", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UTimeTrialUI_BP_UpdateLaps(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UTimeTrialUI Function BP_UpdateLaps ****************************************

// ********** Begin Class UTimeTrialUI Function GetBestLapTime *************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeTrialUI_GetBestLapTime_Statics
struct UHT_STATICS
{
	struct TimeTrialUI_eventGetBestLapTime_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Trial" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gets the best lap time saved */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the best lap time saved" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetBestLapTime constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBestLapTime constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBestLapTime Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(TimeTrialUI_eventGetBestLapTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetBestLapTime Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeTrialUI, nullptr, "GetBestLapTime", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeTrialUI_eventGetBestLapTime_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeTrialUI_eventGetBestLapTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeTrialUI_GetBestLapTime(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeTrialUI::execGetBestLapTime)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetBestLapTime();
	P_NATIVE_END;
}
// ********** End Class UTimeTrialUI Function GetBestLapTime ***************************************

// ********** Begin Class UTimeTrialUI Function GetCurrentLap **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeTrialUI_GetCurrentLap_Statics
struct UHT_STATICS
{
	struct TimeTrialUI_eventGetCurrentLap_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Trial" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gets the current lap number */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the current lap number" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentLap constinit property declarations *************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentLap constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentLap Property Definitions ************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(TimeTrialUI_eventGetCurrentLap_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentLap Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeTrialUI, nullptr, "GetCurrentLap", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeTrialUI_eventGetCurrentLap_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeTrialUI_eventGetCurrentLap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeTrialUI_GetCurrentLap(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeTrialUI::execGetCurrentLap)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetCurrentLap();
	P_NATIVE_END;
}
// ********** End Class UTimeTrialUI Function GetCurrentLap ****************************************

// ********** Begin Class UTimeTrialUI Function GetLapStartTime ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeTrialUI_GetLapStartTime_Statics
struct UHT_STATICS
{
	struct TimeTrialUI_eventGetLapStartTime_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Time Trial" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gets the best lap time saved */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the best lap time saved" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetLapStartTime constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLapStartTime constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLapStartTime Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(TimeTrialUI_eventGetLapStartTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetLapStartTime Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeTrialUI, nullptr, "GetLapStartTime", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TimeTrialUI_eventGetLapStartTime_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TimeTrialUI_eventGetLapStartTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTimeTrialUI_GetLapStartTime(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeTrialUI::execGetLapStartTime)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetLapStartTime();
	P_NATIVE_END;
}
// ********** End Class UTimeTrialUI Function GetLapStartTime **************************************

// ********** Begin Class UTimeTrialUI Function StartRace ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeTrialUI_StartRace_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called from the countdown delegate to start the race */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called from the countdown delegate to start the race" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StartRace constinit property declarations *****************************
// ********** End Function StartRace constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeTrialUI, nullptr, "StartRace", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UTimeTrialUI_StartRace(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeTrialUI::execStartRace)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartRace();
	P_NATIVE_END;
}
// ********** End Class UTimeTrialUI Function StartRace ********************************************

// ********** Begin Class UTimeTrialUI *************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UTimeTrialUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple UI for a Time Trial racing game\n *  Keeps track of lap number and best time\n *  Spawns a sub-widget to do the initial countdown\n */" },
#endif
		{ "IncludePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple UI for a Time Trial racing game\nKeeps track of lap number and best time\nSpawns a sub-widget to do the initial countdown" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartUIClass_MetaData[] = {
		{ "Category", "Start Countdown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of start countdown UI widget to spawn */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of start countdown UI widget to spawn" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UTimeTrialUI constinit property declarations *****************************
	static const UECodeGen_Private::FClassPropertyParams NewProp_StartUIClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UTimeTrialUI constinit property declarations *******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetBestLapTime"), .Pointer = &UTimeTrialUI::execGetBestLapTime },
		{ .NameUTF8 = UTF8TEXT("GetCurrentLap"), .Pointer = &UTimeTrialUI::execGetCurrentLap },
		{ .NameUTF8 = UTF8TEXT("GetLapStartTime"), .Pointer = &UTimeTrialUI::execGetLapStartTime },
		{ .NameUTF8 = UTF8TEXT("StartRace"), .Pointer = &UTimeTrialUI::execStartRace },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTimeTrialUI_BP_UpdateLaps, "BP_UpdateLaps" }, // 1fbe3b404eb20addd0517c0f24a63902c68ea990
		{ &Z_Construct_UFunction_UTimeTrialUI_GetBestLapTime, "GetBestLapTime" }, // c2362f741b4ad46406139ffca226517378fe0c50
		{ &Z_Construct_UFunction_UTimeTrialUI_GetCurrentLap, "GetCurrentLap" }, // 9b3cd7473998356689a983868f62371c13657250
		{ &Z_Construct_UFunction_UTimeTrialUI_GetLapStartTime, "GetLapStartTime" }, // 333ade62b40de0d6f35d67f7d6b1ae420a7ca92f
		{ &Z_Construct_UFunction_UTimeTrialUI_StartRace, "StartRace" }, // 61794d67be7290532676184193193b398fce45cf
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTimeTrialUI>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UTimeTrialUI Property Definitions ****************************************
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_StartUIClass = { "StartUIClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UTimeTrialUI, StartUIClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UTimeTrialStartUI, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartUIClass_MetaData), NewProp_StartUIClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartUIClass,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UTimeTrialUI Property Definitions ******************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UTimeTrialUI,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x00A010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UTimeTrialUI_StaticRegisterNativesUTimeTrialUI()
{
	UClass* Class = UTimeTrialUI::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UTimeTrialUI;
UClass* Z_Construct_UClass_UTimeTrialUI(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UTimeTrialUI;
		if (!Z_Registration_Info_UClass_UTimeTrialUI.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("TimeTrialUI"),
				Z_Registration_Info_UClass_UTimeTrialUI.InnerSingleton,
				UTimeTrialUI_StaticRegisterNativesUTimeTrialUI,
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
		return Z_Registration_Info_UClass_UTimeTrialUI.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UTimeTrialUI.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTimeTrialUI.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UTimeTrialUI.OuterSingleton;
}
#undef UHT_STATICS
UTimeTrialUI::UTimeTrialUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UTimeTrialUI);
UTimeTrialUI::~UTimeTrialUI() {}
// ********** End Class UTimeTrialUI ***************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTimeTrialUI, TEXT("UTimeTrialUI"), &Z_Registration_Info_UClass_UTimeTrialUI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTimeTrialUI), 2591004759U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialUI_h__Script_AstheticDrive_d916923d4a760036fa2efbe0b4488de3b0d89cc3{
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
