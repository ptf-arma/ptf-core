//-- CONTROLS
    #include "\a3\editor_f\Data\Scripts\dikCodes.h";
    disableSerialization;
    [
        "TSP Animate",
        "tsp_animate_stopKey", 
        "Stop Gesture",
        {[call tsp_fnc_playa] call tsp_fnc_animate_stop},
        {}, 
        [DIK_SPACE, [false, false, false]]
    ] call CBA_fnc_addKeybind;
    [
        "TSP Animate", 
        "tsp_animate_readyKey", 
        "Ready", 
        {
            if ([call tsp_fnc_playa] call tsp_fnc_animate_readyCheck == 2) exitWith {(call tsp_fnc_playa) setVariable ["tsp_gestureStop", true]};  //-- If doing manual ready already, stop
            if ([call tsp_fnc_playa] call tsp_fnc_animate_canDoReady) then {[call tsp_fnc_playa, "manual"] call tsp_fnc_animate_ready};           //-- Do ready
        },
        {},
        [DIK_T, [false, false, false]]
    ] call CBA_fnc_addKeybind;
    ["TSP Animate","tsp_animate_walkUp", "Increase Walking Speed", {[player, 0.1] call tsp_fnc_animate_walk}, "", [0xF8, [false, true, false]]] call CBA_fnc_addKeybind;
    ["TSP Animate","tsp_animate_walkDown", "Decrease Walking Speed", {[player, -0.1] call tsp_fnc_animate_walk}, "", [0xF9, [false, true, false]]] call CBA_fnc_addKeybind;

//-- SETTINGS
    [  //-- Night vision animation
        "tsp_cba_animate_nvg", "CHECKBOX",
        ["Night Vision Animation", "Enable/disable animation when toggling night vision goggles."],
        "TSP Animate", true, true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Door opening animation
        "tsp_cba_animate_door", "CHECKBOX",
        ["Door Opening Animation", "Enable/disable animation when opening doors."],
        "TSP Animate", true, true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Map opening animation
        "tsp_cba_animate_map", "CHECKBOX",
        ["Map Animation", "Enable/disable animation when opening map."],
        "TSP Animate", true, true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Adjustable Walk Speed
        "tsp_cba_animate_walk", "CHECKBOX",
        ["Adjustable Walk Speed", "Enable/disable ability to change slow walking speed."],
        "TSP Animate", false, true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Dynamic ready
	    "tsp_cba_animate_dynamicReadyPoll", "SLIDER",
        ["Dynamic Ready Polling Rate", "How often the script checks for obstructions, a value of 0 will disable dynamic ready."],
        ["TSP Animate", "Dynamic Ready"], [0, 5, 0.25], false, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Bush
        "tsp_cba_animate_dynamicReadyBush", "CHECKBOX",
        ["Ignore Bushes", "Enable/disable ignoring bushes with dynamic ready (Could cost performance)."],
        ["TSP Animate", "Dynamic Ready"], true, true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Friends are Objects
        "tsp_cba_animate_friendsAreObjects", "CHECKBOX",
        ["Friends are Objects", "Whether or not friendly units are considered in object distance (Only use if Friend Distance is higher than Object Distance)."],
        ["TSP Animate", "Dynamic Ready"], false, true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Object distance
	    "tsp_cba_animate_dynamicReadyObject", "SLIDER",
        ["Dynamic Ready Distance (Object)", "How close you have to be to an object."],
        ["TSP Animate", "Dynamic Ready"], [0, 5, 2], true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Friend distance
	    "tsp_cba_animate_dynamicReadyFriend", "SLIDER",
        ["Dynamic Ready Distance (Friend)", "How close you have to be to a friendly unit."],
        ["TSP Animate", "Dynamic Ready"], [0, 5, 3], true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Friend angle
	    "tsp_cba_animate_dynamicReadyFriendAngle", "SLIDER",
        ["Dynamic Ready Angle (Friend)", "Angle sector to detect friendly units."],
        ["TSP Animate", "Dynamic Ready"], [0, 180, 35], true, {}
    ] call CBA_Settings_fnc_init;

    [  //-- Object distance
	    "tsp_cba_animate_dynamicReadyVertical", "SLIDER",
        ["Dynamic Ready High/Low Angle", "At what vertical weapon direction should high or low ready be selected."],
        ["TSP Animate", "Dynamic Ready"], [-1, 1, -0.1], false, {}
    ] call CBA_Settings_fnc_init;