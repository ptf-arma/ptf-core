class cfgMagazines {

	class PTF_12Gauge_Bean5 : 2Rnd_12Gauge_Slug {
		displayName = "BeanBag Rounds";
		descriptionShort = "BeanBag";
		ammo = "ptf_B_12Gauge_Slug_NoCartridge";
		count = 5;
		model = "";
		modelSpecial = "";
	};
		class PTF_12Gauge_Bean8 : 2Rnd_12Gauge_Slug {
		displayName = "BeanBag Rounds";
		descriptionShort = "BeanBag";
		ammo = "ptf_B_12Gauge_Slug_NoCartridge";
		count = 8;
		model = "";
		modelSpecial = "";
	};

	class PTF_FIR_Hydra_WP_P_7rnd_M : FIR_Hydra_WP_P_7rnd_M {
		hardpoints[] = {"RHS_HP_FFAR_USMC"};
		pylonWeapon = "PTF_FIR_RKT_Launcher";
	};

	class PTF_rhs_mag_AGM114M_2 : rhs_mag_AGM114M_2 {
		hardpoints[] = {"RHS_HP_FFAR_USMC"};
		pylonWeapon = "PTF_rhs_weap_AGM114M_base_Launcher";
		ammo = "PTF_ACE_Hellfire_AGM114K";
	};
	class ibr_throwable_stone: HandGrenade
	{
		author = "IceBreakr";
		model = "\A3\Weapons_f\ammo\stone_2";
		displayName = "Rock from Larta";
		cost = 1;
		displayNameShort = "Rock from Larta";
		ammo = "ibr_stone_grenade";
		mass = "0.1";
	};
};
