class CfgPatches
{
	class PTF_Headgear
	{
		weapons[] = {"PTF_DI_COVER"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Characters_F"};
	};
};
class cfgWeapons
{
	class ItemCore;
	class HeadgearItem;
	class USMC_DI_COVER: ItemCore
	{
		scope = 2;
		weaponPoolAvailable = 1;
		displayName = "[PTF] DI Cover [http://www.paramarinetaskforce.com/]";
		author = "Paramarine Task Force";
		picture = "\assets\PTF_DICoverUSMC\UI\DS_UI.paa";
		model = "\assets\PTF_DICoverUSMC\DICover.p3d";
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
		class ItemInfo : HeadgearItem
		{
			mass = 2;
			allowedSlots[] = {901, 701, 605};
			uniformModel = "\assets\PTF_DICoverUSMC\DICover.p3d";
			modelSides[] = {6};
			armor = "0*0";
			passThrough = 0.8;
			hiddenSelections[] = {"camo"};
		};
	};
};
