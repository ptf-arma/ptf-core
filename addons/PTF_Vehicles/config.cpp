class cfgPatches
{

   class PTF_Vehicles
   {
      units[] = {
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
         "PTF_M977A4_M2",
         "PTF_M1085A1P2",
         "PTF_M1078A1P2",
         "PTF_M1025_tow",
         "PTF_M1151_M2_LRAS",
         "PTF_Quadbike_6x6",
         "PTF_SAM_RADAR",
         "PTF_SAM_DEFENDER",
         "PTF_ACV",
         "PTF_ACV_MK19",
         "PTF_ACV_30",
         "PTF_Badger",
         "PTF_Badger_D",
         "PTF_M1123",
         "PTF_LCAC",
         "PTF_MK23",
         "PTF_MK23_50",
         "PTF_MK23T",
         "PTF_MK23T_50"
      };
      weapons[] = {
          "PTF_weap_mastersafe"};
      magazines[] = {"PTF_400rnd_TE1_Red_Tracer_762x51_M240_M"};
      requiredVersion = "0.1";
      requiredAddons[] =
          {
              "A3_Weapons_F",
              "PTF_Main",
              "PTF_Textures",
              "PTF_Models",
              "boxloader_tractor",
              "rhsusf_c_mrzr",
              "rhsusf_c_fmtv",
              "rhsusf_c_m11xx",
              "rhsusf_c_hemtt_a4",
              "rhsusf_c_cougar",
              "rhsusf_c_rg33l",
              "A3_Data_F_Oldman_Loadorder",
              "A3_Soft_F_Exp",
              "A3_Boat_F_Beta",
              "Peral_ACV",
              // NOTE: deliberately absent -- "Peral_Airfield_Logistics" and
              // "slr_slingload", the two mods whose classes this addon EDITS
              // (cfgTractors.hpp, and slr_slingload_wreckDummy below).
              //
              // Adding them was tried and reverted. Forcing those PBOs to load
              // BEFORE this one makes the self-referential
              // `class slr_slingload_wreckDummy : slr_slingload_wreckDummy`
              // actually resolve, and Arma then walks that circular chain on
              // every lookup: a 335 MB RPT and a load that never finishes.
              // With them absent the edits are late-binding and quiet (one
              // warning line per session, measured).
              //
              // If you ever want these dependencies declared properly, the
              // self-inheritance below has to become a bare merge FIRST, and
              // the result has to be measured in-game -- the two changes are
              // not independent.
              // Same hazard for the external classes this addon INHERITS FROM:
              // cfg6x6.hpp, cfgMTVR.hpp and cfgLCAC.hpp derive from these, and
              // without the load-order guarantee the cfgIMPORT.hpp forward
              // declarations resolve to nothing and PTF_Quadbike_6x6 /
              // PTF_MK23* / PTF_LCAC become parentless root classes.
              "NDS_6x6_ATV",     // NDS_6x6_ATV_MIL
              "Peral_USMC_Gear", // Peral_MK23, Peral_MK23_50, Peral_MK23T(_50)
              "Peral_LCAC"       // Peral_LCAC
              };
   };
};

#include "cfgIMPORT.hpp"
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
   #include "cfgACV.hpp"
   #include "cfgBadger.hpp"
   #include "cfgBoats.hpp"
   #include "cfgCougar.hpp"
   #include "cfgFMTV.hpp"
   #include "cfgForklifts.hpp"
   #include "cfgM977A4.hpp"
   #include "cfgM1151.hpp"
   #include "cfgM1152.hpp"
   #include "cfgM1232.hpp"
   #include "cfgMRZR.hpp"
   #include "cfgTractors.hpp"
   #include "cfgVANILLA.hpp"
   #include "cfg6x6.hpp"
   #include "cfgSAM.hpp"
   #include "cfgCAT.hpp"
   #include "cfgLCAC.hpp"
   #include "cfgMTVR.hpp"

   // Forward-declared in cfgIMPORT.hpp and then re-declared with the same name
   // as its own base. That pairing is what makes this an EDIT of Sling Load
   // Rigging's class rather than a new one -- the declaration names the
   // external class, and the inheritance resolves against it.
   //
   // Measured, do not "simplify": written as a bare `class X { ... }` (with or
   // without the declaration) this class loses its parent and the RPT goes from
   // one warning line per session to ~364.
   class slr_slingload_wreckDummy : slr_slingload_wreckDummy {
      SlingloadingWeight = "[2900,2800]";
   };
};
