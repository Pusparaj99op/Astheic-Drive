// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAstheticDrive_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
	ASTHETICDRIVE_API UFunction* Z_Construct_UDelegateFunction_AstheticDrive_CountdownFinishedDelegate__DelegateSignature(ETypeConstructPhase);
	ASTHETICDRIVE_API UFunction* Z_Construct_UDelegateFunction_AstheticDrive_StartRaceDelegate__DelegateSignature(ETypeConstructPhase);
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_AstheticDrive;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_AstheticDrive(ETypeConstructPhase)
	{
		if (!Z_Registration_Info_UPackage__Script_AstheticDrive.OuterSingleton)
		{
		static FTypeConstructFunc* SingletonFuncArray[] = {
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_AstheticDrive_CountdownFinishedDelegate__DelegateSignature,
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_AstheticDrive_StartRaceDelegate__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/AstheticDrive",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xE31034BD,
			0xFF366911,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_AstheticDrive.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_AstheticDrive.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_AstheticDrive(Z_Construct_UPackage__Script_AstheticDrive, TEXT("/Script/AstheticDrive"), Z_Registration_Info_UPackage__Script_AstheticDrive, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xE31034BD, 0xFF366911));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
