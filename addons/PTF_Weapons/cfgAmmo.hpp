class cfgAmmo {
	
	class M_Scalpel_AT;
	class ACE_Hellfire_AGM114K : M_Scalpel_AT {
		class ace_missileguidance;
	};

	class PTF_ACE_Hellfire_AGM114K : ACE_Hellfire_AGM114K {
		model = "\PTF_Weapons\Weapons\HellFireStolenFromHatchet.p3d";
		proxyShape = "\PTF_Weapons\Weapons\HellFireStolenFromHatchet.p3d";
		class ace_missileguidance : ace_missileguidance{};
	};
};