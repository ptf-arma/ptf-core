

//make dummy weapon

_player = player;
_Weapon = primaryWeapon _player;
_MagCount = _player ammo primaryWeapon _player;
(primaryWeaponItems _player) params ["_muzzle","_laser","_optic","_grip"];
(primaryWeaponMagazine _player) params ["_WeaponMag","_WeaponGl"]; 
_primaryWeapon = [_Weapon, _muzzle, _laser, _optic, [_WeaponMag, _MagCount], _WeaponGl, _grip];

// _player removeWeapon _Weapon;

_fakeWeapon = createVehicle ["DummyWeapon_Wbk", getPosATL player, [], 0, "CAN_COLLIDE"];
_fakeWeapon addWeaponWithAttachmentsCargoGlobal [_primaryWeapon, 1];
_player setVariable ["PTFHolder",[_fakeWeapon,_primaryWeapon],true];
_fakeWeapon attachTo [player,[-0.2,-0.12,0],"Spine3",true];
		   _yaw = 130; _pitch = -10; _roll = 80;   
	  _fakeWeapon setVectorDirAndUp [
	[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],
	[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D
]; 
player playActionNow "PTF_WeaponBack";



//switch weapons

_player = player;
_Weapon = primaryWeapon _player;
_MagCount = _player ammo primaryWeapon _player;
(primaryWeaponItems _player) params ["_muzzle","_laser","_optic","_grip"];
(primaryWeaponMagazine _player) params ["_WeaponMag","_WeaponGl"]; 
_primaryWeapon = [_Weapon, _muzzle, _laser, _optic, [_WeaponMag, _MagCount], _WeaponGl, _grip];

_player removeWeapon _Weapon;

_FakeWeapon = _player getVariable "PTFHolder" select 0;
_NewWeapon = _player getVariable "PTFHolder" select 1;

deleteVehicle _FakeWeapon;

_NewWeapon params ["_Weapon", "_muzzle", "_laser", "_optic", "_WeaponMag", "_WeaponGl", "_grip"];
_WeaponMag params ["_WeaponMagg","_WeaponMaggAmount"];

_player addMagazine _WeaponMag;
_player addWeapon _Weapon;
{
_player addPrimaryWeaponItem _x;
} forEach [_muzzle,_laser,_optic,_grip, _WeaponGl];


_fakeWeapon = createVehicle ["DummyWeapon_Wbk", getPosATL player, [], 0, "CAN_COLLIDE"];
_fakeWeapon addWeaponWithAttachmentsCargoGlobal [_primaryWeapon, 1];
_player setVariable ["PTFHolder",[_fakeWeapon,_primaryWeapon],true];
_fakeWeapon attachTo [player,[-0.2,-0.12,0],"Spine3",true];
		   _yaw = 130; _pitch = -10; _roll = 80;   
	  _fakeWeapon setVectorDirAndUp [
	[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],
	[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D
];

_player selectWeapon _Weapon;
player playActionNow "PTF_TakeoutWeaponBack";


