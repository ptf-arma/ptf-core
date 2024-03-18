
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



_player = player;

//white list of weapons to place on shoulder in addon settings
_wList = call compile PTF_WeaponWList;
_Acheck = _player getVariable ["PTFHolder", ""];
_Acheck = count _Acheck;

_neardummy = position _player nearObjects ["PTF_DummyHolder", 1.4];
_neardummyC = count _neardummy;
//checks if there is a dummy wepaon allready on the player

//checks if white list is active and if the weapon the player has is in there hand
if ( PTF_WeaponW == true && (currentWeapon _player) in _wList == false && _neardummyC == 0 ) exitwith {
hint "this weapon can't be shoulderd"
};

//check if the weapon on your shoulder is not in the white list and if the one in your hand is also not
if ( PTF_WeaponW == true && ((weaponCargo (_neardummy select 0)) select 0) in _wList == false && (currentWeapon _player) in _wList == false) exitwith {
hint "this weapon can't be shoulderd"
};


//if there is no weapon on shoulder
if (_Acheck == 0) exitwith {
[_player] call PTF_fnc_Shoulder;
};


//check that there is a weapon on back
if (_Acheck > 1) exitwith {
[_player] call PTF_fnc_SoulderNSwap;
};

