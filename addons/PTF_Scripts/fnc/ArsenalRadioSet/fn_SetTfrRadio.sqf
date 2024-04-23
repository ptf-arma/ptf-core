["ace_arsenal_displayClosed",{

if (PTF_TFARSR != 0) then {
 [(call TFAR_fnc_activeSwRadio), 1, PTF_TFARSR] call TFAR_fnc_setChannelFrequency;
};

if (PTF_TFARSRALT != 0) then {
[(call TFAR_fnc_activeSwRadio), 2, PTF_TFARSRALT] call TFAR_fnc_setChannelFrequency;
 [(call TFAR_fnc_activeSwRadio), 2] call TFAR_fnc_setAdditionalSwChannel;
};


if (PTF_TFARLR != 0) then {
[(call TFAR_fnc_activeLrRadio), 1, PTF_TFARLR] call TFAR_fnc_setChannelFrequency;
};

if (PTF_TFARLRALT != 0) then {
[(call TFAR_fnc_activeLrRadio), 2, PTF_TFARSRALT] call TFAR_fnc_setChannelFrequency;
[call TFAR_fnc_activeLrRadio, 2] call TFAR_fnc_setAdditionalLrChannel;
};

}] call CBA_fnc_addEventHandler;


