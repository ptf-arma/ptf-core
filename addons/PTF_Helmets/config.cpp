class cfgPatches
{
	class PTF_Clothes
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = "0.1";
		requiredAddons[] = {
			"rhsusf_infantry",
			"USP_GEAR_Head",
			"PTF_Clothes"
			};
	};
};
class cfgWeapons
{
	class rhsusf_ach_helmet_headset_ucp_alt;
	class HitpointsProtectionInfo;
	class ItemInfo;
	class Head;
	class rhsusf_hgu56p_mask_black;
	class rhsusf_hgu56p_visor_mask_black;
	class rhsusf_hgu56p_visor_black;
	class PTF_Helmet_Infantry_Mich2000_S;
	class PTF_Helmet_Infantry_Mich2000_WD;
	class PTF_Helmet_Infantry_Mich2000_Headset_WD;
	class PTF_Helmet_Infantry_Mich2000_D;
	class USP_OPS_FASTXP_TAN;
	class USP_OPS_FASTXP_CO_TAN;
	class USP_OPS_FASTXP_CT_TAN;
	class USP_OPS_FASTXP_CU_TAN;
	class PTF_Helmet_FASTXP_TAN: USP_OPS_FASTXP_TAN
	{
		scopeArsenal = 2;
		scope = 2;
		side = 1;
		faction = "BLU_F";
		displayName = "[Inf] FAST XP (TAN)";
		author = "Paramarine Task Force";
		ace_hearing_protection = 0.8;
		ace_hearing_lowerVolume = 0;
		class ItemInfo: ItemInfo {
			mass = 20;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 6;
					passThrough = 0.5;
				};
			};
		};
	};
	class PTF_Helmet_FASTXP_CO_TAN: USP_OPS_FASTXP_CO_TAN
	{
		scopeArsenal = 2;
		scope = 2;
		side = 1;
		faction = "BLU_F";
		displayName = "[Inf] FAST XP CO (TAN)";
		author = "Paramarine Task Force";
		ace_hearing_protection = 0.8;
		ace_hearing_lowerVolume = 0;
		class ItemInfo: ItemInfo {
			mass = 20;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 6;
					passThrough = 0.5;
				};
			};
		};
	};
	class PTF_Helmet_FASTXP_CT_TAN: USP_OPS_FASTXP_CT_TAN
	{
		scopeArsenal = 2;
		scope = 2;
		side = 1;
		faction = "BLU_F";
		displayName = "[Inf] FAST XP CT (TAN)";
		author = "Paramarine Task Force";
		ace_hearing_protection = 0.8;
		ace_hearing_lowerVolume = 0;
		class ItemInfo: ItemInfo {
			mass = 20;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 6;
					passThrough = 0.5;
				};
			};
		};
	};
	class PTF_Helmet_FASTXP_CU_TAN: USP_OPS_FASTXP_CU_TAN
	{
		scopeArsenal = 2;
		scope = 2;
		side = 1;
		faction = "BLU_F";
		displayName = "[Inf] FAST XP CU (TAN)";
		author = "Paramarine Task Force";
		ace_hearing_protection = 0.8;
		ace_hearing_lowerVolume = 0;
		class ItemInfo: ItemInfo {
			mass = 20;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 6;
					passThrough = 0.5;
				};
			};
		};
	};
	// N.Cook Personal Helmets
	class PTF_Helmet_Cook_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (WD) [Personal - N.Cook]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_cook.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Cook_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (D) [Personal - N.Cook]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_cook.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Cook_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (S) [Personal - N.Cook]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_cook.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	// K.Black Personal Helmets
	class PTF_Helmet_Black_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (WD) [Personal - K.Black]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_black.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Black_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (D) [Personal - K.Black]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_black.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Black_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (S) [Personal - K.Black]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_black.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	// B.Chmielewski Personal Helmets
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (WD) [Personal - B.Chmielewski]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_chmielewski.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (D) [Personal - B.Chmielewski]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_chmielewski.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (S) [Personal - B.Chmielewski]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_chmielewski.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	// B.Gute Personal Helmets
	class PTF_Helmet_Gute_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (WD) [Personal - B.Gute]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_gute.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	// J.Phillips Personal Helmets
	class PTF_Helmet_Phillips_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (WD) [Personal - J.Phillips]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_phillips.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Phillips_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (S) [Personal - J.Phillips]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_phillips.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Phillips_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (D) [Personal - J.Phillips]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_phillips.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	// I.Nava Personal Helmets
	class PTF_Helmet_Nava_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (WD) [Personal - I.Nava]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_nava.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Nava_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (D) [Personal - I.Nava]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_nava.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Nava_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName = "[Inf] MICH 2000 (S) [Personal - I.Nava]";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_nava.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Harris_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (WD) [Personal - R.Harris]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_harris.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Harris_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (D) [Personal - R.Harris]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_harris.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Harris_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (S) [Personal - R.Harris]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_harris.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Baker_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (WD) [Personal - M.Baker]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_baker.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Baker_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (D) [Personal - M.Baker]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_baker.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Baker_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (S) [Personal - M.Baker]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_baker.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Taylor_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (WD) [Personal - G.Taylor]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_taylor.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Taylor_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (D) [Personal - G.Taylor]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_taylor.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Taylor_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (S) [Personal - G.Taylor]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_taylor.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
		class PTF_Helmet_Galvin_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (WD) [Personal - N.Galvin]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_Galvin.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Galvin_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (D) [Personal - N.Galvin]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_Galvin.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	//class PTF_Helmet_Galvin_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	//{
   	//	displayName = "[Inf] MICH 2000 (S) [Personal - N.Galvin]";
   	//	hiddenSelectionsTextures[] = {
    //   		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_Galvin.paa",
    //   		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	//};
	class PTF_Helmet_Havel_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (WD) [Personal - T.Havel]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_Havel.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Havel_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (D) [Personal - T.Havel]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_Havel.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Havel_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (S) [Personal - T.Havel]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_Havel.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Helmet_Holt_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (WD) [Personal - G.Holt]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_Holt.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Holt_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (D) [Personal - G.Holt]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_des_co_Holt.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};	
	class PTF_Helmet_Holt_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
   		displayName = "[Inf] MICH 2000 (S) [Personal - G.Holt]";
   		hiddenSelectionsTextures[] = {
       		"\z\PTF\addons\PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_Holt.paa",
       		"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};
	};
	class PTF_Gute_rhsusf_hgu56p_mask_black : rhsusf_hgu56p_visor_black {
		displayName = "[MAG] HGU [Personal - B.Gute]";
		hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\helmets\HUG_Gute.paa"};
	};
	class PTF_Smoll_rhsusf_hgu56p_mask_black : rhsusf_hgu56p_visor_black {
		displayName = "[MAG] HGU [Personal - S.Smoll]";
		hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_Smool.paa"};
	};
};
class cfgMods
{
	author = "Hawkins";
	timepacked = "1675880603";
};
