tsp_fnc_animate_playGesture = {
    params ["_unit", "_in", "_inTime", "_loop", "_out", "_interupt", "_instant", "_lower", "_holster"];

    if (_unit getVariable ["tsp_gestureState", ""] == _loop) exitWith {_unit setVariable ["tsp_gestureStop", true]};        //-- Toggle gesture if already on
    if (_unit getVariable ["tsp_gestureState", ""] != "") then {_unit setVariable ["tsp_gestureStop", true]; sleep 0.4};   //-- If already doing gesture, then stop it firest
    if (_holster) then {[_unit] call tsp_fnc_holster};                                                                    //-- Holster weapon if required    
    if (_lower) then {[_unit, {sleep 0.4; _unit getVariable ["tsp_gestureState", ""] != ""}] spawn tsp_fnc_forceLower};  //-- Sleep because the exit condition needs to wait for tsp_fnc_playGesture to do its thing
    [_unit, _in, _inTime, _loop, _out, _interupt, _instant] spawn tsp_fnc_playGesture;                                  //-- Play gesture
};

tsp_fnc_animate_playDance = {
    params ["_unit", "_animation"];	

    [_unit, _animation] remoteExec ["playMove", 0];  //-- Start dancing yo

    //-- Prevent switching back to primary during dance
    waitUntil {animationState _unit == _animation || !alive _unit};  //-- Cause the swtich isn't instant cause playMove
    while {sleep 0.5; animationState _unit == _animation} do {
        _unit selectWeapon (handgunWeapon _unit);  //-- Switch to pistol if we have it, cause we like dancing with pistols
        if (currentWeapon _unit == primaryWeapon _unit) then {if (!isNil "ACE_hitreactions_fnc_throwWeapon") then {_unit call ACE_hitreactions_fnc_throwWeapon}};  //-- Throw rifle if attempt to switch
    };
};

tsp_fnc_animate_stop = {
    params ["_unit"];	
    _animList = [
        "a2_duoivan",
        "a2_duostefan",
        "a2_stefan",
        "a2_zozo",
        "a2_metal",
        "acts_dance_01",
        "acts_dance_02",
        "amovpercmstpsnonwnondnon_exercisekata",
        "amovpercmstpsnonwnondnon_exercisepushup"
    ];
    if (animationState _unit in _animList) then {[_unit, ''] remoteExec ['switchMove', 0]}; 
    if ([call tsp_fnc_playa] call tsp_fnc_animate_readyCheck != 0) exitWith {};  //-- Dont stop with space if in ready
    _unit setVariable ['tsp_gestureStop', true];
};


//-- SPECIALS
tsp_fnc_animate_suicide = {
    params ["_unit"];	

    //-- Choose suicide animation
    _suicideAnimIn = "";
    _suicideAnimLoop = "";
    switch (currentWeapon _unit) do {
        case (primaryWeapon _unit): {_suicideAnimIn = "tsp_animate_suicide_rifle_in"; _suicideAnimLoop = "tsp_animate_suicide_rifle_loop"};
        case (handgunWeapon _unit): {_suicideAnimIn = "tsp_animate_suicide_pistol_in"; _suicideAnimLoop = "tsp_animate_suicide_pistol_loop"};
    };    

    [_unit, _suicideAnimIn, 2, _suicideAnimLoop, "tsp_common_stop", false] spawn tsp_fnc_playGesture;  //-- Play it

    waitUntil {_unit getVariable ["tsp_gestureState", ""] == _suicideAnimLoop || !alive _unit};  //-- Wait until gun is pointed at head

    _suicideEH = _unit addEventHandler ["Fired", {  //-- Kill player if he shoots
        params ["_unit", "_weapon"];
        _unit setHitPointDamage ["hitHead", 100];  //-- Vanilla damage
        [_unit, 100, "head", "bullet"] call ace_medical_fnc_addDamageToUnit;  //-- ACE damage
    }];

    waitUntil {_unit getVariable ["tsp_gestureState", ""] != _suicideAnimLoop || !alive _unit};  //-- Wait until out of suicide anim or dead
    _unit removeEventHandler ["Fired", _suicideEH];  //-- Remove kill self event handler
};

tsp_fnc_animate_inspect = {
    params ["_unit"];

    switch (currentWeapon _unit) do {
        case (primaryWeapon _unit): {[_unit, "", 0, "tsp_animate_inspect_rifle", "tsp_common_stop", false] spawn tsp_fnc_playGesture};
        case (handgunWeapon _unit): {[_unit, "", 0, "tsp_animate_inspect_pistol", "tsp_common_stop", false] spawn tsp_fnc_playGesture};
    };
};

tsp_fnc_animate_door = {
    params ["_unit", ["_open", true]];
    if (!tsp_cba_animate_door) exitWith {};
    _interupt = false;
    if ([_unit] call tsp_fnc_animate_readyCheck != 0) then {_interupt = true};
    if (currentWeapon _unit == "") exitWith {[_unit, "", 0, "tsp_animate_door_close", "", _interupt, true] spawn tsp_fnc_playGesture};  //-- Unnarmed
    [_unit, "", 0, if (_open) then {"tsp_animate_door_gun"} else {"tsp_animate_door_close_gun"}, "", _interupt, true] spawn tsp_fnc_playGesture;  //-- Armed
};

