/*
	Last edited 2019-02-03 by Erik Kofahl for TSOG
	2019-02-03 - Adding CBA settings interface to turn off GUI + CBA XEH to init 
	2019-02-03 - Adding CBA Keybinds
	2019-02-14 - Moving displayed coordinates so they fit in the RHS A-10 "TV" in 10 digit mode
	2019-11-30 - Adding Azimuth and Elevation Indicators
	2020-08-24 - Adding altitude command
	2026 Version (Goltred): new functions are named GLT_fnc_* (registered in class GLT below, files in
	functions\ next to the originals). Edits to original code are marked "GLT:".
	GLT 2026-09-29/30 - HEMTT build fixes (quoted UI expressions, units[], ST_CENTER), requiredVersion 2.14
	GLT 2026-09-30 - file paths built with GLT_QPATH() from GLT_PREFIX (script_name.hpp); prefix is Turret_Enhanced_2026
*/

#include "script_name.hpp"	// GLT: GLT_MOD_NAME, GLT_PREFIX / GLT_QPATH (file paths)
#include "dialogs\changeAltitude.h"
#include "dialogs\changeLoiter.h"
#include "dialogs\markerText.h"	// GLT
#include "dialogs\markerList.h"	// GLT

class CfgPatches
{
	class UAV_Turret_Markers
	{
		units[] = {};	// GLT: was {"Helicopter", "UAV"}: units[] must only list classes this addon defines
		weapons[] = {};
		requiredVersion = 2.14;	// GLT: hashmaps, lockCameraTo "temporary", mission EH arguments
		requiredAddons[] = {"A3_Data_F_Sams_LoadOrder","cba_main"};
		version = "0.2.0";	// GLT: keep in sync with script_version.hpp (read by HEMTT)
		author = "Goltred";
		name = GLT_MOD_NAME;	// GLT: display name
	};
};

class Extended_PreInit_EventHandlers 
{
    class My_pre_init_event 
	{
        init = GLT_QUOTE(GLT_COMPILE(XEH_preInit.sqf));	// GLT: path from GLT_PREFIX
    };
};

class Extended_PostInit_EventHandlers	// GLT: keybinds, local marker counter, overlay / laser map
{
    class GLT_TE_postInit
	{
        init = GLT_QUOTE(GLT_COMPILE(XEH_postInit.sqf));
    };
};



// GLT: announce who owns each new laser spot (GLT_fnc_laserCreated), so other players' handheld
// designators can be shown in the camera view. Same hook ACE uses; the two EventHandlers classes merge.
class CfgVehicles
{
	class All;
	class LaserTarget: All
	{
		class EventHandlers
		{
			class GLT_TurretEnhanced
			{
				init = "_this call GLT_fnc_laserCreated";
			};
		};
	};
};

class CfgFunctions
{
	class fatLurch
	{
		class Lurch_Functions2
		{
			class MPaddaction
			{
				file = GLT_QPATH(functions\MPaddaction.sqf);
			};
			
			class North_Ind
			{
				file = GLT_QPATH(functions\North_Ind.sqf);
			};
			
			class isViewISR
			{
				file = GLT_QPATH(functions\isViewISR.sqf);
			};
			
			class turretAzEl
			{
				file = GLT_QPATH(functions\turretAzEl.sqf);
			};
			
			class hasOpticsIn 
			{
				file = GLT_QPATH(functions\hasOpticsIn.sqf);
				//Usage: [_player, _vehicle]call fatLurch_fnc_hasOpticsIn;
			};
			
			class changeAltitude
			{
				file = GLT_QPATH(functions\changeAltitude.sqf);
			};
			
			class altitudeDialogClose
			{
				file = GLT_QPATH(functions\altitudeDialogClose.sqf);
			};
			
			class blacklistGUI
			{
				file = GLT_QPATH(functions\blacklistGUI.sqf);
			};
			
			class getTurretIndex
			{
				file = GLT_QPATH(functions\getTurretIndex.sqf);
			};
			
			class mapSlew
			{
				file = GLT_QPATH(functions\mapSlew.sqf);
			};

