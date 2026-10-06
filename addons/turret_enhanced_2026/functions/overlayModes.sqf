/*
	GLT_fnc_overlayModes  [GLT] Goltred update - not part of the original Turret Enhanced by Fat_Lurch.
	Works out which camera-overlay modes are allowed and which one is in effect.

	Modes (in cycle order):
		3 = Declutter                - nothing drawn: no markers, no friendly lasers
		0 = No markers (lasers only) - only friendly lasers
		1 = My markers               - + friendly lasers
		2 = All map markers          - + friendly lasers

	Server-wide settings (CBA isGlobal = 1, players can't change them):
		GLT_MarkerOverlayShow      - markers allowed at all
		GLT_MarkerOverlayAllowMine - mode 1 allowed
		GLT_MarkerOverlayAllowAll  - mode 2 allowed
		GLT_LaserOverlayAllow      - friendly lasers allowed (+ player setting GLT_LaserOverlayShow)
	Player setting: GLT_MarkerOverlayMode - the chosen mode (also set by the cycle key / scroll action).

	Declutter is always available. "No markers" is only offered when lasers are on (otherwise it would look
	the same as Declutter). A chosen marker mode that isn't allowed falls back to the other allowed marker
	mode, else to No markers / Declutter.

	Returns: [_effectiveMode, _allowedModes (cycle order), _markerMode (0/1/2 for the marker list), _lasersShown]
*/

if (isNil "GLT_overlayModeNames") then
{
	// index = mode
	GLT_overlayModeNames = ["No markers (lasers only)", "My markers", "All map markers", "Declutter"];
};

private _markersOn = missionNamespace getVariable ["GLT_MarkerOverlayShow", true];
private _lasersOn = (missionNamespace getVariable ["GLT_LaserOverlayAllow", true]) && {missionNamespace getVariable ["GLT_LaserOverlayShow", true]};

private _allowed = [3];
if (_lasersOn) then {_allowed pushBack 0};
if (_markersOn && {missionNamespace getVariable ["GLT_MarkerOverlayAllowMine", true]}) then {_allowed pushBack 1};
if (_markersOn && {missionNamespace getVariable ["GLT_MarkerOverlayAllowAll", true]}) then {_allowed pushBack 2};

private _chosen = missionNamespace getVariable ["GLT_MarkerOverlayMode", 1];
private _fallback = [3, 0] select _lasersOn;
private _effective = switch (true) do
{
	case (_chosen in _allowed): {_chosen};
	case (_chosen in [1, 2]):   {(_allowed select {_x in [1, 2]}) param [0, _fallback]};
	default {_fallback};
};

[_effective, _allowed, [0, _effective] select (_effective in [1, 2]), _lasersOn && {_effective != 3}]
