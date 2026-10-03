// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AstheticDriveOffroadCar.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeAstheticDriveOffroadCar() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_AAstheticDriveOffroadCar(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_AAstheticDrivePawn(ETypeConstructPhase);
ASTHETICDRIVE_API UClass* Z_Construct_UClass_AAstheticDriveOffroadCar(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class AAstheticDriveOffroadCar *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AAstheticDriveOffroadCar_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Offroad car wheeled vehicle implementation\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "OffroadCar/AstheticDriveOffroadCar.h" },
		{ "ModuleRelativePath", "OffroadCar/AstheticDriveOffroadCar.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Offroad car wheeled vehicle implementation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chassis_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Chassis static mesh */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OffroadCar/AstheticDriveOffroadCar.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Chassis static mesh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TireFrontLeft_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** FL Tire static mesh */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OffroadCar/AstheticDriveOffroadCar.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FL Tire static mesh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TireFrontRight_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** FR Tire static mesh */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OffroadCar/AstheticDriveOffroadCar.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FR Tire static mesh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TireRearLeft_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** RL Tire static mesh */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OffroadCar/AstheticDriveOffroadCar.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "RL Tire static mesh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TireRearRight_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** RR Tire static mesh */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OffroadCar/AstheticDriveOffroadCar.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "RR Tire static mesh" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AAstheticDriveOffroadCar constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Chassis;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TireFrontLeft;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TireFrontRight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TireRearLeft;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TireRearRight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AAstheticDriveOffroadCar constinit property declarations *******************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAstheticDriveOffroadCar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AAstheticDriveOffroadCar Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Chassis = { "Chassis", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDriveOffroadCar, Chassis), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chassis_MetaData), NewProp_Chassis_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TireFrontLeft = { "TireFrontLeft", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDriveOffroadCar, TireFrontLeft), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TireFrontLeft_MetaData), NewProp_TireFrontLeft_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TireFrontRight = { "TireFrontRight", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDriveOffroadCar, TireFrontRight), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TireFrontRight_MetaData), NewProp_TireFrontRight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TireRearLeft = { "TireRearLeft", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDriveOffroadCar, TireRearLeft), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TireRearLeft_MetaData), NewProp_TireRearLeft_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TireRearRight = { "TireRearRight", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AAstheticDriveOffroadCar, TireRearRight), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TireRearRight_MetaData), NewProp_TireRearRight_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Chassis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TireFrontLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TireFrontRight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TireRearLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TireRearRight,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AAstheticDriveOffroadCar Property Definitions ******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AAstheticDrivePawn,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_AstheticDrive,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AAstheticDriveOffroadCar,
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
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_AAstheticDriveOffroadCar;
UClass* Z_Construct_UClass_AAstheticDriveOffroadCar(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AAstheticDriveOffroadCar;
		if (!Z_Registration_Info_UClass_AAstheticDriveOffroadCar.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("AstheticDriveOffroadCar"),
				Z_Registration_Info_UClass_AAstheticDriveOffroadCar.InnerSingleton,
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
		return Z_Registration_Info_UClass_AAstheticDriveOffroadCar.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AAstheticDriveOffroadCar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAstheticDriveOffroadCar.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AAstheticDriveOffroadCar.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AAstheticDriveOffroadCar);
AAstheticDriveOffroadCar::~AAstheticDriveOffroadCar() {}
// ********** End Class AAstheticDriveOffroadCar ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_OffroadCar_AstheticDriveOffroadCar_h__Script_AstheticDrive_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAstheticDriveOffroadCar, TEXT("AAstheticDriveOffroadCar"), &Z_Registration_Info_UClass_AAstheticDriveOffroadCar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAstheticDriveOffroadCar), 1139000363U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Astheic_Drive_AstheticDrive_Source_AstheticDrive_OffroadCar_AstheticDriveOffroadCar_h__Script_AstheticDrive_3a53dc50831be026a2d60a195098db5d159d2ea6{
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