			class inputGrid
			{
				file = GLT_QPATH(functions\inputGrid.sqf);
			};
			
			class measDistance
			{
				file = GLT_QPATH(functions\measDistance.sqf);
			};
			
			class getPylonAmmo
			{
				file = GLT_QPATH(functions\getPylonAmmo.sqf);
			};
			
			class weaponReport
			{
				file = GLT_QPATH(functions\weaponReport.sqf);
			};

			class resetUAV
			{
				file = GLT_QPATH(functions\resetUAV.sqf);
			};

			class changeLoiter
			{
				file = GLT_QPATH(functions\changeLoiter.sqf);
			};

			class loiterDialogClose
			{
				file = GLT_QPATH(functions\loiterDialogClose.sqf);
			};
			
			class getISRparams
			{
				file = GLT_QPATH(functions\getISRParams.sqf);
			};
			
			class H60check
			{
				file = GLT_QPATH(functions\h60check.sqf);
			};

			/*
			class blacklistActions
			{
				file = GLT_QPATH(functions\blacklistActions.sqf);
			};
			*/
		};
	};

	// GLT: functions added in the 2026 Version (GLT_fnc_<name>), files in functions\ next to the originals
	class GLT
	{
		class TurretEnhanced
		{
			class addMarker {file = GLT_QPATH(functions\addMarker.sqf);};
			class buildOverlayList {file = GLT_QPATH(functions\buildOverlayList.sqf);};
			class cycleMarkerOverlay {file = GLT_QPATH(functions\cycleMarkerOverlay.sqf);};
			class drawLaserOverlay {file = GLT_QPATH(functions\drawLaserOverlay.sqf);};
			class drawLaserMap {file = GLT_QPATH(functions\drawLaserMap.sqf);};
			class drawMarkerOverlay {file = GLT_QPATH(functions\drawMarkerOverlay.sqf);};
			class friendlyLasers {file = GLT_QPATH(functions\friendlyLasers.sqf);};
			class getISRVehicle {file = GLT_QPATH(functions\getISRVehicle.sqf);};
			class isEnabledFor {file = GLT_QPATH(functions\isEnabledFor.sqf);};
			class isMQ9 {file = GLT_QPATH(functions\isMQ9.sqf);};
			class keyName {file = GLT_QPATH(functions\keyName.sqf);};
			class laserCreated {file = GLT_QPATH(functions\laserCreated.sqf);};
			class laserInfo {file = GLT_QPATH(functions\laserInfo.sqf);};
			class markerActionTitle {file = GLT_QPATH(functions\markerActionTitle.sqf);};
			class markerDialog {file = GLT_QPATH(functions\markerDialog.sqf);};
			class markerLabel {file = GLT_QPATH(functions\markerLabel.sqf);};
			class markerList {file = GLT_QPATH(functions\markerList.sqf);};
			class markerSlotInfo {file = GLT_QPATH(functions\markerSlotInfo.sqf);};
			class markerStyle {file = GLT_QPATH(functions\markerStyle.sqf);};
			class overlayInit {file = GLT_QPATH(functions\overlayInit.sqf);};
			class overlayModes {file = GLT_QPATH(functions\overlayModes.sqf);};
			class placeMarker {file = GLT_QPATH(functions\placeMarker.sqf);};
			class slewMonitor {file = GLT_QPATH(functions\slewMonitor.sqf);};
			class slewTo {file = GLT_QPATH(functions\slewTo.sqf);};
			class updateMarkerActions {file = GLT_QPATH(functions\updateMarkerActions.sqf);};
		};
	};
};

// GLT: the original init event handlers below are disabled. They ran fatLurch_fnc_MPaddaction for every
// plane / helicopter on every machine (each starting a 200 Hz HUD loop). GLT_fnc_overlayInit now runs
// MPaddaction lazily, per player, the first time they look through a vehicle's camera, for every
// vehicle type enabled in Addon Options > Vehicle Types (helicopters, planes).
/*
class Extended_Init_EventHandlers 
{
	class air;
    class plane:air 
	{
        class Fat_Lurch_plane_eh
		{
            init = "(_this select 0) spawn fatLurch_fnc_MPaddaction";
        };
    };
	
	class Helicopter:air 
	{
        class Fat_Lurch_Helicopter_eh
		{
            init = "(_this select 0) spawn fatLurch_fnc_MPaddaction";
        };
    };
	
};
*/

