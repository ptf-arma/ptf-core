_spawner = _this select 0;

_spawner addAction
[
	"Humvee 50",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_M1151_M240",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Humvee MK19",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_M1151_MK19",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Humvee 240",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_M1151_M240",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Unarmed Humvee",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_M1151",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"CAT M2",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_M1151CAT_M2",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"CAT Mk19",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_M1151CAT_MK19",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"CAT TOW",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_M1025_tow",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Mrap 50",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_MRAP_M1232_M2",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Mrap MK19",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_MRAP_M1232_MK19",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Cougar 50",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_MRAP_CGRCAT1A2_M2",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Cougar MK19",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_MRAP_CGRCAT1A2_MK19",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Atlas",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"boxloader_atlas",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Kalmar",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"boxloader_kalmar",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];

_spawner addAction
[
	"Palletjack",
	{
		(_this select 0) setVariable ["SpawnerCooldown", false, true];
		_hang = nearestObject [(_this select 0), "VR_Area_01_circle_4_grey_F"];
		{
			deleteVehicleCrew _x;
			deleteVehicle _x
			} forEach nearestObjects [_hang, ["Car", "Helicopter", "Motorcycle", "Plane", "Ship", "Submarine", "TrackedAPC", "Tank", "WheeledAPC"], 7];
		sleep 0.1;
		_veh = createVehicle
		[
			"PTF_Tools_PalletJack",
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
	"_target distance (nearestObject [_target, ""VR_Area_01_circle_4_grey_F""]) < 12 && _target getVariable ['SpawnerCooldown', true]"
];