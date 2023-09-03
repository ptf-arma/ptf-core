class CfgPatches
{
	class PTF_40mm
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {
			"rhsusf_c_weapons",
			"rhs_c_weapons",
			"A3_Weapons_F",
			};
	};

};

	class SmokeShell;
	class SmokeShellBlue;
	class SmokeShellGreen;
	class SmokeShellOrange;
	class SmokeShellPurple;
	class SmokeShellRed;
	class SmokeShellYellow;
class cfgAmmo {

	class G_40mm_Smoke: SmokeShell {
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};
	class rhs_40mm_smoke_green: SmokeShellGreen {
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};

	class rhs_40mm_smoke_red: SmokeShellRed {
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};

	class rhs_40mm_smoke_white: SmokeShell {
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};

	class rhs_40mm_smoke_yellow: SmokeShellYellow {
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};
	class rhs_40mm_m715_green: SmokeShellGreen
	{
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};
	class rhs_40mm_m713_red: SmokeShellRed
	{
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};
	class rhs_40mm_m714_white: SmokeShell
	{
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};
	class rhs_40mm_m716_yellow: SmokeShellYellow
	{
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};
};