class RscTitles
{
	class North
	{    
		idd = 710;
		fadein = 0;
		fadeout = 0;
		duration = .1;
		//onLoad = "_this call onRscLoad"; //UI event handler
		//onLoad = "uiNameSpace setVariable ['myUI_LevelTitle', (_this select 0) displayCtrl 654];";
		onLoad = "uiNameSpace setVariable ['myUI_LevelTitle', (_this select 0) displayCtrl 654];";
		class controls
		{
			class ExampleControl
			{    
				idc = 709;
				type = 0;	//Keep this (single line text)
				style = 2;	//-2 is center aligned text			
				x = "uiNamespace getVariable 'newPosition' select 0"; 
				y = "uiNamespace getVariable 'newPosition' select 1";
				w = 1;
				h = 1;
				font = "EtelkaNarrowMediumPro";
				sizeEx = 0.05;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				text = "N";
			};  
			
			class ExampleControl654
			{    
				idc = 654;
				type = 0;
				style = 0;
				x = .845; 	//Was 0.9. Updated to fit in RHS A-10 display
				y = .6;
				w = 1;
				h = 1;
				font = "RobotoCondensedLight";
				sizeEx = 0.05;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				//text = "uiNamespace getVariable 'newPosition' select 2";
				text="";
			};  
		};
	};
	class El
	{ 
		//Series of elevation controls relating to the vehicle turret. Controlled by CBA setting Fat_Lurch_ShowEl in CBA
		idd = 709;
		fadein = 0;
		fadeout = 0;
		duration = .1;
		//onLoad = "_this call onRscLoad"; //UI event handler
		//onLoad = "uiNameSpace setVariable ['myUI_LevelTitle', (_this select 0) displayCtrl 654];";
		onLoad = "uiNameSpace setVariable ['guiEl', (_this select 0) displayCtrl 655];";
		class controls
		{
			class elControl655
			{    
				//Moving Elevation indicator
				idc = 655;
				type = 0;
				style = 0;	// GLT: was ST_CENTER, a macro that was never defined, so the engine read it as 0 (left). Kept as 0 to preserve the on-screen layout
				x = -0.1; 	
				y = "uiNamespace getVariable 'guiElPos'"; 	//calculated in North_Ind.sqf
				//y = 0;//0 = CL, - above CL, + below CL?
				w = 1;
				h = 1;
				font = "RobotoCondensedLight";
				sizeEx = 0.05;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				text="";
			};  
			class elevation
			{    
				//Static Elevation scale image
				idc = 660;
				type = 0;
				style=2096;
				x = -0.32; 	
				y = 0.35; //Updated from 0.25 to attempt to work better with USAF MQ-9
				w = 0.7;
				h = 0.55;
				font = "RobotoCondensedLight";
				sizeEx = 0.05;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				text=GLT_QPATH(images\Elevation.paa);
			};
		};
	};
	class Az
	{    
		//Series of Azimuth controls relating to the vehicle turret. Controlled by CBA setting Fat_Lurch_ShowAz in CBA
		idd = 708;
		fadein = 0;
		fadeout = 0;
		duration = .1;
		//onLoad = "_this call onRscLoad"; //UI event handler
		//onLoad = "uiNameSpace setVariable ['myUI_LevelTitle', (_this select 0) displayCtrl 654];";
		onLoad = "uiNameSpace setVariable ['guiAz', (_this select 0) displayCtrl 656]; uiNameSpace setVariable ['guiHdg', (_this select 0) displayCtrl 657];";
		class controls
		{
				//Shit goes here
			class azControl656
			{    
				//Moving Az indicator for turret (-180 (Full left) to 180 (Full right)
				idc = 656;
				type = 0;
				style = 2;
				x = "uiNamespace getVariable 'guiAzPos'"; 
				y = -0.46;//0 = CL, - above CL, + below CL?
				w = 0.1;
				h = 1;
				font = "RobotoCondensedLight";
				sizeEx = 0.05;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				text="";
			};  
			class headingControl657
			{    
				//Current Vehicle Heading. Static, centered above compass 
				idc = 657;
				type = 0;
				style=162;
				x = 0.46; 	//(0.5 = center - Width of control (0.08))
				y = -0.09;//0 = CL, - above CL, + below CL?
				w = 0.08;
				h = 0.05;
				font = "RobotoCondensedLight";
				sizeEx = 0.05;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				text="";
			};
			class compass
			{    
				//Static Compass image
				idc = 658;
				type = 0;
				style=2096;
				x = 0.35; 	
				y = -0.125;//0 = CL, - above CL, + below CL?
				w = .3;
				h = .2;
				font = "RobotoCondensedLight";
				sizeEx = 0.05;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				text=GLT_QPATH(images\Compass.paa);
			};
			class compassArrow
			{
				//Moving Compass arrow that follows the Az indicator 
				idc = 659;
				type = 0;
				style=2096;
				x = "(uiNamespace getVariable 'guiAzPos')+0.0375"; 
				y = -0.005;//0 = CL, - above CL, + below CL?
				w = .025;
				h = .025;
				font = "RobotoCondensedLight";
				sizeEx = 0.05;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				text=GLT_QPATH(images\CompassArrow.paa);
			};
		};
	};
};
class inputCoords
{
	idd = 585;
	fadein = 0;
	fadeout = 0;
	duration = 1e11;
	//onUnload = "uiNamespace setVariable [""someDialog"", nil];";
	onUnload = "uiNamespace setVariable [""coordReturn"", (_this select 1)];";
	
