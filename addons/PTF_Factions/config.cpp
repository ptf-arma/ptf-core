class CfgPatches
{
	class O_CUArmy
	{
		units[]=
		{
			"PTF_Factions_Cuba_Rifleman",
			"PTF_Factions_Cuba_Grenadier",
			"PTF_Factions_Cuba_Machinegunner",
			"PTF_Factions_Cuba_Squadlead",
			"PTF_Factions_Cuba_AT",
			"PTF_Factions_Cuba_Medic",
			"PTF_Factions_Cuba_KORD6T7",
			"PTF_Factions_Cuba_KORD6U16",
			"PTF_Factions_Cuba_NSV6T7",
			"PTF_Factions_Cuba_SPG9M",
			"PTF_Factions_Cuba_Sniper",
			"PTF_Factions_Cuba_Kornet",
			"PTF_Factions_Cuba_BTR60PB",
			"PTF_Factions_Cuba_BTR70",
			"PTF_Factions_Cuba_BTR80",
			"PTF_Factions_Cuba_Podnos",
			"PTF_Factions_Cuba_2A18MD30A",
			"PTF_Factions_Cuba_UAZ",
			"PTF_Factions_Cuba_BMP1",
			"PTF_Factions_Cuba_BMP1P",
			"PTF_Factions_Cuba_BMP1K",
			"PTF_Factions_Cuba_BMP1D",
			"PTF_Factions_Cuba_BRDM2",
			"PTF_Factions_Cuba_BRDM2UM",
			"PTF_Factions_Cuba_GAZ66",
			"PTF_Factions_Cuba_GAZ66_Flatbed",
			"PTF_Factions_Cuba_GAZ66_R142N",
			"PTF_Factions_Cuba_GAZ66_ESB8IM",
			"PTF_Factions_Cuba_GAZ66_AP2",
			"PTF_Factions_Cuba_GAZ66_Ammo",
			"PTF_Factions_Cuba_GAZ66_ZU23",
			"PTF_Factions_Cuba_Mi24P",
			"PTF_Factions_Cuba_Mi8_MT",
			"PTF_Factions_Cuba_Mi8_MTV",
			"PTF_Factions_Cuba_Mig29S",
			"PTF_Factions_Cuba_2S1",
			"PTF_Factions_Cuba_2S3M1",
			"PTF_Factions_Cuba_T72B",
			"PTF_Factions_Cuba_ZSU23",
			"PTF_Factions_Cuba_BM21",
			"PTF_Factions_Cuba_PTSM",
			"PTF_Factions_Cuba_PRP",
			"PTF_Factions_Cuba_BMK",
			"PTF_Factions_Cuba_BRM",
			"PTF_Factions_Cuba_BDM1",
			"PTF_Factions_Cuba_Officer",
			"PTF_Factions_Cuba_Crewman",
			"PTF_Factions_Cuba_Pilot",
			"PTF_Factions_Cuba_9K38"
		};
		weapons[]={};
		requiredVersion=1.01;
		requiredAddons[]={
		};
		author="Paramarine Task Force";
	};
};
class CfgVehicles
{
	#include "cfgImport.hpp"
    #include "Factions\cfgFactionCuba.hpp"
};
class CfgFactionClasses
{
    #include "cfgFactionClasses.hpp"
};
class CfgGroups
{
    class EAST
    {
        #include "cfgGroups.hpp"
    };
};