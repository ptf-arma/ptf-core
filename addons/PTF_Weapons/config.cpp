class CfgPatches
{
	class PTF_AirWeaponSystem_US
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"FIR_AirWeaponSystem_US"};
		
	};
};
#include "cfgImport.hpp"
#include "AirWeapons\Effect.hpp"
class Cfgammo
{
	#include "AirWeapons\Cfgammo.hpp"
};
class CfgMagazines
{
	#include "AirWeapons\cfgMagazine.hpp"
};
class CfgWeapons
{
	#include "AirWeapons\cfgWeaponLauncher.hpp"
};