class CfgPatches
{
   class PTF_Utility
   {
      units[] = {
          "PTF_Cargo_Small_Ammo",
          "PTF_Cargo_Small_Launcher",
          "PTF_Cargo_Small_Explosives",
          "PTF_Cargo_Small_Medical",
          "PTF_Cargo_Small_Humanitarian",
          "PTF_Cargo_Small_Cargo",
          "PTF_Cargo_Mortar",
          "PTF_Cargo_Vic",
          "PTF_Cargo_Tracks",
          "PTF_Cargo_Ammo",
          "PTF_Cargo_Large_Ammo",
          "PTF_Cargo_Large_Launcher",
          "PTF_Cargo_Large_Medical",
          "PTF_Cargo_Large_Cargo",
          "PTF_Cargo_Large_VicBox",
          "PTF_Cargo_Large_Explosives",
          "PTF_Fortifications_Tent_Medical",
          "PTF_Fortifications_Wall_Hesco",
          "PTF_Fortifications_Wall_BigHesco",
          "PTF_Fortifications_Roof_Net",
          "PTF_Fortifications_Tent_Normal",
          "PTF_Fortifications_Wire",
          "PTF_Fortifications_Helipad",
          "PTF_Fortifications_Lights_Single",
          "PTF_Fortifications_Lights_Double",
          "PTF_Fortifications_Lights_Helipad",
          "PTF_Fortifications_Lights_Cone",
          "PTF_Fortifications_Lights_Tent",
          "PTF_Fortifications_Desk",
          "PTF_Fortifications_Computer",
          "PTF_Tools_Toolbox",
          "PTF_Tools_PalletJack",
          "PTF_Standard_Arsenal",
          "PTF_Cargo_Mortar_Combo",
          "PTF_Cargo_Mortar_Smoke",
          "PTF_Cargo_Mortar_HE",
          "PTF_Cargo_DEFENDER_Ammo",
          "PTF_Cargo_Wheels",
          "PTF_Buiding_RepairDepot",
          "PTF_Cargo_Industrial_Repair",
          "PTF_Cargo_Tiny_Ammo",
          "PTF_Cargo_Ammo",
          "PTF_Spawner",
          "PTF_Standard_Arsenal_No_Ammo"
          };
      weapons[] = {};
      requiredVersion = 1.32;
      requiredAddons[] = {
          "PTF_Main",
          "PTF_Textures",
          "PTF_Models",
          "PTF_Scripts",
          "cba_xeh",
          "MAAMod",
          "rhsusf_main",
          "boxloader",
          "boxloader_cargo",
          "boxloader_pallet",
          "boxloader_tractor",
          "ace_main",
          "ace_arsenal",
          "A3_Supplies_F_Heli",
          "A3_Props_F_Enoch",
          "boxloader_fort",
          "A3_Signs_F",
          "A3_Structures_F_EPA",
          "A3_Structures_F_Heli",
          "A3_Supplies_F_Exp"};
   };
};
#include "cfgImport.hpp"
#include "cfgDefinitions.hpp"
class cfgVehicles
{
#include "cfgSmallCrates.hpp"
#include "cfgLargeCrates.hpp"
#include "cfgIndustrialCrates.hpp"
#include "cfgArsenal.hpp"
#include "cfgTools.hpp"
#include "Spawners\cfgSpawners.hpp"
};

