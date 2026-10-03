// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeTrialStartUI.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeTimeTrialStartUI() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UFunction* Z_Construct_UDelegateFunction_AstheticDrive_CountdownFinishedDelegate__DelegateSignature(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UTimeTrialStartUI(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UTimeTrialStartUI(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FCountdownFinishedDelegate ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_AstheticDrive_CountdownFinishedDelegate__DelegateSignature_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialStartUI.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCountdownFinishedDelegate constinit property declarations ************
// ********** End Delegate FCountdownFinishedDelegate constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive, nullptr, "CountdownFinishedDelegate__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UDelegateFunction_AstheticDrive_CountdownFinishedDelegate__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FCountdownFinishedDelegate **********************************************

// ********** Begin Class UTimeTrialStartUI Function BP_StartCountdown *****************************
static FName NAME_UTimeTrialStartUI_BP_StartCountdown = FName(TEXT("BP_StartCountdown"));
void UTimeTrialStartUI::BP_StartCountdown()
{
	UFunction* Func = FindFunctionChecked(NAME_UTimeTrialStartUI_BP_StartCountdown);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeTrialStartUI_BP_StartCountdown_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Countdown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Passes control to Blueprint to animate the race countdown. FinishCountdown should be called to start the race when it's done. */" },
#endif
		{ "DisplayName", "Start Countdown" },
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialStartUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Passes control to Blueprint to animate the race countdown. FinishCountdown should be called to start the race when it's done." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_StartCountdown constinit property declarations *********************
// ********** End Function BP_StartCountdown constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeTrialStartUI, nullptr, "BP_StartCountdown", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UTimeTrialStartUI_BP_StartCountdown(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UTimeTrialStartUI Function BP_StartCountdown *******************************

// ********** Begin Class UTimeTrialStartUI Function FinishCountdown *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UTimeTrialStartUI_FinishCountdown_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Countdown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Finishes the countdown and starts the race. */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialStartUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Finishes the countdown and starts the race." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FinishCountdown constinit property declarations ***********************
// ********** End Function FinishCountdown constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UTimeTrialStartUI, nullptr, "FinishCountdown", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UTimeTrialStartUI_FinishCountdown(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UTimeTrialStartUI::execFinishCountdown)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FinishCountdown();
	P_NATIVE_END;
}
// ********** End Class UTimeTrialStartUI Function FinishCountdown *********************************

// ********** Begin Class UTimeTrialStartUI ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UTimeTrialStartUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A race start countdown widget.\n *  The countdown animation is performed by widget animation.\n *  Calls a delegate when the countdown is done to start the race.\n */" },
#endif
		{ "IncludePath", "Variant_TimeTrial/UI/TimeTrialStartUI.h" },
		{ "ModuleRelativePath", "Variant_TimeTrial/UI/TimeTrialStartUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A race start countdown widget.\nThe countdown animation is performed by widget animation.\nCalls a delegate when the countdown is done to start the race." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UTimeTrialStartUI constinit property declarations ************************
// ********** End Class UTimeTrialStartUI constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FinishCountdown"), .Pointer = &UTimeTrialStartUI::execFinishCountdown },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTimeTrialStartUI_BP_StartCountdown, "BP_StartCountdown" }, // 0e1528ba8e188b176158dfe7f9b97c0a656ac253
		{ &Z_Construct_UFunction_UTimeTrialStartUI_FinishCountdown, "FinishCountdown" }, // 9db3353f4e7d9b588cd8e974c43daed3615d3795
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTimeTrialStartUI>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UTimeTrialStartUI,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x00A010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UTimeTrialStartUI_StaticRegisterNativesUTimeTrialStartUI()
{
	UClass* Class = UTimeTrialStartUI::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UTimeTrialStartUI;
UClass* Z_Construct_UClass_UTimeTrialStartUI(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UTimeTrialStartUI;
		if (!Z_Registration_Info_UClass_UTimeTrialStartUI.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("TimeTrialStartUI"),
				Z_Registration_Info_UClass_UTimeTrialStartUI.InnerSingleton,
				UTimeTrialStartUI_StaticRegisterNativesUTimeTrialStartUI,
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
		return Z_Registration_Info_UClass_UTimeTrialStartUI.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UTimeTrialStartUI.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTimeTrialStartUI.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UTimeTrialStartUI.OuterSingleton;
}
#undef UHT_STATICS
UTimeTrialStartUI::UTimeTrialStartUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UTimeTrialStartUI);
UTimeTrialStartUI::~UTimeTrialStartUI() {}
// ********** End Class UTimeTrialStartUI **********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialStartUI_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTimeTrialStartUI, TEXT("UTimeTrialStartUI"), &Z_Registration_Info_UClass_UTimeTrialStartUI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTimeTrialStartUI), 4151775417U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_UI_TimeTrialStartUI_h__Script_AstheticDrive_d9269b965a773e08882dbc5e3bcbe1ddd2569b54{
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
