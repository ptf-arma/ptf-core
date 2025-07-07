//AH-1Z

class RscInGameUI
{
   class RHS_RscOptics_Heli_Attack_01_gunner;
   class PTF_RscOptics_AH1Z_gunner: RHS_RscOptics_Heli_Attack_01_gunner
   {
      onLoad = "['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this spawn PTF_fnc_ah1z_gunnerUI";
   };
};

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
   class Components: Components
      {
         class TransportPylonsComponent
         {
            UIPicture = "\rhsusf\addons\rhsusf_a2port_air2\data\loadouts\RHS_AH1_EDEN_CA.paa";
            class pylons
            {
               class pylonTip1
               {
                  hardpoints[]      = {"RHS_HP_AIM9_HELI_USMC"};
                  priority          = 3;
                  attachment        = "rhs_mag_Sidewinder_heli_2";
                  maxweight         = 1200;
                  UIposition[]      = {0.625,0.25};
                  bay               = -1;
                  hitpoint          = HitPylon1;
               };
               class pylon2
               {
                  hardpoints[]      = {"RHS_HP_HELLFIRE_RACK","RHS_HP_FFAR_USMC"};
                  priority          = 2;
                  attachment        = "ace_compat_rhs_usf3_pylon_mag_4rnd_hellfire_k";
                  maxweight         = 1200;
                  UIposition[]      = {0.625,0.39};
                  bay               = -1;
                  turret[]          = {0};
                  hitpoint          = HitPylon2;
               };
               class pylon3 : pylon2
               {
                  UIposition[]      = {0.565,0.44};
                  priority         = 1;
                  attachment         = "rhs_mag_M151_19_green";
                  turret[]          = {};
                  hitpoint          = HitPylon3;
               };
               class pylon4 : pylon3
               {
                  UIposition[]      = {0.10,0.44};
                  mirroredMissilePos   = 3;
                  turret[]          = {};
                  hitpoint          = HitPylon4;
               };
               class pylon5 : pylon2
               {
                  UIposition[]      = {0.04,0.39};
                  mirroredMissilePos   = 2;
                  turret[]          = {0};
                  hitpoint          = HitPylon5;
               };
               class pylonTip6 : pylonTip1
               {
                  UIposition[]      = {0.04,0.25};
                  mirroredMissilePos   = 1;
                  hitpoint          = HitPylon6;
               };
               class cmDispenser
               {
                  hardpoints[]   = {"RHSUSF_cm_ANALE39","RHSUSF_cm_ANALE39_x2","RHSUSF_cm_ANALE39_x4"};
                  priority      = 1;
                  attachment      = "rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4";
                  maxweight      = 800;
                  UIposition[]   = {0.33,0.0};
               };
            };
            class Presets
            {
               class ATA
               {
                  attachment[] =
                  {
                     "rhs_mag_Sidewinder_heli_2",
                     "ace_compat_rhs_usf3_pylon_mag_4rnd_hellfire_k",
                     "rhs_mag_M151_19_green",
                     "rhs_mag_M151_19_green",
                     "ace_compat_rhs_usf3_pylon_mag_4rnd_hellfire_k",
                     "rhs_mag_Sidewinder_heli_2",
                     "rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4"
                  };
                  displayname = "Anti-Tank (AGM-114K)";
               };
               class ThermoA
               {
                  attachment[] =
                  {
                     "rhs_mag_Sidewinder_heli_2",
                     "ace_compat_rhs_usf3_pylon_mag_4rnd_hellfire_n",
                     "rhs_mag_M151_19_green",
                     "rhs_mag_M151_19_green",
                     "ace_compat_rhs_usf3_pylon_mag_4rnd_hellfire_n",
                     "rhs_mag_Sidewinder_heli_2",
                     "rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4"
                  };
                  displayname = "Thermobaric (AGM-114N)";
               };
               class ApkwsA
               {
                  attachment[] =
                  {
                     "rhs_mag_Sidewinder_heli_2",
                     "FIR_APKWS_M282_P_7rnd_M",
                     "rhs_mag_M151_19_green",
                     "rhs_mag_M151_19_green",
                     "FIR_APKWS_M282_P_7rnd_M",
                     "rhs_mag_Sidewinder_heli_2",
                     "rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4"
                  };
                  displayname = "Light Anti-Armor (APKWS M282)";
               };
            };
         };
      };
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
            visionMode[] = {"Normal","NVG","Ti"};
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
         turretInfoType = "PTF_RscOptics_AH1Z_gunner";
         class OpticsIn
            {
               class Wide
               {
                  opticsDisplayName = "W";
                  initAngleX = 0;
                  minAngleX = -30;
                  maxAngleX = 30;
                  initAngleY = 0;
                  minAngleY = -100;
                  maxAngleY = 100;
                  initFov = 0.456;
                  minFov = 0.456;
                  maxFov = 0.456;
                  directionStabilized = 0;
                  visionMode[] = {"Normal","NVG","Ti"};
                  thermalMode[] = {0,1};
                  gunnerOpticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64";
               };
               class Medium: Wide
               {
                  directionStabilized = 1;
                  opticsDisplayName = "M - Stabilized";
                  initFov = 0.093;
                  minFov = 0.093;
                  maxFov = 0.093;
                  gunnerOpticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64_2";
               };
               class Narrow: Medium
               {
                  opticsDisplayName = "N - Stabilized";
                  gunnerOpticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64_3";
                  initFov = 0.029;
                  minFov = 0.029;
                  maxFov = 0.029;
               };
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
