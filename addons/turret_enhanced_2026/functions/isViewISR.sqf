//isviewISR

//Erik Kofahl

params["_player", "_veh"];

// GLT: per vehicle type enable settings (Addon Options > Vehicle Types). Every Turret Enhanced feature
// (actions, HUD, marking, slewing) goes through this check.
if (!([_veh] call GLT_fnc_isEnabledFor)) exitWith {false};

if((unitIsUAV _veh) && (cameraView == "GUNNER") && (UAVControl _veh select 1 == "GUNNER")) exitWith {true};

if((!(unitIsUAV _veh)) &&(cameraView == "GUNNER") && (_veh getCargoIndex _player == -1))  exitWith {true};

false

