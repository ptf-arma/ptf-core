class cfgWeapons {

	class PTF_FIR_RKT_Launcher : FIR_RKT_Launcher {
		magazines[] = {"PTF_FIR_Hydra_WP_P_7rnd_M"};
	};

	class PTF_rhs_weap_AGM114M_base_Launcher: rhs_weap_AGM114M_base_Launcher {
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