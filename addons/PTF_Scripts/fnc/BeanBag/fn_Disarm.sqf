/*
 * Author: lost
 * Removes the curret weapon from a units hand and drops it
 *
 * Arguments:
 * object
 *
 * Return Value:
 * N/a
 *
 * Exslrle:
 *  [player] call PTF_fnc_Disarm
 */

params ["_Object"];

private _key = "";

private _Drop = createHashMapFromArray [
["primary",["proxy:\a3\characters_f\proxies\weapon.001"]],
["secondary",["proxy:\a3\characters_f\proxies\pistol.001"]],
["launcher",["proxy:\a3\characters_f\proxies\launcher.001"]]
];




private _Weapon = currentWeapon _Object;

// A holstered unit returns "" here, and "" also matches an empty launcher or
// handgun slot in the switch below, so bail out before the cases are compared.
if (_Weapon isEqualTo "") exitWith {};

switch _Weapon do {
case (primaryWeapon _Object) : {_key = "primary"};
case (secondaryWeapon _Object) : {_key = "launcher"};
case (handgunWeapon _Object) : {_key = "secondary"};
};

if (_key isEqualTo "") exitWith {};

// Read the attachments and magazine of the slot actually being disarmed, else a
// dropped pistol or launcher is spawned carrying the rifle's optic, grip and mag.
private _MagCount = _Object ammo currentWeapon _Object;
private _WeaponItems = [];
private _WeaponMags = [];
switch _key do {
case "secondary" : {_WeaponItems = handgunItems _Object; _WeaponMags = handgunMagazine _Object};
case "launcher" : {_WeaponItems = secondaryWeaponItems _Object; _WeaponMags = secondaryWeaponMagazine _Object};
default {_WeaponItems = primaryWeaponItems _Object; _WeaponMags = primaryWeaponMagazine _Object};
};

_WeaponItems params ["_muzzle","_laser","_optic","_grip"];
// Only an underbarrel GL fills the second slot, so default both or an unloaded
// weapon leaves them undefined and the array below throws.
_WeaponMags params [["_WeaponMag",""],["_WeaponGl",""]];
private _primaryWeapon = [_Weapon, _muzzle, _laser, _optic, [_WeaponMag, _MagCount], _WeaponGl, _grip];

//_Object removeWeapon _Weapon;

private _fakeWeapon = createVehicle ["PTF_DummyHolder", getPosATL _Object, [], 0, "CAN_COLLIDE"];
_fakeWeapon addWeaponWithAttachmentsCargoGlobal [_primaryWeapon, 1];





private _pos = getPosATL _Object vectorAdd (_Object vectorModelToWorld (selectionPosition [_Object,(_drop get _key) select 0 ,9,true,"AveragePoint"]));
_pos = _pos vectorAdd (_Object vectorModelToWorld [-0.3,0,-0.7]);
_fakeWeapon setPos _pos;

	private _yaw = (getDirVisual _Object) -90;
	private _pitch = 90; private _roll = 0;
	_fakeWeapon setVectorDirAndUp [
	[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],
	[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D
	];

//





