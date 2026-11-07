#include "script_component.hpp"
/*
 * Author: PTF
 * Create an SLR rope without shocking the load. A rope created shorter than
 * the gap between its ends snaps tight the instant it exists, which throws the
 * load at the aircraft. That gap can be longer than the rope's length: a rope
 * still shortening, or stretched under load. So the rope starts just long
 * enough to reach, then winds in to its length at the normal adjust speed.
 *
 * Arguments:
 * 0: Source object <OBJECT>
 * 1: Point on the source, model space or memory point name <ARRAY or STRING>
 * 2: Target object <OBJECT>
 * 3: Point on the target, model space <ARRAY>
 * 4: Rope length <NUMBER>
 * 5: Rope end offset <ARRAY>
 *
 * Return Value:
 * The rope, or objNull if it couldn't be created <OBJECT>
 *
 * Example:
 * [_heli, _hookPos, _cargo, _liftPoint, 10, [0,0,-11]] call slr_slingload_fnc_createRope
 */

params ["_source", "_sourcePoint", "_target", "_targetPoint", "_length", "_ropeEnd"];

private _sourcePosition = if (_sourcePoint isEqualType "") then {_source selectionPosition _sourcePoint} else {_sourcePoint};
private _gap = (_source modelToWorldWorld _sourcePosition) vectorDistance (_target modelToWorldWorld _targetPoint);
private _startLength = _length max (_gap + 0.1);

private _rope = ropeCreate [_source, _sourcePoint, _target, _targetPoint, _startLength, ["", [0,0,-1]], ["RopeEnd", _ropeEnd]];
if (isNull _rope) exitWith {objNull};

if (_startLength > _length) then {
    [{
        params ["_rope", "_length"];
        if (!isNull _rope) then {
            ropeUnwind [_rope, 1, _length, false];
        };
    }, [_rope, _length]] call CBA_fnc_execNextFrame;
};

_rope
