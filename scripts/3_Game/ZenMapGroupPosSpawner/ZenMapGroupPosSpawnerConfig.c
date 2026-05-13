/*
Steps:
1. Define a .cpp entry which has zenHookObjectP3D="validP3dPath" and inherits from "Zen_MapGroupProtoSpawner"
2. Run DayZ editor with your custom .cpp files in a custom mod
3. Open loot editor on the custom Zen_MapGroupProtoSpawner object
4. Place spawn locations - exit - copy mapgroupproto to .xml and edit values
5. Run server with mod added and add your custom ZenMapGroupProtoSpawner map to ZenMapGroupPosSpawnerConfig
  -> p3d: Zen_MapGroupProtoSpawnerObject

6.... or, just dump the mapgrouppos.xml entries and create your own mapgroupproto.xml and guess the spawn coordinates.
Use flags="32" on the spawn point XML entry to force objects to spawn on surface - eg:

		<group name="Land_ZenTreeHouse_Ladder" lootmax="2">
			<usage name="Hunting" />
			<container name="lootFloor" lootmax="2">
				<category name="weapons" />
				<tag name="floor" />
				<point pos="-2.121422 5.601023 0.994468" range="1" height="1" flags="32" /> 
			</container>
		</group>
*/

ref ZenMapGroupPosSpawnerConfig g_ZenMapGroupPosSpawnerConfig;

static ZenMapGroupPosSpawnerConfig GetZenMapGroupPosSpawnerConfig()
{
	if (!g_ZenMapGroupPosSpawnerConfig)
		GetZenConfigRegister().RegisterConfig(ZenMapGroupPosSpawnerConfig);

	return g_ZenMapGroupPosSpawnerConfig;
}

modded class ZenConfigRegister
{
	override void RegisterPreload()
	{
		super.RegisterPreload();
		RegisterType(ZenMapGroupPosSpawnerConfig); // auto-create + auto-load
	}
}

class ZenMapGroupPosSpawnerConfig : ZenObjectHookConfigBase
{
	override string    	GetCurrentVersion()   		{ return "1.29.2"; }
	
	// -------------------------
	// CONFIG SETTINGS
	// -------------------------
	override void OnRegistered()
	{
		g_ZenMapGroupPosSpawnerConfig = this;
	}
	
	override ZenObjectHookDbBase GetDB()
	{
		return GetZenMapGroupPosSpawnerDB();
	}

	override bool ReadJson(string path, out string err)
	{
		return JsonFileLoader<ZenMapGroupPosSpawnerConfig>.LoadFile(path, this, err);
	}

	override bool WriteJson(string path, out string err)
	{
		return JsonFileLoader<ZenMapGroupPosSpawnerConfig>.SaveFile(path, this, err);
	}

	// -------------------------
	// CONFIG VARIABLES
	// -------------------------
	float MaxAngleThreshold;
	
	override void SetDefaults()
	{
		super.SetDefaults();
		
		MaxAngleThreshold = 9999;
		
		SpawnMapGroupPosXML = true;
		SpawnObjects = false;

		// Parent static tokens + offsets
		SpawnHooks.Insert(new ZenObjectHookDef("Garbage_Bin2.p3d", "Zen_MapGroupProtoSpawner_GarbageBin2", "0 0 0", "0 0 0", 1, 1.0));
	}
}