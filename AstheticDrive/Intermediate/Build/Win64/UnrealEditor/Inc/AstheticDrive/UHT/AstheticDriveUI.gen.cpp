// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AstheticDriveUI.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeAstheticDriveUI() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveUI(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveUI(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UAstheticDriveUI Function OnGearUpdate ***********************************
struct AstheticDriveUI_eventOnGearUpdate_Parms
{
	int32 NewGear;
};
static FName NAME_UAstheticDriveUI_OnGearUpdate = FName(TEXT("OnGearUpdate"));
void UAstheticDriveUI::OnGearUpdate(int32 NewGear)
{
	AstheticDriveUI_eventOnGearUpdate_Parms Parms;
	Parms.NewGear=NewGear;
	UFunction* Func = FindFunctionChecked(NAME_UAstheticDriveUI_OnGearUpdate);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAstheticDriveUI_OnGearUpdate_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Vehicle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Implemented in Blueprint to display the new gear */" },
#endif
		{ "ModuleRelativePath", "AstheticDriveUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Implemented in Blueprint to display the new gear" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnGearUpdate constinit property declarations **************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewGear;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnGearUpdate constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnGearUpdate Property Definitions *************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NewGear = { "NewGear", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AstheticDriveUI_eventOnGearUpdate_Parms, NewGear), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewGear,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnGearUpdate Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAstheticDriveUI, nullptr, "OnGearUpdate", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<AstheticDriveUI_eventOnGearUpdate_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(AstheticDriveUI_eventOnGearUpdate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAstheticDriveUI_OnGearUpdate(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UAstheticDriveUI Function OnGearUpdate *************************************

// ********** Begin Class UAstheticDriveUI Function OnSpeedUpdate **********************************
struct AstheticDriveUI_eventOnSpeedUpdate_Parms
{
	float NewSpeed;
};
static FName NAME_UAstheticDriveUI_OnSpeedUpdate = FName(TEXT("OnSpeedUpdate"));
void UAstheticDriveUI::OnSpeedUpdate(float NewSpeed)
{
	AstheticDriveUI_eventOnSpeedUpdate_Parms Parms;
	Parms.NewSpeed=NewSpeed;
	UFunction* Func = FindFunctionChecked(NAME_UAstheticDriveUI_OnSpeedUpdate);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAstheticDriveUI_OnSpeedUpdate_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Vehicle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Implemented in Blueprint to display the new speed */" },
#endif
		{ "ModuleRelativePath", "AstheticDriveUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Implemented in Blueprint to display the new speed" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnSpeedUpdate constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSpeedUpdate constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSpeedUpdate Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewSpeed = { "NewSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AstheticDriveUI_eventOnSpeedUpdate_Parms, NewSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewSpeed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnSpeedUpdate Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAstheticDriveUI, nullptr, "OnSpeedUpdate", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<AstheticDriveUI_eventOnSpeedUpdate_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(AstheticDriveUI_eventOnSpeedUpdate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAstheticDriveUI_OnSpeedUpdate(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UAstheticDriveUI Function OnSpeedUpdate ************************************

// ********** Begin Class UAstheticDriveUI *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UAstheticDriveUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple Vehicle HUD class\n *  Displays the current speed and gear.\n *  Widget setup is handled in a Blueprint subclass.\n */" },
#endif
		{ "IncludePath", "AstheticDriveUI.h" },
		{ "ModuleRelativePath", "AstheticDriveUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple Vehicle HUD class\nDisplays the current speed and gear.\nWidget setup is handled in a Blueprint subclass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMPH_MetaData[] = {
		{ "Category", "Vehicle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Controls the display of speed in Km/h or MPH */" },
#endif
		{ "ModuleRelativePath", "AstheticDriveUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Controls the display of speed in Km/h or MPH" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAstheticDriveUI constinit property declarations *************************
	static void NewProp_bIsMPH_SetBit(void* Obj)
	{
		((UAstheticDriveUI*)Obj)->bIsMPH = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMPH;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAstheticDriveUI constinit property declarations ***************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAstheticDriveUI_OnGearUpdate, "OnGearUpdate" }, // 9824a903fb3a4380c6d6ee2d386a8a61028a91e3
		{ &Z_Construct_UFunction_UAstheticDriveUI_OnSpeedUpdate, "OnSpeedUpdate" }, // d86ddfabd49b050505226f9ae189003b7115eb90
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAstheticDriveUI>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UAstheticDriveUI Property Definitions ************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsMPH = { "bIsMPH", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UAstheticDriveUI), &UHT_STATICS::NewProp_bIsMPH_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMPH_MetaData), NewProp_bIsMPH_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsMPH,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UAstheticDriveUI Property Definitions **************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UAstheticDriveUI,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UAstheticDriveUI;
UClass* Z_Construct_UClass_UAstheticDriveUI(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UAstheticDriveUI;
		if (!Z_Registration_Info_UClass_UAstheticDriveUI.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("AstheticDriveUI"),
				Z_Registration_Info_UClass_UAstheticDriveUI.InnerSingleton,
				nullptr,
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
		return Z_Registration_Info_UClass_UAstheticDriveUI.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UAstheticDriveUI.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAstheticDriveUI.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UAstheticDriveUI.OuterSingleton;
}
#undef UHT_STATICS
UAstheticDriveUI::UAstheticDriveUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAstheticDriveUI);
UAstheticDriveUI::~UAstheticDriveUI() {}
// ********** End Class UAstheticDriveUI ***********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDriveUI_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAstheticDriveUI, TEXT("UAstheticDriveUI"), &Z_Registration_Info_UClass_UAstheticDriveUI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAstheticDriveUI), 1336483550U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDriveUI_h__Script_AstheticDrive_0f281541cec16b08ce474c22f2cadad2a3618210{
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
