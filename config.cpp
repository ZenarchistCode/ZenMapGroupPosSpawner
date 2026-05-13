/*
	(c) 2025 | ZenMapgroupPosSpawner | Zenarchist
*/

class CfgPatches
{
	class ZenMapgroupPosSpawner
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"ZenModCore"
		};
	};
};

class CfgMods
{
	class ZenMapgroupPosSpawner
	{
		author = "Zenarchist";
		type = "mod";
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenMapgroupPosSpawner/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenMapgroupPosSpawner/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenMapgroupPosSpawner/scripts/5_Mission"
				};
			};
		};
	};
};

class CfgVehicles
{
	class Zen_InvisibleNonInteractableObject;
	class ZenMapGroupPosSpawner : Zen_InvisibleNonInteractableObject
	{
		scope = 1;
	};

	class ZenMapGroupPosSpawner_GarbageBin2 : ZenMapGroupPosSpawner
	{
		scope = 2;
		zenHookObjectP3D="DZ\structures_bliss\Residential\Misc\Garbage_Bin2.p3d";
	};
};