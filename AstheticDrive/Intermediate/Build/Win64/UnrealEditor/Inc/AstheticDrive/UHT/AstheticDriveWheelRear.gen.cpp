// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AstheticDriveWheelRear.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeAstheticDriveWheelRear() {}

// ********** Begin Cross Module References ********************************************************
CHAOSVEHICLES_API UClass* Z_Construct_UClass_UChaosVehicleWheel(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveWheelRear(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveWheelRear(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UAstheticDriveWheelRear **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UAstheticDriveWheelRear_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Base rear wheel definition.\n */" },
#endif
		{ "IncludePath", "AstheticDriveWheelRear.h" },
		{ "ModuleRelativePath", "AstheticDriveWheelRear.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base rear wheel definition." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAstheticDriveWheelRear constinit property declarations ******************
// ********** End Class UAstheticDriveWheelRear constinit property declarations ********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAstheticDriveWheelRear>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UChaosVehicleWheel,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UAstheticDriveWheelRear,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UAstheticDriveWheelRear;
UClass* Z_Construct_UClass_UAstheticDriveWheelRear(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UAstheticDriveWheelRear;
		if (!Z_Registration_Info_UClass_UAstheticDriveWheelRear.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("AstheticDriveWheelRear"),
				Z_Registration_Info_UClass_UAstheticDriveWheelRear.InnerSingleton,
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
		return Z_Registration_Info_UClass_UAstheticDriveWheelRear.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UAstheticDriveWheelRear.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAstheticDriveWheelRear.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UAstheticDriveWheelRear.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAstheticDriveWheelRear);
UAstheticDriveWheelRear::~UAstheticDriveWheelRear() {}
// ********** End Class UAstheticDriveWheelRear ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDriveWheelRear_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAstheticDriveWheelRear, TEXT("UAstheticDriveWheelRear"), &Z_Registration_Info_UClass_UAstheticDriveWheelRear, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAstheticDriveWheelRear), 3387953265U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_AstheticDriveWheelRear_h__Script_AstheticDrive_497cbc33dfd4e82e4df842e39e556ff03ab9fc4f{
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
