/*
 * Author: lost
 * places a weapon the players shoulder & swaps it out with the one on there back
 *
 * Arguments:
 * player
 * 
 * Return Value:
 * N/a
 *
 * Exslrle:
 *  call PTF_fnc_SoulderNSwap.
 */


_Weapon = primaryWeapon player;
_MagCount = player ammo primaryWeapon player;
(primaryWeaponItems player) params ["_muzzle","_laser","_optic","_grip"];
(primaryWeaponMagazine player) params ["_WeaponMag","_WeaponGl"]; 
_primaryWeapon = [_Weapon, _muzzle, _laser, _optic, [_WeaponMag, _MagCount], _WeaponGl, _grip];

//make the array above to be used addWeaponWithAttachmentsCargoGlobal

player removeWeapon _Weapon;

_FakeWeapon = player getVariable "PTFHolder" select 0;
_NewWeapon = player getVariable ["PTFHolder",[[],null]] select 1;

//gets all the info need to give the player the shouldered weapon

deleteVehicle _FakeWeapon;
//removed the fake wepaon from back


_NewWeapon params ["_Weapon", "_muzzle", "_laser", "_optic", "_WeaponMag", "_WeaponGl", "_grip"];
_WeaponMag params ["_WeaponMagg","_WeaponMaggAmount"];



player addMagazine _WeaponMag;
player addWeapon _Weapon;


{
player addPrimaryWeaponItem _x;
} forEach [_muzzle,_laser,_optic,_grip, _WeaponGl];
//define what the arrays from the players PTFHolder var mean and used to give the 
//player the weapon that was on there back


_fakeWeapon = createVehicle ["PTF_DummyHolder", getPosATL player, [], 0, "CAN_COLLIDE"];
//crate fake wepaon holder
_fakeWeapon addWeaponWithAttachmentsCargoGlobal [_primaryWeapon, 1];
//adds attachments to fake weapon
player setVariable ["PTFHolder",[_fakeWeapon,_primaryWeapon],true];
//set the PTFHolder var to info need to give player the shouldered weapon next time its called
_pos = [_Weapon] call PTF_fnc_Pos;
_fakeWeapon attachTo [player,_pos,"Spine3",true];
		   _yaw = 130; _pitch = -10; _roll = 80;   
	  _fakeWeapon setVectorDirAndUp [
	[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],
	[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D
];
//rotates the dummy object

player selectWeapon _Weapon;
player playActionNow "PTF_TakeoutWeaponBack";