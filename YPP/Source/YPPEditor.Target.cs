// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class YPPEditorTarget : TargetRules
{
	public YPPEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;

        ExtraModuleNames.AddRange(new string[] { "YPP", "YPPSetting" });
    }
}
