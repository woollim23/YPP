// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class YPPTarget : TargetRules
{
	public YPPTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;

        ExtraModuleNames.AddRange(new string[] { "YPP", "YPPSetting" });
    }
}
