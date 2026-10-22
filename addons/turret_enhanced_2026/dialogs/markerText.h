/*
	(Turret Enhanced 2026 Version)
	Turret Enhanced - marker text input dialog
	Opened by GLT_fnc_addMarker when "Prompt for Marker Text" is enabled.
	Logic lives in functions\markerDialog.sqf
	Enter / Numpad Enter / OK = place marker, Esc / Cancel = no marker
*/

class GLT_MarkerText
{
	idd = 588;
	movingEnable = 0;
	onLoad = "['onLoad', _this] call GLT_fnc_markerDialog";
	onUnload = "['onUnload', _this] call GLT_fnc_markerDialog";

	class ControlsBackground
	{
		class Background
		{
			type = 0;
			idc = -1;
			x = "safeZoneX + safeZoneW * 0.40";
			y = "safeZoneY + safeZoneH * 0.62";
			w = "safeZoneW * 0.20";
			h = "safeZoneH * 0.105";
			style = 0;
			text = "";
			colorBackground[] = {0,0,0,0.8};
			colorText[] = {0,1,0,1};
			font = "PuristaMedium";
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		};
	};

	class Controls
	{
		class Header
		{
			type = 13;	// CT_STRUCTURED_TEXT
			idc = 100;
			x = "safeZoneX + safeZoneW * 0.40";
			y = "safeZoneY + safeZoneH * 0.623";
			w = "safeZoneW * 0.20";
			h = "safeZoneH * 0.025";
			style = 0;
			text = "";
			size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			colorBackground[] = {0,0,0,0};
			colorText[] = {0,1,0,1};
			class Attributes
			{
				font = "PuristaBold";
				color = "#00FF00";
				align = "center";
				shadow = 1;
			};
		};
		class Input
		{
			type = 2;	// CT_EDIT
			idc = 1400;
			x = "safeZoneX + safeZoneW * 0.405";
			y = "safeZoneY + safeZoneH * 0.653";
			w = "safeZoneW * 0.19";
			h = "safeZoneH * 0.03";
			style = 0;
			text = "";
			maxChars = 60;
			autocomplete = "";
			tooltip = "Marker text (optional). Enter = place marker, Esc = cancel";
			colorBackground[] = {0.2,0.2,0.2,1};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelection[] = {1,0,0,1};
			colorText[] = {0,1,0,1};
			font = "PuristaMedium";
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		};
		class OK
		{
			type = 1;	// CT_BUTTON
			idc = 1600;
			x = "safeZoneX + safeZoneW * 0.445";
			y = "safeZoneY + safeZoneH * 0.69";
			w = "safeZoneW * 0.045";
			h = "safeZoneH * 0.026";
			style = 0+2;
			text = "Mark";
			action = "['commit'] call GLT_fnc_markerDialog";
			borderSize = 0;
			colorBackground[] = {0.2,0.2,0.2,1};
			colorBackgroundActive[] = {1,0,0,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,1};
			colorText[] = {0,1,0,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
		};
		class Cancel: OK
		{
			idc = 2;	// IDC_CANCEL - closes the dialog with exit code 2
			x = "safeZoneX + safeZoneW * 0.51";
			text = "Cancel";
			action = "";
		};
	};
};
