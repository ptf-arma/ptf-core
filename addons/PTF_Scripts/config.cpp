class CfgPatches
{
   class PTF_Scripts
   {
      units[] = {};
      weapons[] = {};
      requiredVersion = 1.0;
      requiredAddons[] = {
          "PTF_Main",
          "cba_main"};
      author = "Paramarine Task Force";
   };
};

class CBA_Extended_EventHandlers;

class CfgUnitInsignia
{
#include "cfgUnitInsignia.hpp"
};
class CfgFunctions
{
#include "cfgFlagFunctions.hpp"
};
class CfgVehicles
{
#include "cfgFlagVehicles.hpp"
};