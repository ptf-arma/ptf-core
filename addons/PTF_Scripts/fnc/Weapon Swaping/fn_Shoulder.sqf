/*
 * Author: lost
 * places a weapon the players shoulder & delete the one in there hand
 *
 * Arguments:
 * player
 * 
 * Return Value:
 * N/a
 *
 * Exslrle:
 *  [player] call PTF_fnc_Soulder
 */

_Weapon = primaryWeapon player;
_MagCount = player ammo primaryWeapon player;
(primaryWeaponItems player) params ["_muzzle","_laser","_optic","_grip"];
(primaryWeaponMagazine player) params ["_WeaponMag","_WeaponGl"]; 
_primaryWeapon = [_Weapon, _muzzle, _laser, _optic, [_WeaponMag, _MagCount], _WeaponGl, _grip];

//make the array above to be used addWeaponWithAttachmentsCargoGlobal

player removeWeapon _Weapon;

//create the dummy weapon
_fakeWeapon = createVehicle ["PTF_DummyHolder", getPosATL player, [], 0, "CAN_COLLIDE"];
//set the weeapons looks all from _primaryWeapon
_fakeWeapon addWeaponWithAttachmentsCargoGlobal [_primaryWeapon, 1];
//set the players var to have all the infor needed to give the player a weapon
player setVariable ["PTFHolder",[_fakeWeapon,_primaryWeapon],true];
//set the location of the fake wepaon
_pos = [_Weapon] call PTF_fnc_Pos;
_fakeWeapon attachTo [player,_pos,"Spine3",true];
		   _yaw = 130; _pitch = -10; _roll = 80;   
	  _fakeWeapon setVectorDirAndUp [
	[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],
	[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D
]; 
//play put back animation
player playActionNow "PTF_WeaponBack";
