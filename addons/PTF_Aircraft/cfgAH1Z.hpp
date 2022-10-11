//AH-1Z
class PTF_AH1Z : RHS_AH1Z
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   armor = 90;
   armorStructural = 40;
   damageResistance = 0.075;
   driverCanSee = 31;
   gunnerCanSee = 31;
   faction = "BLU_F";
   side = 1;
   crew = "B_Pilot_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 300;
   author = "Paramarine Task Force";
   displayName = "AH-1Z [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   weapons[] = {
       "PTF_weap_mastersafe",
       "CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {
       "Camo1", "Camo2", "screen", "pip"};
   hiddenSelectionsTextures[] = {
       "\rhsusf\addons\rhsusf_a2port_air2\ah1z\data\ah1z_body_co.paa", "\rhsusf\addons\rhsusf_a2port_air2\ah1z\data\ah1z_engines_co.paa", "#(argb,8,8,3)color(0,0,0,1.0,co)", "#(argb,8,8,3)color(0,0,0,1.0,co)", "#(argb,8,8,3)color(0,0,0,1.0,co)", "#(argb,8,8,3)color(0,0,0,1.0,co)"};

   class MFD
   {
#include "rotarymfd.hpp"
   };

   class DriverOpticsIn
   {
      class Wide
      {
         hitpoint = Hit_Optic_TADS;
         camPos = GunnerView;
         camDir = gunnerview_dir;
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
         visionMode[] =
             {
                 "Normal", "NVG"};
         opticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64";
      };
      class Medium : Wide
      {
         directionStabilized = 1;
         opticsDisplayName = "M - Stabilized";
         initFov = 0.093;
         minFov = 0.093;
         maxFov = 0.093;
         opticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64_2";
      };
      class Narrow : Medium
      {
         opticsDisplayName = "N - Stabilized";
         opticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64_3";
         initFov = 0.029;
         minFov = 0.029;
         maxFov = 0.029;
      };
   };

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MainTurret : MainTurret
      {
         gunnerCompartments = "Compartment1";
         showHMD = 1;
         enableManualFire = 1;
         isCopilot = 1;
         gunnerAction = "rhs_AH1Z_Gunner";
         gunnerInAction = "rhs_AH1Z_Gunner";
         gunnerRightHandAnimName = "stick_copilot";
         gunnerLeftHandAnimName = "lever_copilot";
         gunnerGetInAction = "Heli_Attack_01_Pilot_enter";
         gunnerGetOutAction = "Heli_Attack_01_Pilot_exit";
         gunnerName = "WSO";
         minElev = -60;
         maxElev = 10;
         initElev = 0;
         minTurn = -70;
         maxTurn = 70;
         initTurn = 0;
         turretInfoType = "RscOptics_GENERAL_FLIR";
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
         gunnerOpticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64";
         class MFD
         {
#include "rotarymfd.hpp"
         };
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
               visionMode[] =
                   {
                       "Normal", "NVG"};
               gunnerOpticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64";
            };
            class Medium : Wide
            {
               directionStabilized = 1;
               opticsDisplayName = "M - Stabilized";
               initFov = 0.093;
               minFov = 0.093;
               maxFov = 0.093;
               gunnerOpticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64_2";
            };
            class Narrow : Medium
            {
               opticsDisplayName = "N - Stabilized";
               gunnerOpticsModel = "\rhsusf\addons\rhsusf_a2port_air\ah64\gunnerOptics_ah64_3";
               initFov = 0.029;
               minFov = 0.029;
               maxFov = 0.029;
            };
         };
         class OpticsOut
         {
            class Monocular
            {
               initAngleX = 0;
               minAngleX = -30;
               maxAngleX = 30;
               initAngleY = 0;
               minAngleY = -100;
               maxAngleY = 100;
               initFov = 1.1;
               minFov = 0.133;
               maxFov = 1.1;
               visionMode[] = {"Normal", "NVG"};
               gunnerOpticsModel = "";
               gunnerOpticsEffect[] = {};
            };
         };
      };
   };
   class textureSources
   {
   };
   class UserActions : UserActions
   {
   };
   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
