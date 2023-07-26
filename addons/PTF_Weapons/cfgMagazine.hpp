class cfgMagazines {
	class PylonRack_4Rnd_ACE_Hellfire_AGM114K;
	class FIR_Hydra_WP_P_7rnd_M;
	
	class PTF_FIR_Hydra_WP_P_7rnd_M : FIR_Hydra_WP_P_7rnd_M {
		hardpoints[] = {"RHS_HP_FFAR_USMC"};
		pylonWeapon = "PTF_FIR_RKT_Launcher";
	};
	class PTF_PylonRack_4Rnd_ACE_Hellfire_AGM114K :PylonRack_4Rnd_ACE_Hellfire_AGM114K {
		hardpoints[] = {"RHS_HP_FFAR_USMC", "RHS_HP_AIM9_HELI_USMC"};
		displayName = "4x AGM-114K [Hatchet]";
		ammo = "PTF_ACE_Hellfire_AGM114K";
		pylonWeapon = "PTF_ace_hellfire_launcher";
	};
};