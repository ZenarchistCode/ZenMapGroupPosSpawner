ref ZenMapGroupPosSpawnerDB g_ZenMapGroupPosSpawnerDB;

static ZenMapGroupPosSpawnerDB GetZenMapGroupPosSpawnerDB()
{
	if (!g_ZenMapGroupPosSpawnerDB) GetZenConfigRegister().RegisterConfig(ZenMapGroupPosSpawnerDB);
	return g_ZenMapGroupPosSpawnerDB;
}

modded class ZenConfigRegister
{
	override void RegisterPreload()
	{
		super.RegisterPreload();
		RegisterType(ZenMapGroupPosSpawnerDB);
	}
}

class ZenMapGroupPosSpawnerDB: ZenObjectHookDbBase
{
	// -------------------------
	// CONFIG SETTINGS
	// -------------------------
	override void OnRegistered()
	{
		g_ZenMapGroupPosSpawnerDB = this;
	}

	override bool ReadJson(string path, out string err)
	{
		return JsonFileLoader<ZenMapGroupPosSpawnerDB>.LoadFile(path, this, err);
	}

	override bool WriteJson(string path, out string err)
	{
		return JsonFileLoader<ZenMapGroupPosSpawnerDB>.SaveFile(path, this, err);
	}
}