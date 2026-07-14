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

_key = "";

_Drop = createHashMapFromArray [
["primary",["proxy:\a3\characters_f\proxies\weapon.001"]],
["secondary",["proxy:\a3\characters_f\proxies\pistol.001"]],
["launcher",["proxy:\a3\characters_f\proxies\launcher.001"]]
];




_Weapon = currentWeapon _Object;
_MagCount = _Object ammo currentWeapon _Object;
(primaryWeaponItems _Object) params ["_muzzle","_laser","_optic","_grip"];
(primaryWeaponMagazine _Object) params ["_WeaponMag","_WeaponGl"]; 
_primaryWeapon = [_Weapon, _muzzle, _laser, _optic, [_WeaponMag, _MagCount], _WeaponGl, _grip];

switch _Weapon do {
case (primaryWeapon _Object) : {_key = "primary"};
case (secondaryWeapon _Object) : {_key = "launcher"};
case (handgunWeapon _Object) : {_key = "secondary"};
};

if (_key isEqualTo "") exitWith {};

//_Object removeWeapon _Weapon;

_fakeWeapon = createVehicle ["PTF_DummyHolder", getPosATL _Object, [], 0, "CAN_COLLIDE"];
_fakeWeapon addWeaponWithAttachmentsCargoGlobal [_primaryWeapon, 1];





_pos = getPosATL _Object vectorAdd (_Object vectorModelToWorld (selectionPosition [_Object,(_drop get _key) select 0 ,9,true,"AveragePoint"]));
_pos = _pos vectorAdd (_Object vectorModelToWorld [-0.3,0,-0.7]);
_fakeWeapon setPos _pos;  

	_yaw = (getDirVisual _Object) -90; 
	_pitch = 90; _roll = 0;   
	_fakeWeapon setVectorDirAndUp [
	[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],
	[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D
	];

//





