// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeTrialTrackGate.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeTimeTrialTrackGate() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_ATimeTrialTrackGate(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_ATimeTrialTrackGate(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ATimeTrialTrackGate ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ATimeTrialTrackGate_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A track gate volume for a Time Trial racing game.\n *  Players must pass through the track gates in order to complete a lap.\n */" },
#endif
		{ "IncludePath", "Variant_TimeTrial/TimeTrialTrackGate.h" },
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialTrackGate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A track gate volume for a Time Trial racing game.\nPlayers must pass through the track gates in order to complete a lap." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionBox_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Collision Box */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialTrackGate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collision Box" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsFinishLine_MetaData[] = {
		{ "Category", "Track Gate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If this is set to true, this track gate is considered the finish line and will increase the lap when passed */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialTrackGate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If this is set to true, this track gate is considered the finish line and will increase the lap when passed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextMarker_MetaData[] = {
		{ "Category", "Track Gate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pointer to the next track marker in the sequence */" },
#endif
		{ "ModuleRelativePath", "Variant_TimeTrial/TimeTrialTrackGate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pointer to the next track marker in the sequence" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ATimeTrialTrackGate constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionBox;
	static void NewProp_bIsFinishLine_SetBit(void* Obj)
	{
		((ATimeTrialTrackGate*)Obj)->bIsFinishLine = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFinishLine;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NextMarker;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ATimeTrialTrackGate constinit property declarations ************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATimeTrialTrackGate>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ATimeTrialTrackGate Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CollisionBox = { "CollisionBox", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialTrackGate, CollisionBox), Z_Construct_UClass_UBoxComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionBox_MetaData), NewProp_CollisionBox_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsFinishLine = { "bIsFinishLine", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ATimeTrialTrackGate), &UHT_STATICS::NewProp_bIsFinishLine_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsFinishLine_MetaData), NewProp_bIsFinishLine_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NextMarker = { "NextMarker", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ATimeTrialTrackGate, NextMarker), Z_Construct_UClass_ATimeTrialTrackGate, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextMarker_MetaData), NewProp_NextMarker_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CollisionBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsFinishLine,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NextMarker,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ATimeTrialTrackGate Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ATimeTrialTrackGate,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_ATimeTrialTrackGate;
UClass* Z_Construct_UClass_ATimeTrialTrackGate(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ATimeTrialTrackGate;
		if (!Z_Registration_Info_UClass_ATimeTrialTrackGate.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("TimeTrialTrackGate"),
				Z_Registration_Info_UClass_ATimeTrialTrackGate.InnerSingleton,
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
		return Z_Registration_Info_UClass_ATimeTrialTrackGate.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ATimeTrialTrackGate.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATimeTrialTrackGate.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ATimeTrialTrackGate.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATimeTrialTrackGate);
ATimeTrialTrackGate::~ATimeTrialTrackGate() {}
// ********** End Class ATimeTrialTrackGate ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialTrackGate_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATimeTrialTrackGate, TEXT("ATimeTrialTrackGate"), &Z_Registration_Info_UClass_ATimeTrialTrackGate, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATimeTrialTrackGate), 983339943U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_Variant_TimeTrial_TimeTrialTrackGate_h__Script_AstheticDrive_ee0dd162f0457200c6e6da957df5447298478eb7{
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