tsp_fnc_animate_nvg = {
    params ["_unit"];
    if (hmd _unit == "") exitWith {};
    _nvgArray = getArray (configFile >> "CfgWeapons" >> (hmd _unit) >> "visionMode");
    if !("NVG" in _nvgArray) exitWith {};
    if (cameraView == "GUNNER" && currentWeapon _unit == binocular _unit) exitWith {};
    if (currentVisionMode _unit == 1) then {
        [_unit, "", 0, "tsp_animate_nightvision_up", "", false] spawn tsp_fnc_playGesture;
    } else {
        [_unit, "", 0, "tsp_animate_nightvision_down", "", false] spawn tsp_fnc_playGesture;
    };
};

tsp_fnc_animate_map = {
    params ["_unit", "_isOpened"];
    
	if (_isOpened) then {
        if (vehicle _unit != _unit) exitWith {};                             //-- Only do map anim if not in vehicle
	    if (stance _unit == "PRONE") exitWith {};                            //-- Only do map anim if not prone
        if (_unit getVariable ["tsp_gestureState", ""] != "") exitWith {};   //-- Only do map anim if not doing another

		[_unit,"tsp_animate_map_in",0.4,"tsp_animate_map_loop","tsp_common_stop_left",true,false,true,false] spawn tsp_fnc_animate_playGesture;  //-- I gest

        if (isNil "tsp_animate_map") then {
            tsp_animate_map = createVehicle ["Land_Map_unfolded_Malden_F", [0,0,0], [], 0, "CAN_COLLIDE"];  //-- Create map
            sleep 0.2;
            if (isNil "tsp_animate_map") exitWith {};  //-- A lot can change in 0.2 seconds
            tsp_animate_map attachto [_unit, [-0.03, 0, -0.03], "leftHand", true];   //-- Position
            _y = 40; _p = 40; _r = 175;                                             //-- Rotation
            tsp_animate_map setVectorDirAndUp [[sin _y * cos _p, cos _y * cos _p, sin _p],[[sin _r, -sin _p, cos _r * cos _p], -_y] call BIS_fnc_rotateVector2D];
        };                      
	} else {
        sleep 0.2;
        if (!isNil "tsp_animate_map") then {deleteVehicle tsp_animate_map; tsp_animate_map = nil};           //-- Delete map object it it exists
        _gest = _unit getVariable ["tsp_gestureState", ""];
        if (_gest == "tsp_animate_map_loop" || _gest == "tsp_animate_map_in") then {  //-- Cancel if doing
            _unit setVariable ["tsp_gestureStop", true];
        };
    };
};

tsp_fnc_animate_walk = {
    params ["_unit", ["_speed", 0]];
    if (!tsp_cba_animate_walk) exitWith {};    
    if (weaponLowered _unit || stance _unit == "PRONE" || !(["mwlk", animationState _unit] call BIS_fnc_inString)) exitWith {  //-- Return to default speed
        if (getAnimSpeedCoef _unit != 1) then {[_unit, 1] remoteExecCall ["setAnimSpeedCoef", _unit]};        
    };
    _unit setVariable ["_speed", ((_unit getVariable ["_speed", 1]) + _speed) min 2 max 0.5];  //-- Update speed var
    if (_unit getVariable "_speed" == getAnimSpeedCoef _unit) exitWith {};                    //-- If speed is same as current speed, exit
    [_unit, (_unit getVariable "_speed")] remoteExecCall ["setAnimSpeedCoef", 0];            //-- Set new speed
};


//-- READY
tsp_fnc_animate_readyCheck = {
    params ["_unit"];
    _readyAnimsAuto = [
        "tsp_animate_highready_rifle_friend", 
        "tsp_animate_lowready_rifle_friend",
        "tsp_animate_ready_pistol_friend", 
        "tsp_animate_highready_rifle_object", 
        "tsp_animate_lowready_rifle_object",
        "tsp_animate_highready_pistol_object",
        "tsp_animate_highready_pistol_friend",
        "tsp_animate_lowready_pistol_friend"
    ];
    _readyAnimsManual = [
        "tsp_animate_highready_rifle_manual", 
        "tsp_animate_lowready_rifle_manual",
        "tsp_animate_highready_pistol_manual",
        "tsp_animate_lowready_pistol_manual"
    ];
    _gest = _unit getVariable ["tsp_gestureState", ""];
    if ((_readyAnimsAuto find _gest) != -1) exitWith {1};
    if ((_readyAnimsManual find _gest) != -1) exitWith {2};
    0
};

