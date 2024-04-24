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



//when the players opens the loadout display check if they have a wepaon on there back and add that weapon to there backpack (or give them one to)
["ace_arsenal_loadoutsDisplayOpened",{
_weapon = player getVariable ["PTFHolder", []];
_backpack = unitBackpack player;
if (count _weapon == 0) exitWith {};
if (isNull _backpack) then {
player addBackpack "PTF_Backpack_Air_Carryall_Invis";
_backpack = unitBackpack player;
};

_backpack addWeaponWithAttachmentsCargoGlobal [(_weapon # 1),1];

player setVariable ["PTF_LoadOutWeapon",_weapon # 1];

}] call CBA_fnc_addEventHandler;



//when the players closes the loadout display get all there weapons in there backpack and remove them
["ace_arsenal_loadoutsDisplayClosed",{

player setVariable ["PTF_LoadOutWeapon",[]];
private _backpack = unitBackpack player;
private _weaponarray = [];
private _weapon = player getVariable ["PTFHolder", ""];
private _weaponholder = position player nearObjects ["PTF_DummyHolder", 1.4];

if (typeof _backpack == "PTF_FAKEBACKPACK") exitWith {removeBackpack player};

if (count _weaponholder < 0) exitWith {
};
private _allweapons = getWeaponCargo _backpack;
{
if (_x !=  ((_weapon select 1)select 0)) then {
private _weaponInset = [_allweapons select 0 select _forEachIndex,_allweapons select 1 select _forEachIndex];
_weaponarray insert[-1,[_weaponInset]];
};
}foreach (_allweapons select 0);
	
clearWeaponCargo _backpack;

{
_backpack addWeaponCargoGlobal _x
}foreach _weaponarray;

}] call CBA_fnc_addEventHandler;


//when a loadout is saved check if the loadout var is set if true it means that there is a weapon on backpack
//if true save to profile the loadout index and the weapon
["ace_arsenal_onLoadoutSave",{

private _loadoutsavevar = player getVariable ["PTF_LoadOutWeapon",[]];
if (count _loadoutsavevar == 0) exitWith {};
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
