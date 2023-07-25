_spawner = _this select 0;

_spawner addAction
[
	"Spawn F-18 CAG",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestBuilding (_this select 0);
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_F18C_CAG",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang)-180;
		createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestBuilding _target) < 30 && typeOf nearestBuilding _target == ""Land_Hangar_F"" && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn EA-6B Prowler",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestBuilding (_this select 0);
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"FIR_EA6B_VMAQ4",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang)-180;
		createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestBuilding _target) < 30 && typeOf nearestBuilding _target == ""Land_Hangar_F"" && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn F-18D",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestBuilding (_this select 0);
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_F18D",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang)-180;
		createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestBuilding _target) < 30 && typeOf nearestBuilding _target == ""Land_Hangar_F"" && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn AV-8B Harrier II",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestBuilding (_this select 0);
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_AV8B",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang)-180;
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestBuilding _target) < 30 && typeOf nearestBuilding _target == ""Land_Hangar_F"" && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn MQ-9",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestBuilding (_this select 0);
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_MQ9_SCARFACE",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang)-180;
		createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestBuilding _target) < 30 && typeOf nearestBuilding _target == ""Land_Hangar_F"" && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn AH-1Z Viper (Gunfighters)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_AH1Z_GUNFIGHTERS",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn CH-53E Super Stallion (Cargo)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_CH53_CARGO",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn CH-53E Super Stallion (GAU-21)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_CH53_Ramp",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn MV-22 Osprey (Cargo)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_MV22_Cargo",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn MV-22 Osprey (Ramp Gun)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_MV22_Ramp",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn MV-22 Mini",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_MV22_Minigun",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn UH-1Y Venom (Gunfighters)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_UH1Y_GUNFIGHTERS",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn UH-1Y Venom (Scarface)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_UH1Y_SCARFACE",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn UH-1Y Venom (MEDEVAC)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_UH1Y_Medevac",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn UH-1Y Venom (Trainer)",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_HelipadCircle_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 19];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_UH1Y_Unarmed",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_HelipadCircle_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];