////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.10
//https://mikero.bytex.digital/Downloads
//'now' is Fri Mar 08 20:53:50 2024 : 'file' last modified on Thu Aug 04 06:17:01 2022
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class tsp_animate
	{
		requiredAddons[] = {"tsp_common","cba_common"};
		units[] = {};
	};
};
class Extended_PreInit_EventHandlers
{
	class tsp_animate
	{
		init = "call compile preProcessFileLineNumbers '\z\PTF\addons\tsp_animate\cba.sqf'";
	};
};
class CfgFunctions
{
	class tsp_animate
	{
		class functions
		{
			class functions
			{
				file = "\z\PTF\addons\tsp_animate\functions.sqf";
				preInit = "true";
			};
			class init
			{
				file = "\z\PTF\addons\tsp_animate\init.sqf";
				postInit = "true";
			};
		};
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class ACE_SelfActions
		{
			class ACE_Animations
			{
				displayName = "Animations";
				icon = "\z\ace\addons\gestures\UI\gestures_ca.paa";
				class tsp_ace_animate_cancel
				{
					displayName = "Cancel";
					icon = "\z\PTF\addons\tsp_animate\gui\cancel.paa";
					statement = "[_player, ''] remoteExec ['switchMove', 0]; (call tsp_fnc_playa) setVariable ['tsp_gestureStop', true];";
				};
				class tsp_ace_animate_emotes
				{
					displayName = "Emotes";
					icon = "\z\PTF\addons\tsp_animate\gui\emotes.paa";
				};
				class tsp_ace_animate_dances
				{
					displayName = "Dances";
					icon = "\z\PTF\addons\tsp_animate\gui\dances.paa";
				};
				class ace_gestures_cat_gestures
				{
					displayName = "Signals";
					icon = "\z\PTF\addons\tsp_animate\gui\signal.paa";
					condition = "(canStand _target)";
					statement = "";
					exceptions[] = {"isNotSwimming"};
					showDisabled = 1;
					class ace_gestures_Advance
					{
						displayName = "Advance";
						condition = "true";
						statement = "[_target, 'gestureAdvance'] call ace_common_fnc_doGesture";
						showDisabled = 1;
					};
					class ace_gestures_Go
					{
						displayName = "Go";
						condition = "true";
						statement = "[_target, selectRandom ['gestureGo', 'gestureGoB']] call ace_common_fnc_doGesture";
						showDisabled = 1;
					};
					class ace_gestures_Follow
					{
						displayName = "Follow";
						condition = "true";
						statement = "[_target, 'gestureFollow'] call ace_common_fnc_doGesture";
						showDisabled = 1;
					};
					class ace_gestures_Up
					{
						displayName = "Up";
						condition = "true";
						statement = "[_target, 'gestureUp'] call ace_common_fnc_doGesture";
						showDisabled = 1;
					};
					class ace_gestures_CeaseFire
					{
						displayName = "Cease Fire";
						condition = "true";
						statement = "[_target, 'gestureCeaseFire'] call ace_common_fnc_doGesture";
						showDisabled = 1;
					};
					class ace_gestures_Stop
					{
						displayName = "Stop";
						condition = "true";
						statement = "[_target, 'gestureFreeze'] call ace_common_fnc_doGesture";
						showDisabled = 1;
					};
					class ace_gestures_Forward
					{
						displayName = "Forward";
						condition = "true";
						statement = "'ace_gestures_forward' call ace_gestures_fnc_playSignal";
						exceptions[] = {"isNotSwimming"};
						showDisabled = 1;
					};
					class ace_gestures_Regroup
					{
						displayName = "Regroup";
						condition = "true";
						statement = "'ace_gestures_regroup' call ace_gestures_fnc_playSignal";
						exceptions[] = {"isNotSwimming"};
						showDisabled = 1;
					};
					class ace_gestures_Freeze
					{
						displayName = "Freeze";
						condition = "true";
						statement = "'ace_gestures_freeze' call ace_gestures_fnc_playSignal";
						exceptions[] = {"isNotSwimming"};
						showDisabled = 1;
					};
					class ace_gestures_Cover
					{
						displayName = "Cover";
						condition = "true";
						statement = "'ace_gestures_cover' call ace_gestures_fnc_playSignal";
						exceptions[] = {"isNotSwimming"};
						showDisabled = 1;
					};
					class ace_gestures_Point
					{
						displayName = "Point";
						condition = "true";
						statement = "'ace_gestures_point' call ace_gestures_fnc_playSignal";
						exceptions[] = {"isNotSwimming"};
						showDisabled = 1;
					};
					class ace_gestures_Engage
					{
						displayName = "Engage";
						condition = "true";
						statement = "'ace_gestures_engage' call ace_gestures_fnc_playSignal";
						exceptions[] = {"isNotSwimming"};
						showDisabled = 1;
					};
					class ace_gestures_Hold
					{
						displayName = "Hold";
						condition = "true";
						statement = "'ace_gestures_hold' call ace_gestures_fnc_playSignal";
						exceptions[] = {"isNotSwimming"};
						showDisabled = 1;
					};
					class ace_gestures_Warning
					{
						displayName = "Warning";
						condition = "true";
						statement = "'ace_gestures_warning' call ace_gestures_fnc_playSignal";
						exceptions[] = {"isNotSwimming"};
						showDisabled = 1;
					};
				};
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
		a2_duoivan = "a2_duoivan";
		a2_duostefan = "a2_duostefan";
		a2_stefan = "a2_stefan";
		a2_zozo = "a2_zozo";
		a2_metal = "a2_metal";
		tsp_animate_bird_in[] = {"tsp_animate_bird_in","Gesture"};
		tsp_animate_bird_loop[] = {"tsp_animate_bird_loop","Gesture"};
		tsp_animate_ok_in[] = {"tsp_animate_ok_in","Gesture"};
		tsp_animate_ok_loop[] = {"tsp_animate_ok_loop","Gesture"};
		tsp_animate_jackoff_loop[] = {"tsp_animate_jackoff_loop","Gesture"};
		tsp_animate_jackoff_out[] = {"tsp_animate_jackoff_out","Gesture"};
		tsp_animate_mahalo_loop[] = {"tsp_animate_mahalo_loop","Gesture"};
		tsp_animate_mic[] = {"tsp_animate_mic","Gesture"};
		tsp_animate_mic2[] = {"tsp_animate_mic2","Gesture"};
		tsp_animate_horns_loop[] = {"tsp_animate_horns_loop","Gesture"};
		tsp_animate_peace_loop[] = {"tsp_animate_peace_loop","Gesture"};
		tsp_animate_nightvision_up[] = {"tsp_animate_nightvision_up","Gesture"};
		tsp_animate_nightvision_down[] = {"tsp_animate_nightvision_down","Gesture"};
		tsp_animate_door[] = {"tsp_animate_door","Gesture"};
		tsp_animate_door_gun[] = {"tsp_animate_door_gun","Gesture"};
		tsp_animate_door_close[] = {"tsp_animate_door_close","Gesture"};
		tsp_animate_door_close_gun[] = {"tsp_animate_door_close_gun","Gesture"};
		tsp_animate_map_in[] = {"tsp_animate_map_in","Gesture"};
		tsp_animate_map_loop[] = {"tsp_animate_map_loop","Gesture"};
		tsp_animate_dab_loop[] = {"tsp_animate_dab_loop","Gesture"};
		tsp_animate_rockpaperscissors_in[] = {"tsp_animate_rockpaperscissors_in","Gesture"};
		tsp_animate_rockpaperscissors_rock_loop[] = {"tsp_animate_rockpaperscissors_rock_loop","Gesture"};
		tsp_animate_rockpaperscissors_paper_loop[] = {"tsp_animate_rockpaperscissors_paper_loop","Gesture"};
		tsp_animate_rockpaperscissors_scissors_loop[] = {"tsp_animate_rockpaperscissors_scissors_loop","Gesture"};
		tsp_animate_lowready_rifle_object[] = {"tsp_animate_lowready_rifle_object","Gesture"};
		tsp_animate_highready_rifle_object[] = {"tsp_animate_highready_rifle_object","Gesture"};
		tsp_animate_highready_rifle_friend[] = {"tsp_animate_highready_rifle_friend","Gesture"};
		tsp_animate_lowready_rifle_friend[] = {"tsp_animate_lowready_rifle_friend","Gesture"};
		tsp_animate_highready_rifle_manual[] = {"tsp_animate_highready_rifle_manual","Gesture"};
		tsp_animate_lowready_rifle_manual[] = {"tsp_animate_lowready_rifle_manual","Gesture"};
		tsp_animate_highready_pistol_object[] = {"tsp_animate_highready_pistol_object","Gesture"};
		tsp_animate_highready_pistol_friend[] = {"tsp_animate_highready_pistol_friend","Gesture"};
		tsp_animate_lowready_pistol_friend[] = {"tsp_animate_lowready_pistol_friend","Gesture"};
		tsp_animate_highready_pistol_manual[] = {"tsp_animate_highready_pistol_manual","Gesture"};
		tsp_animate_lowready_pistol_manual[] = {"tsp_animate_lowready_pistol_manual","Gesture"};
		tsp_animate_stopReady[] = {"tsp_animate_stopReady","Gesture"};
		tsp_animate_suicide_pistol_in[] = {"tsp_animate_suicide_pistol_in","Gesture"};
		tsp_animate_suicide_pistol_loop[] = {"tsp_animate_suicide_pistol_loop","Gesture"};
		tsp_animate_suicide_rifle_in[] = {"tsp_animate_suicide_rifle_in","Gesture"};
		tsp_animate_suicide_rifle_loop[] = {"tsp_animate_suicide_rifle_loop","Gesture"};
		tsp_animate_inspect_rifle[] = {"tsp_animate_inspect_rifle","Gesture"};
		tsp_animate_inspect_pistol[] = {"tsp_animate_inspect_pistol","Gesture"};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class CutSceneAnimationBase;
		class a2_duoivan: CutSceneAnimationBase
		{
			file = "\z\PTF\addons\tsp_animate\anim\ActsPercMstpSnonWnonDnon_DancingDuoIvan.rtm";
			speed = 0.025;
			showHandGun = "true";
			canPullTrigger = "true";
			weaponLowered = "false";
			disableWeapons = "false";
			disableWeaponsLong = "false";
			head = "headDefault";
			interpolationSpeed = 2;
			InterpolateTo[] = {"AmovPercMstpSnonWnonDnon",1};
			InterpolateFrom[] = {"AmovPercMstpSnonWnonDnon",1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
			weaponIK = 0;
		};
		class a2_duostefan: a2_duoivan
		{
			file = "\z\PTF\addons\tsp_animate\anim\ActsPercMstpSnonWnonDnon_DancingDuoStefan.rtm";
			speed = 0.025;
		};
		class a2_stefan: a2_duoivan
		{
			file = "\z\PTF\addons\tsp_animate\anim\ActsPercMstpSnonWnonDnon_DancingStefan.rtm";
			speed = 0.0104;
		};
		class a2_zozo: a2_duoivan
		{
			file = "\z\PTF\addons\tsp_animate\anim\ZozinoDancing.rtm";
			speed = 0.03413;
		};
		class a2_metal: a2_duoivan
		{
			file = "\z\PTF\addons\tsp_animate\anim\MadMetalDancing.rtm";
			speed = 0.019036;
		};
		class Acts_Dance_01: CutSceneAnimationBase
		{
			interpolateTo[] = {"amovpercmstpsnonwnondnon",100,"Unconscious",0.02};
			interpolateFrom[] = {"amovpercmstpsnonwnondnon",100};
			interpolationSpeed = 1;
		};
		class Acts_Dance_02: CutSceneAnimationBase
		{
			interpolateTo[] = {"amovpercmstpsnonwnondnon",100,"Unconscious",0.02};
			interpolateFrom[] = {"amovpercmstpsnonwnondnon",100};
			interpolationSpeed = 1;
		};
	};
};
class CfgGesturesMale
{
	skeletonName = "OFP2_ManSkeleton";
	class Default{};
	class States
	{
		class GestureNo;
		class tsp_animate_bird_in: GestureNo
		{
			file = "\z\PTF\addons\tsp_animate\anim\bird_in.rtm";
			mask = "rightArmAndNeck";
			speed = 1.5;
			interpolationSpeed = 3;
			rightHandIKCurve[] = {};
			leftHandIKCurve[] = {1};
		};
		class tsp_animate_bird_loop: tsp_animate_bird_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\bird_loop.rtm";
			interpolationSpeed = 1;
			speed = 0.5;
			looped = "true";
		};
		class tsp_animate_ok_in: tsp_animate_bird_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\ok_in.rtm";
			speed = 1.5;
		};
		class tsp_animate_ok_loop: tsp_animate_bird_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\ok_loop.rtm";
			speed = 0.5;
		};
		class tsp_animate_jackoff_loop: tsp_animate_bird_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\jackoff_loop.rtm";
			speed = 2.5;
		};
		class tsp_animate_jackoff_out: tsp_animate_bird_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\jackoff_out.rtm";
			speed = 1.5;
		};
		class tsp_animate_mahalo_loop: tsp_animate_bird_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\mahalo_loop.rtm";
			speed = 1.5;
		};
		class tsp_animate_mic: tsp_animate_mahalo_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\mic.rtm";
			showHandgun = "true";
			rightHandIKCurve[] = {1};
		};
		class tsp_animate_mic2: tsp_animate_mic
		{
			file = "\z\PTF\addons\tsp_animate\anim\mic2.rtm";
		};
		class tsp_animate_horns_loop: tsp_animate_bird_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\horns_loop.rtm";
			mask = "leftArmAndNeck";
			speed = 1.5;
			rightHandIKCurve[] = {1};
			leftHandIKCurve[] = {};
		};
		class tsp_animate_peace_loop: tsp_animate_horns_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\peace_loop.rtm";
			speed = 0.5;
		};
		class tsp_animate_nightvision_up: tsp_animate_bird_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\nightvision_up.rtm";
			mask = "leftArm";
			speed = 1.5;
			rightHandIKCurve[] = {1};
			leftHandIKCurve[] = {0,1,0.2,0,0.8,0,1,1};
		};
		class tsp_animate_nightvision_down: tsp_animate_nightvision_up
		{
			file = "\z\PTF\addons\tsp_animate\anim\nightvision_down.rtm";
		};
		class tsp_animate_door: tsp_animate_nightvision_up
		{
			enableOptics = "true";
			file = "\z\PTF\addons\tsp_animate\anim\door.rtm";
		};
		class tsp_animate_door_gun: tsp_animate_door
		{
			file = "\z\PTF\addons\tsp_animate\anim\door_gun.rtm";
		};
		class tsp_animate_door_close: tsp_animate_door
		{
			file = "\z\PTF\addons\tsp_animate\anim\door_close.rtm";
		};
		class tsp_animate_door_close_gun: tsp_animate_door_gun
		{
			file = "\z\PTF\addons\tsp_animate\anim\door_close_gun.rtm";
		};
		class tsp_animate_map_in: tsp_animate_nightvision_up
		{
			file = "\z\PTF\addons\tsp_animate\anim\map_in.rtm";
		};
		class tsp_animate_map_loop: tsp_animate_horns_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\map_loop.rtm";
		};
		class tsp_animate_dab_loop: tsp_animate_bird_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\dab_loop.rtm";
			mask = "bothArmsAndNeck";
			speed = 0.5;
			rightHandIKCurve[] = {1};
			leftHandIKCurve[] = {1};
			disableWeapons = 0;
		};
		class tsp_animate_rockpaperscissors_in: tsp_animate_bird_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\rockpaperscissors_in.rtm";
			mask = "bothArmsAndNeck";
			speed = 1;
			rightHandIKCurve[] = {1};
			leftHandIKCurve[] = {1};
			disableWeapons = "false";
			interpolationSpeed = 2;
		};
		class tsp_animate_rockpaperscissors_rock_loop: tsp_animate_dab_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\rockpaperscissors_rock_loop.rtm";
			interpolationSpeed = 5;
		};
		class tsp_animate_rockpaperscissors_paper_loop: tsp_animate_rockpaperscissors_rock_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\rockpaperscissors_paper_loop.rtm";
		};
		class tsp_animate_rockpaperscissors_scissors_loop: tsp_animate_rockpaperscissors_rock_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\rockpaperscissors_scissors_loop.rtm";
		};
		class tsp_animate_suicide_pistol_in: tsp_animate_dab_loop
		{
			file = "\z\PTF\addons\tsp_animate\anim\suicide_pistol_in.rtm";
			speed = 0.15;
			mask = "suicidePistol";
			rightHandIKCurve[] = {1};
			looped = "false";
		};
		class tsp_animate_suicide_pistol_loop: tsp_animate_suicide_pistol_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\suicide_pistol_loop.rtm";
			looped = "true";
		};
		class tsp_animate_suicide_rifle_in: tsp_animate_suicide_pistol_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\suicide_rifle_in.rtm";
			mask = "suicideRifle";
			leftHandIKCurve[] = {1};
		};
		class tsp_animate_suicide_rifle_loop: tsp_animate_suicide_rifle_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\suicide_rifle_loop.rtm";
			looped = "true";
		};
		class tsp_animate_inspect_rifle: tsp_animate_suicide_rifle_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\inspect_rifle.rtm";
		};
		class tsp_animate_inspect_pistol: tsp_animate_suicide_pistol_in
		{
			file = "\z\PTF\addons\tsp_animate\anim\inspect_pistol.rtm";
		};
		class tsp_animate_lowready_rifle_object: GestureNo
		{
			file = "\z\PTF\addons\tsp_animate\anim\lowready_rifle_object.rtm";
			mask = "readyRifle";
			looped = "true";
			interpolationSpeed = 5;
			rightHandIKCurve[] = {1};
			leftHandIKCurve[] = {1};
			enableBinocular = "true";
			enableMissile = "true";
			disableWeapons = "false";
			disableWeaponsLong = "false";
			enableOptics = "false";
		};
		class tsp_animate_highready_rifle_object: tsp_animate_lowready_rifle_object
		{
			mask = "readyRifleAndArm";
			file = "\z\PTF\addons\tsp_animate\anim\highready_rifle_object.rtm";
		};
		class tsp_animate_highready_rifle_friend: tsp_animate_lowready_rifle_object
		{
			file = "\z\PTF\addons\tsp_animate\anim\highready_rifle_friend.rtm";
			disableWeapons = "true";
			disableWeaponsLong = "true";
			canPullTrigger = "false";
		};
		class tsp_animate_lowready_rifle_friend: tsp_animate_highready_rifle_friend
		{
			file = "\z\PTF\addons\tsp_animate\anim\lowready_rifle_friend.rtm";
		};
		class tsp_animate_highready_rifle_manual: tsp_animate_highready_rifle_friend{};
		class tsp_animate_lowready_rifle_manual: tsp_animate_lowready_rifle_friend{};
		class tsp_animate_highready_pistol_object: tsp_animate_lowready_rifle_object
		{
			file = "\z\PTF\addons\tsp_animate\anim\highready_pistol_object.rtm";
			mask = "readyPistol";
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};
		class tsp_animate_highready_pistol_friend: tsp_animate_highready_pistol_object
		{
			file = "\z\PTF\addons\tsp_animate\anim\highready_pistol_friend.rtm";
			disableWeapons = "true";
			disableWeaponsLong = "true";
			canPullTrigger = "false";
		};
		class tsp_animate_lowready_pistol_friend: tsp_animate_highready_pistol_friend
		{
			file = "\z\PTF\addons\tsp_animate\anim\highready_pistol_friend.rtm";
		};
		class tsp_animate_highready_pistol_manual: tsp_animate_highready_pistol_friend{};
		class tsp_animate_lowready_pistol_manual: tsp_animate_lowready_pistol_friend{};
		class GestureAdvance;
		class tsp_animate_stopReady: GestureAdvance
		{
			enableOptics = 1;
			file = "";
			speed = 5000;
		};
	};
	class BlendAnims
	{
		suicideRifle[] = {"Neck",1,"weapon",1,"Spine",1,"Spine1",0.1,"Spine2",0,"Spine3",0,"Neck",0};
		suicidePistol[] = {"neck",1,"neck1",1,"head",1,"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandThumb",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"Spine",1,"Spine1",0.1,"Spine2",0,"Spine3",0};
		readyRifle[] = {"weapon",1,"Spine",0.2,"Spine1",0.1,"Spine2",0,"Spine3",0,"Neck",0};
		readyRifleAndArm[] = {"weapon",1,"Spine",0.2,"Spine1",0.1,"Spine2",0,"Spine3",0,"Neck",0,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1};
		readyPistol[] = {"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1};
		bothArmsAndNeck[] = {"neck",0.25,"neck1",0.25,"head",0.25,"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandThumb",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandThumb",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1};
		rightArmAndNeck[] = {"neck",0.25,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"RightHandRing",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1};
		leftArmAndNeck[] = {"neck",0.5,"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1};
	};
};
class cfgMods
{
	author = "ASmallDinosaur";
	timepacked = "1659637021";
};
