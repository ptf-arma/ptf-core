class cfgAmmo {
	
	class PTF_ACE_Hellfire_AGM114K : ACE_Hellfire_AGM114K {        
		model = "\PTF_Weapons\Weapons\HellFireStolenFromHatchet.p3d";
		proxyShape = "\PTF_Weapons\Weapons\HellFireStolenFromHatchet.p3d";
		class ace_missileguidance : ace_missileguidance{};
	};

	class ptf_B_12Gauge_Slug_NoCartridge : B_12Gauge_Slug_NoCartridge {
		hit = 0;
		class EventHandlers {
			init	= "_this call PTF_Fnc_BeanBag";
		};
	};

	class G_40mm_Smoke: SmokeShell {
		simulation = "shotSmoke";
		deflectionSlowDown = 0.3;
	};
};

