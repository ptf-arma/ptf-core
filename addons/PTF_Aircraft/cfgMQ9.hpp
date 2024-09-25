//MQ-9
class PTF_MQ9 : USAF_MQ9
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   side = 1;
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "MQ-9 [MAG36]";
   weapons[] = {"CMFlareLauncher"};
   magazines[] = {"240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelectionsTextures[] = {"USAF_MQ9\data\USAF_MQ9_co.paa", "USAF_MQ9\data\USAF_MQ9_Wing_co.paa", "usaf_mq9\data\usaf_MQ9_hinges_co.paa", "", "\z\PTF\addons\PTF_Textures\aircraft\3_ca.paa", "\z\PTF\addons\PTF_Textures\aircraft\6_ca.paa", "", "", "", "", ""};
   class ACE_Actions : ACE_Actions {
      class ACE_MainActions : ACE_MainActions {
         class AH1z_Loadouts {
            displayName = "Loadouts";
            statement = "";
            icon = "";
            #include "\z\PTF\addons\PTF_Scripts\fnc\Ace actions\air\MQ9.hpp"
         };
      };
   };
};
class PTF_MQ9_SCARFACE : PTF_MQ9
{
   displayName = "MQ-9 (Scarface) [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\Aircraft\MQ9\Scarface\USAF_MQ9_co.paa", "\z\PTF\addons\PTF_Textures\Aircraft\MQ9\Scarface\USAF_MQ9_Wing_co.paa", "usaf_mq9\data\usaf_MQ9_hinges_co.paa", "", "\z\PTF\addons\PTF_Textures\aircraft\3_ca.paa", "\z\PTF\addons\PTF_Textures\aircraft\6_ca.paa", "", "", "", "", ""};
};
class PTF_MQ9_HQ : PTF_MQ9
{
   displayName = "MQ-9 (MAG36 HQ) [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\Aircraft\MQ9\HQ\USAF_MQ9_co.paa", "\z\PTF\addons\PTF_Textures\Aircraft\MQ9\HQ\USAF_MQ9_Wing_co.paa", "usaf_mq9\data\usaf_MQ9_hinges_co.paa", "", "\z\PTF\addons\PTF_Textures\aircraft\3_ca.paa", "\z\PTF\addons\PTF_Textures\aircraft\6_ca.paa", "", "", "", "", ""};
};