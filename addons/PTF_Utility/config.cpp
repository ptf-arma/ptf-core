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
          "PTF_Cargo_Small_Repair",
          "PTF_Cargo_Small_Rearm",
          "PTF_Cargo_Mortar",
          "PTF_Cargo_Vic",
          "PTF_Cargo_Tracks",
          "PTF_Cargo_Ammo",
          "PTF_Cargo_Large_Ammo",
          "PTF_Cargo_Large_Launcher",
          "PTF_Cargo_Large_Medical",
          "PTF_Cargo_Large_VicBox",
          "PTF_Cargo_Large_Explosives",
          "PTF_Cargo_Large_Refuel",
          "PTF_Cargo_VicAmmo",
          "PTF_Cargo_Fuel_WD",
          "PTF_Cargo_Fuel_D",
          "PTF_Tools_Toolbox",
          "PTF_Tools_PalletJack",
          "PTF_Standard_Arsenal",
          "PTF_Buiding_RepairDepot",
          "PTF_Cargo_Tiny_Ammo",
          "PTF_Cargo_Ammo",
          "PTF_Spawner",
          "PTF_Pso_Arsenal",
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
          "A3_Supplies_F_Exp",
          "tsp_breach",
          "tsp_breach_block",
          "tsp_breach_linear",
          "tsp_breach_package",
          "tsp_breach_popper",
          "tsp_breach_shock",
          "tsp_breach_silhouette",
          "tsp_breach_stick"};
   };
};
#include "cfgImport.hpp"
#include "cfgDefinitions.hpp"
class cfgVehicles
{
#include "cfgSmallCrates.hpp"
#include "cfgLargeCrates.hpp"
#include "cfgOtherCrates.hpp"
#include "cfgIndustrialCrates.hpp"
#include "cfgArsenal.hpp"
#include "cfgTools.hpp"
#include "Spawners\cfgSpawners.hpp"
};

