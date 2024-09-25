/*
 * Author: lost
 * places a weapon the players shoulder and delete the fake weapon
 *
 * Arguments:
 * n/a
 * 
 * Return Value:
 * N/a
 *
 * Exslrle:
 * call PTf_fnc_SawpNDelete
 */


private _FakeWeapon = player getVariable "PTFHolder" select 0;
private _NewWeapon = player getVariable ["PTFHolder",[[],null]] select 1;

//gets all the info need to give the player the shouldered weapon

deleteVehicle _FakeWeapon;
//removed the fake wepaon from back


_NewWeapon params ["_Weapon", "_muzzle", "_laser", "_optic", "_WeaponMag", "_WeaponGl", "_grip"];
_WeaponMag params ["_WeaponMagg","_WeaponMaggAmount"];


if (count _WeaponMagg != 0) then {
player addMagazine _WeaponMag;
};

player addWeapon _Weapon;


{
player addPrimaryWeaponItem _x;
} forEach [_muzzle,_laser,_optic,_grip, _WeaponGl];

player selectWeapon _Weapon;
player playActionNow "PTF_TakeoutWeaponBack";

player setVariable ["PTFHolder",[]];

