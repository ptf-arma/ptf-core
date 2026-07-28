//cfgWeapons


class  rhs_weap_AGM114M_base_Launcher;

class GrenadeLauncher;
//cfgAmmo

class M_Scalpel_AT;
class ACE_Hellfire_AGM114K : M_Scalpel_AT {
	class ace_missileguidance;
};

class SmokeShell;
class SmokeShellBlue;
class SmokeShellGreen;
class SmokeShellOrange;
class SmokeShellPurple;
class SmokeShellRed;
class SmokeShellYellow;

class B_12Gauge_Slug_NoCartridge;

class Default;
class Grenade: Default{};
class GrenadeHand: Grenade{};

//cfgMagazines
class 2Rnd_12Gauge_Slug;

class CA_Magazine: Default{};
class HandGrenade: CA_Magazine{};

class PylonRack_4Rnd_ACE_Hellfire_AGM114K;

class VehicleMagazine;
class rhs_mag_Hellfire_base : VehicleMagazine{};
class rhs_mag_AGM114K : rhs_mag_Hellfire_base{};
class rhs_mag_AGM114M : rhs_mag_AGM114K{};
class rhs_mag_AGM114M_2 : rhs_mag_AGM114M{};
class rhs_mag_AGM114M_4 : rhs_mag_AGM114M_2{};
