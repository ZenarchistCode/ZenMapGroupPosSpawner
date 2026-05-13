modded class ZenObjectHookSpawner
{
	override bool DoesObjectPassChecks(Object obj)
	{
	    if (!obj)
	        return false;
		
		float maxAngleThreshold = GetZenMapGroupPosSpawnerConfig().MaxAngleThreshold;
	
	    if (maxAngleThreshold <= 0)
	        return true;
	
	    vector orientation = obj.GetOrientation();
	
	    float pitch = Math.AbsFloat(orientation[1]);
	    float roll = Math.AbsFloat(orientation[2]);
	
	    if (pitch > 180)
	        pitch = 360 - pitch;
	
	    if (roll > 180)
	        roll = 360 - roll;
	
	    if (pitch > maxAngleThreshold)
		{
			ZMPrint("[ZenMapGroupPosSpawner] Ignoring object " + obj + " @ " + obj.GetPosition() + " as pitch " + pitch + " > " + maxAngleThreshold);
	        return false;
		}
	
	    if (roll > maxAngleThreshold)
		{
			ZMPrint("[ZenMapGroupPosSpawner] Ignoring object " + obj + " @ " + obj.GetPosition() + " as roll " + roll + " > " + maxAngleThreshold);
	        return false;
		}
		
	    return true;
	}
}