class cfgWeapons {

	class rhs_weap_M320;
	
	//class ace_hellfire_launcher;
	class FIR_RKT_Launcher;

	class  rhs_weap_AGM114M_base_Launcher;

	//class PTF_ace_hellfire_launcher : ace_hellfire_launcher {
		//magazines[] = {"PTF_PylonRack_4Rnd_ACE_Hellfire_AGM114K"};
	//};

	class PTF_FIR_RKT_Launcher : FIR_RKT_Launcher {
		magazines[] = {"PTF_FIR_Hydra_WP_P_7rnd_M"};
	};

	class PTF_rhs_weap_AGM114M_base_Launcher: rhs_weap_AGM114M_base_Launcher {
		magazines[] = {"PTF_rhs_mag_AGM114M_2"};
	};

	class PTF_rhs_weap_M320 : rhs_weap_M320 {
		type = 4;
	};
};