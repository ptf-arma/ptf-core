class cfgFunctions {
	class PTF_functions {
		tag = "PTF";
		class WeaponSwap {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Weapon Swaping";
			class weaponSwap {};
			class SoulderNSwap {};
			class Shoulder {};
			class SawpNDelete {};
			class pos {};
			class ArsenalEventHandlers {
				preinit = 1;
			};
			class WeaponEventHandlerPlayer{
				postinit = 1;
			}
		};
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
		};
		class Spawners {
			File = "\z\PTF\addons\PTF_Scripts\fnc\spawners";
			class SpawnFunction{};
			};
		class F18Normal {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Loadouts\F-18\Normal";
			class ApkwsGbu16FN {};
			class MaverickFN {};
			class SeadFN {};
			class SmokeGpFN {};
			class SnakeyeFN {};
			class UnguidedBombFN {};
		};
		class F18ED {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Loadouts\F-18\ED";
			class A2aFE {};
			class CbuFE {};
			class CmFE {};
			class GbuFE {};
			class GpsFE {};
			class MarverickFE {};
			class ScalpelFE {};
			class ZuniFE {};
		};
		class AH1zLoadoutFunctions {
			file = "\z\PTF\addons\PTF_Scripts\fnc\Loadouts\AH1z";
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
		class TfarRadioSetting {
			file = "\z\PTF\addons\PTF_Scripts\fnc\ArsenalRadioSet";
			class SetTfrRadio {
				preinit = 1;
			};
		};
	};
};