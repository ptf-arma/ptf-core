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

	class SmokeShell;
	class SmokeShellBlue;
	class SmokeShellGreen;
	class SmokeShellOrange;
	class SmokeShellPurple;
	class SmokeShellRed;
	class SmokeShellYellow;

//40mm
	class G_40mm_Smoke: SmokeShell {
		simulation = "shotSmoke";
		deflectionSlowDown = 0.3;
	};
};

