class cfgWepaons {
	
	class PTF_ace_hellfire_launcher : ace_hellfire_launcher {
		magazines[] = {"PTF_PylonRack_4Rnd_ACE_Hellfire_AGM114K"};
	};

	class PTF_FIR_RKT_Launcher : FIR_RKT_Launcher {
		magazines[] = {"PTF_FIR_Hydra_WP_P_7rnd_M"}:
		class Far_AI : Far_AI;
		class Single : Single;
		class Burst : burst;
	};
};