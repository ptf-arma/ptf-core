_spawner = _this select 0;

_spawner addAction
[
	"Spawn Large Ammo Crate",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_JumpTarget_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC", "PTF_Cargo_Large_Ammo", "PTF_Cargo_Large_Medical", "PTF_Cargo_Large_Explosives", "PTF_Cargo_Small_Ammo", "PTF_Cargo_Small_Explosives", "PTF_Cargo_Small_Medical", "PTF_Cargo_Small_Humanitarian"], 7];
		sleep 2;
		_veh = createVehicle
		[
			"PTF_Cargo_Large_Ammo",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		_veh setFuel 0;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_JumpTarget_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn Large Explosives Crate",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_JumpTarget_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC", "PTF_Cargo_Large_Ammo", "PTF_Cargo_Large_Medical", "PTF_Cargo_Large_Explosives", "PTF_Cargo_Small_Ammo", "PTF_Cargo_Small_Explosives", "PTF_Cargo_Small_Medical", "PTF_Cargo_Small_Humanitarian"], 7];
		sleep 2;
		_veh = createVehicle
		[
			"PTF_Cargo_Large_Explosives",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		_veh setFuel 0;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_JumpTarget_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn Large Medical Crate",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_JumpTarget_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC", "PTF_Cargo_Large_Ammo", "PTF_Cargo_Large_Medical", "PTF_Cargo_Large_Explosives", "PTF_Cargo_Small_Ammo", "PTF_Cargo_Small_Explosives", "PTF_Cargo_Small_Medical", "PTF_Cargo_Small_Humanitarian"], 7];
		sleep 2;
		_veh = createVehicle
		[
			"PTF_Cargo_Large_Medical",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		_veh setFuel 0;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_JumpTarget_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn Small Ammo Crate",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_JumpTarget_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC", "PTF_Cargo_Large_Ammo", "PTF_Cargo_Large_Medical", "PTF_Cargo_Large_Explosives", "PTF_Cargo_Small_Ammo", "PTF_Cargo_Small_Explosives", "PTF_Cargo_Small_Medical", "PTF_Cargo_Small_Humanitarian"], 7];
		sleep 2;
		_veh = createVehicle
		[
			"PTF_Cargo_Small_Ammo",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		_veh setFuel 0;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_JumpTarget_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn Small Explosives Crate",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_JumpTarget_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC", "PTF_Cargo_Large_Ammo", "PTF_Cargo_Large_Medical", "PTF_Cargo_Large_Explosives", "PTF_Cargo_Small_Ammo", "PTF_Cargo_Small_Explosives", "PTF_Cargo_Small_Medical", "PTF_Cargo_Small_Humanitarian"], 7];
		sleep 2;
		_veh = createVehicle
		[
			"PTF_Cargo_Small_Explosives",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		_veh setFuel 0;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_JumpTarget_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn Small Medical Crate",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_JumpTarget_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC", "PTF_Cargo_Large_Ammo", "PTF_Cargo_Large_Medical", "PTF_Cargo_Large_Explosives", "PTF_Cargo_Small_Ammo", "PTF_Cargo_Small_Explosives", "PTF_Cargo_Small_Medical", "PTF_Cargo_Small_Humanitarian"], 7];
		sleep 2;
		_veh = createVehicle
		[
			"PTF_Cargo_Small_Medical",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		_veh setFuel 0;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_JumpTarget_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Spawn Small Humanitarian Crate",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "Land_JumpTarget_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
		} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC", "PTF_Cargo_Large_Ammo", "PTF_Cargo_Large_Medical", "PTF_Cargo_Large_Explosives", "PTF_Cargo_Small_Ammo", "PTF_Cargo_Small_Explosives", "PTF_Cargo_Small_Medical", "PTF_Cargo_Small_Humanitarian"], 7];
		sleep 2;
		_veh = createVehicle
		[
			"PTF_Cargo_Small_Humanitarian",
			getPosATL _hang,
			[],
			0,
			"NONE"
		];
		_veh setDir (getDir _hang);
		// createVehicleCrew _veh;
		_veh setFuel 0;
		(_this select 0) setVariable ["SpawnerCooldown", true, true]
	},
	nil,
	1.5,
	true,
	true,
	"",
	"_target distance (nearestObject [_target, ""Land_JumpTarget_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];