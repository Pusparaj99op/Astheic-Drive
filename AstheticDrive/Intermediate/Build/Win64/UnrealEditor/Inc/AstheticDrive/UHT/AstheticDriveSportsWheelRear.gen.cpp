// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AstheticDriveSportsWheelRear.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeAstheticDriveSportsWheelRear() {}

// ********** Begin Cross Module References ********************************************************
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveSportsWheelRear(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveWheelRear(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveSportsWheelRear(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UAstheticDriveSportsWheelRear ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UAstheticDriveSportsWheelRear_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Rear wheel definition for Sports Car.\n */" },
#endif
		{ "IncludePath", "SportsCar/AstheticDriveSportsWheelRear.h" },
		{ "ModuleRelativePath", "SportsCar/AstheticDriveSportsWheelRear.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rear wheel definition for Sports Car." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAstheticDriveSportsWheelRear constinit property declarations ************
// ********** End Class UAstheticDriveSportsWheelRear constinit property declarations **************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAstheticDriveSportsWheelRear>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UAstheticDriveWheelRear,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UAstheticDriveSportsWheelRear,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UAstheticDriveSportsWheelRear;
UClass* Z_Construct_UClass_UAstheticDriveSportsWheelRear(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UAstheticDriveSportsWheelRear;
		if (!Z_Registration_Info_UClass_UAstheticDriveSportsWheelRear.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("AstheticDriveSportsWheelRear"),
				Z_Registration_Info_UClass_UAstheticDriveSportsWheelRear.InnerSingleton,
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
		return Z_Registration_Info_UClass_UAstheticDriveSportsWheelRear.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UAstheticDriveSportsWheelRear.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAstheticDriveSportsWheelRear.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UAstheticDriveSportsWheelRear.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAstheticDriveSportsWheelRear);
UAstheticDriveSportsWheelRear::~UAstheticDriveSportsWheelRear() {}
// ********** End Class UAstheticDriveSportsWheelRear **********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_SportsCar_AstheticDriveSportsWheelRear_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAstheticDriveSportsWheelRear, TEXT("UAstheticDriveSportsWheelRear"), &Z_Registration_Info_UClass_UAstheticDriveSportsWheelRear, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAstheticDriveSportsWheelRear), 2976378300U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_SportsCar_AstheticDriveSportsWheelRear_h__Script_AstheticDrive_1dd1b63b01557bbe9cbf01fb932e5e7892a97124{
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
