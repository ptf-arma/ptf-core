class cfgPatches
{

   class PTF_Vehicles
   {
      units[] = {
          "PTF_F450_S7Training",
          "PTF_F450_AirOperations",
          "PTF_F450_Tow",
          "PTF_F450_EMS",
          "PTF_M1151_MK19",
          "PTF_M1151_M240",
          "PTF_M1151_M2",
          "PTF_M1078A1P2_M2",
          "PTF_Quadbike",
          "PTF_SDV",
          "PTF_MKVSOC",
          "PTF_Atlas",
          "PTF_Kalmar",
          "PTF_Tractor",
          "PTF_Command_MRZR_HQ",
          "PTF_Command_MRZR_1ST",
          "PTF_Command_MRZR_2ND",
          "PTF_Command_MRZR_MAG36",
          "PTF_MRZR4",
          "PTF_M1151",
		    "PTF_M1151CAT_MK19",
		    "PTF_M1151CAT_M2",
          "PTF_M1152",
          "PTF_MRAP_CGRCAT1A2_MK19",
          "PTF_MRAP_CGRCAT1A2_M2",
          "PTF_MRAP_M1232_M2",
          "PTF_MRAP_M1232_MK19",
          "PTF_M977A4_Refuel",
          "PTF_M977A4_Repair",
          "PTF_M977A4_Ammo",
          "PTF_M1085A1P2",
          "PTF_M1078A1P2",
		    "PTF_M1025_tow",
		    "PTF_M1151CAT_MK19",
		    "PTF_M1151CAT_M2",
          "PTF_MTVR_Repair",
          "PTF_MTVR_Ammo",
          "PTF_MTVR_Refuel",
          "PTF_TowingTractor",
          "PTF_M1151_M2_LRAS",
          "PTF_Quadbike_6x6",
          "PTF_AAV",
          "PTF_AAV_CMD",
          "PTF_SAM_RADAR",
          "PTF_SAM_DEFENDER",
          "PTF_M1123"};
      weapons[] = {
          "PTF_weap_mastersafe",
          "PTF_Vlmg_M240_veh"};
      magazines[] = {"PTF_400rnd_TE1_Red_Tracer_762x51_M240_M"};
      requiredVersion = "0.1";
      requiredAddons[] =
          {
              "A3_Weapons_F",
              "A3_Armor_F_Tank",
              "PTF_Main",
              "PTF_Textures",
              "PTF_Models",
              "d3s_fseries_15",
              "d3s_cars_core",
              "d3s_cars_core_18",
              "boxloader_tractor",
              "rhsusf_c_mrzr",
              "rhsusf_c_fmtv",
              "rhsusf_c_m11xx",
              "rhsusf_c_hemtt_a4",
              "rhsusf_c_cougar",
              "rhsusf_c_rg33l",
              "A3_Data_F_Oldman_Loadorder",
              "A3_Soft_F_Exp",
              "A3_Boat_F_Beta"
              };
   };
};
#include "cfgImport.hpp"
class cfgWeapons
{
#include "cfgMastersafe.hpp"
};

class cfgMagazines
{
   class PTF_400rnd_TE1_Red_Tracer_762x51_M240_M : VehicleMagazine
   {
      scope = 2;
      displayName = "M240";
      displayNameShort = "7.62x51mm";
      ammo = "B_762x51_Tracer_Red";
      initSpeed = 900;
      maxLeadSpeed = 200;
      nameSound = "mgun";
      count = 400;
      tracersEvery = 1;
   };
};
//Defines Vehicles
class cfgVehicles
{
#include "cfgBoats.hpp"
#include "cfgCougar.hpp"
#include "cfgF450.hpp"
#include "cfgFMTV.hpp"
#include "cfgForklifts.hpp"
#include "cfgM977A4.hpp"
#include "cfgM1151.hpp"
#include "cfgM1152.hpp"
#include "cfgM1232.hpp"
#include "cfgMRZR.hpp"
#include "cfgTractors.hpp"
#include "cfgVanilla.hpp"
#include "cfgStretcher.hpp"
#include "cfg6x6.hpp"
#include "cfgSAM.hpp"
#include "cfgCAT.hpp"
};
