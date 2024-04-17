//-- MISCELLANIOUS
	tsp_fnc_distanceFromSurface = {
		params ["_unit"];
		_intersect = lineIntersectsSurfaces [getPosASL _unit, getPos _unit, _unit, objNull, true, 1, "GEOM", "GEOM"];
		if (count _intersect > 0) exitWith {(_intersect#0#0) distance getPosASL _unit};  //-- If line intersects something below unit, return that distance
		getPosATL _unit#2  //-- Else, just give height from ground
	};

	tsp_fnc_isFalling = {
		params ["_unit", "_distance", ["_speed", 10]];
		if (["halofreefall", animationState _unit] call BIS_fnc_inString) exitWith {true};  //-- If doing halo animation, probably falling
		if ([_unit] call tsp_fnc_getHighestVelocity > _speed && [_unit] call tsp_fnc_distanceFromSurface > _distance) exitWith {true};  //-- Or if has downwards velocity and distance from surface
		false  //-- I guess we aren't falling
	};

	tsp_fnc_getHighestVelocity = {
		params ["_unit"];
		_highest = 0;
		{
			_val = _x;
			if (_val < 0) then {_val = _val*-1};  //-- Convert negatives to positive
			if (_val > _highest) then {
				_highest = _val;
			};
		} forEach (velocity _unit);
		_highest
	};

	tsp_fnc_playa = {
		_unit = player;
		if (!isNull getAssignedCuratorLogic _unit) then {  //-- If has zeus
			_unitsBeingControlled = curatorEditableObjects (getAssignedCuratorLogic _unit) select {_x getVariable "bis_fnc_moduleremotecontrol_owner" isEqualTo _unit};
			if (count _unitsBeingControlled == 1) then {_unit = _unitsBeingControlled#0};  //-- If contolling someone
		};
		_unit
	};	

	tsp_fnc_stringReplace = {
		params ["_text", "_orignal", "_replacement"];    
		_return = "";  
		_positionOfOriginal = _text find _orignal;
		while {_positionOfOriginal != -1 && count _text > 0} do {  //-- While there is still an instance of the word
			_return = _return + (_text select [0, _positionOfOriginal]) + _replacement;
			_text = (_text select [_positionOfOriginal + (count _orignal)]);
			_positionOfOriginal = _text find _orignal;
		};
		_return + _text;
	};
	
	tsp_fnc_addMoreDefaultBinds = {
		params ["_bindID", "_originalBind", "_newBind"];
		_currentControl = cba_keybinding_actions getVariable _bindID;
		_currentBinds = _currentControl#2;
		if !(_originalBind in _currentBinds) exitWith {};
		_currentBinds pushBack _newBind;
		_currentControl set [2, _currentBinds];
		cba_keybinding_actions setVariable [_bindID, _currentControl];
	};

	tsp_fnc_addUIEvent = {
		params ["_script", ["_update", false]];
		if (isNil "tsp_uievents") then {tsp_uievents = ""};
		tsp_uievents = tsp_uievents + _script;
		while {sleep 10; _update} do {
			inGameUISetEventHandler ["Action", tsp_uievents]; 
		};
	};

//-- ANIMATIONS
	tsp_fnc_playGesture = {
		params ["_unit", "_in", ["_inTime", 0], ["_loop", ""], ["_out",""], ["_interupt", false], ["_instant", false]];

		if (["stop", _in] call BIS_fnc_inString) exitWith {_unit playActionNow _in};

		if (!_interupt && _unit getVariable ["tsp_gestureState",""] != "") exitWith {};  //-- Do not interupt current gesture/reload
		if (_unit getVariable ["tsp_gestureState",""] == _loop) exitWith {};  //-- Do not repeat same gesture

		//-- Stop any current gesture, wait if necessary for previous gesture to exit cleanly
		if (!_instant && _unit getVariable ["tsp_gestureState",""] != "") then {
			_unit setVariable ["tsp_gestureStop", true];
			waitUntil {_unit getVariable ["tsp_gestureState",""] == ""};
		};

		//-- Play in and actual gesture
		if (_in != "") then {_unit playAction _in; sleep _inTime};
		_unit setVariable ["tsp_gestureStop", false];
		if (_unit getVariable ["tsp_gestureStop", false]) exitWith {};  //-- In case stopped when going in
		if (_loop != "") then {_unit playAction _loop};
		
		//-- Play out gesture
		if (_out != "") then {
			_unit setVariable ["tsp_gestureStop", false];
			waitUntil {_unit getVariable ["tsp_gestureState",""] == _loop && _unit getVariable ["tsp_gestureStop", false]};  //-- Wait until it's time to stop
			_unit setVariable ["tsp_gestureStop", false];
			if (_unit getVariable ["tsp_gestureState",""] != _loop) exitWith {};  //-- If gesture interupted during wait, leave
			_unit playActionNow _out;
		};
	};

	tsp_fnc_gestureState = {
		params ["_unit", "_gesture"];
		_gestureActual = _gesture;
		if (["reload", _gesture] call BIS_fnc_inString) then {_gestureActual = "reload"};
		if (["<none>", _gesture] call BIS_fnc_inString) then {_gestureActual = ""};
		if (["aidl", _gesture] call BIS_fnc_inString) then {_gestureActual = ""};
		if (["amov", _gesture] call BIS_fnc_inString) then {_gestureActual = ""};
		if (["stop", _gesture] call BIS_fnc_inString) then {_gestureActual = ""};
		if (["rcc", _gesture] call BIS_fnc_inString) then {_gestureActual = ""};
		if (["switch", _gesture] call BIS_fnc_inString) then {_gestureActual = "switch"};
		if (_gestureActual != _unit getVariable ["tsp_gestureState",""]) then {_unit setVariable ["tsp_gestureState",_gestureActual]};
	};

	tsp_fnc_weaponGesture = {  //-- Custom hold gesute for weapons
		params ["_unit", "_weapons", "_restAnim", "_cba"];
		_cba params ["_unit", "_new", "_old"];	
		if (_new in _weapons) then {
			waitUntil {_unit getVariable ["tsp_gestureState",""] == ""};
			sleep 2.2;
			while {alive _unit && currentWeapon _unit == _new} do {
				if (_unit getVariable ["tsp_gestureState",""] == "") then {[_unit, "", 0, _restAnim, "tsp_common_stop"] spawn tsp_fnc_playGesture};
				sleep 0.2;
			};
		};
	};

	tsp_fnc_forceCrouch = {
		params ["_unit", "_cond"];
		_unit playAction "PlayerCrouch";
		while _cond do {
			if (stance _unit != "CROUCH") then {_unit playAction "PlayerCrouch"};  
			sleep 1;                    
		};
	};

	tsp_fnc_forceLower = {
		params ["_unit", "_cond"];
		if (!weaponLowered _unit) then {
			_unit action ["WeaponOnBack", _unit];
		};
		//while _cond do {
		//	if (currentWeapon _unit != "" && !weaponLowered _unit) then {  //-- If attempt to raise weapon, lower it
		//		_unit action ["WeaponOnBack", _unit];  //-- Yes... WeaponOnBack does lower the gun
		//		sleep 1;		
		//	};		
		//};
	};

	tsp_fnc_holster = {
		params ["_unit"];
		if (currentWeapon _unit == "") exitWith {};
		_unit action ["SWITCHWEAPON", _unit, _unit, -1];
		sleep 3;
	};

//-- DAMAGE
	tsp_fnc_hasArmor = {
		params ["_item"];
		_cond1 = (getNumber (configFile >> "CfgWeapons" >> _item >> "itemInfo" >> "HitpointsProtectionInfo" >> "Head" >> "armor") > 5);
		_cond2 = (getNumber (configFile >> "CfgWeapons" >> _item >> "itemInfo" >> "HitpointsProtectionInfo" >> "Chest" >> "armor") > 5);
		_cond3 = (getNumber (configFile >> "CfgWeapons" >> _item >> "itemInfo" >> "armor") > 5);
		if (_cond1 || _cond2 || _cond3) exitWith {true};
		false
	};

	tsp_fnc_getHitpoint = {
		params ["_input"];
		_hitPoint = "hitBody";
		_bodypart = "body";
		switch (true) do {  //-- Find ACE bodypart equivelant of memory point
			case (["head", _input, false] call BIS_fnc_inString): {_bodypart = "head"; _hitPoint = "hitHead"};
			case (["neck", _input, false] call BIS_fnc_inString): {_bodypart = "head"; _hitPoint = "hitHead"};
			case (["body", _input, false] call BIS_fnc_inString): {_bodypart = "body"; _hitPoint = "hitBody"};
			case (["spine", _input, false] call BIS_fnc_inString): {_bodypart = "body"; _hitPoint = "hitBody"};
			case (["arm", _input, false] call BIS_fnc_inString): {if (["right", _bodyPart, false] call BIS_fnc_inString) then {_bodypart = "hand_r"} else {_bodypart = "hand_l"}; _hitPoint = "hitHands"};
			case (["leg", _input, false] call BIS_fnc_inString): {if (["right", _bodyPart, false] call BIS_fnc_inString) then {_bodypart = "leg_r"} else {_bodypart = "leg_l"}; _hitPoint = "hitLegs"};
		}; 
		[_hitPoint, _bodypart]
	};

	tsp_fnc_addHitPointDamage = {
		params ["_unit", ["_bodypart", "body"], "_damage", "_damageType", ["_knockout", false], ["_effects", true]];

		if (!isDamageAllowed _unit) exitWith {};

		([_bodypart] call tsp_fnc_getHitpoint) params ["_hitpoint", "_bodypart"];
		
		if (!isNil "ace_medical_fnc_addDamageToUnit" && isNil 'tsp_ace_medical_disabled') then {
			[_unit, _damage, _bodypart, _damageType] remoteExec ["ace_medical_fnc_addDamageToUnit", _unit];  //-- ACE damage		
			if (_knockout) then {[_unit, true, 10, true] call ace_medical_fnc_setUnconscious};              //-- ACE unconscious
		} else {_unit setHitPointDamage [_hitPoint, (_unit getHitPointDamage _hitPoint) + _damage]};       //-- Vanilla damage

		if (isPlayer _unit && _effects) then {  //-- Show hit effect on victim
			[300] call BIS_fnc_bloodEffect;
			[] call BIS_fnc_indicateBleeding;
			[] spawn {
				enableCamShake true;
				addCamShake [10, 2, 25];
				sleep 1;
				enableCamShake false;
			};
		};
	};

	tsp_fnc_blood = {
		params ["_unit", "_pos", "_level", ["_duration", 0.2]];
		
		///-- Select what particles to use
		_particles = [];
		switch (_level) do {
			case 0: {_particles = []};
			case 1: {_particles = ["blood1"]};
			case 2: {_particles = ["blood1","blood2","blood2"]};
		}; 

		//-- GUI effect
		if (isPlayer _unit) then {
			[150 * _level] call BIS_fnc_bloodEffect;
			[] call BIS_fnc_indicateBleeding;
			enableCamShake true;
			addCamShake [5*_level, 1*_level, 12*_level];
		};

		//-- Spray
		_bloodArray = [];
		{
			_blood = "#particlesource" createVehicle (getPos _unit); 
			_blood setParticleClass _x; 
			if (_blood isEqualTo "blood1") then {_blood setDropInterval 0.1} else {_blood setDropInterval 1};
			_blood setPos _pos;
			_blood setParticleRandom [
				0,                  //-- Lifetime
				[0.2, 0.2, 0.2],   //-- Position
				[1, 1, 1],        //-- Velocity
				0,               //-- Rotatiion
				0,              //-- Size
				[0, 0, 0, 0],  //-- Color
				0,            //-- Direction period
				0,           //-- Direction intensity
				360,        //-- Angle
				0          //-- Bounce
			];
			_bloodArray pushBack _blood;
		} forEach _particles;
		uiSleep _duration;
		{deleteVehicle _x} forEach _bloodArray;
	};

	tsp_fnc_preventDrop = {  //-- Remove handguard from container if dropped
		params ["_unit", "_container", "_item", "_blacklist"];
		if (_item in _blacklist) then {		
			_unit removeItems _item;
			_unit addPrimaryWeaponItem _item;
			[_container, _item] call cba_fnc_removeItemCargo;
		};
	};