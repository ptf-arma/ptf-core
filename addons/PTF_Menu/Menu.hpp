	enableDisplay = 1;
	delete Spotlight;
	class controls 
	{
		delete Spotlight1;
		delete Spotlight2;
		delete Spotlight3;
		delete BackgroundSpotlightRight;
		delete BackgroundSpotlightLeft;
		delete BackgroundSpotlight;
		delete SpotlightNext;
		delete SpotlightPrev;
		class Logo
		{
			access = 0;
			color[] = {0.9,0.9,0.9,1};
			colorActive[] = {1,1,1,1};
			colorDisabled[] = {1,1,1,0.25};
			default = 0;
			deletable = 0;
			fade = 0;
			font = "RobotoCondensed";
			h = "1 * 	5 * 	(pixelH * pixelGrid * 2)";
			idc = -1;
			onButtonClick = "";
			onKillFocus = "";
			onLoad = "";
			onSetFocus = "";
			shadow = 0;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			soundClick[] = {"",0.1,1};
			soundEnter[] = {"",0.1,1};
			soundEscape[] = {"",0.1,1};
			soundPush[] = {"",0.1,1};
			style = 48;
			text = "\PTF_Menu\data\ptfemblem.paa";
			tooltip = "Paramarines Website";
			tooltipColorBox[] = {1,1,1,1};
			tooltipColorShade[] = {0,0,0,0.65};
			tooltipColorText[] = {1,1,1,1};
			type = 11;
			url = "https://paramarines.net/";
			w = "2 * 	5 * 	(pixelW * pixelGrid * 2)";
			x = "0.5 - 	5 * 	(pixelW * pixelGrid * 2)";
			y = "safezoneY + (3 - 0.5 * 	5) * 	(pixelH * pixelGrid * 2)";
		};
		class infomods:RscControlsgroupNoHScrollbars {
			show=0;
		};
		class infoDLCsOwned:infomods {
			show=0;
		};
		class infoDLCs:infoDLCsOwned {
			show=0;
		};
		class infoNews:infomods {
			show=0;
		};
		class infoVersion:infoNews {
			show=0;
		};
		class GroupMultiplayer : GroupSingleplayer {
			class Controls: Controls {
			delete QuickPlay;
			delete ApexProtocol;
				class Joinmainserver : Campaigns {
					idc = 123987;
					text = "Join Op server";
					tooltip = "";
					y = "(0 * 	1.5) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					onbuttonclick = "connectToServer ['51.222.245.138', 2302, 'PTF2020']";
				};
				class JoinLibserver : Campaigns {
					idc = 123987;
					text = "Join Training server";
					tooltip = "";
					y = "(1 * 	1.5) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					onbuttonclick = "connectToServer ['54.39.29.138', 2402, 'PTF2020']";
				};
				class ServerBrowser : Campaigns {
					idc = 105;
					text = "$STR_A3_RscDisplayMain_GroupMultiplayer_ServerBrowser_text";
					tooltip = "";
					y = "(2 * 	1.5) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					onbuttonclick = "";
				};
			};
		};
	};