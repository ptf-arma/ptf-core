for "_i" from 1 to (PTF_LRChannels) do {  
   
 [(call TFAR_fnc_activeLrRadio), _i, (missionNamespace getVariable ("PTF_TFARLR" + str _i))] call TFAR_fnc_setChannelFrequency;
};

[call TFAR_fnc_activeLrRadio, PTF_TFARLRALT - 1] call TFAR_fnc_setAdditionalLrChannel;


[[["TFAR_selfinteraction_LRradio_TFAR_anprc155_coyote","AN/PRC-155 Coyote","\z\tfar\addons\backpacks\anprc155\ui\155_icon.paa",{
TF_lr_dialog_radio = (_this select 2) select 1;
call TFAR_fnc_onLrDialogOpen;
},{true},{(_this select 2) call tfar_core_fnc_getStereoChildren},[B Alpha 1-1:1 (Jacob),[26536e1a110# 1779921: clf_nicecomm2.p3d,"radio_settings"]],{[0, 0, 0]},2,[false,false,false,false,false],{}],[],B Alpha 1-1:1 (Jacob)],[["TFAR_selfinteraction_SRradio_TFAR_anprc152_1","AN/PRC-152 1","\z\tfar\addons\handhelds\anprc152\ui\152_icon.paa",{
TF_sw_dialog_radio = (_this select 2) select 1;
call TFAR_fnc_onSwDialogOpen;
},{true},{(_this select 2) call tfar_core_fnc_getStereoChildren},[B Alpha 1-1:1 (Jacob),"TFAR_anprc152_1"],{[0, 0, 0]},2,[false,false,false,false,false],{}],[],B Alpha 1-1:1 (Jacob)],[["TFAR_LowerHeadset","Lower Headset","\a3\ui_f\data\igui\cfg\actions\arrow_down_gs.paa",{true call TFAR_fnc_setHeadsetLowered;},{(!(missionNamespace getVariable ['TFAR_core_isHeadsetLowered',false])) && {call TFAR_fnc_haveSWRadio || call TFAR_fnc_haveLRRadio}},{},[],{[0, 0, 0]},2,[false,false,false,false,false],{}],[],B Alpha 1-1:1 (Jacob)],[["TFAR_RaiseHeadset","Raise Headset","\a3\ui_f\data\igui\cfg\actions\arrow_up_gs.paa",{false call TFAR_fnc_setHeadsetLowered;},{(missionNamespace getVariable ['TFAR_core_isHeadsetLowered',false]) && {call TFAR_fnc_haveSWRadio || call TFAR_fnc_haveLRRadio}},{},[],{[0, 0, 0]},2,[false,false,false,false,false],{}],[],B Alpha 1-1:1 (Jacob)]]