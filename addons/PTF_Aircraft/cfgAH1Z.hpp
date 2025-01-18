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
   class DriverOpticsIn
      {
         class Wide
         {
            hitpoint          = Hit_Optic_TADS;
            camPos            = GunnerView;
            camDir            = gunnerview_dir;
            opticsDisplayName ="W";
            initAngleX        = 0;
            minAngleX         = -30;
            maxAngleX         = 30;
            initAngleY        = 0;
            minAngleY         = -100;
            maxAngleY         = 100;
            initFov           = 0.456;
            minFov            = 0.456;
            maxFov            = 0.456;
            directionStabilized  = 1;
            visionMode[]=
            {
               "Normal",
               "NVG",
               "Ti"
            };
            thermalMode[]={0,1};
            opticsModel="\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64";
            opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
         };
         class Medium: Wide
         {
            directionStabilized  = 1;
            opticsDisplayName = "M - Stabilized";
            initFov           = 0.093;
            minFov            = 0.093;
            maxFov            = 0.093;
            opticsModel       = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64_2";
         };
         class Narrow: Medium
         {
            opticsDisplayName ="N - Stabilized";
            opticsModel       ="\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64_3";
            initFov           =0.029;
            minFov            =0.029;
            maxFov            =0.029;
         };
      };
   class Turrets : Turrets
   {
      class MainTurret : MainTurret
      {
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_fcs_ah64",
                 "rhs_weap_M197",
                 "rhs_weap_laserDesignator_AI"
              };
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
