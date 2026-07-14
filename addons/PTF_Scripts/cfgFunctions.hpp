class cfgFunctions {
	class PTF_functions {
		tag = "PTF";
		class MapMarkers {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Markers";
			class Dot{};
			class ccp{};
			class lz{};
			class re{};
		};
		class Boxes {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Boxes";
			class BigVicBox_init {};
			class SmallVicBox_init {};
			class Tracks_init {};
		};
		class Drone {
			file = "\z\PTF\addons\PTF_Scripts\fnc\drone";
			class droneitem {};
		};
		class Flags {
			file = "\z\PTF\addons\PTF_Scripts\fnc\flag";
			class PTFFlagRaise {};
			class USMCFlagRaise {};
			class 11FlagRaise {};
			class 12FlagRaise {};
			class 13FlagRaise {};
			class 14FlagRaise {};
			class 3flagRaise {};
			class 3AflagRaise {};
			class 3BflagRaise {};
			class 3CflagRaise {};
			class 3EflagRaise {};
			class MAG36FlagRaise {};
			class scarFlagRaise {};
			class gunFlagRaise {};
			class FlagRemove {};
    	};
		class arsenal {
			file = "\z\PTF\addons\PTF_Scripts\fnc\arsenal";
			class arsenal_init {};
			class arsenalnoammo_init {};
			class arsenalPSO_init {};
			class arsenalWhitelist {};
		};
		class Spawners {
			File = "\z\PTF\addons\PTF_Scripts\fnc\spawners";
			class SpawnFunction{};
			};
		class Aircraft {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Aircraft";
			class ah1z_gunnerUI {};
			class ah1z_MFD_switch {};
			class uh1_handler {};
			class uh1_obsHandler {};
			class uh1_toggleCam {};
		};
		class AH1zLoadoutFunctions {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Loadouts\AH1z";
			class ApkwsA {};
			class ATA {};
			class ThermoA {};
		};
		class MQ9LoadoutFunctions {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Loadouts\MQ9";
			class HellfireM {};
		};
		class PTFSalvage {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Salvage";
			class Salvage {};
		};
		class PTFSlingLoading {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Sling loading";
			class slingloading {};
		};
		class BeanBag {
			file = "\z\PTF\addons\PTF_Scripts\fnc\BeanBag";
			class BeanBag {};
			class Disarm {};
		};
	};
};
