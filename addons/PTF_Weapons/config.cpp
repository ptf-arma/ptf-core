class CfgPatches
{
	class PTF_AirWeapon
	{
		author = "PTF";
		units[] = {};
		weapons[] = {
			"PTF_FIR_Hydra_WP_P_7rnd_M",
			"PTF_PylonRack_4Rnd_ACE_Hellfire_AGM114K",
			"PTF_rhs_mag_AGM114M_2",
			"PTF_rhs_mag_AGM114M_4"
		};
		requiredVersion = 1.0;
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
#include "cfgWeapons.hpp"
#include "cfgAmmo.hpp"
#include "cfgMagazine.hpp"
