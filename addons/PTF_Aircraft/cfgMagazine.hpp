class cfgMagazines {
	// Built on the stock 2x AGM-114R rack (USAF_AGM114_C), which the MQ-9 pylons
	// already list, rather than on USAF_1Rnd_AGM114_4Rack: that class is forward-
	// declared by USAF_AGM114_C and only defined later by USAF_BRU_C (RPT: "base
	// class was a empty forward declaration"), so it is not a reliable parent.
	class USAF_PylonRack_2Rnd_AGM114R;
	class PTF_PylonRack_4Rnd_AGM114R: USAF_PylonRack_2Rnd_AGM114R
	{
		ammo = "USAF_AGM114R_AG";
		count = 4;
		mirrorMissilesIndexes[] = {4,3,2,1};
		mass = 300;
		displayName = "4x AGM-114R Hellfire II";
		displayNameShort = "AGM114R";
		model = "\USAF_missilebox\USAF_BRU_LAU\AGM114HellfirePod.p3d";
		descriptionShort = "Hellfire Air-to-Surface Missile (ASM)\n  Guidance: Laser\n  Max Range: 8 km\n  Warhead: 31 lb (14 kg) Multi-function warhead\n  Cost: 99,600 USD";
		// PTF tag plus the stock USAF 4-rack tag, so any pylon that takes a USAF
		// 4x Hellfire rack also takes this one.
		hardpoints[] = {"B_MISSILE_AGM114R_4","B_MISSILE_AGM114P_4"};
		pylonWeapon = "PTF_AGM114R_Launcher";
	};
};
