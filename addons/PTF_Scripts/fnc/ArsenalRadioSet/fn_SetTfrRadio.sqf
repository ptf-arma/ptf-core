["ace_arsenal_displayClosed",{

if (is3DEN == true) exitwith {};

if ((call compile PTF_TFARSR) != 0) then {
 [(call TFAR_fnc_activeSwRadio), 1, (PTF_TFARSR)] call TFAR_fnc_setChannelFrequency;
};

if ((call compile PTF_TFARSRALT) != 0) then {
[(call TFAR_fnc_activeSwRadio), 2, (PTF_TFARSRALT)] call TFAR_fnc_setChannelFrequency;
 [(call TFAR_fnc_activeSwRadio), 1] call TFAR_fnc_setAdditionalSwChannel;
};


if (isNil {call TFAR_fnc_activeLrRadio}) exitwith {};

if ((call compile PTF_TFARLR) != 0) then {
[(call TFAR_fnc_activeLrRadio), 1, (PTF_TFARLR)] call TFAR_fnc_setChannelFrequency;
};

if ((call compile PTF_TFARLRALT) != 0) then {
[(call TFAR_fnc_activeLrRadio), 2, (PTF_TFARSRALT)] call TFAR_fnc_setChannelFrequency;
[call TFAR_fnc_activeLrRadio, 1] call TFAR_fnc_setAdditionalLrChannel;
};

}] call CBA_fnc_addEventHandler;


