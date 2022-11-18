// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SkybrawlProject2022 : ModuleRules
{
	public SkybrawlProject2022(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
