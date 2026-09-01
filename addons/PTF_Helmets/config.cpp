class cfgPatches
{
	class PTF_Helmets
	{
		units[]={};
		// The remaining helmets in this addon declare no scope of their own;
		// they inherit it from their PTF_Clothes / RHS / USP parents.
		weapons[]=
		{
			"PTF_Helmet_FASTXP_TAN",
			"PTF_Helmet_FASTXP_CO_TAN",
			"PTF_Helmet_FASTXP_CT_TAN",
			"PTF_Helmet_FASTXP_CU_TAN"
		};
		requiredVersion="0.1";
		requiredAddons[]=
		{
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
	class rhsusf_cvc_green_helmet;
	class rhsusf_cvc_green_alt_helmet;
	class USP_OPS_FASTXP_TAN;
	class USP_OPS_FASTXP_CO_TAN;
	class USP_OPS_FASTXP_CT_TAN;
	class USP_OPS_FASTXP_CU_TAN;
	class PTF_Helmet_Air_HMDS;
	class PTF_Helmet_Air_HMDS_Mask;
	class PTF_Helmet_FASTXP_TAN: USP_OPS_FASTXP_TAN
	{
		scopeArsenal=2;
		scope=2;
		side=1;
		faction="BLU_F";
		displayName="[Inf] FAST XP (TAN)";
		author="Paramarine Task Force";
		ace_hearing_protection=0.80000001;
		ace_hearing_lowerVolume=0;
		class ItemInfo: ItemInfo
		{
			mass=20;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=6;
					passThrough=0.5;
				};
			};
		};
	};
	class PTF_Helmet_FASTXP_CO_TAN: USP_OPS_FASTXP_CO_TAN
	{
		scopeArsenal=2;
		scope=2;
		side=1;
		faction="BLU_F";
		displayName="[Inf] FAST XP CO (TAN)";
		author="Paramarine Task Force";
		ace_hearing_protection=0.80000001;
		ace_hearing_lowerVolume=0;
		class ItemInfo: ItemInfo
		{
			mass=20;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=6;
					passThrough=0.5;
				};
			};
		};
	};
	class PTF_Helmet_FASTXP_CT_TAN: USP_OPS_FASTXP_CT_TAN
	{
		scopeArsenal=2;
		scope=2;
		side=1;
		faction="BLU_F";
		displayName="[Inf] FAST XP CT (TAN)";
		author="Paramarine Task Force";
		ace_hearing_protection=0.80000001;
		ace_hearing_lowerVolume=0;
		class ItemInfo: ItemInfo
		{
			mass=20;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=6;
					passThrough=0.5;
				};
			};
		};
	};
	class PTF_Helmet_FASTXP_CU_TAN: USP_OPS_FASTXP_CU_TAN
	{
		scopeArsenal=2;
		scope=2;
		side=1;
		faction="BLU_F";
		displayName="[Inf] FAST XP CU (TAN)";
		author="Paramarine Task Force";
		ace_hearing_protection=0.80000001;
		ace_hearing_lowerVolume=0;
		class ItemInfo: ItemInfo
		{
			mass=20;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=6;
					passThrough=0.5;
				};
			};
		};
	};
	class PTF_Helmet_Jameson_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - M.Jameson]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_jameson.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Jameson_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - M.Jameson]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_jameson.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Jameson_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - M.Jameson]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_jameson.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Wade_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - D.Wade]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_wade.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Wade_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - D.Wade]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_wade.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Wade_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - D.Wade]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_wade.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_C_Havel_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - C.Havel]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_c.havel.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_C_Havel_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - C.Havel]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_c.havel.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_C_Havel_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - C.Havel]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_c.havel.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Cook_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - N.Cook]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_cook.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Cook_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - N.Cook]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_cook.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Cook_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - N.Cook]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_cook.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Black_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - K.Black]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_black.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Black_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - K.Black]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_black.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Black_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - K.Black]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_black.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Chmielewski]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_chmielewski.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - B.Chmielewski]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_chmielewski.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - B.Chmielewski]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_chmielewski.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Gute_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Gute]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_gute.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Phillips_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - J.Phillips]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_phillips.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Phillips_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - J.Phillips]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_phillips.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Phillips_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - J.Phillips]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_phillips.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Nava_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - I.Nava]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_nava.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Nava_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - I.Nava]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_nava.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Nava_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - I.Nava]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_nava.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Harris_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - R.Harris]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_harris.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Harris_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - R.Harris]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_harris.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Harris_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - R.Harris]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_harris.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Baker_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - M.Baker]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_baker.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Baker_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - M.Baker]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_baker.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Baker_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - M.Baker]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_baker.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Taylor_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - G.Taylor]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_taylor.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Taylor_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - G.Taylor]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_taylor.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Taylor_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - G.Taylor]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_taylor.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Galvin_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - N.Galvin]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_Galvin.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Galvin_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - N.Galvin]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_Galvin.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Havel_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - T.Havel]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_Havel.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Havel_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - T.Havel]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_Havel.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Havel_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - T.Havel]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_Havel.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	// Jettison Helmets
	class PTF_Helmet_Jettison_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - S.Jettison]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_jettison.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Jettison_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - S.Jettison]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_jettison.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Jettison_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - S.Jettison]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_jettison.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	//  Holt Helmets
	class PTF_Helmet_Holt_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - G.Holt]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_Holt.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Holt_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - G.Holt]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_Holt.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Holt_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - G.Holt]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_Holt.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Lowe_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Lowe]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_lowe.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Lowe_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - B.Lowe]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_lowe.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Lowe_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - B.Lowe]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_lowe.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Soarin_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Soarin]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_Soarin.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Soarin_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - B.Soarin]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_soarin.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Soarin_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - B.Soarin]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_soarin.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
		class PTF_Helmet_Walker_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - K.Walker]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_walker.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
		class PTF_Helmet_Walker_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - K.Walker]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_walker.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
		class PTF_Helmet_Walker_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - K.Walker]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_walker.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
		class PTF_Helmet_Adams_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - T.Adams]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_adams.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
			class PTF_Helmet_Adams_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - T.Adams]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_adams.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
		class PTF_Helmet_Adams_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - T.Adams]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_adams.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
		class PTF_Helmet_Byrnes_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - M.Byrnes]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_byrnes.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
		class PTF_Helmet_Byrnes_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - M.Byrnes]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_byrnes.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
		class PTF_Helmet_Byrnes_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - M.Byrnes]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_byrnes.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Wolff_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Wolff]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_wolff.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Wolff_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - B.Wolff]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_wolff.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Wolff_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - B.Wolff]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_wolff.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Stroh_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - A.Stroh]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_stroh.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Stroh_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - A.Stroh]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_stroh.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_Stroh_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - A.Stroh]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_stroh.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Helmet_1_1_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1-1";
        hiddenSelectionsTextures[]=
        {
            "\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1_1.paa",
            "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
        };
    };
    class PTF_Helmet_1_2_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1-2";
        hiddenSelectionsTextures[]=
        {
            "\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1_2.paa",
            "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
        };
    };
    class PTF_Helmet_1_3_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1-3";
        hiddenSelectionsTextures[]=
        {
            "\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1_3.paa",
            "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
        };
    };
    class PTF_Helmet_1_4_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1-4";
        hiddenSelectionsTextures[]=
        {
            "\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1_4.paa",
            "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
        };
    };
	class PTF_Helmet_1st_plt_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1st Plt.";
        hiddenSelectionsTextures[]=
        {
            "\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1st_plt.paa",
            "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
        };
    };
    class PTF_Helmet_HQ_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) HQ";
        hiddenSelectionsTextures[]=
        {
            "\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_HQ.paa",
            "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
        };
    };
    class PTF_Helmet_Halstead_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - W.Halstead]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_halstead.paa",
			"rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
		};
	};
	class PTF_Goltred_rhsusf_hgu56p_visor_black : PTF_Helmet_Air_HMDS
	{
		displayName = "[MAG] HGU [Personal - F.Goltred] (Black)";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Textures\gear\helmets\MAG_Goltred_blk.paa"
		};
	};
	class PTF_Galvin_rhsusf_hgu56p_mask_black: PTF_Helmet_Air_HMDS_Mask
	{
		displayName="[MAG] HGU [Personal - N. Galvin - Mask] (Black)";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_Galvin.paa"
		};
	};
	class PTF_Galvin_rhsusf_hgu56p_visor_black: PTF_Helmet_Air_HMDS
	{
		displayName="[MAG] HGU [Personal - N. Galvin] (Black)";
		hiddenSelectionsTextures[] = {
			"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_Galvin.paa"
		};
	};
    class PTF_Gute_rhsusf_hgu56p_mask_black: rhsusf_hgu56p_visor_black
	{
		displayName="[MAG] HGU [Personal - B.Gute]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_Gute.paa"
		};
	};
	class PTF_Jesus_rhsusf_hgu56p_visor_black: rhsusf_hgu56p_visor_black
	{
		displayName="[MAG] HGU [Personal - S.Jesus]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_Jesus.paa"
		};
	};
	class PTF_Gustav_rhsusf_hgu56p_mask_black: rhsusf_hgu56p_visor_black
	{
		displayName="[MAG] HGU [Personal - T. Gustav]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_Gustav.paa"
		};
	};
	class PTF_David_rhsusf_hgu56p_mask_black: rhsusf_hgu56p_visor_black
	{
		displayName="[MAG] HGU [Personal - J. David]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_David.paa"
		};
	};
	class PTF_Halstead_rhsusf_hgu56p_mask_black: rhsusf_hgu56p_visor_black
	{
		displayName="[MAG] HGU [Personal - W. Halstead]";
		hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_Halstead.paa","\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_patches_empire_co.paa"};
	};
	class PTF_Halstead_rhsusf_hgu56p_mask_Visor_black: rhsusf_hgu56p_visor_mask_black
	{
		displayName="[MAG] HGU [Personal - W. Halstead - Mask]";
		hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_Halstead.paa","\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_patches_empire_co.paa"};
	};
	class PTF_ACV_3_4: rhsusf_cvc_green_alt_helmet
	{
		displayName=" [ACV] Crewman Helmet [Team - 3-4]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_cvc_green_alt_co_3-4.paa"
		};
	};
	class PTF_ACV_3_2: rhsusf_cvc_green_alt_helmet
	{
		displayName=" [ACV] Crewman Helmet [Team - 3-2]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_cvc_green_alt_co_3-2.paa"
		};
	};
	class PTF_ACV_3_3: rhsusf_cvc_green_alt_helmet
	{
		displayName=" [ACV] Crewman Helmet [Team - 3-3]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_cvc_green_alt_co_3-3.paa"
		};
	};
	class PTF_ACV_3_1: rhsusf_cvc_green_alt_helmet
	{
		displayName=" [ACV] Crewman Helmet [Team - 3-1]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_cvc_green_alt_co_3-1.paa"
		};
	};
	class PTF_ACV_David_rhsusf_cvc_green_alt: rhsusf_cvc_green_alt_helmet
	{
		displayName=" [ACV] Crewman Helmet [Personal - J.David]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_cvc_green_alt_co_david.paa"
		};
	};
	class PTF_ACV_Chmielewski_rhsusf_cvc_green_alt: rhsusf_cvc_green_alt_helmet
	{
		displayName=" [ACV] Crewman Helmet [Personal - B.Chmielewski]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_cvc_green_alt_co_chmielewski.paa"
		};
	};
};

class cfgMods
{
	author="Hawkins";
	timepacked="1732036966";
};
