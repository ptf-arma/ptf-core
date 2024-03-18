////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.10
//https://mikero.bytex.digital/Downloads
//'now' is Fri Mar 08 20:54:15 2024 : 'file' last modified on Wed Jun 15 13:37:03 2022
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class tsp_common
	{
		requiredAddons[] = {};
		units[] = {};
	};
};
class CfgFunctions
{
	class tsp_common
	{
		class functions
		{
			class functions
			{
				file = "\z\PTF\addons\tsp_common\functions.sqf";
				preInit = "true";
			};
			class init
			{
				file = "\z\PTF\addons\tsp_common\init.sqf";
				postInit = "true";
			};
		};
	};
};
class CfgMovesBasic
{
	class default;
	class DefaultDie;
	class ManActions
	{
		tsp_common_stop[] = {"tsp_common_stop","Gesture"};
		tsp_common_stop_right[] = {"tsp_common_stop_right","Gesture"};
		tsp_common_stop_left[] = {"tsp_common_stop_left","Gesture"};
	};
};
class CfgGesturesMale
{
	skeletonName = "OFP2_ManSkeleton";
	class Default{};
	class States
	{
		class GestureNo;
		class tsp_common_stop: GestureNo
		{
			mask = "empty";
			interpolationSpeed = 5;
			showHandGun = 0;
			rightHandIKCurve[] = {1};
			leftHandIKCurve[] = {1};
			canPullTrigger = "true";
			enableBinocular = "true";
			enableMissile = "true";
			enableOptics = "true";
			disableWeapons = "false";
		};
		class tsp_common_stop_right: tsp_common_stop
		{
			rightHandIKCurve[] = {0,0,0.5,1};
			leftHandIKCurve[] = {1};
		};
		class tsp_common_stop_left: tsp_common_stop
		{
			rightHandIKCurve[] = {1};
			leftHandIKCurve[] = {0,0,0.5,1};
		};
	};
	class BlendAnims
	{
		leftArm[] = {"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1};
	};
};
class cfgMods
{
	author = "ASmallDinosaur";
	timepacked = "1655343423";
};
