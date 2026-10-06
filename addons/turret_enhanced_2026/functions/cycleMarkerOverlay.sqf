/*
	GLT_fnc_cycleMarkerOverlay  [GLT] Goltred update - not part of the original Turret Enhanced by Fat_Lurch.
	Controls action "Cycle Camera Overlay" (GLT_cycleMarkerOverlay, default SHIFT+7) and the
	"Camera Overlay: <mode>" scroll-menu action (fatlurch_fnc_MPaddaction):
		Declutter -> No markers (lasers only) -> My markers -> All map markers -> Declutter ...
	skipping every mode the server doesn't allow (GLT_fnc_overlayModes).

	The key changes the player's own (client) value of GLT_MarkerOverlayMode and saves it to the profile, so
	Addon Options always shows the same choice.

	Server control:
		- markers / "My Markers" / "All Map Markers" / friendly lasers switched off (server-wide) -> those
		  modes are skipped; Declutter is always available
		- "Overlay Mode" forced by the server / mission (CBA force) -> the key does nothing (only a notice)
	The settings are read at every press, so a change made by an admin mid-mission applies immediately.

	Returns: <BOOL> true if the mode changed
*/

private _notify = {
	params ["_text"];
	"GLT_cycleMarkerOverlay" cutText [format ["Camera overlay: %1", _text], "PLAIN DOWN", 0.3];
};

(call GLT_fnc_overlayModes) params ["_current", "_allowed"];

if (count _allowed < 2) exitWith
{
	[format ["%1 (nothing else allowed by the server)", GLT_overlayModeNames select _current]] call _notify;
	false
};
// Source in effect: "client" = the player's own value, "mission" / "server" = forced
if (("GLT_MarkerOverlayMode" call CBA_settings_fnc_priority) != "client") exitWith
{
	[format ["%1 (locked by server settings)", GLT_overlayModeNames select _current]] call _notify;
	false
};

private _index = (_allowed find _current) max 0;
private _next = _allowed select ((_index + 1) mod (count _allowed));

// ["setting", value, priority, source, store in profile]
["GLT_MarkerOverlayMode", _next, 0, "client", true] call CBA_settings_fnc_set;
call GLT_fnc_buildOverlayList;
call GLT_fnc_friendlyLasers;

// Report what is actually in effect now
private _now = (call GLT_fnc_overlayModes) select 0;
[GLT_overlayModeNames select _now] call _notify;

_now != _current
