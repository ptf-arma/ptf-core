class cfgWeapons {

	class PTF_rhs_weap_AGM114M_base_Launcher: rhs_weap_AGM114M_base_Launcher 
	{
		magazines[] = {"PTF_rhs_mag_AGM114M_2"};
	};
	class Throw: GrenadeLauncher
	{
		muzzles[] += {"throwable_Grenade_Muzzle"};
		class ThrowMuzzle;
		class throwable_Grenade_Muzzle: ThrowMuzzle
		{
			magazines[] = {"ibr_throwable_stone"};
		};
	};
};
