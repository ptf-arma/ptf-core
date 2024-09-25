for "_i" from 1 to (PTF_SRChannels) do { 
  
 [(call TFAR_fnc_activeSwRadio), _i, (missionNamespace getVariable ("PTF_TFARSR" + str _i))] call TFAR_fnc_setChannelFrequency; 
};

[(call TFAR_fnc_activeSwRadio), PTF_TFARSRALT - 1] call TFAR_fnc_setAdditionalSwChannel;