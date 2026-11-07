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
// Declared at file root, not in cfgWeapons: a stub in there becomes a fake weapon
// called ItemInfo, which the engine then tries to create and logs errors about.
#include "\z\PTF\addons\PTF_Clothes\helmets\cfgHelmetMacros.hpp"
class ItemInfo;
class cfgWeapons
{
	class rhsusf_ach_helmet_headset_ucp_alt;
	class rhsusf_hgu56p_mask_black;
	class rhsusf_hgu56p_visor_black;
	class PTF_Helmet_Infantry_Mich2000_S;
	class PTF_Helmet_Infantry_Mich2000_WD;
	class PTF_Helmet_Infantry_Mich2000_Headset_WD;
	class PTF_Helmet_Infantry_Mich2000_D;
	class rhsusf_cvc_green_helmet;
	class rhsusf_cvc_green_alt_helmet;
	class rhsusf_cvc_green_ess;
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
		PTF_HELMET_ITEMINFO
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
		PTF_HELMET_ITEMINFO
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
		PTF_HELMET_ITEMINFO
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
		PTF_HELMET_ITEMINFO
	};
	class PTF_Helmet_Jameson_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - M.Jameson]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_jameson.paa")
	};
	class PTF_Helmet_Jameson_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - M.Jameson]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_jameson.paa")
	};
	class PTF_Helmet_Jameson_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - M.Jameson]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_jameson.paa")
	};
	class PTF_Helmet_Wade_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - D.Wade]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_wade.paa")
	};
	class PTF_Helmet_Wade_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - D.Wade]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_wade.paa")
	};
	class PTF_Helmet_Wade_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - D.Wade]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_wade.paa")
	};
	class PTF_Helmet_C_Havel_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - C.Havel]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_c.havel.paa")
	};
	class PTF_Helmet_C_Havel_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - C.Havel]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_c.havel.paa")
	};
	class PTF_Helmet_C_Havel_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - C.Havel]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_c.havel.paa")
	};
	class PTF_Helmet_Cook_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - N.Cook]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_cook.paa")
	};
	class PTF_Helmet_Cook_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - N.Cook]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_cook.paa")
	};
	class PTF_Helmet_Cook_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - N.Cook]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_cook.paa")
	};
	class PTF_Helmet_Black_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - K.Black]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_black.paa")
	};
	class PTF_Helmet_Black_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - K.Black]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_black.paa")
	};
	class PTF_Helmet_Black_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - K.Black]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_black.paa")
	};
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Chmielewski]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_chmielewski.paa")
	};
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - B.Chmielewski]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_chmielewski.paa")
	};
	class PTF_Helmet_Chmielewski_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - B.Chmielewski]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_chmielewski.paa")
	};
	class PTF_Helmet_Gute_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Gute]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_gute.paa")
	};
	class PTF_Helmet_Phillips_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - J.Phillips]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_phillips.paa")
	};
	class PTF_Helmet_Phillips_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - J.Phillips]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_phillips.paa")
	};
	class PTF_Helmet_Phillips_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - J.Phillips]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_phillips.paa")
	};
	class PTF_Helmet_Nava_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - I.Nava]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_nava.paa")
	};
	class PTF_Helmet_Nava_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - I.Nava]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_nava.paa")
	};
	class PTF_Helmet_Nava_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - I.Nava]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_nava.paa")
	};
	class PTF_Helmet_Harris_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - R.Harris]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_harris.paa")
	};
	class PTF_Helmet_Harris_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - R.Harris]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_harris.paa")
	};
	class PTF_Helmet_Harris_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - R.Harris]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_harris.paa")
	};
	class PTF_Helmet_Baker_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - M.Baker]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_baker.paa")
	};
	class PTF_Helmet_Baker_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - M.Baker]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_baker.paa")
	};
	class PTF_Helmet_Baker_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - M.Baker]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_baker.paa")
	};
	class PTF_Helmet_Taylor_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - G.Taylor]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_taylor.paa")
	};
	class PTF_Helmet_Taylor_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - G.Taylor]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_taylor.paa")
	};
	class PTF_Helmet_Taylor_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - G.Taylor]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_taylor.paa")
	};
	class PTF_Helmet_Galvin_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - N.Galvin]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_Galvin.paa")
	};
	class PTF_Helmet_Galvin_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - N.Galvin]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_Galvin.paa")
	};
	class PTF_Helmet_Havel_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - T.Havel]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_Havel.paa")
	};
	class PTF_Helmet_Havel_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - T.Havel]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_Havel.paa")
	};
	class PTF_Helmet_Havel_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - T.Havel]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_Havel.paa")
	};
	// Jettison Helmets
	class PTF_Helmet_Jettison_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - S.Jettison]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_jettison.paa")
	};
	class PTF_Helmet_Jettison_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - S.Jettison]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_jettison.paa")
	};
	class PTF_Helmet_Jettison_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - S.Jettison]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_jettison.paa")
	};
	class PTF_Helmet_Lowe_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Lowe]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_lowe.paa")
	};
	class PTF_Helmet_Lowe_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - B.Lowe]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_lowe.paa")
	};
	class PTF_Helmet_Lowe_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - B.Lowe]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_lowe.paa")
	};
		class PTF_Helmet_Walker_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - K.Walker]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_walker.paa")
	};
		class PTF_Helmet_Walker_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - K.Walker]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_walker.paa")
	};
		class PTF_Helmet_Walker_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - K.Walker]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_walker.paa")
	};
		class PTF_Helmet_Adams_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - T.Adams]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_adams.paa")
	};
			class PTF_Helmet_Adams_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - T.Adams]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_adams.paa")
	};
		class PTF_Helmet_Adams_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - T.Adams]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_adams.paa")
	};
	class PTF_Helmet_Wolff_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - B.Wolff]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_wolff.paa")
	};
	class PTF_Helmet_Wolff_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - B.Wolff]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_wolff.paa")
	};
	class PTF_Helmet_Wolff_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - B.Wolff]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_wolff.paa")
	};
	class PTF_Helmet_Stroh_Infantry_Mich2000_WD: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (WD) [Personal - A.Stroh]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_wd_co_stroh.paa")
	};
	class PTF_Helmet_Stroh_Infantry_Mich2000_D: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (D) [Personal - A.Stroh]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_stroh.paa")
	};
	class PTF_Helmet_Stroh_Infantry_Mich2000_S: PTF_Helmet_Infantry_Mich2000_Headset_WD
	{
		displayName="[Inf] MICH 2000 (S) [Personal - A.Stroh]";
		PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_snow_co_stroh.paa")
	};
	class PTF_Helmet_1_1_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1-1";
        PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1_1.paa")
    };
    class PTF_Helmet_1_2_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1-2";
        PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1_2.paa")
    };
    class PTF_Helmet_1_3_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1-3";
        PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1_3.paa")
    };
    class PTF_Helmet_1_4_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1-4";
        PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1_4.paa")
    };
	class PTF_Helmet_1st_plt_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) 1st Plt.";
        PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_1st_plt.paa")
    };
    class PTF_Helmet_HQ_Infantry_Mich2000_DES: PTF_Helmet_Infantry_Mich2000_Headset_WD
    {
        displayName="[Inf] MICH 2000 (D) HQ";
        PTF_MICH_TEXTURES("\z\PTF\addons\PTF_Textures\gear\helmets\ptf_mich_covered_rhino_des_co_HQ.paa")
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
	class PTF_David_rhsusf_hgu56p_mask_black: rhsusf_hgu56p_visor_black
	{
		displayName="[MAG] HGU [Personal - J. David]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\HGU_David.paa"
		};
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
	class PTF_ACV_David_rhsusf_cvc_green_ess: rhsusf_cvc_green_ess
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
	class PTF_ACV_Brown_rhsusf_cvc_green_alt: rhsusf_cvc_green_alt_helmet
	{
		displayName=" [ACV] Crewman Helmet [Personal - B.Brown]";
		hiddenSelectionsTextures[]=
		{
			"\z\PTF\addons\PTF_Textures\gear\helmets\ptf_cvc_green_alt_co_brown.paa"
		};
	};
};

class cfgMods
{
	author="Hawkins";
	timepacked="1732036966";
};
