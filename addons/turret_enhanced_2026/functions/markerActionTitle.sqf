/*
	GLT_fnc_markerActionTitle  (Turret Enhanced 2026 Version)
	Builds the scroll-menu title for a marker slot, coloured with the colour configured in
	the CBA settings. Dark colours (e.g. black) get a light outline so they stay readable
	on the action menu background.

	Params: _slot <NUMBER> 1, 2 or 3
	Returns: <STRING> structured text title
*/

params [["_slot", 1, [0]]];

([_slot] call GLT_fnc_markerSlotInfo) params ["_type", "_color", "_typeName", "_colorName", "_hex", "_isDark"];

private _outline = ["", " shadow='2' shadowColor='#FFFFFF'"] select _isDark;

format ["Mark Target <t color='%1'%2>(%3 %4)</t>", _hex, _outline, _colorName, _typeName]
