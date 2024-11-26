// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Robot_Protype_V3 : ModuleRules
{
	public Robot_Protype_V3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
