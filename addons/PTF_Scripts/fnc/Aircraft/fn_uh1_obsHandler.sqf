/*
PTF_fnc_uh1_obsHandler
UH1Y Flir camera handling script

a: reyhard (RHS Original), A.Nilsen (PTF Modifications)
*/
disableSerialization;

uiNameSpace setVariable ["PTF_UH1_ObsCtrl",_this select 0];

/*
gunner
high refresh rate loop [0.1 sec]
*/
[] spawn
{
    private _RHS_TV_ppEffect = [];
    disableSerialization;
    private _p = call rhsusf_fnc_findPlayer;
    private _v = vehicle _p;

    private _c = uiNamespace getVariable "PTF_UH1_ObsCtrl";

    private _z = (_c displayCtrl 180);
    private _d = (_c displayCtrl 151);

    private _zoom=(_c displayCtrl 2);
    private _time=(_c displayCtrl 4);
    private _time2=(_c displayCtrl 41);
    private _gun=(_c displayCtrl 5);
    private _tur=(_c displayCtrl 6);

    private _turPos=[26.29 *   (0.01875 *    Safezoneh),31.8*   (0.025 *    SafezoneH),0.8 *   (0.01875 * SafezoneH),0.8 *   (0.025 * SafezoneH)];
    private _turMid=26.29*   (0.01875 *    Safezoneh);
    private _turMax=-(14 *   (0.01875 *    Safezoneh)) /pi;

    private _gunPos=[10.65 *   (0.01875 *    Safezoneh),10.8*   (0.025 *    SafezoneH),0.8 *   (0.01875 * SafezoneH),0.8 *   (0.025 * SafezoneH)];
    private _gunMid=10.8*   (0.025 *    SafezoneH);
    private _gunMax=-(18.8 *   (0.025 *    SafezoneH)) /2.0944;


    private _gridaA="";
    private _change=true;

    while{not(isNull _d)}do
    {


        /*
            camera mode handler
        */
        if(cameraView == "gunner")then
        {
            private _visionMode        = currentVisionMode _p;
            private _previousMode    = _v getVariable ["rhs_uh1_mode",-1];
            if(_visionMode != _previousMode)then
            {
                _v setVariable ["rhs_uh1_mode",_visionMode,true];
            };
        };


        /*
            time handler
        */
        _min =  daytime mod 1;
        _hour = daytime - _min;

        _sec = (60 * _min) mod 1;
        _msec = (60 * _sec) mod 1;

        _hour = (if (_hour <= 9) then {"0"} else {""}) + str _hour;

        _min = (60 * _min) - ((60 * _min) mod 1);
        _min = (if (_min <= 9) then {"0"} else {""}) + str _min;

        _sec = (60 * _sec) - ((60 * _sec) mod 1);
        _sec = (if (_sec <= 9) then {"0"} else {""}) + str _sec;

        _dayString =format["%1 %2 %3",_hour,_min,_sec];
        _time ctrlSetText _dayString;
        _time2 ctrlSetText _dayString;

        /*
            elevation & horizontal handler
        */
        _turPos set [0,_turMid+(vehicle _p animationPhase "obsTurret")*_turMax];
        _tur ctrlSetPosition _turPos;
        _tur ctrlCommit 0.1;

        _gunPos set [1,_gunMid+(vehicle _p animationPhase "obsGun")*_gunMax];
        _gun ctrlSetPosition _gunPos;
        _gun ctrlCommit 0.1;

        /*
            cam zoom handler - gui part
        */
        _zoomLevel=(parseNumber  (ctrlText _z))*70;

        _zoomLevel=(if (_zoomLevel <= 99) then {"0"} else {""})+ str _zoomLevel;
        _gridA=toArray _zoomLevel;
        _gridaA=toString (call compile (format["[%1,%2,32,%3]",_gridA select 0,_gridA select 1,_gridA select 2]));

        _zoom ctrlSetText _gridaA;


        sleep 0.07;
    };
    uiNameSpace setVariable ["PTF_UH1_ObsCtrl",displayNull];
};

/*
gunner
low refresh rate loop [1 sec]
*/
[] spawn
{
    disableSerialization;
    _p=call rhsusf_fnc_findPlayer;
    _v=vehicle _p;

    _c = uiNamespace getVariable "PTF_UH1_ObsCtrl";

    private _z    = (_c displayCtrl 180);
    private _d    = (_c displayCtrl 151);

    private _range    = (_c displayCtrl 1);
    private _zoom    = (_c displayCtrl 2);
    private _pos    = (_c displayCtrl 3);
    private _pos2    = (_c displayCtrl 31);

    private _grid2            = [];
    private _gridaA            = "";
    private _distance        = "0000";
    private _oldDistance    = "";
    private _oldZoom        = 0;
    rhs_laserReady            = true;

    _range ctrlSetText _distance;

    rhs_key_lase_tgt_GLB    = (profileNamespace getVariable ["rhs_key_lase_tgt","LockTarget"]);
    rhs_key_dmp_lead_GLB    = (profileNamespace getVariable ["rhs_key_dmp_lead","Throw"]);

    while{not(isNull _d)}do
    {
        /*
            lrf distance handler
        */
        if(inputAction rhs_key_lase_tgt_GLB > 0 AND {rhs_laserReady})then{
            _distance=(ctrlText _d);
            if(_distance isEqualTo "")then{
                    _distance="0000";
            };
            [_v,"PTF_UH1_ObsCtrl","CopilotTurret"] spawn rhsusf_fnc_autoTrack;

            _range ctrlSetText _distance;
            rhs_laserReady=false;

            [] spawn
            {
                sleep 2.5;
                rhs_laserReady = true;
            };
        };


        /*
            map grid handler - first one is player pos, second one is laser target pos
        */
        //visible in gunner cam
        _gridA=toArray (mapGridPosition _p);
        _gridaA=toString (call compile (format["[%1,32,%2,32,%3,32,32,%4,32,%5,32,%6]",_gridA select 0,_gridA select 1,_gridA select 2,_gridA select 3,_gridA select 4,_gridA select 5]));
        _pos ctrlSetText _gridaA;

        //laser part
        if(isNull (laserTarget vehicle _p))then{
            _pos2 ctrlSetText "0 0 0  0 0 0";
            _grid2="000000";
        }else{
            _grid2=(mapGridPosition (laserTarget vehicle _p));
            _gridA=toArray _grid2;
            _gridaA=toString (call compile (format["[%1,32,%2,32,%3,32,32,%4,32,%5,32,%6]",_gridA select 0,_gridA select 1,_gridA select 2,_gridA select 3,_gridA select 4,_gridA select 5]));
            _pos2 ctrlSetText _gridaA;
        };

        /*
            cam zoom handler - gui part
        */
        //visible in gunner cam
        _zoomLevel=(parseNumber (ctrlText _z))*70;

        /*
            zoom is refreshed at low rate to avoid excessive mp traffic + data is transfered only in case of change
        */

        if(_oldDistance != _distance)then{_v setVariable ["rhs_uh1_range",_distance,true];_oldDistance=_distance;};
        if(_oldZoom != _zoomLevel)then{_v setVariable ["rhs_uh1_zoom",_zoomLevel,true];_oldZoom=_zoomLevel;};

        sleep 1;
    };
    rhs_trackActive=false;
};
