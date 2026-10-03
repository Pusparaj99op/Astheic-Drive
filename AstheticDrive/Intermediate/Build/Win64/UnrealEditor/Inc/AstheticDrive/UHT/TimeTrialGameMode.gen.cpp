// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeTrialGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeTimeTrialGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_ATimeTrialGameMode(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_ATimeTrialGameMode(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ATimeTrialGameMode *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ATimeTrialGameMode_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A simple GameMode for a Time Trial racing game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Variant_TimeTrial/TimeTrialGameMode.h" },
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple GameMode for a Time Trial racing game" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinishTag_MetaData[] = {
		{ "Category", "Time Trial" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Actor tag used to find the finish line marker on the level */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Actor tag used to find the finish line marker on the level" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Laps_MetaData[] = {
		{ "Category", "Time Trial" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of laps for the race */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of laps for the race" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfLocalPlayers_MetaData[] = {
		{ "Category", "Local Multiplayer" },
		{ "ClampMax", "4" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Determines how many local players should be spawned on game start */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Determines how many local players should be spawned on game start" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ATimeTrialGameMode constinit property declarations ***********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_FinishTag;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Laps;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfLocalPlayers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ATimeTrialGameMode constinit property declarations *************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATimeTrialGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ATimeTrialGameMode Property Definitions **********************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_FinishTag = { "FinishTag", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialGameMode, FinishTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinishTag_MetaData), NewProp_FinishTag_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Laps = { "Laps", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialGameMode, Laps), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Laps_MetaData), NewProp_Laps_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NumberOfLocalPlayers = { "NumberOfLocalPlayers", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialGameMode, NumberOfLocalPlayers), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumberOfLocalPlayers_MetaData), NewProp_NumberOfLocalPlayers_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FinishTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Laps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NumberOfLocalPlayers,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ATimeTrialGameMode Property Definitions ************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AGameModeBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ATimeTrialGameMode,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_ATimeTrialGameMode;
UClass* Z_Construct_UClass_ATimeTrialGameMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ATimeTrialGameMode;
		if (!Z_Registration_Info_UClass_ATimeTrialGameMode.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("TimeTrialGameMode"),
				Z_Registration_Info_UClass_ATimeTrialGameMode.InnerSingleton,
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
		return Z_Registration_Info_UClass_ATimeTrialGameMode.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ATimeTrialGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATimeTrialGameMode.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ATimeTrialGameMode.OuterSingleton;
}
#undef UHT_STATICS
ATimeTrialGameMode::ATimeTrialGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATimeTrialGameMode);
ATimeTrialGameMode::~ATimeTrialGameMode() {}
// ********** End Class ATimeTrialGameMode *********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialGameMode_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATimeTrialGameMode, TEXT("ATimeTrialGameMode"), &Z_Registration_Info_UClass_ATimeTrialGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATimeTrialGameMode), 2489899671U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialGameMode_h__Script_AstheticDrive_69759732aa28282c6f699913b16ba6de2dc0bb6c{
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
