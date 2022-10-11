////////////////////////////////////////////////////////////////////
//DeRap: DIHatUSMC\config.bin
//Produced from mikero's Dos Tools Dll version 7.97
//https://mikero.bytex.digital/Downloads
//'now' is Fri Apr 02 14:30:21 2021 : 'file' last modified on Wed Feb 07 18:28:47 2018
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class USMC_DI_HAT
	{
		units[] = {};
		weapons[] = {"USMC_DI_HAT"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Characters_F"};
	};
};
class cfgWeapons
{
	class ItemCore;
	class HeadgearItem;
	class USMC_DI_HAT: ItemCore
	{
		scope = 2;
		weaponPoolAvailable = 1;
		displayName = "Campaign Cover [http://www.paramarinetaskforce.com/]";
		picture = "DIHatUSMC\UI\DS_UI.paa";
		model = "DIHatUSMC\USMC_DI_HAT.p3d";
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
		class ItemInfo: HeadgearItem
		{
			mass = 2;
			allowedSlots[] = {901,701,605};
			uniformModel = "DIHatUSMC\USMC_DI_HAT.p3d";
			modelSides[] = {6};
			armor = "0*0";
			passThrough = 0.8;
			hiddenSelections[] = {"camo"};
		};
	};
};
