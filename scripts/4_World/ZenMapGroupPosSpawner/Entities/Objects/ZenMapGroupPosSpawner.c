class ZenMapGroupPosSpawner extends BuildingSuper
{
	#ifdef DayZEditor
	Object m_ZenProxyObject;
	
	override void DeferredInit()
	{
		super.DeferredInit();
		
		if (m_ZenProxyObject != null)
			return;

		string p3dName = ConfigGetString("zenHookObjectP3D");
		if (p3dName != "")
		{
			m_ZenProxyObject = g_Game.CreateStaticObjectUsingP3D(p3dName, GetPosition(), GetOrientation(), 1);
			SetPosition(m_ZenProxyObject.GetPosition());
			SetOrientation(m_ZenProxyObject.GetOrientation());
			Update();
		}
		else 
		{
			Error("[ZenMapgroupPosSpawner] P3D not found! Ensure you have set up 'zenHookObjectP3D=p3dFilePath' correctly in .cpp");
		}
	}
	
	void ~ZenMapgroupPosSpawner()
	{
		if (g_Game && m_ZenProxyObject)
			g_Game.ObjectDelete(m_ZenProxyObject);
	}
	#endif
}