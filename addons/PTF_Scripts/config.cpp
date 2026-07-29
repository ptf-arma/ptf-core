#include "cfgFunctions.hpp"

class CfgPatches
{
   class PTF_Scripts
   {
      units[] = {};
      weapons[] = {};
      requiredVersion = 1.60;
      requiredAddons[] = {
          "PTF_Main",
          "ace_pylons",
          "cba_main"
          };
      author = "Paramarine Task Force";
   };
};

/*
    CfgRemoteExec - deliberately NOT defined here. See README.md.

    PTF_fnc_SpawnFunction and PTF_fnc_Salvage forward themselves to the server
    with remoteExec, and both report back with remoteExec ["hint", _caller]. If a
    mission whitelists remote execution, those three entries have to be in the
    MISSION's description.ext - an addon config cannot supply them:

      - Lookup order is missionConfigFile > campaignConfigFile > configFile, and
        an addon config.cpp only reaches configFile. A description.ext
        CfgRemoteExec replaces the lot wholesale rather than merging with it.
      - With no mission definition the game default already permits these calls,
        so an addon-level entry would add nothing in that case either.
      - Worse, every addon's CfgRemoteExec merges into the one configFile tree
        and "mode" is taken from the last parsed config, so a mode set here could
        silently loosen or break remote execution for every other mod in the
        repack.

    Entries missions need (paste into description.ext):

    class CfgRemoteExec {
        class Functions {
            mode = 1;
            class PTF_fnc_SpawnFunction { allowedTargets = 2; }; // server only
            class PTF_fnc_Salvage       { allowedTargets = 2; }; // server only
        };
        class Commands {
            mode = 1;
            class hint { allowedTargets = 1; };                  // clients only
        };
    };
*/

class Extended_PreInit_EventHandlers {
    class W41_PreInit {
        init = "call compile preprocessFileLineNumbers '\z\PTF\addons\PTF_Scripts\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers {
    class W41_PostInit {
        init = "call compile preprocessFileLineNumbers '\z\PTF\addons\PTF_Scripts\XEH_postInit.sqf'";
    };
};

class CfgUnitInsignia
{
#include "cfgUnitInsignia.hpp"
};
class CfgVehicles
{
class CargoNet_01_box_F;
class PTF_DummyHolder: CargoNet_01_box_F {
	displayName = "PTF_DummyHolder";
	model = "\A3\Weapons_f\DummyWeapon_Single.p3d";
	showWeaponCargo = 1;
};
#include "AceActions.hpp"
};

class CfgMovesBasic
{
	class Default;
	class StandBase;
	class HealBase: Default
	{
		disableWeapons = 1;
		disableWeaponsLong = 1;
		showWeaponAim = 0;
		canPullTrigger = 0;
		duty = 0.2;
		limitGunMovement = 0;
		aiming = "empty";
		aimingBody = "empty";
		actions = "HealActionBase";
		looped = 0;
	};
	class ManActions
	{
		PTF_WeaponBack[] = {"PTF_WeaponBack","Gesture"};
      PTF_TakeoutWeaponBack[] = {"PTF_TakeoutWeaponBack","Gesture"};
	};
};
class CfgGesturesMale
{
	class ManActions{};
	class Actions;
	class Default;
	class States
	{
		class PTF_WeaponBack: Default
		{
			speed = 1;
			looped = 0;
			file = "a3\anims_f\data\anim\sdr\mov\erc\stp\ras\rfl\amovpercmstpsraswrfldnon_amovpercmstpsraswlnrdnon.rtm";
			mask = "handsWeapon_context";
			soundOverride = "rifle_to_launcher";
			disableWeapons = 1;
			interpolationRestart = 2;
			leftHandIKBeg = 1;
			leftHandIKCurve[] = {0.386364,1,0.5,0};
			leftHandIKEnd = 0;
			rightHandIKBeg = 1;
			rightHandIKCurve[] = {0.181818,1,0.25,0};
			rightHandIKEnd = 0;
			weaponIK = 0;
			canReload = 1;
			headBobMode = 1;
			headBobStrength = -1;
			enableAutoActions = 0;
		};
      class PTF_TakeoutWeaponBack: PTF_WeaponBack
		{
			speed = 0.8;
			file = "a3\anims_f\data\anim\sdr\mov\erc\stp\ras\lnr\amovpercmstpsraswlnrdnon_amovpercmstpsraswrfldnon_end.rtm";
			rightHandIKCurve[] = {0.657143,0,0.728571,1};
			leftHandIKCurve[] = {0.671429,0,0.771429,1};
		};
   };
};
