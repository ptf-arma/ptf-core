/*
 * Author: Paramarine Task Force
 * Zeus's anti-radiation missile (PTF_GATOR_fnc_initZeus): launched high from a bearing and range
 * off a G/ATOR, homing on its radar if it is transmitting. Server only. The first ARM the game
 * has of the AGM-88 HARM, the modset's AGM-88 and the Kh-58.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: From bearing, degrees <NUMBER>
 * 2: Range, metres <NUMBER>
 *
 * Return Value:
 * The missile <OBJECT>
 */
params [["_radar", objNull, [objNull]], ["_bearing", 0, [0]], ["_range", 9000, [0]]];
if (!isServer || {!alive _radar}) exitWith {objNull};

private _ammo = ["ammo_Missile_HARM", "FIR_AGM88", "USAF_AGM88_AG", "ammo_Missile_KH58"] select {isClass (configFile >> "CfgAmmo" >> _x)} param [0, ""];
if (_ammo == "") exitWith {objNull};
private _from = (_radar getPos [_range, _bearing]) vectorAdd [0, 0, 2500 max (_range / 4)];
private _missile = createVehicle [_ammo, _from, [], 0, "CAN_COLLIDE"];
private _to = (getPosASL _radar) vectorDiff (AGLToASL _from);
_missile setVectorDirAndUp [vectorNormalized _to, [0, 0, 1]];
_missile setVelocity (vectorNormalized _to vectorMultiply 600);
private _sensor = _radar getVariable ["PTF_GATOR_sensor", objNull];
if (!isNull _sensor) then {_missile setMissileTarget _sensor};
diag_log format ["[PTF_GATOR] Zeus ARM (%1) at %2 from %3 deg, %4 m, homing: %5", _ammo, _radar, round _bearing, round _range, !isNull _sensor];
// Its crew hears of it (or, silent, the missile flies on blind).
[PTF_GATOR_fnc_armWatch, [_missile]] call CBA_fnc_execNextFrame;
_missile
