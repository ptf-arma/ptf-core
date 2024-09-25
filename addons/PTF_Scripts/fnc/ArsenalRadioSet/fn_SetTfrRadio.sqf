if (PTF_ArsenelExit == true) exitwith {

["ace_arsenal_displayClosed",{

if (is3DEN == true) exitwith {};

call PTF_fnc_SRset;

if (isNil {call TFAR_fnc_activeLrRadio}) exitwith {};

call PTF_fnc_LRset;

}] call CBA_fnc_addEventHandler;
};




