	enableDisplay = 1;
	delete Spotlight;
	class controls 
	{
		delete Spotlight1;
		delete ACE_news_apex;
		delete Spotlight2;
		delete ProjectOPFORLogo;
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
			text = "\z\PTF\addons\PTF_Menu\data\ptfemblem.paa";
			tooltip = "paramarines Website";
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
		class GroupSingleplayer : GroupSingleplayer{
		class Controls : Controls {
			delete Showcases;
			delete Challenges;
				class Editor: Campaigns
				{
					idc = 142;
					text = "$STR_A3_RscDisplayMain_ButtonEditor";
					tooltip = "$STR_TOOLTIP_SINGLEPLAYER_EDITOR_A3";
					y = "(2 * 	1.5) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					onbuttonclick = "";
				};
				class Campaigns : Campaigns {
					x = 0;
					y = "(0) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					w = "10 * 	(pixelW * pixelGrid * 2)";
					h = "1.5 * 	(pixelH * pixelGrid * 2) - 	(pixelH)";
				};
				class Scenarios: Campaigns
				{
					idc = 103;
					text = "$STR_A3_RscDisplayMain_ButtonScenarios";
					tooltip = "$STR_TOOLTIP_MAIN_SCENARIOS";
					y = "(1 * 	1.5) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					onbuttonclick = "uinamespace setvariable ['RscDisplaySingleMission_title', toUpper (localize 'STR_A3_RSCDISPLAYMAIN_BUTTONSCENARIOS')];";
				};
			};
		};

		class GroupTutorials :  GroupSingleplayer {
			class Controls: Controls {
				delete VRTraining;
				delete FieldManual;
				class Bootcamp;
				class CommunityGuides : Bootcamp {
					y = "(1 *   1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
				}
				class Arsenal : Campaigns {
					idc = 203;
					text = "$STR_A3_RscDisplayMain_ButtonVirtualArsenal";
					tooltip = "$STR_A3_RscDisplayMain_ButtonVirtualArsenal_tooltip";
					y = "(2 * 	1.5) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					w = "(10 + 3.5) * 	(pixelW * pixelGrid * 2)";
					onbuttonclick = "playMission['','\A3\Missions_F_Bootcamp\Scenarios\Arsenal.VR']";
					animTextureNormal = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\buttonMenu_ca.paa";
					animTextureDisabled = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\buttonMenu_ca.paa";
					animTextureOver = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\buttonMenuHover_ca.paa";
					animTextureFocused = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\buttonMenuHover_ca.paa";
					animTexturePressed = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\buttonMenu_ca.paa";
					animTextureDefault = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\buttonMenu_ca.paa";
				};
			};
		};
		 
		class GroupMultiplayer : GroupSingleplayer {
			class Controls: Controls {
			delete QuickPlay;
			delete ApexProtocol;
				class Joinmainserver : Campaigns {
					idc = 123987;
					text = "Join Op Server";
					tooltip = "";
					y = "(0 * 	1.5) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					onbuttonclick = "_display = ctrlParent (_this # 0) createDisplay 'RscDisplayPassword';_password = _display displayCtrl 101;_buttonok = _display displayCtrl 1;_buttonCancle = _display displayCtrl 2;_passwordText = profileNamespace getVariable ['PTF_serverPassword',''];_password ctrlSetText _passwordText;_display displayAddEventHandler ['KeyDown',{if(_this select 1 == 28) then {_passwordText = profileNamespace getVariable ['PTF_serverPassword',''];connectToServer ['172.93.183.88', 2302,_passwordText];}}];_password ctrlAddEventHandler ['EditChanged',{private _password = _this # 0;profileNamespace setVariable ['PTF_serverPassword',(ctrlText _password)];saveProfileNamespace;}];_ButtonOk ctrlAddEventHandler  ['MouseButtonUp',{_passwordText = profileNamespace getVariable ['PTF_serverPassword',''];connectToServer ['172.93.183.88', 2302,_passwordText];_display = ctrlParent (_this # 0);_display closeDisplay 1;}];_buttonCancle ctrlAddEventHandler  ['MouseButtonUp',{_passwordText = profileNamespace setVariable ['PTF_serverPassword',''];_display = ctrlParent (_this # 0);_display closeDisplay 1;}];";
				};
				class JoinLibserver : Campaigns {
					idc = 123987;
					text = "Join Training Server";
					tooltip = "";
					y = "(1 * 	1.5) * 	(pixelH * pixelGrid * 2) + 	(pixelH)";
					onbuttonclick = "_display = ctrlParent (_this # 0) createDisplay 'RscDisplayPassword';_password = _display displayCtrl 101;_buttonok = _display displayCtrl 1;_buttonCancle = _display displayCtrl 2;_passwordText = profileNamespace getVariable ['PTF_serverPassword',''];_password ctrlSetText _passwordText;_display displayAddEventHandler ['KeyDown',{if(_this select 1 == 28) then {_passwordText = profileNamespace getVariable ['PTF_serverPassword',''];connectToServer ['172.93.183.88', 2308,_passwordText];}}];_password ctrlAddEventHandler ['EditChanged',{private _password = _this # 0;profileNamespace setVariable ['PTF_serverPassword',(ctrlText _password)];saveProfileNamespace;}];_ButtonOk ctrlAddEventHandler  ['MouseButtonUp',{_passwordText = profileNamespace getVariable ['PTF_serverPassword',''];connectToServer ['172.93.183.88', 2308,_passwordText];_display = ctrlParent (_this # 0);_display closeDisplay 1;}];_buttonCancle ctrlAddEventHandler  ['MouseButtonUp',{_passwordText = profileNamespace setVariable ['PTF_serverPassword',''];_display = ctrlParent (_this # 0);_display closeDisplay 1;}];";
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