	class controls
	{
		class RscText
		{
			idc = 1000;
			type=0;
			style=16;
			text = "Input Target Grid"; //--- ToDo: Localize;
			x = "0.446146 * safezoneW + safezoneX";
			y = "0.649667 * safezoneH + safezoneY";
			w = "0.0670312 * safezoneW";
			h = "0.022 * safezoneH";
			font = "PuristaMedium";
			lineSpacing=1;
			sizeEx = 0.03;
			colorSelection[] = {-1,-1,-1,-1};
			colorText[] = {1,1,1,1};
			colorDisabled[] = {-1,-1,-1,-1}; 
			colorBackground[] = {0,0,0,0.7};
		};
		class RscEdit
		{
			idc = 1400;
			maxChars=10;
			//forceDrawCaret = true;
			type = 2;
			style=16;
			x = "0.446374 * safezoneW + safezoneX";
			y = "0.676 * safezoneH + safezoneY";
			w = "0.0670312 * safezoneW";
			h = "0.022 * safezoneH";
			font = "PuristaMedium";
			autoComplete="";
			sizeEx = 0.03;
			colorSelection[] = {-1,-1,-1,-1};
			colorText[] = {1,1,1,1};
			colorDisabled[] = {-1,-1,-1,-1}; 
			colorBackground[] = {0,0,0,0.7};
			text="";
		};
		class RscButton
		{
			idc = 1600;
			type=1;
			style=16;
			action="closeDialog 1;_ctrl=(findDisplay 585) displayCtrl 1400;coords = ctrlText _ctrl;_ctrl ctrlSetText '';";
			text = "ENTER"; //--- ToDo: Localize;
			x = "0.517532 * safezoneW + safezoneX";
			y = "0.6496 * safezoneH + safezoneY";
			w = "0.0309375 * safezoneW";
			h = "0.044 * safezoneH";
			font = "PuristaMedium";
			sizeEx = 0.03;
			colorSelection[] = {-1,-1,-1,-1};
			colorText[] = {1,1,1,1};
			colorDisabled[] = {-1,-1,-1,-1}; 
			colorBackground[] = {0,0,0,0.7};
			soundEnter[] = {"",0.1,1};
			soundPush[] = {"",0.1,1};
			soundClick[] = {"",0.1,1};
			soundEscape[] = {"",0.1,1};
			colorBackgroundDisabled[] = {0.6,0.6,0.6,1};
			colorBackgroundActive[] = {1,0.5,0,1};
			colorFocused[] = {0,0,0,1};
			colorShadow[] = {0,0,0,1};
			offsetX = 0.004;
			offsetY = 0.004;
			offsetPressedX = 0.002;
			offsetPressedY = 0.002;
			borderSize = 0.008;
			colorBorder[] = {0,0,0,1};
			tooltip="Enter on numpad to commit. Escape key to cancel";
		};
		
	};
};

