// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ThirdPersonHW_1 : ModuleRules
{
	public ThirdPersonHW_1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ThirdPersonHW_1",
			"ThirdPersonHW_1/Variant_Platforming",
			"ThirdPersonHW_1/Variant_Platforming/Animation",
			"ThirdPersonHW_1/Variant_Combat",
			"ThirdPersonHW_1/Variant_Combat/AI",
			"ThirdPersonHW_1/Variant_Combat/Animation",
			"ThirdPersonHW_1/Variant_Combat/Gameplay",
			"ThirdPersonHW_1/Variant_Combat/Interfaces",
			"ThirdPersonHW_1/Variant_Combat/UI",
			"ThirdPersonHW_1/Variant_SideScrolling",
			"ThirdPersonHW_1/Variant_SideScrolling/AI",
			"ThirdPersonHW_1/Variant_SideScrolling/Gameplay",
			"ThirdPersonHW_1/Variant_SideScrolling/Interfaces",
			"ThirdPersonHW_1/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
