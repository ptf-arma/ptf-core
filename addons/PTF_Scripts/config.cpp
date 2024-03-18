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
class CargoNet_01_box_F;
class PTF_DummyHolder: CargoNet_01_box_F {
	displayName = "PTF_DummyHolder";
	model = "\A3\Weapons_f\DummyWeapon_Single.p3d";
	showWeaponCargo = 1;
};
#include "AceActions.hpp"
};
class CfgMarkers {
#include "fnc\Markers\CfgMarker.hpp"
};

//custom keybinds
class CfgUserActions
{
	class PTF_WeaponSwitch // This class name is used for internal representation and also for the inputAction command.
	{
		displayName = "Stow / Switch Weapon";
		tooltip = "Put a Weapon on your back or Swtich to the one allready there";
		onActivate = "call PTF_fnc_weaponSwap";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
};
class CfgDefaultKeysPresets
{
	class Arma2 // Arma2 is inherited by all other presets.
	{
		class Mappings
		{
			PTF_WeaponSwitch[] = {
				0x05, // DIK_K
				"0x05", // 256 is the bitflag for "doubletap", 0x25 is the DIK code for K.
				"0x00000000 + 4" // 0x00010000 is the bitflag for "mouse button".
			};
		};
	};
}
class UserActionGroups
{
	class PTF_KeyBinds // Unique classname of your category.
	{
		name = "Paramarine Task Force KeyBinds "; // Display name of your category.
		isAddon = 1;
		group[] = {"PTF_WeaponSwitch"}; // List of all actions inside this category.
	};
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
