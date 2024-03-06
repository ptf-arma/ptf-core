class Attributes : Attributes {
	class PTF_Boat_Spawnable {
		displayName = "Make Boats Spawnable";
		tooltip = "Make Boats Spawnable Must have a Marker called Boat placed in world"; // Tooltip assigned to UI control class Title
		property = "BoatSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['BoatSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_Cougar_Spawnable {
		displayName = "Make Cougar Spawnable Must have a Marker called Vic placed in world";
		tooltip = "Make Cougar Spawnable"; // Tooltip assigned to UI control class Title
		property = "CougarSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['CougarSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_ForkLift_Spawnable {
		displayName = "Make ForkLift Spawnable Must have a Marker called Forklift placed in world";
		tooltip = "Make ForkLift Spawnable"; // Tooltip assigned to UI control class Title
		property = "ForkLiftSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['ForkLiftSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_AttackHelicopter_Spawnable {
		displayName = "Make Attack Helicopters Spawnable Must have a Marker called Attack placed in world";
		tooltip = "Make Attack Helicopters Spawnable"; // Tooltip assigned to UI control class Title
		property = "AttackHelicoptersSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['AttackHelicoptersSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_SupplyHelicopter_Spawnable {
		displayName = "Make Supply Helicopters Spawnable Must have a Marker called Cargo placed in world";
		tooltip = "Make Supply Helicopters Spawnable"; // Tooltip assigned to UI control class Title
		property = "SupplyHelicoptersSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['SupplyHelicoptersSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_TransportHelicopter_Spawnable {
		displayName = "Make Transport Helicopters Spawnable Must have a Marker called Transport placed in world";
		tooltip = "Make Transport Helicopters Spawnable"; // Tooltip assigned to UI control class Title
		property = "TransportHelicoptersSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['TransportHelicoptersSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_Hummve_Spawnable {
		displayName = "Make Hummves Spawnable Must have a Marker called Vic placed in world";
		tooltip = "Make Hummves Spawnable"; // Tooltip assigned to UI control class Title
		property = "HummveSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['HummveSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_Mrap_Spawnable {
		displayName = "Make Mraps Spawnable Must have a Marker called Vic placed in world";
		tooltip = "Make Mraps Spawnable"; // Tooltip assigned to UI control class Title
		property = "MrapSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['MrapSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_Planes_Spawnable {
		displayName = "Make Planes Spawnable Must have a Marker called Plane placed in world";
		tooltip = "Make Planes Spawnable"; // Tooltip assigned to UI control class Title
		property = "PlanesSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['PlanesSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
	class PTF_Supplys_Spawnable {
		displayName = "Make Supplys Spawnable Must have a Marker called SmSupplys & LgSupplys placed in world";
		tooltip = "Make Supplys Spawnable"; // Tooltip assigned to UI control class Title
		property = "SupplysSpawnAbleProperty"; // Unique config property name saved in SQM
    	condition = "objectVehicle";
    	control = "Checkbox";
    	defaultValue = "(false)";
    	expression = "if (_value) then {_this setVariable ['SupplysSpawnable', true, true]}";
   		typeName = "BOOL";
 	};
};