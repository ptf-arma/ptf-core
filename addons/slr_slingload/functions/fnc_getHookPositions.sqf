#include "script_component.hpp"
/*
 * Author: Ampersand, PTF
 * Where an aircraft's cargo hooks are, in its model space. Public: SLR uses it
 * for the Attach Cargo actions and the hook-up, and other mods (e.g. a hook
 * camera) can use it to find the same points.
 *
 * Aircraft in slr_customHooks (by model, then by class) get that entry, in
 * order [main, forward, aft]; an entry can be [] if the aircraft lacks that
 * hook. Anything else gets its config slingLoadMemoryPoint as the main hook.
 *
 * Arguments:
 * 0: Heli <OBJECT>
 *
 * Return Value:
 * Hook positions, model space, [main, forward, aft] or fewer; [] if the
 * aircraft has no hook <ARRAY>
 *
 * Example:
 * [vehicle player] call slr_slingload_fnc_getHookPositions
 */

params ["_heli"];

private _config = configOf _heli;
private _customHooks = slr_customHooks getOrDefaultCall [getText (_config >> "model"), {
    slr_customHooks getOrDefault [typeOf _heli, []]
}];
if (_customHooks isNotEqualTo []) exitWith {+_customHooks};

private _memoryPointPosition = _heli selectionPosition getText (_config >> "slingLoadMemoryPoint");
if (_memoryPointPosition isEqualTo [0, 0, 0]) exitWith {[]};
[_memoryPointPosition]
