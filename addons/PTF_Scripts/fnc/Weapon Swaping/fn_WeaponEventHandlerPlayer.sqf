player addEventHandler ["InventoryClosed", {
	params ["_unit", "_container"];
	private _shouldervar = player getVariable ["PTFHolder",[]];
	if (count _shouldervar == 0) exitWith {};
	if (secondaryWeapon player == "") exitWith {};
	
_fakeWeapon = createVehicle ["PTF_DummyHolder", getPosATL player, [], 0, "CAN_COLLIDE"];
_fakeWeapon addWeaponCargo [secondaryWeapon player,1];
player removeWeapon  (secondaryWeapon player);
}];

//show weapon on back in player inventory
player addEventHandler ["InventoryOpened", {
params ["_unit", "_container"];
if (isNil{(player getVariable "PTFHolder") select 1} == true) exitWith {};

[] spawn {
waitUntil {dialog == true};
_weaponvar = (player getVariable "PTFHolder") select 1;  
_display = findDisplay 602;  
_lauancherbackground = _display displayCtrl 611; 
_lauancherbackground ctrlShow false;   
_pic = [configFile >> 'CfgWeapons' >> (_weaponvar # 0) , 'picture',""] call BIS_fnc_returnConfigEntry;   
_lauancherslot = _display ctrlCreate ["RscPicture",18739]; 
_lauancherslot ctrlSetPosition [safeZoneX + safeZoneW * 0.52083334,safeZoneY + safeZoneH * 0.16574075,safeZoneW * 0.128125,safeZoneH * 0.08240741]; 
_lauancherslot ctrlSetText _pic; 
_lauancherslot ctrlSetBackgroundColor [0,0,0,0]; 
_lauancherslot ctrlCommit 0;
}
}];