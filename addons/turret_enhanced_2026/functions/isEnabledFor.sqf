/*
	GLT_fnc_isEnabledFor  (Turret Enhanced 2026 Version)
	Whether Turret Enhanced is enabled for this vehicle's type
	(Addon Options > Turret Enhanced (2026 Version) > Vehicle Types). Air assets only: helicopters and
	planes, including UAVs of either type. Everything else is excluded.

	Params: _veh <OBJECT>
	Returns: <BOOL>
*/

params [["_veh", objNull, [objNull]]];

switch (true) do
{
	case (isNull _veh):                 {false};
	case (_veh isKindOf "Helicopter"):  {missionNamespace getVariable ["GLT_EnableHelicopters", true]};
	case (_veh isKindOf "Plane"):       {missionNamespace getVariable ["GLT_EnablePlanes", true]};
	default {false};
}
