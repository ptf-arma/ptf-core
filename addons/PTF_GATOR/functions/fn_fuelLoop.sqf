/*
 * Author: Paramarine Task Force
 * Burns a G/ATOR's fuel while its generator runs, once a second, on the machine where the
 * G/ATOR is local, and stops the generator (and the antenna) when the tank runs dry or the
 * generator is wrecked. Started everywhere by the PTF_GATOR XEH init; does nothing where the
 * G/ATOR isn't local, so it carries on wherever it moves (towing hands it to the driver).
 *
 * Fire: a wrecked tank (HitFuel) with fuel in it catches fire. The fuel pours out and burns
 * within FIRE_DRAIN seconds for a full tank, the generator and the trailer char as it burns,
 * and if it is still burning after FIRE_KILL seconds (more than about half a tank) the
 * G/ATOR is lost. With less fuel the fire burns out first and leaves it repairable.
 * PTF_GATOR_fireStart (global) is when it caught, or -1; clients draw the flames from it.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_fuelLoop
 */
#define FIRE_DRAIN 45
#define FIRE_KILL 25

params [["_radar", objNull, [objNull]]];

if (isNull _radar) exitWith {};

[{
	params ["_radar", "_handle"];
	if (isNull _radar) exitWith {[_handle] call CBA_fnc_removePerFrameHandler};
	if (!alive _radar) exitWith {
		// Its own fire gives way to the wreck's.
		if (local _radar && {_radar getVariable ["PTF_GATOR_fireStart", -1] >= 0}) then {
			deleteVehicle (_radar getVariable ["PTF_GATOR_fireSound", objNull]);
			_radar setVariable ["PTF_GATOR_fireStart", -1, true];
		};
		[_handle] call CBA_fnc_removePerFrameHandler;
	};
	if (!local _radar) exitWith {};

	private _stopGenerator = {
		if (_radar getVariable ["PTF_GATOR_spinning", false]) then {
			_radar setVariable ["PTF_GATOR_spinning", false, true];
			_radar animateSource ["ptf_gator_spin", ceil (_radar animationSourcePhase "ptf_gator_spin")];
		};
		if ([_radar] call PTF_GATOR_fnc_powerState in ["starting", "on"]) then {
			_radar setVariable ["PTF_GATOR_powerOn", false, true];
			_radar setVariable ["PTF_GATOR_powerTime", CBA_missionTime, true];
		};
	};

	// Fire.
	private _fireStart = _radar getVariable ["PTF_GATOR_fireStart", -1];
	if (_fireStart < 0 && {_radar getHitPointDamage "HitFuel" >= 0.9} && {fuel _radar > 0.02}) then {
		_fireStart = CBA_missionTime;
		_radar setVariable ["PTF_GATOR_fireStart", _fireStart, true];
		_radar setVariable ["PTF_GATOR_fireSound", createSoundSource ["Sound_Fire", _radar modelToWorld (_radar selectionPosition ["destructionEffect1", "Memory"]), [], 0]];
		call _stopGenerator;
	};
	if (_fireStart >= 0) exitWith {
		private _fuel = (fuel _radar - 1 / FIRE_DRAIN) max 0;
		_radar setFuel _fuel;
		{
			_x params ["_hit", "_rate"];
			_radar setHitPointDamage [_hit, ((_radar getHitPointDamage _hit) + _rate) min 1];
		} forEach [["HitEngine", 0.04], ["HitBody", 0.02], ["HitRadar", 0.01]];
		if (CBA_missionTime - _fireStart >= FIRE_KILL) exitWith {
			deleteVehicle (_radar getVariable ["PTF_GATOR_fireSound", objNull]);
			_radar setVariable ["PTF_GATOR_fireStart", -1, true];
			_radar setDamage 1;
		};
		if (_fuel <= 0) then {
			deleteVehicle (_radar getVariable ["PTF_GATOR_fireSound", objNull]);
			_radar setVariable ["PTF_GATOR_fireStart", -1, true];
		};
	};

	if !([_radar] call PTF_GATOR_fnc_powerState in ["starting", "on"]) exitWith {};
	private _fuel = (fuel _radar - 1 / (60 * getNumber (configOf _radar >> "ptf_gator_fuelMinutes"))) max 0;
	_radar setFuel _fuel;
	// It stops when the tank runs dry or the generator is shot up.
	if (_fuel > 0 && {_radar getHitPointDamage "HitEngine" < 0.9}) exitWith {};
	call _stopGenerator;
}, 1, _radar] call CBA_fnc_addPerFrameHandler;
