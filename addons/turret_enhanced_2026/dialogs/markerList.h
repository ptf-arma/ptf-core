/*
	(Turret Enhanced 2026 Version)
	Turret Enhanced - Marker List dialog
	Opened with the "Marker List" control (SHIFT+5 by default, Options > Controls) or scroll action.
	Logic lives in functions\markerList.sqf
	Double-click / Enter = slew camera to marker, Del = delete marker, Hide/Unhide toggles the overlay, Esc = close
*/

class RscText;
class RscListBox;
class RscButton;


class GLT_MarkerList
{
	idd = 589;
	movingEnable = 0;
	onLoad = "['onLoad', _this] call GLT_fnc_markerList";
	onUnload = "['onUnload', _this] call GLT_fnc_markerList";

	class ControlsBackground
	{
		class Background: RscText
		{
			idc = -1;
			x = "(safeZoneX + safeZoneW * 0.33)";
			y = "(safeZoneY + safeZoneH * 0.25)";
			w = "(safeZoneW * 0.34)";
			h = "safeZoneH * 0.46";
			colorBackground[] = {0,0,0,0.8};
		};
		class Title: RscText
		{
			idc = -1;
			x = "(safeZoneX + safeZoneW * 0.33)";
			y = "(safeZoneY + safeZoneH * 0.25)";
			w = "(safeZoneW * 0.34)";
			h = "safeZoneH * 0.03";
			text = "My Markers";
			font = "PuristaBold";
			sizeEx = "((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.1";
			colorText[] = {0,1,0,1};
			colorBackground[] = {0.1,0.1,0.1,1};
		};
		class Help: RscText
		{
			idc = -1;
			x = "(safeZoneX + safeZoneW * 0.33)";
			y = "(safeZoneY + safeZoneH * 0.25) + safeZoneH * 0.425";
			w = "(safeZoneW * 0.34)";
			h = "safeZoneH * 0.03";
			text = "Double-click / Enter = slew    Del = delete    Grey = hidden";
			font = "PuristaLight";
			sizeEx = "((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.9";
			colorText[] = {0,1,0,0.7};
		};
	};

	class Controls
	{
		class List: RscListBox
		{
			idc = 1500;
			x = "(safeZoneX + safeZoneW * 0.33) + safeZoneW * 0.005";
			y = "(safeZoneY + safeZoneH * 0.25) + safeZoneH * 0.035";
			w = "(safeZoneW * 0.34) - safeZoneW * 0.01";
			h = "safeZoneH * 0.34";
			sizeEx = "((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight = "((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.3";
			colorText[] = {0,1,0,1};
			colorBackground[] = {0.15,0.15,0.15,1};
			colorSelect[] = {0,0,0,1};
			colorSelectBackground[] = {0,1,0,0.8};
			colorSelectBackground2[] = {0,1,0,0.8};
			tooltip = "Double-click or Enter to slew the camera to this marker";
		};
		class Empty: RscText
		{
			idc = 1001;
			x = "(safeZoneX + safeZoneW * 0.33) + safeZoneW * 0.005";
			y = "(safeZoneY + safeZoneH * 0.25) + safeZoneH * 0.035";
			w = "(safeZoneW * 0.34) - safeZoneW * 0.01";
			h = "safeZoneH * 0.03";
			text = "No markers placed yet";	// filled with the bound keys by GLT_fnc_markerList
			colorText[] = {0,1,0,0.7};
			sizeEx = "((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Slew: RscButton
		{
			idc = 1600;
			x = "(safeZoneX + safeZoneW * 0.33) + safeZoneW * 0.005";
			y = "(safeZoneY + safeZoneH * 0.25) + safeZoneH * 0.385";
			w = "safeZoneW * 0.075";
			h = "safeZoneH * 0.035";
			text = "Slew To";
			sizeEx = "((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,1,0,1};
			colorBackground[] = {0.2,0.2,0.2,1};
			colorBackgroundActive[] = {0.3,0.3,0.3,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			action = "['slew'] call GLT_fnc_markerList";
			tooltip = "Slew the camera to the selected marker";
		};
		class Delete: Slew
		{
			idc = 1601;
			x = "(safeZoneX + safeZoneW * 0.33) + safeZoneW * 0.0875";
			text = "Delete";
			action = "['delete'] call GLT_fnc_markerList";
			tooltip = "Delete the selected marker from the map for everyone";
		};
		class Hide: Slew
		{
			idc = 1602;
			x = "(safeZoneX + safeZoneW * 0.33) + safeZoneW * 0.17";
			text = "Hide";
			action = "['hide'] call GLT_fnc_markerList";
			tooltip = "Hide from the camera overlay. The marker stays on the map";
		};
		class Close: Slew
		{
			idc = 2;	// IDC_CANCEL - closes the dialog
			x = "(safeZoneX + safeZoneW * 0.33) + safeZoneW * 0.26";
			text = "Close";
			action = "";
			tooltip = "";
		};
	};
};
