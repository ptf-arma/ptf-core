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

	class PTF_rhs_mag_AGM114M_2 : rhs_mag_AGM114M_2 {
		hardpoints[] = {"RHS_HP_FFAR_USMC"};
		pylonWeapon = "PTF_rhs_weap_AGM114M_base_Launcher";
	};
};
