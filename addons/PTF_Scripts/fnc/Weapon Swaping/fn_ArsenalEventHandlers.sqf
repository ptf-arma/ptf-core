/*
 * Author: lost
 * EventHandlers to run in arsenal to make it so you can save a weapon.
 *
 * Arguments:
 * N/A
 * 
 * Return Value:
 * none
 *
 * Exslrle:
 *  call PTF_fnc_ArsenalEventHandlers
 */


//when a loadout is saved check if the loadout var is set if true it means that there is a weapon on backpack
//if true save to profile the loadout index and the weapon
["ace_arsenal_onLoadoutSave",{



private _loadoutsavevar = player getVariable ["PTFHolder",[]];
if (count _loadoutsavevar == 0) exitWith {};
_loadoutsavevar = _loadoutsavevar select 1;
private _loadouts = profileNamespace getVariable ["ace_arsenal_saved_loadouts",[]];
private _name = _loadouts select (_this select 0);
_name = _name select 0;	
private _profilevar = profileNamespace getVariable ["PTF_WeaponLoadOutSave",[]];
private _insertarray = [_name] + _loadoutsavevar;
if (_name in (_loadouts select (_this select 0))) exitwith {

_profilevar set [(_this select 0),_insertarray];
};
_profilevar insert [-1,[_insertarray]];
profileNamespace setVariable ["PTF_WeaponLoadOutSave",_profilevar];
saveProfileNamespace;

}] call CBA_fnc_addEventHandler;


//when a loadout is loaded check if there is a saved loadout in the profile via ladout index
//if true add the weapon to the players back
["ace_arsenal_onLoadoutLoad",{

private _profilevar = profileNamespace getVariable ["PTF_WeaponLoadOutSave",[]];
private _weaponcheck = player getVariable ["PTFHolder", []];

if (count _weaponcheck != 0) then {
deleteVehicle (_weaponcheck select 0);
};

{
if ((_x select 0) == (_this select 1)) then {
_weapon = _x;
_weapon = _weapon - [_weapon select 0];
_primaryWeapon = _weapon;
_fakeWeapon = createVehicle ["PTF_DummyHolder", getPosATL player, [], 0, "CAN_COLLIDE"];
_fakeWeapon addWeaponWithAttachmentsCargoGlobal [_primaryWeapon, 1];
player setVariable ["PTFHolder",[_fakeWeapon,_primaryWeapon],true];
_pos = [_primaryWeapon select 0] call PTF_fnc_Pos;
_fakeWeapon attachTo [player,_pos,"Spine3",true];
		   _yaw = 130; _pitch = -10; _roll = 80;   
	  _fakeWeapon setVectorDirAndUp [
	[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],
	[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D
]; 
};
}foreach _profilevar;

}] call CBA_fnc_addEventHandler;



//check if when a loadout is delete that its save in PTF_WeaponLoadOutSave profile var if true delete it
["ace_arsenal_onLoadoutDelete",{
private _WeaponHolderLoadouts = profileNamespace getVariable ["PTF_WeaponLoadOutSave",[]];
if ( count _WeaponHolderLoadouts == 0 ) exitwith {};
private _Remove = scriptNull; 
{
if ( (_this select 0) in _x) then {
_Remove = _forEachIndex;
};
}foreach _WeaponHolderLoadouts;

_WeaponHolderLoadouts = _WeaponHolderLoadouts - [_WeaponHolderLoadouts select _Remove];

profileNamespace setVariable ["PTF_WeaponLoadOutSave",_WeaponHolderLoadouts];
saveProfileNamespace;

}] call CBA_fnc_addEventHandler;
