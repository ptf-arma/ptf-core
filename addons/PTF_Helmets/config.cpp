class cfgPatches
{
	class PTF_Clothes
	{
		units[]={};
		weapons[]=
		{
		};
		requiredVersion="0.1";
		requiredAddons[]=
		{
         "rhsusf_infantry",
         "USP_GEAR_Head"
		};
	};
};
class cfgWeapons
{
   class rhsusf_ach_helmet_headset_ucp_alt;
   class HitpointsProtectionInfo;
   class ItemInfo;
   class Head;
   class USP_OPS_FASTXP_TAN;
   class USP_OPS_FASTXP_CO_TAN;
   class USP_OPS_FASTXP_CT_TAN;
   class USP_OPS_FASTXP_CU_TAN;
   class PTF_Helmet_FASTXP_TAN : USP_OPS_FASTXP_TAN
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] FAST XP (TAN)";
      author = "Paramarine Task Force";
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_FASTXP_CO_TAN : USP_OPS_FASTXP_CO_TAN
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] FAST XP CO (TAN)";
      author = "Paramarine Task Force";
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_FASTXP_CT_TAN : USP_OPS_FASTXP_CT_TAN
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] FAST XP CT (TAN)";
      author = "Paramarine Task Force";
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_FASTXP_CU_TAN : USP_OPS_FASTXP_CU_TAN
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] FAST XP CU (TAN)";
      author = "Paramarine Task Force";
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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


   
   class PTF_Helmet_Cook_Infantry_Mich2000_WD : rhsusf_ach_helmet_headset_ucp_alt
   {
      scope = 2;
      side = 1;
      displayName = "[Inf] MICH 2000 (WD) [Personal - N.Cook]";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_cook.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
      };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_Cook_Infantry_Mich2000_D : rhsusf_ach_helmet_headset_ucp_alt
   {
      scope = 2;
      side = 1;
      displayName = "[Inf] MICH 2000 (D) [Personal - N.Cook]";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_des_co_cook.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
      };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_Cook_Infantry_Mich2000_S : rhsusf_ach_helmet_headset_ucp_alt
   {
      scope = 2;
      side = 1;
      displayName = "[Inf] MICH 2000 (S) [Personal - N.Cook]";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_cook.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
      };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_Black_Infantry_Mich2000_WD : rhsusf_ach_helmet_headset_ucp_alt
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] MICH 2000 (WD) [Personal - K.Black]";
      author = "Paramarine Task Force";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_black.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
         };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_Black_Infantry_Mich2000_D : rhsusf_ach_helmet_headset_ucp_alt
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] MICH 2000 (D) [Personal - K.Black]";
      author = "Paramarine Task Force";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_des_co_black.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
         };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_Black_Infantry_Mich2000_S : rhsusf_ach_helmet_headset_ucp_alt
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] MICH 2000 (S) [Personal - K.Black]";
      author = "Paramarine Task Force";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_black.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
         };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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

class PTF_Helmet_Chmielewski_Infantry_Mich2000_WD : rhsusf_ach_helmet_headset_ucp_alt
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] MICH 2000 (WD) [Personal - B.Chmielewski]";
      author = "Paramarine Task Force";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_chmielewski.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
         };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_Chmielewski_Infantry_Mich2000_D : rhsusf_ach_helmet_headset_ucp_alt
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] MICH 2000 (D) [Personal - B.Chmielewski]";
      author = "Paramarine Task Force";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_des_co_chmielewski.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
         };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_Chmielewski_Infantry_Mich2000_S : rhsusf_ach_helmet_headset_ucp_alt
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] MICH 2000 (S) [Personal - B.Chmielewski]";
      author = "Paramarine Task Force";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_snow_co_chmielewski.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
         };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
   class PTF_Helmet_Gute_Infantry_Mich2000_WD : rhsusf_ach_helmet_headset_ucp_alt
   {
      scopeArsenal = 2;
      scope = 2;
      side = 1;
      faction = "BLU_F";
      displayName = "[Inf] MICH 2000 (S) [Personal - B.Gute]";
      author = "Paramarine Task Force";
      hiddenSelections[] = {"Camo1", "Camo2"};
      hiddenSelectionsTextures[] = {
         "PTF_Helmets\data\ptf_mich_covered_rhino_wd_co_gute.paa.paa",
         "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"
         };
      ace_hearing_protection = 0.8;
      ace_hearing_lowerVolume = 0;
      class ItemInfo : ItemInfo
      {
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
};