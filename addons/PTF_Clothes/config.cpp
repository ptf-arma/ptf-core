class cfgPatches
{
   class PTF_Clothes
   {
      units[] = {};
      weapons[] = {"PTF_Infantry_Weapon_Scope_M8541A"};
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
              "tfar_ai_hearing"};
   };
};
#include "cfgImport.hpp"
#include "cfgOpticRail.hpp"
class cfgWeapons
{
#include "helmets\cfgInfantryHelmets.hpp"
#include "helmets\cfgAirHelmets.hpp"
#include "helmets\cfgDIHat.hpp"
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
#include "backpacks\cfgInfantryBackpacks.hpp"
#include "backpacks\cfgAirBackpacks.hpp"
#include "backpacks\cfgLRBackpacks.hpp"
#include "uniforms\cfgUniformVehicles.hpp"
};
class cfgAmmo
{
#include "cfgAmmo.hpp"
};
class cfgMagazineWells
{
#include "cfgMagazineWells.hpp"
};
class cfgMagazines
{
#include "cfgMagazines.hpp"
};