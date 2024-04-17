//-- ACE ACTIONS
#include "\a3\editor_f\Data\Scripts\dikCodes.h";
_gestureActions = [
    //-- Gestures
    [
        "Bird","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa),"tsp_animate_bird_in",0.4,"tsp_animate_bird_loop","tsp_common_stop_right",true,false,true,false] spawn tsp_fnc_animate_playGesture}
    ],[
        "Ok","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa),"tsp_animate_ok_in",0.4,"tsp_animate_ok_loop","tsp_common_stop_right",true,false,true,false] spawn tsp_fnc_animate_playGesture}
    ],[
        "Jackoff","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa),"",0,"tsp_animate_jackoff_loop","tsp_animate_jackoff_out",true,false,true,false] spawn tsp_fnc_animate_playGesture}
    ],[
        "Mahalo","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa),"",0,"tsp_animate_mahalo_loop","tsp_common_stop_right",true,false,true,false] spawn tsp_fnc_animate_playGesture}
    ],[
        "Horns","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa),"",0,"tsp_animate_horns_loop","tsp_common_stop_left",true,false,true,false] spawn tsp_fnc_animate_playGesture}
    ],[
        "Peace","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa),"",0,"tsp_animate_peace_loop","tsp_common_stop_left",true,false,true,false] spawn tsp_fnc_animate_playGesture}
    ],[
        "Dab","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa),"",0,"tsp_animate_dab_loop","tsp_common_stop",true,false,false,true] spawn tsp_fnc_animate_playGesture}
    ],[
        "Rock","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) in ["","tsp_animate_rockpaperscissors_paper_loop","tsp_animate_rockpaperscissors_scissors_loop","tsp_animate_rockpaperscissors_rock_loop"]},
        {
            if ((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""] in ["tsp_animate_rockpaperscissors_paper_loop","tsp_animate_rockpaperscissors_scissors_loop","tsp_animate_rockpaperscissors_rock_loop"]) then {(call tsp_fnc_playa) setVariable ["tsp_gestureState", ""]};
            [(call tsp_fnc_playa),"tsp_animate_rockpaperscissors_in",1,"tsp_animate_rockpaperscissors_rock_loop","tsp_common_stop",true,true,false,true] spawn tsp_fnc_animate_playGesture;
        }
    ],[
        "Paper","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) in ["","tsp_animate_rockpaperscissors_paper_loop","tsp_animate_rockpaperscissors_scissors_loop","tsp_animate_rockpaperscissors_rock_loop"]},
        {
            if ((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""] in ["tsp_animate_rockpaperscissors_paper_loop","tsp_animate_rockpaperscissors_scissors_loop","tsp_animate_rockpaperscissors_rock_loop"]) then {(call tsp_fnc_playa) setVariable ["tsp_gestureState", ""]};
            [(call tsp_fnc_playa),"tsp_animate_rockpaperscissors_in",1,"tsp_animate_rockpaperscissors_paper_loop","tsp_common_stop",true,true,false,true] spawn tsp_fnc_animate_playGesture;
        }
    ],[
        "Scissors","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) in ["","tsp_animate_rockpaperscissors_paper_loop","tsp_animate_rockpaperscissors_scissors_loop","tsp_animate_rockpaperscissors_rock_loop"]},
        {
            if ((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""] in ["tsp_animate_rockpaperscissors_paper_loop","tsp_animate_rockpaperscissors_scissors_loop","tsp_animate_rockpaperscissors_rock_loop"]) then {(call tsp_fnc_playa) setVariable ["tsp_gestureState", ""]};
            [(call tsp_fnc_playa),"tsp_animate_rockpaperscissors_in",1,"tsp_animate_rockpaperscissors_scissors_loop","tsp_common_stop",true,true,false,true] spawn tsp_fnc_animate_playGesture;
        }
    ],[
        "Inspect Weapon","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_emotes"],
        {(currentWeapon (call tsp_fnc_playa) != "" && (currentWeapon (call tsp_fnc_playa) == primaryWeapon (call tsp_fnc_playa) || currentWeapon (call tsp_fnc_playa) == handgunWeapon (call tsp_fnc_playa))) && ((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa)] call tsp_fnc_animate_inspect}
    ],[
        "Suicide","tsp_animate\gui\suicide.paa",["ACE_SelfActions", "ACE_Animations"],
        {(currentWeapon (call tsp_fnc_playa) != "" && (currentWeapon (call tsp_fnc_playa) == primaryWeapon (call tsp_fnc_playa) || currentWeapon (call tsp_fnc_playa) == handgunWeapon (call tsp_fnc_playa))) && ((call tsp_fnc_playa) getVariable ["tsp_gestureState", ""]) == ""},
        {[(call tsp_fnc_playa)] spawn tsp_fnc_animate_suicide}
    ],

    //-- Animations
    ["Duo (Ivan)","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "a2_duoivan"] spawn tsp_fnc_animate_playDance}],
    ["Duo (Stefan)","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "a2_duostefan"] spawn tsp_fnc_animate_playDance}],
    ["Stefan","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "a2_stefan"] spawn tsp_fnc_animate_playDance}],
    ["ZOZO","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "a2_zozo"] spawn tsp_fnc_animate_playDance}],
    ["Metal","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "a2_metal"] spawn tsp_fnc_animate_playDance}],

    ["Contact Dance 1","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "Acts_Dance_01"] spawn tsp_fnc_animate_playDance}],
    ["Contact Dance 2","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "Acts_Dance_02"] spawn tsp_fnc_animate_playDance}],

    ["Kata","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "AmovPercMstpSnonWnonDnon_exerciseKata"] remoteExec ["playMove", 0]}],
    ["Pushups","",["ACE_SelfActions", "ACE_Animations","tsp_ace_animate_dances"],{true},{[(call tsp_fnc_playa), "AmovPercMstpSnonWnonDnon_exercisePushUp"] remoteExec ["playMove", 0]}]
];

{
    _x params ["_name", "_img", "_category", "_condition", "_code"];
    
    [  //-- CBA setting
        "tsp_cba_animate_"+_name, "CHECKBOX",
        [_name, "Enable/disable this animation."],
        ["TSP Animate", "Animations"], true, true, {}
    ] call CBA_Settings_fnc_init;

    if (missionNameSpace getVariable ["tsp_cba_animate_"+_name, false]) then {  //-- If enabled in CBA
        if !(isNil "ace_interact_menu_fnc_createAction") then {  //-- Add ACE interaction
            _action = [_name, _name, _img, _code, _condition] call ace_interact_menu_fnc_createAction;
            ["CAManBase", 1, _category, _action, true] call ace_interact_menu_fnc_addActionToClass;
        };
        
        //-- Add CBA control
        missionNameSpace setVariable [("tsp_animate_condition_" + _name), _condition];
        [
            "TSP Animate", 
            "tsp_animate_" + _name, 
            _name, 
            compile ("if (call (missionNameSpace getVariable ['tsp_animate_condition_" + _name + "',true])) then " + str _code),
            {}, 
            [-1, [false, false, false]]
        ] call CBA_fnc_addKeybind;
    };
} forEach _gestureActions;

ace_gestures_showOnInteractionMenu = 1;  //-- REMOVE ACE GESTURES

//-- READY
[] spawn {
    waitUntil {time > 1};
    (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {  //-- Mouse button to cancel ready quickly
        if ((_this#1) != 0 && (_this#1) != 1) exitWith {};        //-- Only mouse 1 and 2
        if ([call tsp_fnc_playa] call tsp_fnc_animate_readyCheck != 2) exitWith {};  //-- 0 No, 1 Auto, 2 Manual
        (call tsp_fnc_playa) setVariable ["tsp_gestureStop", true];
    }];
    while {tsp_cba_animate_dynamicReadyPoll > 0} do {  //-- Polling
        call {
            _obstructionData = [call tsp_fnc_playa, 3, tsp_cba_animate_dynamicReadyFriendAngle] call tsp_fnc_animate_isViewObstructed;
            _obstructionData params ["_obstruction", "_distance"];
            _isFriend = (_obstruction isKindOf "Man" && side _obstruction == side (call tsp_fnc_playa));
            _obstructedByFriend = (_distance < tsp_cba_animate_dynamicReadyFriend && _isFriend);
            _obstructedByObject = (
                _distance < (tsp_cba_animate_dynamicReadyObject + (getNumber (configFile >> "CfgWeapons" >> (currentWeapon (call tsp_fnc_playa)) >> "inertia")/2)) && 
                (!_isFriend || tsp_cba_animate_friendsAreObjects)
            );
            _readyState = [call tsp_fnc_playa] call tsp_fnc_animate_readyCheck;  //-- 0 No, 1 Auto, 2 Manual

            if (!([call tsp_fnc_playa] call tsp_fnc_animate_canDoReady) && _readyState != 0) exitWith {(call tsp_fnc_playa) setVariable ["tsp_gestureStop", true]; sleep 0.5};  //-- Stop if you cant do it
            if (_readyState == 2) exitWith {};  //-- If manual, exit
            if (_obstructedByFriend) exitWith {[call tsp_fnc_playa, "friend"] call tsp_fnc_animate_ready};
            if (_obstructedByObject) exitWith {[call tsp_fnc_playa, "object"] call tsp_fnc_animate_ready};
            if (!_obstructedByFriend && !_obstructedByObject && _readyState == 1) exitWith {(call tsp_fnc_playa) setVariable ["tsp_gestureStop", true]; sleep 0.5};  //-- Stop if not obstructed and doing auto
        };
        sleep tsp_cba_animate_dynamicReadyPoll;
    };
};

//-- NIGHTVISION
[] spawn {  //-- Input eventHandlers requires a wait
    waitUntil {time > 1};    
    (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["_displayorcontrol", "_key", "_shift", "_ctrl", "_alt"];       
        if (_key in (actionKeys "nightVision") && tsp_cba_animate_nvg) then {[call tsp_fnc_playa] call tsp_fnc_animate_nvg};
        false
    }];    
};

//-- DOOR
["
    if (['door', _this#4] call BIS_fnc_inString) then {
        [call tsp_fnc_playa, if (['close', _this#4] call BIS_fnc_inString) then {false} else {true}] call tsp_fnc_animate_door;
    };
"] spawn tsp_fnc_addUIEvent;

//-- MAP
addMissionEventHandler ["Map", {
	params ["_isOpened","_isForced"];
    if (!tsp_cba_animate_map) exitWith {};
    [call tsp_fnc_playa, _isOpened] spawn tsp_fnc_animate_map;
}];

//-- WALK SPEED
player addEventHandler ["AnimStateChanged", { 
    params ["_unit", "_anim"]; 
    if (!tsp_cba_animate_walk) then {};
    [_unit] call tsp_fnc_animate_walk;
}];