/*
class changeAltitude
{
	idd = 586;
	fadein = 0;
	fadeout = 0;
	duration = 1e11;
	onUnload = "uiNamespace setVariable [""coordReturn"", (_this select 1)];";		//TODO
	
	class controls
	{
		class RscText
		{
			idc = 1000;
			type=0;
			style=16;
			text = "Input New Altitude (Meters)"; //--- ToDo: Localize;
			x = "0.446146 * safezoneW + safezoneX";
			y = "0.649667 * safezoneH + safezoneY";
			w = "0.0670312 * safezoneW";
			h = "0.022 * safezoneH";
			font = "PuristaMedium";
			lineSpacing=1;
			sizeEx = 0.03;
			colorSelection[] = {-1,-1,-1,-1};
			colorText[] = {1,1,1,1};
			colorDisabled[] = {-1,-1,-1,-1}; 
			colorBackground[] = {0,0,0,0.7};
		};
		class RscEdit
		{
			idc = 1400;
			maxChars=10;
			//forceDrawCaret = true;
			type = 2;
			style=16;
			x = "0.446374 * safezoneW + safezoneX";
			y = "0.676 * safezoneH + safezoneY";
			w = "0.0670312 * safezoneW";
			h = "0.022 * safezoneH";
			font = "PuristaMedium";
			autoComplete="";
			sizeEx = 0.03;
			colorSelection[] = {-1,-1,-1,-1};
			colorText[] = {1,1,1,1};
			colorDisabled[] = {-1,-1,-1,-1}; 
			colorBackground[] = {0,0,0,0.7};
			text="";
		};
		class RscButton
		{
			idc = 1600;
			type=1;
			style=16;
			action="closeDialog 1;_ctrl=(findDisplay 586) displayCtrl 1400;coords = ctrlText _ctrl;_ctrl ctrlSetText '';";		//TODO
			text = "ENTER"; //--- ToDo: Localize;
			x = "0.517532 * safezoneW + safezoneX";
			y = "0.6496 * safezoneH + safezoneY";
			w = "0.0309375 * safezoneW";
			h = "0.044 * safezoneH";
			font = "PuristaMedium";
			sizeEx = 0.03;
			colorSelection[] = {-1,-1,-1,-1};
			colorText[] = {1,1,1,1};
			colorDisabled[] = {-1,-1,-1,-1}; 
			colorBackground[] = {0,0,0,0.7};
			soundEnter[] = {"",0.1,1};
			soundPush[] = {"",0.1,1};
			soundClick[] = {"",0.1,1};
			soundEscape[] = {"",0.1,1};
			colorBackgroundDisabled[] = {0.6,0.6,0.6,1};
			colorBackgroundActive[] = {1,0.5,0,1};
			colorFocused[] = {0,0,0,1};
			colorShadow[] = {0,0,0,1};
			offsetX = 0.004;
			offsetY = 0.004;
			offsetPressedX = 0.002;
			offsetPressedY = 0.002;
			borderSize = 0.008;
			colorBorder[] = {0,0,0,1};
			tooltip="Enter on numpad to commit. Escape key to cancel";
		};
		
	};
};
*/


