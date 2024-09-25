for "_i" from 1 to (PTF_LRChannels) do {  
   
 [(call TFAR_fnc_activeLrRadio), _i, (missionNamespace getVariable ("PTF_TFARLR" + str _i))] call TFAR_fnc_setChannelFrequency;
};

[call TFAR_fnc_activeLrRadio, PTF_TFARLRALT - 1] call TFAR_fnc_setAdditionalLrChannel;