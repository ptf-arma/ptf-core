class CfgPatches
{
	class PTF_AirWeapon
	{
		author = "PTF";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		magazines[] = {
		"PTF_12Gauge_Bean8",
		"PTF_12Gauge_Bean5",
		"PTF_FIR_Hydra_WP_P_7rnd_M",
		"PTF_rhs_mag_AGM114M_2"
		};
		requiredAddons[] = {
		"rhsusf_c_airweapons",
		"FIR_AirWeaponSystem_US",
		"ace_missileguidance",
		"rhsusf_c_weapons",
		"rhs_c_weapons",
		"A3_Weapons_F",
		"ace_hellfire"
		};
	};
};

#include "cfgImport.hpp"


#include "cfgWeapons.hpp"
#include "cfgAmmo.hpp"
#include "cfgMagazine.hpp"

class CfgMagazineWells {
	class CBA_12g_8rnds {
		PTF_AirWeapon[] = {"PTF_12Gauge_Bean8"};
	};
	class CBA_12g_5rnds {
		PTF_AirWeapon[] = {"PTF_12Gauge_Bean5"};
	};
};
