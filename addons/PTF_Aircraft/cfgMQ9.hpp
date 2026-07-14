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
   LESH_canBeTowed = 1;
   LESH_towFromFront = 1;
   LESH_AxisOffsetTarget[] = {0,5,-1};
   LESH_WheelOffset[] = {0.35,0};
   AL_canBeMoved = 1;
   AL_CraneAttachpoint[] = {0,3.5,0.45};
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
   class Components: Components
   {
      class TransportPylonsComponent: TransportPylonsComponent
      {
         UIPicture = "USAF_MQ9\Data\UI\mq9_loadout.paa";
         class presets
         {
            class empty
            {
               displayName = "Empty";
               attachment[] = {"","","",""};
            };
            class Default
            {
               displayName = "Extended Fly Time";
               attachment[] = {"PTF_PylonRack_4Rnd_AGM114R","USAF_PylonRack_1Rnd_MQ9FuelTank","USAF_PylonRack_1Rnd_MQ9FuelTank","PTF_PylonRack_4Rnd_AGM114R"};
            };
            class ERCAS
            {
               displayName = "ER CAS";
               attachment[] = {"PTF_PylonRack_4Rnd_AGM114R","USAF_PylonRack_1Rnd_MQ9FuelTank","USAF_PylonRack_2Rnd_AGM114R","PTF_PylonRack_4Rnd_AGM114R"};
            };
            class GroundAttack
            {
               displayName = "Ground Attack";
               attachment[] = {"USAF_PylonRack_7Rnd_APKWS","USAF_PylonRack_2Rnd_AGM114R","USAF_PylonRack_2Rnd_AGM114R","USAF_PylonRack_7Rnd_APKWS"};
            };
            class SDB
            {
               displayName = "SDB Mix";
               attachment[] = {"USAF_PylonRack_4Rnd_GBU53","USAF_PylonRack_4Rnd_GBU39","USAF_PylonRack_4Rnd_GBU39","USAF_PylonRack_4Rnd_GBU53"};
            };
            class AA
            {
               displayName = "AG/AA Mix";
               attachment[] = {"USAF_PylonRack_2Rnd_AIM9X", "USAF_PylonRack_2Rnd_AGM114R","USAF_PylonRack_2Rnd_AGM114R","USAF_PylonRack_2Rnd_AIM9X"};
            };
         };
         class pylons: pylons
         {
            class pylons1: pylons1
            {
               hardpoints[] = {"B_USAF_MQ9_FUEL","B_BOMB_GBU12","B_BOMB_GBU38","B_BOMB_GBU39","B_BOMB_GBU49","B_BOMB_GBU53","B_BOMB_GBU54","B_BOMB_APKWS7","B_MISSILE_AGM114P_4","B_MISSILE_AGM114P_2","B_MISSILE_AGM114R", "B_MISSILE_AGM114R_4","B_AIM9X_DUAL_RAIL"};
               attachment = "PTF_PylonRack_4Rnd_AGM114R";
            };
            class pylons2: pylons2
            {
               hardpoints[] = {"B_USAF_MQ9_FUEL","B_BOMB_GBU12","B_BOMB_GBU38","B_BOMB_GBU39","B_BOMB_GBU49","B_BOMB_GBU53","B_BOMB_GBU54","B_MISSILE_AGM114R","B_MISSILE_AGM114P_2", "B_AIM9X_DUAL_RAIL", "B_BOMB_APKWS7"};
               attachment = "USAF_PylonRack_2Rnd_AGM114R";
            };
            class pylons3: pylons3
            {
               attachment = "USAF_PylonRack_1Rnd_MQ9FuelTank";
            };
            class pylons4: pylons4
            {
               attachment = "PTF_PylonRack_4Rnd_AGM114R";
            };
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