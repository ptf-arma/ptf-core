/*
	GLT_fnc_drawLaserMap  (Turret Enhanced 2026 Version)
	(map control "Draw" event, every map frame)
	While a vehicle is lasing, draws a red line from the vehicle to the laser spot and a laser icon on
	the spot, labelled with the group name and vehicle type.

	Only vehicles in GLT_lasingCache are checked (built twice a second by GLT_fnc_overlayInit from
	vehicle types enabled in Addon Options > Turret Enhanced (2026 Version) > Vehicle Types, minus MQ-9s when
	"Skip MQ-9" is on).

	CBA settings (Turret Enhanced (2026 Version) > Laser):
		GLT_LaserMapShow     - draw lasers on the map at all
		GLT_LaserMapFriendly - also draw lasers of friendly vehicles (not only your own / your UAV)
*/

params ["_map"];

// Tunables
private _laserColor = [1, 0, 0, 1];
private _laserMarker = "mil_destroy";	// CfgMarkers class used as the laser spot icon

if (!(missionNamespace getVariable ["GLT_LaserMapShow", true])) exitWith {};
private _friendly = missionNamespace getVariable ["GLT_LaserMapFriendly", false];

private _mine = [vehicle player, getConnectedUAV player];
private _icon = getText (configFile >> "CfgMarkers" >> _laserMarker >> "icon");

{
	private _veh = _x;
	private _show = (_veh in _mine) || {_friendly && {((side group _veh) getFriend playerSide) >= 0.6}};

	if (_show) then
	{
		private _info = [_veh] call GLT_fnc_laserInfo;
		if (_info isNotEqualTo []) then
		{
			_info params ["_from", "_to"];

			// Label: "<group name> (<vehicle type>)", cached per vehicle
			private _label = _veh getVariable "GLT_laserLabel";
			if (isNil "_label" || {(_label select 0) != groupId group _veh}) then
			{
				private _group = groupId group _veh;
				private _type = getText (configOf _veh >> "displayName");
				_label = [_group, format ["%1 (%2)", _group, _type]];
				_veh setVariable ["GLT_laserLabel", _label];
			};

			_map drawLine [_from, _to, _laserColor];
			_map drawIcon [_icon, _laserColor, _to, 24, 24, 0, _label select 1, 1, 0.04, "PuristaBold", "right"];
		};
	};
} forEach (missionNamespace getVariable ["GLT_lasingCache", []]);
