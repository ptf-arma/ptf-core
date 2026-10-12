/*
	GLT_fnc_getISRVehicle  (Turret Enhanced 2026 Version)
	Returns the vehicle whose turret/camera the local player is currently looking through
	(connected UAV or the vehicle the player is sitting in), or objNull if the player is
	not in an ISR (gunner) view.

	Usage: private _veh = call GLT_fnc_getISRVehicle;
*/

private _veh = getConnectedUAV player;

if (isNull _veh) then
{
	_veh = vehicle player;
	if (_veh == player) then {_veh = objNull};
};

if (isNull _veh) exitWith {objNull};
if (!([player, _veh] call fatlurch_fnc_isViewISR)) exitWith {objNull};

_veh
