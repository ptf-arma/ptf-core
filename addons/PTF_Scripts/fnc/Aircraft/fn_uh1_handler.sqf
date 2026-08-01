/*
PTF_fnc_uh1_handler
UH1Y Flir camera handling script
handles monitor stuff

a: reyhard (RHS Original), A.Nilsen (PTF Modifications)
*/
disableSerialization;

uiNameSpace setVariable ["PTF_UH1_Ctrl",_this select 0];

// Each display gets its own session id. An older spawn can still be sitting in its 1 second
// sleep when the display is re-created (mode switch, respawn into another UH1Y) - the checks
// below make sure only the newest session ever touches the shared globals
private _session = (uiNamespace getVariable ["PTF_UH1_Session",0]) + 1;
uiNamespace setVariable ["PTF_UH1_Session",_session];



/*
heli
low refresh rate loop [1 sec]
*/

[_session] spawn
{
    params["_session"];
    sleep 0.1;

    private["_c","_w","_p","_v","_old","_n","_mode","_min","_hour","_sec","_dayString","_nm","_textureList","_grid2","_gridaA","_oldZoom","_ehID","_distance","_grid","_zoomLevel","_texCache"];
    disableSerialization;

    // A newer display claimed the session while we slept - everything below creates or
    // destroys shared state, so do not run at all
    if((uiNamespace getVariable ["PTF_UH1_Session",0]) isNotEqualTo _session)exitWith{};

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
    PTF_uh1Flir=_v;
    // Shared singleton across every UH1Y - if the display is re-created before the
    // loop below exits we would orphan the old render to texture camera
    if(!isNil "PTF_uh1_cam")then
    {
        PTF_uh1_cam cameraeffect ["terminate","back"];
        camDestroy PTF_uh1_cam;
    };
    PTF_uh1_cam = "camera" camCreate [0,0,0];
    PTF_uh1_cam cameraEffect ["Internal", "Back", "rendertarget0"];

    PTF_uh1_cam attachTo [PTF_uh1Flir, [0,0,0], "gun_begin"];
    PTF_uh1_cam camSetFov (0.7/_oldZoom);

    // A previous session's handler is only ever removed by its owner, and that owner now
    // skips its cleanup - so take the slot down here before claiming it
    private _oldEH = uiNamespace getVariable ["PTF_UH1_DrawEH",-1];
    if(_oldEH >= 0)then{removeMissionEventHandler ["Draw3D",_oldEH]};

    _ehID = addMissionEventHandler ["Draw3D", {
        // Self removal - the loop below only unhooks this if it exits cleanly, and this
        // runs every frame. Id is shared through uiNamespace so it is only removed once
        if(isNil "PTF_uh1_cam" || {isNil "PTF_uh1Flir"} || {isNull (uiNamespace getVariable ["PTF_UH1_Ctrl",displayNull])})exitWith
        {
            private _drawEH = uiNamespace getVariable ["PTF_UH1_DrawEH",-1];
            if(_drawEH >= 0)then
            {
                removeMissionEventHandler ["Draw3D",_drawEH];
                uiNamespace setVariable ["PTF_UH1_DrawEH",-1];
            };
        };
        private _dir =
            (PTF_uh1Flir selectionPosition "gun_begin")
                vectorFromTo
            (PTF_uh1Flir selectionPosition "gun_end");
        PTF_uh1_cam setVectorDirAndUp [
            _dir,
            _dir vectorCrossProduct [-(_dir select 1), _dir select 0, 0]
        ];
    }];
    uiNamespace setVariable ["PTF_UH1_DrawEH",_ehID];

    // Drop out as soon as a newer display takes over so two loops never drive the same globals
    while{not(isNull _w) && {(uiNamespace getVariable ["PTF_UH1_Session",0]) isEqualTo _session}}do
    {
        _textureList=[];
        /*
            pip camera zoom - as zoom data is synced max at each seconds, there is small transition applied there
        */
        _n=(_v getVariable ["PTF_uh1_zoom",42])/21;
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
                    PTF_uh1_cam camSetFov (0.7/(_i+0.01));
                    sleep 0.01;
                };
            };
            _oldZoom=_n;
        };

        /*
            lrf distance handler
        */
        _distance= _v getVariable ["PTF_uh1_range","0000"];
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
        _zoomLevel= str (_v getVariable ["PTF_uh1_zoom",42]);
        // Always pad to 3 chars - a single digit zoom left index 2 empty, which asked
        // for a digi_num_.paa that does not exist on every pass
        while{count (toArray _zoomLevel) < 3}do{_zoomLevel="0"+_zoomLevel};
        for "_i" from 0 to 2 do
        {
            _nm=_zoomLevel select [_i,1];
            _textureList pushBack [_i+24,format["rhsusf\addons\rhsusf_optics\data\tex\digi_num_%1.paa",_nm]];
        };

        {
            _x params ["_slot","_tex"];
            if((_texCache param [_slot,""]) isNotEqualTo _tex)then
            {
                PTF_uh1Flir setObjectTexture _x;
                _texCache set [_slot,_tex];
            };
        }foreach _textureList;

        sleep 1;
    };

    // Only the session that still owns the display may tear the shared state down - a newer
    // display would otherwise lose its control handle, camera and Draw3D handler
    if((uiNamespace getVariable ["PTF_UH1_Session",0]) isEqualTo _session)then
    {
        uiNameSpace setVariable ["PTF_UH1_Ctrl",displayNull];
        // Only remove our own handler - it may already have taken itself down, and mission
        // event handler ids are reused, so a blind remove could kill somebody else's
        if((uiNamespace getVariable ["PTF_UH1_DrawEH",-1]) isEqualTo _ehID)then
        {
            removeMissionEventHandler ["Draw3D",_ehID];
            uiNamespace setVariable ["PTF_UH1_DrawEH",-1];
        };
        if(!isNil "PTF_uh1_cam")then
        {
            PTF_uh1_cam cameraeffect ["terminate","back"];
            camDestroy PTF_uh1_cam;
            PTF_uh1_cam = nil;
        };
        // The old cleanup cleared a misspelled name (rhs_uh1_flir), so the reference to the
        // heli was never released. Only clear it if no newer display has claimed it
        if(!isNil "PTF_uh1Flir" && {PTF_uh1Flir isEqualTo _v})then{PTF_uh1Flir = nil};
    };
};



/*
heli
high refresh rate loop [0.1 sec]
*/
[_session] spawn
{
    params["_session"];
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
        // The 1 sec loop owns the shared cam and clears it on exit - without this we
        // would throw on every pass once it is gone. The session check stops an older
        // loop from fighting a newer one over the same camera
        if(isNil "PTF_uh1_cam" || {isNil "PTF_uh1Flir"} || {(uiNamespace getVariable ["PTF_UH1_Session",0]) isNotEqualTo _session})exitWith{};

        /*
            camera mode handler
        */
        _mode=_v getVariable ["PTF_uh1_mode",0];
        if(_mode != _old)then
        {
            PTF_uh1_cam cameraeffect ["terminate","back"];
            PTF_uh1_cam cameraEffect ["internal", "Back", "rendertarget0"];
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
                PTF_uh1Flir setObjectTexture _x;
                _texCache set [_slot,_tex];
            };
        }foreach _textureList;


        sleep 0.1;

        //diag_log format["%1",_textureList];
    };

};
