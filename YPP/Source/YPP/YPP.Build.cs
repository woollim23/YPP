// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class YPP : ModuleRules
{
	public YPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "EnhancedInput", "NavigationSystem", "AIModule", "GameplayTasks", "YPPSetting"});

		PrivateDependencyModuleNames.AddRange(new string[] { "YPPSetting" });
	}
}
