// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AstheticDriveOffroadWheelRear.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeAstheticDriveOffroadWheelRear() {}

// ********** Begin Cross Module References ********************************************************
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveOffroadWheelRear(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveWheelRear(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveOffroadWheelRear(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UAstheticDriveOffroadWheelRear *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UAstheticDriveOffroadWheelRear_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Rear wheel definition for Offroad Car.\n */" },
#endif
		{ "IncludePath", "OffroadCar/AstheticDriveOffroadWheelRear.h" },
		{ "ModuleRelativePath", "OffroadCar/AstheticDriveOffroadWheelRear.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rear wheel definition for Offroad Car." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAstheticDriveOffroadWheelRear constinit property declarations ***********
// ********** End Class UAstheticDriveOffroadWheelRear constinit property declarations *************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAstheticDriveOffroadWheelRear>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UAstheticDriveWheelRear,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UAstheticDriveOffroadWheelRear,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UAstheticDriveOffroadWheelRear;
UClass* Z_Construct_UClass_UAstheticDriveOffroadWheelRear(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UAstheticDriveOffroadWheelRear;
		if (!Z_Registration_Info_UClass_UAstheticDriveOffroadWheelRear.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("AstheticDriveOffroadWheelRear"),
				Z_Registration_Info_UClass_UAstheticDriveOffroadWheelRear.InnerSingleton,
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
		return Z_Registration_Info_UClass_UAstheticDriveOffroadWheelRear.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UAstheticDriveOffroadWheelRear.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAstheticDriveOffroadWheelRear.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UAstheticDriveOffroadWheelRear.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAstheticDriveOffroadWheelRear);
UAstheticDriveOffroadWheelRear::~UAstheticDriveOffroadWheelRear() {}
// ********** End Class UAstheticDriveOffroadWheelRear *********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_OffroadCar_AstheticDriveOffroadWheelRear_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAstheticDriveOffroadWheelRear, TEXT("UAstheticDriveOffroadWheelRear"), &Z_Registration_Info_UClass_UAstheticDriveOffroadWheelRear, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAstheticDriveOffroadWheelRear), 2534636528U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_OffroadCar_AstheticDriveOffroadWheelRear_h__Script_AstheticDrive_6a9d85394f8e9ef57641746ebb4edd97ff45ba2d{
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