tsp_fnc_animate_isViewObstructed = {
    params ["_unit", "_reach", "_angle"];

    _obstruction = objNull;
    _distance = 999;

    //-- Blocked directly
    _startPos = eyePos _unit;
    _endPos = _startPos vectorAdd (vectorDir _unit vectorMultiply _reach);
    _intersections = lineIntersectsSurfaces [_startPos, _endPos, _unit, objNull, true, 1];
    if !(_intersections isEqualTo []) then {        
        if (tsp_cba_animate_dynamicReadyBush && (_intersections#0#2) in (nearestTerrainObjects [_unit, ["Bush"], 10])) exitWith {};
        _obstruction = _intersections#0#2;
        _distance = (_intersections#0#0) distance (getPosASL _unit);
    };

    //-- Block by units in angle
    {
        if (_x != _unit && _x isKindOf "Man") then {
            _eyeHeightDifference = ((eyePos _unit)#2) - ((eyePos _x)#2);
            if (_eyeHeightDifference > 0.3 || _eyeHeightDifference < -0.8) exitWith {};
            if !([position _unit, getDir _unit, _angle, position _x] call BIS_fnc_inAngleSector) exitWith {};
            _obstruction = _x; 
            _distance = _unit distance _x;
        };
    } forEach (_unit nearEntities _reach);

    [_obstruction, _distance]
};

tsp_fnc_animate_canDoReady = {
    params ["_unit"];
    if (stance _unit == "PRONE" || stance _unit == "UNDEFINED") exitWith {false};
    if (vehicle _unit != _unit) exitWith {false};
    if (currentWeapon _unit == "") exitWith {false};
    if (currentWeapon _unit != primaryWeapon _unit && currentWeapon _unit != handgunWeapon _unit) exitWith {false};
    if (weaponLowered _unit) exitWith {false};
    if !(["amov", animationState (call tsp_fnc_playa)] call BIS_fnc_inString || ["aadj", animationState (call tsp_fnc_playa)] call BIS_fnc_inString) exitWith {false};
    true
};

tsp_fnc_animate_ready = {
    params ["_unit", "_type", ["_stance", 0]];

    if !([_unit] call tsp_fnc_animate_canDoReady) exitWith {};

    //-- Decide which animations to use based on type of ready given
    _rifleAnim = [];
    _pistolAnim = [];
    switch (_type) do {
        case "friend": {
            _rifleAnim = [
                ["tsp_animate_highready_rifle_friend", "tsp_animate_lowready_rifle_friend"],   //-- Stand
                ["tsp_animate_highready_rifle_friend", "tsp_animate_highready_rifle_friend"]  //-- Crouch
            ];
            _pistolAnim = [["tsp_animate_highready_pistol_friend", "tsp_animate_lowready_pistol_friend"],["tsp_animate_highready_pistol_friend", "tsp_animate_highready_pistol_friend"]];
        };
        case "object": {
            _rifleAnim = [["tsp_animate_highready_rifle_object", "tsp_animate_lowready_rifle_object"],["tsp_animate_highready_rifle_object", "tsp_animate_highready_rifle_object"]];
            _pistolAnim = [["tsp_animate_highready_pistol_object", "tsp_animate_highready_pistol_object"],["tsp_animate_highready_pistol_object", "tsp_animate_highready_pistol_object"]];
        };
        case "manual": {
            _rifleAnim = [["tsp_animate_highready_rifle_manual", "tsp_animate_lowready_rifle_manual"],["tsp_animate_highready_rifle_manual", "tsp_animate_highready_rifle_manual"]];
            _pistolAnim = [["tsp_animate_highready_pistol_manual", "tsp_animate_lowready_pistol_manual"],["tsp_animate_highready_pistol_manual", "tsp_animate_highready_pistol_manual"]];
        };
    };
    
    //-- Decide which animations to use based on equipped weapon
    _animToUse = [];
    if (currentWeapon _unit == primaryWeapon _unit) then {_animToUse = _rifleAnim};
    if (currentWeapon _unit == handgunWeapon _unit) then {_animToUse = _pistolAnim};

    //-- Decide which animations to use based on unit stance
    if (stance _unit == "STAND") then {_animToUse = _animToUse#0};
    if (stance _unit == "CROUCH") then {_animToUse = _animToUse#1};

    //-- Decide which animation to use based on whether looking up or down
    if ((_unit weaponDirection (currentWeapon _unit))#2 >= tsp_cba_animate_dynamicReadyVertical) then {_animToUse = _animToUse#0} else {_animToUse = _animToUse#1};
    if (_stance == 1) then {_animToUse = _animToUse#0}; if (_stance == -1) then {_animToUse = _animToUse#1};

    //-- Play gesture
    _interupt = false; if ([_unit] call tsp_fnc_animate_readyCheck != 0) then {_interupt = true};  //-- Only interupt other ready gestures
    _stopAnim = "tsp_common_stop";
    if (currentWeapon _unit == handgunWeapon _unit) then {_stopAnim = "tsp_animate_stopReady"};
    [_unit, "", 0, _animToUse, _stopAnim, _interupt] spawn tsp_fnc_playGesture;    
};