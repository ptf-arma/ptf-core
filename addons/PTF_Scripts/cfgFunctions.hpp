class cfgFunctions {
	class PTF_functions {
		tag = "PTF";
		class spawners {
			file = "\PTF_Scripts\fnc\spawners";
			class supplySpawner_init {};
			class VicSpawner_init {};
			class aircraftSpawner_init {};
		};
		class Boxes {
			file = "\PTF_Scripts\fnc\Boxes"
			class BigVicBox_init {};
			class SmallVicBox_init {};
			class Tracks_init {};
		};
		class Drone {
			file = "\PTF_Scripts\fnc\drone"
			class droneitem {};
		};
		class Flags {
			file = "\PTF_Scripts\fnc\flag";
			class PTFFlagRaise {};
			class MAG36FlagRaise {};
			class USMCFlagRaise {};
			class 11FlagRaise {};
			class 12FlagRaise {}; 
			class 13FlagRaise {};
			class 14FlagRaise {};
			class scarFlagRaise {};
			class gunFlagRaise {};
			class FlagRemove {};
    	};
		class arsenal {
			file = "\PTF_Scripts\fnc\arsenal"
			class arsenal_init {};
			class arsenalnoammo_init {};
		};
	};
};