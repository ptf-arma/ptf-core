//UH-1Y
#include "cfgMacro.hpp"
class PTF_UH1Y : RHS_UH1Y_d
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 20;
   ace_cargo_hasCargo = 1;
   armorStructural = 500;
   epeImpulseDamageCoef = 0.1;
   armor=500;
   hullDamageCauseExplosion = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (FFAR/MG) [MAG36]";
   weapons[] = {
       "PTF_weap_mastersafe",
       "CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_ext_co.paa", "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_int_co.paa"};
   class Turrets : Turrets
   {
      class MainTurret : MainTurret
      {
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_m134_minigun_1"};
         magazines[] =
             {
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000"
            };
      };
      class RightDoorGun : RightDoorGun
      {
          weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_m134_minigun_1"};
         magazines[] =
             {
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000"
            };

      };
      class CargoTurret_01 : CargoTurret_01
      {};
      class CargoTurret_02 : CargoTurret_02
      {};
      class CargoTurret_03 : CargoTurret_03
      {};
      class CargoTurret_04 : CargoTurret_04
      {};
      class CargoTurret_05 : CargoTurret_05
      {};
      class CargoTurret_06 : CargoTurret_06
      {};
   };
};
class PTF_UH1Y_Unarmed : RHS_UH1Y_UNARMED_d
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_AIR";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 20;
   ace_cargo_hasCargo = 1;
   armorStructural = 500;
   epeImpulseDamageCoef = 0.1;
   armor=500;
   hullDamageCauseExplosion = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Trainer) [MAG36]";
   weapons[] = {"CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {
       "\PTF_Textures\aircraft\uh1y\Trainer\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

   class Turrets : Turrets
   {
      class CargoTurret_01 : CargoTurret_01
      {};
      class CargoTurret_02 : CargoTurret_02
      {};
      class CargoTurret_03 : CargoTurret_03
      {};
      class CargoTurret_04 : CargoTurret_04
      {};
      class CargoTurret_05 : CargoTurret_05
      {};
      class CargoTurret_06 : CargoTurret_06
      {};
      class CargoTurret_07 : CargoTurret_07
      {};
      class CargoTurret_08 : CargoTurret_08
      {};
   };
};
class PTF_UH1Y_Medevac : CUP_B_UH1Y_MEV_USMC
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_AIR";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   armorStructural = 500;
   epeImpulseDamageCoef = 0.1;
   armor=500;
   hullDamageCauseExplosion = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Medevac) [MAG36]";
   weapons[] = {"CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelections[] = {"camo1", "camo2"};
   hiddenSelectionsTextures[] = {
       "\PTF_Textures\aircraft\uh1y\medevac\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
   class Turrets : Turrets
   {
      class CargoTurret_01 : CargoTurret_01
      {};
      class CargoTurret_02 : CargoTurret_02
      {};
   };
   class TransportMagazines : TransportMagazines
   {
      mag_xx(SmokeShellPurple, 40);
   };
   class TransportItems : TransportItems
   {
      item_xx(ACE_fieldDressing, 300);
      item_xx(ACE_quikclot, 300);
      item_xx(ACE_elasticBandage, 300);
      item_xx(ACE_packingBandage, 300);
      item_xx(ACE_epinephrine, 100);
      item_xx(ACE_adenosine, 50);
      item_xx(ACE_morphine, 50);
      item_xx(ACE_bodyBag, 20);
      item_xx(ACE_surgicalKit, 10);
      item_xx(ACE_CableTie, 20);
      item_xx(ACE_salineIV, 30);
      item_xx(ACE_salineIV_250, 60);
      item_xx(ACE_salineIV_500, 60);
   };
};
class PTF_UH1Y_HQ : PTF_UH1Y
{
   displayName = "UH-1Y (MAG36 HQ) [MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\uh1y\HQ\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_SCARFACE : PTF_UH1Y
{
   displayName = "UH-1Y (Scarface) [MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\UH1Y\Scarface\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_SCARFACE_SL : PTF_UH1Y
{
   displayName = "UH-1Y (Scarface SL) [MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\UH1Y\ScarfaceSL\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_GUNFIGHTERS : PTF_UH1Y
{
   displayName = "UH-1Y (Gunfighters) [MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\UH1Y\Gunfighters\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_GUNFIGHTERS_SL : PTF_UH1Y
{
   displayName = "UH-1Y (Gunfighters SL) [MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\UH1Y\GunfightersSL\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};