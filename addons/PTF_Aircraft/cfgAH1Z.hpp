//AH-1Z
class PTF_AH1Z : RHS_AH1Z
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   armor = 90;
   armorStructural = 40;
   damageResistance = 0.075;
   faction = "BLU_F";
   side = 1;
   author = "Paramarine Task Force";
   displayName = "AH-1Z [MAG36]";
   weapons[] = {"PTF_weap_mastersafe","CMFlareLauncher"};
   magazines[] = {"240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_a2port_air2\ah1z\data\ah1z_body_co.paa", "\rhsusf\addons\rhsusf_a2port_air2\ah1z\data\ah1z_engines_co.paa", "#(argb,8,8,3)color(0,0,0,1.0,co)", "#(argb,8,8,3)color(0,0,0,1.0,co)", "#(argb,8,8,3)color(0,0,0,1.0,co)", "#(argb,8,8,3)color(0,0,0,1.0,co)"};
   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MainTurret : MainTurret
      {
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_fcs_ah64",
                 "rhs_weap_M197",
                 "rhs_weap_laserDesignator_AI"};
         magazines[] =
             {
                 "rhs_mag_M197_750",
                 "rhs_laserfcsmag",
                 "rhs_LaserMag_ai"};
      };
   };
   class ACE_Actions : ACE_Actions {
      class ACE_MainActions : ACE_MainActions {
         class AH1z_Loadouts {
            displayName = "Loadouts";
            statement = "";
            icon = "";
            #include "\z\PTF\addons\PTF_Scripts\fnc\Ace actions\air\AH1z.hpp"
         };
      };
   };
};
class PTF_AH1Z_HQ : PTF_AH1Z
{
   displayName = "AH-1Z (MAG36 HQ) [MAG36]";
   hiddenSelectionsTextures[] = {
       "\z\PTF\addons\PTF_Textures\Aircraft\AH1Z\HQ\ah1z_body_co.paa", "\z\PTF\addons\PTF_Textures\Aircraft\AH1Z\HQ\ah1z_engines_co.paa", "", ""};
};
class PTF_AH1Z_GUNFIGHTERS : PTF_AH1Z
{
   displayName = "AH-1Z (Gunfighters) [MAG36]";
   hiddenSelectionsTextures[] = {
       "\z\PTF\addons\PTF_Textures\Aircraft\AH1Z\Gunfighters\ah1z_body_co.paa", "\z\PTF\addons\PTF_Textures\Aircraft\AH1Z\Gunfighters\ah1z_engines_co.paa", "", ""};
};
