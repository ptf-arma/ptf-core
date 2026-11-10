/*
 * Author: Paramarine Task Force
 * Starts or stops a deployed G/ATOR's antenna turning. The turntable runs off the
 * ptf_gator_spin source, one turn per unit of phase (the source's animPeriod is one
 * revolution). Starting sends the phase far ahead; stopping lets it finish the turn it is
 * on, so the array always comes to rest facing aft, ready to stow. Global effect: call it
 * on one machine.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Turn (true) or stop (false) <BOOL> (default: true)
 *
 * Return Value:
 * Changed <BOOL>
 *
 * Example:
 * [_radar, true] call PTF_GATOR_fnc_setSpinning
 */
params [["_radar", objNull, [objNull]], ["_spin", true, [true]]];

if !([_radar, _spin] call PTF_GATOR_fnc_canSetSpinning) exitWith {false};

private _phase = _radar animationSourcePhase "ptf_gator_spin";
// either way, out of sector mode and any dwell (PTF_GATOR_fnc_operator)
_radar setVariable ["PTF_GATOR_mode", "full", true];
_radar setVariable ["PTF_GATOR_dwell", nil, true];
// About eight days of turning at one turn every few seconds; stopping comes long before.
_radar animateSource ["ptf_gator_spin", [ceil _phase, _phase + 100000] select _spin];
_radar setVariable ["PTF_GATOR_spinning", _spin, true];
true
