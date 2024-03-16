#include "CfgFunctions.hpp"

class CfgPatches
{
   class PTF_Scripts
   {
      units[] = {};
      weapons[] = {};
      requiredVersion = 1.0;
      requiredAddons[] = {
          "PTF_Main",
          "ace_pylons",
          "cba_main"
          };
      author = "Paramarine Task Force";
   };
};

class CBA_Extended_EventHandlers;

class CfgUnitInsignia
{
#include "cfgUnitInsignia.hpp"
};
class CfgVehicles
{
#include "AceActions.hpp"
};
class CfgMarkers {
#include "fnc\Markers\CfgMarker.hpp"
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
