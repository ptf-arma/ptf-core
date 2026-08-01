class cfgPatches
{
   class PTF_Clothes
   {
      units[] = {"PTF_MAG_Pilot"};
      weapons[] =
         {
            "PTF_Infantry_Weapon_Scope_M8541A",
            "PTF_Infantry_Weapon_Scope_Accu",
            "PTF_Infantry_Weapon_Scope_Accu_RMR",
            "PTF_Infantry_Weapon_Scope_Accu_RMRCant",
            "PTF_Infantry_Weapon_Scope_Accu_T1",
            "PTF_Infantry_Weapon_Scope_Accu_T2"
         };
      requiredVersion = "0.1";
      requiredAddons[] =
          {
              "PTF_Main",
              "PTF_Textures",
              "PTF_Models",
              "A3_Drones_F",
              "A3_Weapons_F",
              "A3_Characters_F",
              "ace_nightvision",
              "rhsusf_c_troops",
              "rhsusf_c_weapons",
              "tfar_core",
              "rhsusf_infantry",
              "tfar_backpacks",
              "tfar_handhelds",
              "tfar_ai_hearing",
              "ace_common",
              "ace_gforces",
              // Load-order dependencies for the external classes this addon
              // INHERITS FROM. Without these, PTF_Clothes can parse first, the
              // forward declarations in cfgImport.hpp resolve to nothing, and
              // every derived helmet/vest/uniform/backpack/optic silently
              // becomes a parentless root class -- model, ItemInfo,
              // HitpointsProtectionInfo and XEH all vanish.
              // CfgPatches class names read from each mod's own PBO; several
              // do not match the PBO or mod name.
              "USP_Gear_Head",     // USP_OPSCORE_* / USP_OPS_FASTXP_* helmets
              "USP_Gear_Vest",     // USP_CRYE_CPC*, USP_VEST_STRANDHOGG2_CBR
              "USP_Gear_Pack",     // USP zipon/reebow/delta/45L backpacks
              "USP_Gear_Body",     // USP_G3C_* / USP_G3F_* uniforms
              "MoePilotCoveralls", // CWU27P_Base, CSU15BP_* flight suits
              "MoePilotVests",     // CMU33P, SV2B_LPU*, SRU21P* survival vests
              "Peral_USMC_Gear",   // JPC_2_JTAC/Marksman/SL_Tan vests
              "tfw_radios_ilbe",   // tfw_ilbe_* long-range radio backpacks
              "Scotty_LPVO",       // Scot_Trij_Accu* optics (GOLD Optics)
              "cba_jr",            // asdg_OpticRail, extended by cfgOpticRail.hpp
              "cba_jam"            // CBA_556x45_STANAG / CBA_762x51_SCAR wells
            };
   };
};
#include "cfgImport.hpp"
#include "cfgOpticRail.hpp"

class cfgWeapons
{
#include "helmets\cfgInfantryHelmets.hpp"
#include "helmets\cfgAirHelmets.hpp"
#include "helmets\cfgSpecialHelmets.hpp"
#include "vests\cfgAirVests.hpp"
#include "vests\cfgInfantryVests.hpp"
#include "vests\cfgSpecialVests.hpp"
#include "uniforms\cfgAirUniforms.hpp"
#include "uniforms\cfgInfantryUniforms.hpp"
#include "uniforms\cfgSpecialUniforms.hpp"
#include "cfgScopes.hpp"
#include "cfgNightvision.hpp"
};
class cfgVehicles
{
#include "cfgDroneItems.hpp"
#include "cfgDrones.hpp"
#include "cfgSpawnUnits.hpp"
#include "backpacks\cfgInfantryBackpacks.hpp"
#include "backpacks\cfgAirBackpacks.hpp"
#include "backpacks\cfgLRBackpacks.hpp"
#include "uniforms\cfgUniformVehicles.hpp"
};
class cfgMagazineWells
{
#include "cfgMagazineWells.hpp"
};
class cfgMagazines
{
#include "cfgMagazines.hpp"
};
