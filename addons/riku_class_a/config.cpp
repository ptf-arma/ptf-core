#define _ARMA_

class CfgPatches
{
	class riku_class_a
	{
		units[] = {};
		weapons[] = {};
		requiredVersion="0.1";
		requiredAddons[]=
		{
			"PTF_Main",
			"A3_Characters_F"
		};
	};
};

class EventHandlers;
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class HitPoints
		{
			class HitFace;
			class HitNeck;
			class HitHead;
			class HitPelvis;
			class HitAbdomen;
			class HitDiaphragm;
			class HitChest;
			class HitBody;
			class HitArms;
			class HitHands;
			class HitLegs;
		};
	};
	class SoldierWB: CAManBase{};
	class B_Soldier_base_F: SoldierWB{};
	class riku_class_a_ab_inf_base: B_Soldier_base_F
	{
		scope = 1;
		author = "rikugun";
		side = 1;
		identityTypes[] = {"LanguageENG_F","Head_EURO","LIB_Glasses"};
		genericNames = "EnglishMen";
		editorPreview = "";
		magazines[] = {};
		respawnMagazines[] = {};
		uniformClass = "U_US_class_A_ab_inf";
		allowedHeadgear[] = {};
		headgearList[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
		model = "riku_class_a\riku_EM.p3d";
		hiddenSelections[] = {"camo","camo2","rank","insignia"};
		hiddenSelectionsTextures[] = {"riku_class_a\data\em_decor_co.paa","riku_class_a\data\prewar lapels\EN_AB_INF.paa","",""};
		backpack = "";
		class Wounds
		{
			tex[] = {};
			mat[] = {"a3\characters_f\heads\data\hl_white_bald_muscular.rvmat","a3\characters_f\heads\data\hl_white_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_white_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_black_bald_muscular.rvmat","a3\characters_f\heads\data\hl_black_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_black_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_white_hairy_muscular.rvmat","a3\characters_f\heads\data\hl_white_hairy_muscular_injury.rvmat","a3\characters_f\heads\data\hl_white_hairy_muscular_injury.rvmat","a3\characters_f\heads\data\hl_white_old.rvmat","a3\characters_f\heads\data\hl_white_old_injury.rvmat","a3\characters_f\heads\data\hl_white_old_injury.rvmat","a3\characters_f\heads\data\hl_asian_bald_muscular.rvmat","a3\characters_f\heads\data\hl_asian_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_asian_bald_muscular_injury.rvmat"};
		};
	};
	class riku_class_a_ab_inf_SecondLT: riku_class_a_ab_inf_base
	{
		scope = 1;
		author = "Paramarine Task Force";
		uniformClass = "U_US_class_A_ab_inf_SecLT";
		model = "riku_class_a\riku_CA.p3d";
		hiddenSelections[] = {"camo","camo2","rank","insignia"};
		hiddenSelectionsTextures[] = {"riku_class_a\data\CA_co_3.paa","riku_class_a\data\prewar lapels\CO_AB_INF_2.paa","riku_class_a\data\ranks\13) 2lt.paa",""};
		class Wounds
		{
			tex[] = {};
			mat[] = {"a3\characters_f\heads\data\hl_white_bald_muscular.rvmat","a3\characters_f\heads\data\hl_white_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_white_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_black_bald_muscular.rvmat","a3\characters_f\heads\data\hl_black_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_black_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_white_hairy_muscular.rvmat","a3\characters_f\heads\data\hl_white_hairy_muscular_injury.rvmat","a3\characters_f\heads\data\hl_white_hairy_muscular_injury.rvmat","a3\characters_f\heads\data\hl_white_old.rvmat","a3\characters_f\heads\data\hl_white_old_injury.rvmat","a3\characters_f\heads\data\hl_white_old_injury.rvmat","a3\characters_f\heads\data\hl_asian_bald_muscular.rvmat","a3\characters_f\heads\data\hl_asian_bald_muscular_injury.rvmat","a3\characters_f\heads\data\hl_asian_bald_muscular_injury.rvmat"};
		};
	};
	class riku_class_a_ab_inf_FirstLT: riku_class_a_ab_inf_SecondLT
	{
		uniformClass = "U_US_class_A_ab_inf_FirstLT";
		hiddenSelectionsTextures[] = {"riku_class_a\data\CA_co_3.paa","riku_class_a\data\prewar lapels\CO_AB_INF_2.paa","riku_class_a\data\ranks\12) 1lt.paa",""};
	};
	class riku_class_a_ab_inf_cpt: riku_class_a_ab_inf_SecondLT
	{
		uniformClass = "U_US_class_A_ab_inf_cpt";
		hiddenSelectionsTextures[] = {"riku_class_a\data\CA_co_3.paa","riku_class_a\data\prewar lapels\CO_AB_INF_2.paa","riku_class_a\data\ranks\14) cpt.paa",""};
	};
	class riku_class_a_ab_inf_enlisted: riku_class_a_ab_inf_SecondLT
	{
		uniformClass = "U_US_class_A_ab_inf_enlisted";
		hiddenSelectionsTextures[] = {"riku_class_a\data\CA_co_3.paa","riku_class_a\data\prewar lapels\CO_AB_INF_2.paa","",""};
	};
};
class cfgWeapons
{
	class Uniform_Base;
	class ItemCore;
	class U_BasicBody: Uniform_Base
	{
		class ItemInfo;
	};
	class U_rike_BasicBody: U_BasicBody
	{
		author = "Simcardigs";
		scope = 0;
		displayName = "nuffign";
		model = "riku_class_a\suitpack_ca.p3d";
		picture = "riku_class_a\icons\riku_em.paa";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"riku_class_a\data\em_co.paa"};
		class ItemInfo: ItemInfo
		{
			containerClass = "Supply30";
			mass = 20;
		};
	};
	class U_US_class_A_ab_inf_SecLT: U_rike_BasicBody
	{
		scope = 2;
		author = "Paramarine Task Force";
		displayName = "Service Alpha, O-1 [PTF]";
		model = "riku_class_a\suitpack_ca.p3d";
		picture = "riku_class_a\icons\riku_ca.paa";
		descriptionShort = "Coats, Wool, Elastique, Officer's, O.D.";
		hiddenSelectionsTextures[] = {"riku_class_a\data\ca_co.paa"};
		class ItemInfo: ItemInfo
		{
			uniformClass = "riku_class_a_ab_inf_SecondLT";
		};
	};
	class U_US_class_A_ab_inf_FirstLT: U_US_class_A_ab_inf_SecLT
	{
		author = "Paramarine Task Force";
		displayName = "Service Alpha, O-2 [PTF]";
		descriptionShort = "Coats, Wool, Elastique, Officer's, O.D.";
		class ItemInfo: ItemInfo
		{
			uniformClass = "riku_class_a_ab_inf_FirstLT";
		};
	};
	class U_US_class_A_ab_inf_Cpt: U_US_class_A_ab_inf_SecLT
	{
		author = "Paramarine Task Force";
		displayName = "Service Alpha, O-3 [PTF]";
		descriptionShort = "Coats, Wool, Elastique, Officer's, O.D.";
		class ItemInfo: ItemInfo
		{
			uniformClass = "riku_class_a_ab_inf_Cpt";
		};
	};
	class U_US_class_A_ab_inf_enlisted: U_US_class_A_ab_inf_SecLT
	{
		author = "Paramarine Task Force";
		displayName = "Service Alpha, Enlisted [PTF]";
		descriptionShort = "Coats, Wool, Elastique, Enlisted, O.D.";
		class ItemInfo: ItemInfo
		{
			uniformClass = "riku_class_a_ab_inf_enlisted";
		};
	};
	class H_Booniehat_khk;
	class HeadgearItem;
	class r_Garrison_cap_base_en: H_Booniehat_khk
	{
		scope = 0;
		author = "Courtland";
		_generalMacro = "Garrison_cap";
		displayName = "US Garrison Cap Base Enlisted";
		picture = "";
		model = "riku_class_a\GarrisonCap.p3d";
		hiddenSelections[] = {"camo","camo1","rank"};
		hiddenSelectionsTextures[] = {"riku_class_a\data\enlisted\EN_Gar_INF.paa","",""};
		allowedFacewear[] = {""};
		class ItemInfo: HeadgearItem
		{
			mass = 10;
			hiddenSelections[] = {"camo","camo1","rank"};
			hiddenSelectionsTextures[] = {"riku_class_a\data\enlisted\EN_Gar_INF.paa","",""};
			uniformModel = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_SLA\CUP_SLA_officer_hat.p3d";
			modelSides[] = {6};
		};
	};
	class r_Garrison_cap_AB_inf: r_Garrison_cap_base_en
	{
		scope = 0;
		author = "Courtland";
		_generalMacro = "Garrison_cap_AB";
		displayName = "US Garrison Cap Airborne Infantry Enlisted";
		picture = "";
		model = "riku_class_a\GarrisonCap.p3d";
		hiddenSelections[] = {"camo","camo1","rank"};
		hiddenSelectionsTextures[] = {"riku_class_a\data\enlisted\EN_Gar_INF.paa","riku_class_a\data\patches\ab_inf_garrison.paa",""};
		allowedFacewear[] = {""};
		class ItemInfo: HeadgearItem
		{
			mass = 10;
			hiddenSelections[] = {"camo","camo1","rank"};
			hiddenSelectionsTextures[] = {"riku_class_a\data\enlisted\EN_Gar_INF.paa","riku_class_a\data\patches\ab_inf_garrison.paa",""};
			uniformModel = "riku_class_a\GarrisonCap.p3d";
			modelSides[] = {6};
		};
	};
	class r_Garrison_cap_AB_inf_2LT: r_Garrison_cap_AB_inf
	{
		scope = 2;
		author = "Paramarine Task Force";
		_generalMacro = "Garrison_cap_AB_1LT";
		model = "riku_class_a\GarrisonCap_off.p3d";
		displayName = "Garrison Cap [PTF]";
		hiddenSelections[] = {"camo","camo1","rank"};
		hiddenSelectionsTextures[] = {"riku_class_a\data\officer\CO_Gar_PTF.paa","","riku_class_a\data\ranks\cap_ega_officer.paa"};
		class ItemInfo: HeadgearItem
		{
			mass = 10;
			hiddenSelections[] = {"camo","camo1","rank"};
			hiddenSelectionsTextures[] = {"riku_class_a\data\officer\CO_Gar_PTF.paa","","riku_class_a\data\ranks\cap_ega_officer.paa"};
			uniformModel = "riku_class_a\GarrisonCap_off.p3d";
			modelSides[] = {6};
		};
	};
};