// GLT: Options > Controls actions (keyboard, mouse, joystick / HOTAS). Handlers in XEH_postInit.sqf
class CfgUserActions
{
	class GLT_markSlot1
	{
		displayName = "Mark Target (Marker 1)";
		tooltip = "Places marker 1 at the crosshair. Icon, colour and prefix: Addon Options > Turret Enhanced (2026 Version) > Marker 1";
		onActivate = "";
		onDeactivate = "";
		onAnalog = "";
		analogChangeThreshold = 0.01;
		modifierBlocking = 1;	// SHIFT+1 blocks the plain "1" action
	};
	class GLT_markSlot2: GLT_markSlot1
	{
		displayName = "Mark Target (Marker 2)";
		tooltip = "Places marker 2 at the crosshair. Icon, colour and prefix: Addon Options > Turret Enhanced (2026 Version) > Marker 2";
	};
	class GLT_markSlot3: GLT_markSlot1
	{
		displayName = "Mark Target (Marker 3)";
		tooltip = "Places marker 3 at the crosshair. Icon, colour and prefix: Addon Options > Turret Enhanced (2026 Version) > Marker 3";
	};
	class GLT_markSlot4: GLT_markSlot1
	{
		displayName = "Mark Target (Marker 4)";
		tooltip = "Places marker 4 at the crosshair. Icon, colour and prefix: Addon Options > Turret Enhanced (2026 Version) > Marker 4";
	};
	class GLT_markerList: GLT_markSlot1
	{
		displayName = "Marker List";
		tooltip = "Open the list of your markers: slew the camera to one, delete, hide / unhide";
	};
	class GLT_measure: GLT_markSlot1
	{
		displayName = "Measure Distance (start / finish)";
		tooltip = "Press once to set the start point, slew, press again to get distance and heading";
	};
	class GLT_resetMarkerCounter: GLT_markSlot1
	{
		displayName = "Reset Marker Counter";
		tooltip = "Resets your local marker numbering back to 0";
	};
	class GLT_cycleMarkerOverlay: GLT_markSlot1
	{
		displayName = "Cycle Camera Overlay (declutter / lasers / markers)";
		tooltip = "Cycles what the camera view shows: Declutter (nothing), No markers (lasers only), My markers, All map markers. Modes the server doesn't allow are skipped";
	};
};

class UserActionGroups
{
	class GLT_TurretEnhanced
	{
		name = GLT_MOD_NAME;
		isAddon = 1;
		group[] = {
			"GLT_markSlot1", "GLT_markSlot2", "GLT_markSlot3", "GLT_markSlot4",
			"GLT_markerList", "GLT_measure", "GLT_resetMarkerCounter", "GLT_cycleMarkerOverlay"
		};
	};
};

// Default keys. Combined keys are written as pre-calculated numbers, as recommended by the BI wiki
// (adding the values at runtime can round wrongly): Left Shift = 0x2A000000, + DIK code of the key.
class CfgDefaultKeysPresets
{
	class Arma2
	{
		class Mappings
		{
			GLT_markSlot1[] = {704643074};	// Left Shift + 1  (0x2A000000 + 0x02)
			GLT_markSlot2[] = {704643075};	// Left Shift + 2  (0x2A000000 + 0x03)
			GLT_markSlot3[] = {704643076};	// Left Shift + 3  (0x2A000000 + 0x04)
			GLT_markSlot4[] = {704643077};	// Left Shift + 4  (0x2A000000 + 0x05)
			GLT_markerList[] = {704643078};	// Left Shift + 5  (0x2A000000 + 0x06)
			GLT_measure[] = {704643079};	// Left Shift + 6  (0x2A000000 + 0x07)
			GLT_resetMarkerCounter[] = {};	// unbound
			GLT_cycleMarkerOverlay[] = {704643080};	// Left Shift + 7  (0x2A000000 + 0x08)
		};
	};
};

// Lets the Controls menu flag keys that clash with vanilla actions
class UserActionsConflictGroups
{
	class ActionGroups
	{
		GLT_TurretEnhanced[] = {
			"GLT_markSlot1", "GLT_markSlot2", "GLT_markSlot3", "GLT_markSlot4",
			"GLT_markerList", "GLT_measure", "GLT_resetMarkerCounter", "GLT_cycleMarkerOverlay"
		};
	};
	class CollisionGroups
	{
		GLT_TurretEnhancedCollisions[] = {"basic", "vehBasic", "HeadMove", "GLT_TurretEnhanced"};
	};
};
