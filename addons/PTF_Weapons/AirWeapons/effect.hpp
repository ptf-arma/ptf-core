class PTF_WPExplosion : FIR_WPExplosion
{
	class LightExp 
	{
		simulation = "light";
		type = "ExploLight";
		position[] = {
				0, 0, 0
		};
		intensity = 0.001000;
		interval = 1;
		lifeTime = 1;
	};

	class Explosion1 
	{
		simulation = "particles";
		type = "FIR_WPCloud";
		position[] = {
				0, 0, 0
		};
		intensity = 1;
		interval = 1;
		lifeTime = 30;
	};

	class Trails 
	{
		simulation = "particles";
		type = "WPTrails";
		position[] = {
				0, 0, 0
		};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class FireDamage1 
	{
		simulation = "particles";
		type = "FIR_FireDamage1";
	};	
};