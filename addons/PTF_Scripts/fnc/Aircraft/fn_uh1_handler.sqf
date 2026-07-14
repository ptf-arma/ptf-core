/*
PTF_fnc_uh1_handler
UH1Y Flir camera handling script
handles monitor stuff

a: reyhard (RHS Original), A.Nilsen (PTF Modifications)
*/
disableSerialization;

uiNameSpace setVariable ["PTF_UH1_Ctrl",_this select 0];



/*
heli
low refresh rate loop [1 sec]
*/

[] spawn
{
    sleep 0.1;

    private["_c","_w","_p","_v","_old","_n","_mode","_min","_hour","_sec","_dayString","_nm","_textureList","_grid2","_gridaA","_oldZoom","_ehID","_distance","_grid","_zoomLevel","_texCache"];
    disableSerialization;
    _c = uiNamespace getVariable "PTF_UH1_Ctrl";
    _w = (_c displayCtrl 120);

    _grid2=[];
    _gridaA="";
    _oldZoom=1.05;

    // Per-slot cache of last applied texture so setObjectTexture only fires on change
    _texCache = [];  // slot(index) -> last applied texture; param/set are pre-2.02 safe

    _p = call rhsusf_fnc_findPlayer;
    _v = vehicle _p;

    /*
        core r2t handling
    */
    rhs_uh1Flir=_v;
    //rhs_zoom_param=40;
    rhs_uh1_cam = "camera" camCreate [0,0,0];
    rhs_uh1_cam cameraEffect ["Internal", "Back", "rendertarget0"];

    rhs_uh1_cam attachTo [rhs_uh1Flir, [0,0,0], "gun_begin"];
    rhs_uh1_cam camSetFov (0.7/_oldZoom);

    _ehID = addMissionEventHandler ["Draw3D", {
        if(isNil "rhs_uh1_cam")exitWith{};
        _dir =
            (rhs_uh1Flir selectionPosition "gun_begin")
                vectorFromTo
            (rhs_uh1Flir selectionPosition "gun_end");
        rhs_uh1_cam setVectorDirAndUp [
            _dir,
            _dir vectorCrossProduct [-(_dir select 1), _dir select 0, 0]
        ];
    }];

    while{not(isNull _w)}do
    {
        _textureList=[];
        /*
            pip camera zoom - as zoom data is synced max at each seconds, there is small transition applied there
        */
        _n=(_v getVariable ["rhs_uh1_zoom",42])/21;
        if(_oldZoom != _n)then
        {
            [_n,_oldZoom] spawn
            {
                private["_n","_i","_s"];

                _n = floor (_this select 0);
                _i = floor (_this select 1);

                _s=1;
                if(_n<_i)then{_s=-1};

                while{_i != _n}do
                {
                    _i=_i+1*_s;
                    rhs_uh1_cam camSetFov (0.7/(_i+0.01));
                    sleep 0.01;
                };
            };
            _oldZoom=_n;
        };

        /*
            lrf distance handler
        */
        _distance= _v getVariable ["rhs_uh1_range","0000"];
        for "_i" from 0 to 3 do
        {
            _nm=_distance select [_i,1];
            _textureList pushBack [_i+2,format["rhsusf\addons\rhsusf_optics\data\tex\digi_num_%1.paa",_nm]];
        };


        /*
            map grid handler - first one is player pos, second one is laser target pos
        */
        //visible in internal cam
        _grid=(mapGridPosition _p);
        _grid2=(mapGridPosition (laserTarget vehicle _p));
        if(_grid2 == "")then{_grid2="000000"};
        for "_i" from 0 to 5 do
        {
            _nm=_grid select [_i,1];
            _textureList pushBack [_i+12,format["rhsusf\addons\rhsusf_optics\data\tex\digi_num_%1.paa",_nm]];
        };

        for "_i" from 0 to 5 do
        {
            _nm=_grid2 select [_i,1];
            _textureList pushBack [_i+18,format["rhsusf\addons\rhsusf_optics\data\tex\digi_num_%1.paa",_nm]];
        };

        /*
            cam zoom handler
        */
        //visible in internal cam
        _zoomLevel= _v getVariable ["rhs_uh1_zoom",42];
        _zoomLevel=(if (_zoomLevel <= 99) then {"0"} else {""})+ str _zoomLevel;
        for "_i" from 0 to 2 do
        {
            _nm=_zoomLevel select [_i,1];
            _textureList pushBack [_i+24,format["rhsusf\addons\rhsusf_optics\data\tex\digi_num_%1.paa",_nm]];
        };

        {
            _x params ["_slot","_tex"];
            if((_texCache param [_slot,""]) isNotEqualTo _tex)then
            {
                rhs_uh1Flir setObjectTexture _x;
                _texCache set [_slot,_tex];
            };
        }foreach _textureList;

        sleep 1;
    };

    uiNameSpace setVariable ["PTF_UH1_Ctrl",displayNull];
    removeMissionEventHandler ["Draw3D",_ehID];
    rhs_uh1_cam cameraeffect ["terminate","back"];
    camDestroy rhs_uh1_cam;
    rhs_uh1_cam = nil;
    rhs_uh1_flir = nil;
};



/*
heli
high refresh rate loop [0.1 sec]
*/
[] spawn
{
    sleep 0.2;

    private["_c","_w","_p","_v","_old","_n","_mode","_min","_hour","_sec","_dayString","_nm","_textureList","_texCache"];

    disableSerialization;
    _c = uiNamespace getVariable "PTF_UH1_Ctrl";
    _w = (_c displayCtrl 120);

    _p = call rhsusf_fnc_findPlayer;
    _v = vehicle _p;

    _old=-2;

    // Per-slot cache of last applied texture so setObjectTexture only fires on change
    _texCache = [];  // slot(index) -> last applied texture; param/set are pre-2.02 safe

    while{not(isNull _w)}do
    {


        /*
            camera mode handler
        */
        _mode=_v getVariable ["rhs_uh1_mode",0];
        if(_mode != _old)then
        {
            rhs_uh1_cam cameraeffect ["terminate","back"];
            rhs_uh1_cam cameraEffect ["internal", "Back", "rendertarget0"];
            "rendertarget0" setPiPEffect [_mode];
            _old=_mode;
        };


        _textureList=[];
        /*
            time handler
        */

        _dayString = call PTF_fnc_formatDaytime;
        for "_i" from 0 to 5 do
        {
            _nm=_dayString select [_i,1];
            _textureList pushBack [_i+6,format["rhsusf\addons\rhsusf_optics\data\tex\digi_num_%1.paa",_nm]];
        };


        {
            _x params ["_slot","_tex"];
            if((_texCache param [_slot,""]) isNotEqualTo _tex)then
            {
                rhs_uh1Flir setObjectTexture _x;
                _texCache set [_slot,_tex];
            };
        }foreach _textureList;


        sleep 0.1;

        //diag_log format["%1",_textureList];
    };

};
