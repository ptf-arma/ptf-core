// Lives: every player gets a set number of respawns for the mission.
//
// The server keeps the count, by SteamID, so leaving and rejoining keeps it.
// A life is used by dying (a manual respawn is a death too) or by leaving the
// game while unconscious; leaving while conscious costs nothing. A player who
// uses their last life waits as a spectator until an admin gives them one,
// and then respawns on their own.
//
// Players see the counts on the Billet tablet's (or Rugged Phone's) home
// screen, and admins get a Lives tab there to change them, through the
// tablet's add-on slot (class blk_tabletApps below). Admin means the server's
// logged-in admin (#login) or anyone with Billet's "Manage lives" permission.
// See README.md.
class CfgPatches
{
	class PTF_Lives
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.20;
		requiredAddons[] = {"A3_Functions_F", "cba_main", "cba_settings"};
		author = "PTF";
	};
};

class CfgFunctions
{
	class PTF_Lives
	{
		class main
		{
			file = "\z\PTF\addons\PTF_Lives\functions";
			class init {};
			class serverInit {};
			class clientInit {};
			class charge {};
			class died {};
			class retire {};
			class publish {};
			class isAdmin {};
			class callerUid {};
			class hello {};
			class askAdmin {};
			class admin {};
			class notify {};
			class spectate {};
			class mine {};
			class users {};
			class tablet {};
		};
	};
};

class Extended_PreInit_EventHandlers
{
	class PTF_Lives
	{
		init = "call compile preprocessFileLineNumbers '\z\PTF\addons\PTF_Lives\XEH_preInit.sqf'";
	};
};

// CBA's postInit, not CfgFunctions' postInit: that one runs after CBA has
// announced its settings, so fn_serverInit would never hear them.
class Extended_PostInit_EventHandlers
{
	class PTF_Lives
	{
		init = "call PTF_Lives_fnc_init";
	};
};

// The Billet tablet's add-on slot (Billet's tablet mod reads this; without it
// nothing reads it). The tablet asks `function` what to show while it is open:
// ["widget"] for the home screen, ["tab"] for this tab (nothing: no tab), and
// passes the player's clicks back as ["action", action, key, value].
class blk_tabletApps
{
	class ptf_lives
	{
		title = "Lives";
		// a heart, in the tablet's 24 x 24 stroked icon style
		icon = "M12 20s-7.5-4.6-7.5-10.1A4.2 4.2 0 0 1 12 7.4a4.2 4.2 0 0 1 7.5 2.5C19.5 15.4 12 20 12 20z";
		function = "PTF_Lives_fnc_tablet";
	};
};
