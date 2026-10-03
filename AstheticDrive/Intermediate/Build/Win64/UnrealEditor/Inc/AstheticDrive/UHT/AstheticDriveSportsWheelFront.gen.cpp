// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AstheticDriveSportsWheelFront.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeAstheticDriveSportsWheelFront() {}

// ********** Begin Cross Module References ********************************************************
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveSportsWheelFront(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveWheelFront(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_UAstheticDriveSportsWheelFront(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UAstheticDriveSportsWheelFront *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UAstheticDriveSportsWheelFront_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Front wheel definition for Sports Car.\n */" },
#endif
		{ "IncludePath", "SportsCar/AstheticDriveSportsWheelFront.h" },
		{ "ModuleRelativePath", "SportsCar/AstheticDriveSportsWheelFront.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Front wheel definition for Sports Car." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAstheticDriveSportsWheelFront constinit property declarations ***********
// ********** End Class UAstheticDriveSportsWheelFront constinit property declarations *************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAstheticDriveSportsWheelFront>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UAstheticDriveWheelFront,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UAstheticDriveSportsWheelFront,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UAstheticDriveSportsWheelFront;
UClass* Z_Construct_UClass_UAstheticDriveSportsWheelFront(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UAstheticDriveSportsWheelFront;
		if (!Z_Registration_Info_UClass_UAstheticDriveSportsWheelFront.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("AstheticDriveSportsWheelFront"),
				Z_Registration_Info_UClass_UAstheticDriveSportsWheelFront.InnerSingleton,
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
		return Z_Registration_Info_UClass_UAstheticDriveSportsWheelFront.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UAstheticDriveSportsWheelFront.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAstheticDriveSportsWheelFront.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UAstheticDriveSportsWheelFront.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAstheticDriveSportsWheelFront);
UAstheticDriveSportsWheelFront::~UAstheticDriveSportsWheelFront() {}
// ********** End Class UAstheticDriveSportsWheelFront *********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_SportsCar_AstheticDriveSportsWheelFront_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAstheticDriveSportsWheelFront, TEXT("UAstheticDriveSportsWheelFront"), &Z_Registration_Info_UClass_UAstheticDriveSportsWheelFront, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAstheticDriveSportsWheelFront), 1700970155U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_SportsCar_AstheticDriveSportsWheelFront_h__Script_AstheticDrive_096fabaedc95177defb004d3532829de5ecbaa4b{
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
