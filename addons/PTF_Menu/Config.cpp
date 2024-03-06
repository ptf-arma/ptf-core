 class CfgPatches
{
	class PTF_Menu
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Data_F_Decade_Loadorder"};
	};
};


class CfgWorlds {
	class CAWorld;	// External class reference
	class Altis : CAWorld {
		cutscenes[] = {"mymainmenu"};
	};
	
	class Stratis : CAWorld {
		cutscenes[] = {"mymainmenu"};
	};

	class Enoch : CAWorld {
		cutscenes[] = {"mymainmenu"};
	};

	class hellanmaa : CAWorld {
		cutscenes[] = {"mymainmenu"};
	};
	
	class hellanmaaw : CAWorld {
		cutscenes[] = {"mymainmenu"};
	};

	class VR : CAWorld {
		cutscenes[] = {"mymainmenu"};
	};

	initWorld = "Stratis";
	demoWorld = "Stratis";
};

class CfgMissions
{
	class Cutscenes
	{
		class mymainmenu // Class referenced in 'cutscenes' property in CfgWorlds
		{
			directory = "PTF_Menu\Intro.Stratis"; // Path to scenario with the scene
		};
	};
};

#include "import.hpp"

class RscDisplayMain: RscStandardDisplay {
 #include "menu.hpp"
};