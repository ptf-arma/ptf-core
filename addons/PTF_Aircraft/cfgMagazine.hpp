class cfgMagazines {
	class USAF_1Rnd_AGM114_4Rack;
	class PTF_PylonRack_4Rnd_AGM114R: USAF_1Rnd_AGM114_4Rack
	{
		ammo = "USAF_AGM114R_AG";
		count = 4;
		mirrorMissilesIndexes[] = {4,3,2,1};
		mass = 300;
		displayName = "4x AGM-114R Hellfire II";
		displayNameShort = "AGM114R";
		model = "\USAF_missilebox\USAF_BRU_LAU\AGM114HellfirePod.p3d";
		descriptionShort = "Hellfire Air-to-Surface Missile (ASM)\n  Guidance: Laser\n  Max Range: 8 km\n  Warhead: 31 lb (14 kg) Multi-function warhead\n  Cost: 99,600 USD";
		hardpoints[] = {"B_MISSILE_AGM114R_4"};
		pylonWeapon = "PTF_AGM114R_Launcher";
	};
};