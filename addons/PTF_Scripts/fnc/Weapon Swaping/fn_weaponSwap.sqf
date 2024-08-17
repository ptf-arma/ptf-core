
/*
 * Author: lost
 * Places a wepaon on a players shoulder or switches out the players wepaon with the one on the shoulder
 *
 * Arguments:
 * N/A
 * 
 * Return Value:
 * none
 *
 * Exslrle:
 *  call PTF_fnc_weaponSwap 
 */


//white list of weapons to place on shoulder in addon settings
_wList = call compile PTF_WeaponWList;
_Acheck = player getVariable ["PTFHolder", ""];
_Acheck = count _Acheck;

_weaponCheck = primaryWeapon player;

_neardummy = position player nearObjects ["PTF_DummyHolder", 1.5];
_neardummyC = count _neardummy;
//checks if there is a dummy wepaon allready on the player


if (_weaponCheck == "" && _neardummyC == 1) exitwith {
call PTf_fnc_SawpNDelete
};

//checks if white list is active and if the weapon the player has is in there hand
if ( PTF_WeaponW == true && (currentWeapon player) in _wList == false && _neardummyC == 0 ) exitwith {
hint "this weapon can't be shouldered"
};

//check if the weapon on your shoulder is not in the white list and if the one in your hand is also not
if ( PTF_WeaponW == true && ((weaponCargo (_neardummy select 0)) select 0) in _wList == false && (currentWeapon player) in _wList == false) exitwith {
hint "this weapon can't be shouldered"
};


//if there is no weapon on shoulder
if (_Acheck == 0 ) exitWith {
call PTF_fnc_Shoulder;
};


//check that there is a weapon on back
if (_Acheck > 1) exitWith {
call PTF_fnc_SoulderNSwap;
};

