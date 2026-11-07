// Fixes for config mistakes in the third-party PBOs PTF ships (and the
// vanilla classes they damage). Nothing here adds content.
//
// Every class in this addon is an EDIT of a class someone else owns, so each
// one must name that class's real parent (read from the shipped PBO, or the
// vanilla config) - a wrong or missing parent resets the inheritance, which
// is exactly the bug most of these patches undo. The requiredAddons below
// make this load after every PBO it patches.
class CfgPatches {
    class PTF_Compat {
        name = "PTF Core - Compatibility fixes";
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.18;
        requiredAddons[] = {
            "A3_Static_F",
            "A3_Static_F_Mortar_01",
            "A3_Weapons_F",
            "cba_xeh",
            "MD_APOBS",
            "NDS_M224_mortar",
            "Peral_ACV",
            "Peral_LST",
            "Peral_M4A1",
            "Peral_USMC_Gear",
            "RHICC"
        };
        author = "Paramarine Task Force";
    };
};

class CBA_Extended_EventHandlers_base;

#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
