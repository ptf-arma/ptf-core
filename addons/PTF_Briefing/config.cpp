// Google Slides on the LHA briefing-room screens.
//
// Peral's LHA (workshop 3596653038) is another author's mod and is never edited:
// its two briefing screens are hiddenSelections 0 and 1 on the root Peral_LHA object,
// which setObjectTexture reaches from here, and the podium laptop is a named proxy
// in LHA_Med_2 that we only read a position from.
//
// The server's billet-link extension downloads the deck from Google and renders
// it (see the Billet repo, mod/extension/src/slides.rs). Players need nothing
// extra: each slide reaches them as a JPEG data URL and is shown by viewer.html
// in Arma's sandboxed web browser control, drawn into the screen's texture.
class CfgPatches
{
	class PTF_Briefing
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.22;
		requiredAddons[] = {"A3_Functions_F", "A3_UI_F", "cba_main", "ace_interact_menu"};
		author = "PTF";
	};
};

class CfgFunctions
{
	class PTF_Briefing
	{
		class main
		{
			file = "\z\PTF\addons\PTF_Briefing\functions";
			class init { postInit = 1; };
			class serverInit {};
			class onExtension {};
			class requestLoad {};
			class requestSlide {};
			class setSlide {};
			class clientLoop {};
			class receiveSlide {};
			class addActions {};
			class openLoadDialog {};
			class notify {};
			class canControl {};
			class callerOwner {};
			class laptopPos {};
		};
	};
};

// Ships the briefing system knows. Keyed by the root object's class.
class PTF_Briefing_Ships
{
	class Peral_LHA
	{
		// The LHA part that holds the briefing room and the podium laptop.
		part = "LHA_Med_2";
		// Laptop position in the part's model space. The engine can't read a proxy's
		// position, so this was measured in game (tools/briefing-test).
		laptopOffset[] = {6.30, 7.96, 4.50};
		// Per screen: hiddenSelection index, UI texture size (W, H; Arma only makes
		// power-of-two textures) and the screen's real width/height, which the
		// viewer corrects for so slides keep their proportions.
		// 1.5 measured in game from a circle drawn on the texture (tools/briefing-test).
		screens[] = {{0, 2048, 1024, 1.5}, {1, 2048, 1024, 1.5}};
		// How far from the laptop a player may run the controls, in metres.
		controlRange = 4;
	};
};

class RscWebBrowser;

// Drawn into a screen texture with #(rgb,W,H,1)ui('PTF_Briefing_RscScreen','<name>').
class PTF_Briefing_RscScreen
{
	idd = -1;
	class controls
	{
		class Browser: RscWebBrowser
		{
			idc = 1000;
			x = 0;
			y = 0;
			w = 1;
			h = 1;
			url = "";
			colorBackground[] = {0, 0, 0, 1};
		};
	};
};
