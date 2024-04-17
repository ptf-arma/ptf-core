["weapon", {params ["_unit", "_new", "_old"]; [call tsp_fnc_playa, "switch"] spawn tsp_fnc_gestureState}] call CBA_fnc_addPlayerEventHandler;
player addEventHandler ["GestureChanged", {params ["_unit", "_gesture"]; [call tsp_fnc_playa, _gesture] spawn tsp_fnc_gestureState}];
player addEventHandler ["GestureDone", {params ["_unit", "_gesture"]; [call tsp_fnc_playa, _gesture] spawn tsp_fnc_gestureState}];
[] spawn {while {sleep 1; true} do {[call tsp_fnc_playa, gestureState (call tsp_fnc_playa)] spawn tsp_fnc_gestureState}};
["", true] spawn tsp_fnc_addUIEvent;