class cfgMagazines {
	
	class PylonRack_4Rnd_ACE_Hellfire_AGM114K;

	class FIR_Hydra_WP_P_7rnd_M;

	class VehicleMagazine;
	class rhs_mag_Hellfire_base : VehicleMagazine{};
	class rhs_mag_AGM114K : rhs_mag_Hellfire_base{};
	class rhs_mag_AGM114M : rhs_mag_AGM114K{};
	class rhs_mag_AGM114M_2 : rhs_mag_AGM114M{};
	class rhs_mag_AGM114M_4 : rhs_mag_AGM114M_2{};


	
	class PTF_FIR_Hydra_WP_P_7rnd_M : FIR_Hydra_WP_P_7rnd_M {
		hardpoints[] = {"RHS_HP_FFAR_USMC"};
		pylonWeapon = "PTF_FIR_RKT_Launcher";
	};

	class PTF_rhs_mag_AGM114M_2 : rhs_mag_AGM114M_2 {
		hardpoints[] = {"RHS_HP_FFAR_USMC"};
		pylonWeapon = "PTF_rhs_weap_AGM114M_base_Launcher";
		ammo = "PTF_ACE_Hellfire_AGM114K"
	};
	//class PTF_rhs_mag_AGM114M_4 : rhs_mag_AGM114M_4 {
		//hardpoints[] = {"RHS_HP_FFAR_USMC"};
		//pylonWeapon = "PTF_rhs_weap_AGM114M_base_Launcher";
	//};

	//class PTF_PylonRack_4Rnd_ACE_Hellfire_AGM114K :PylonRack_4Rnd_ACE_Hellfire_AGM114K {
		//hardpoints[] = {"RHS_HP_FFAR_USMC", "RHS_HP_AIM9_HELI_USMC"};
		//displayName = "4x AGM-114K [Hatchet]";
		//ammo = "PTF_ACE_Hellfire_AGM114K";
		//pylonWeapon = "PTF_ace_hellfire_launcher";
	//};
};