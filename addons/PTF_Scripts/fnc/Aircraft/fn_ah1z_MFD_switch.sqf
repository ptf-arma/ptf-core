/*
PTF_fnc_ah1z_MFD_switch
AH1Z MFD functionality

a: reyhard (RHS Original), A.Nilsen (PTF Modifications)
*/

params["_vehicle","_mfd"];

private _unit = call rhs_fnc_findPlayer;
private _mfdTextureIndex = -1;
private _mfdCheck = [4,5];
private _emptyScreen = "#(argb,8,8,3)color(0,0,0,1.0,co)";

// Driver
if((driver _vehicle) isEqualTo _unit)then
{
    switch(_mfd)do
    {
        case 4: {_mfdTextureIndex = 3;};
        case 5: {_mfdTextureIndex = 4;};
    };
}else{
// Gunner
    switch(_mfd)do
    {
        case 4: {_mfdTextureIndex = 5;_mfd = 6;};
        case 5: {_mfdTextureIndex = 6;_mfd = 7;};
    };
    _mfdCheck = [6,7];
};

private _destroyCam =
{
    params["_vehicle"];

    _videoFeedCam = _vehicle getVariable ["rhs_ah64_cam",objNull];
    _videoFeedCam cameraeffect ["terminate","back","rhs_ah64_videoFeed"];
    camDestroy _videoFeedCam;
    // Remove Event Handlers
    (findDisplay 46) displayRemoveEventHandler ["KeyUp", uiNameSpace getVariable ["rhs_ah64d_videoKey_eh",-1]];
    ["rhs_ah64_videoFeed_pfh", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
};

private _nextMode =  [1,2,3,4,5,0] # ((getUserMFDvalue _vehicle) # _mfd);
_vehicle setUserMFDvalue [_mfd,_nextMode];
private _mfdValues = getUserMFDvalue _vehicle;

switch(_nextMode)do
{
    // Flight page
    case 0:
    {
        // Deinitalization of radar page
        if(
            ( _mfdValues # (_mfdCheck # 0) != 5) &&
            ( _mfdValues # (_mfdCheck # 1) != 5)
        )then
        {
            // Check if EH already exist. If yes, then remove it
            if( not ( (uiNameSpace getVariable ["rhs_ah64d_radarPage_eh",-1]) isEqualTo -1))then
            {
                (findDisplay 46) displayRemoveEventHandler ["KeyUp", uiNameSpace getVariable "rhs_ah64d_radarPage_eh"];
            };
        };

        // Add loop
        ["rhs_ah64_flightPage_pfh", "onEachFrame", {

            params["_time","_vehicle","_vehicleDirPrev"];

            if(time >= _time)then
            {
                _this set [0,time+0.05];

                // Get Data
                private _vehicleDir = getDir _vehicle;
                private _turnRate   = (_vehicleDir - _vehicleDirPrev);
                // Calculate turn rate
                if(abs(_turnRate) > 180)then{_turnRate = (_turnRate - 360)};
                // Update MFD value (invers result)
                _vehicle setUserMFDvalue [11,-_turnRate];

                // Update parameter
                _this set [2,_vehicleDir];
            };
        },[0,_vehicle,0]] call BIS_fnc_addStackedEventHandler;
    };
    // Weapons page
    case 1:
    {
        // Deinitalization of flight page
        if(
            ( _mfdValues # (_mfdCheck # 0) != 0) &&
            ( _mfdValues # (_mfdCheck # 1) != 0)
        )then
        {
            ["rhs_ah64_flightPage_pfh", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
        };
    };
    // Fuel page
    case 2:
    {
    };
    // Engine page
    case 3:
    {
        if(!difficultyEnabledRTD)exitWith{};
        // Add loop
        ["rhs_ah64_enginePage_pfh", "onEachFrame", {
            params["_time","_vehicle"];

            if(!alive _vehicle)exitWith
            {
                ["rhs_ah64_enginePage_pfh", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
            };
            private _enginesRPM     = (enginesRpmRTD _vehicle);
            private _mainRotorSpeed = (rotorsRpmRTD _vehicle) # 0;
            private _hydraulics     = _vehicle getHitPointDamage "HitHydraulics";

            _vehicle setUserMFDvalue
            [
                12,
                linearConversion [0,315*1.2,_mainRotorSpeed,0,100*1.2,true],
                linearConversion [0,20000*1.2,_enginesRPM # 0,0,100*1.2,true],
                linearConversion [0,20000*1.2,_enginesRPM # 1,0,100*1.2,true],
                linearConversion [0,1,_hydraulics,3000,0,true]
            ];


        },[0,_vehicle]] call BIS_fnc_addStackedEventHandler;
    };
    // C scope - Video feed handling
    case 4:
    {
        // Deinitalization of Engine page if RTD is enabled
        if(isObjectRTD _vehicle)then
        {
            if(
                ( _mfdValues # (_mfdCheck # 0) != 3) &&
                ( _mfdValues # (_mfdCheck # 1) != 3)
            )then
            {
                ["rhs_ah64_enginePage_pfh", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
            };
        };

        // Exit if picture in picture is disabled
        if(!isPipEnabled)exitWith{};
        // Todo - move to separate files as sort of modules
        // Apply texture - aspect ratio seems to be broken - need to use UVanim
        _vehicle setObjectTexture [_mfdTextureIndex,"#(argb,512,512,1)r2t(rhs_ah64_videoFeed,1.33)"];

        // Try to retrieve existing cam
        _videoFeedCam = _vehicle getVariable ["rhs_ah64_cam",objNull];
        // If it doesn't exist, create a new one
        if(_videoFeedCam isEqualTo objNull)then
        {
            // Create R2T window
            _videoFeedCam = "camera" camCreate [0,0,0];
            _videoFeedCam cameraEffect ["Internal", "Back", "rhs_ah64_videoFeed"];
            _videoFeedCam attachTo [_vehicle, [0,0,0], "gunnerview"];
            _videoFeedCam camSetFov (0.7/24);
        };

        _vehicle setVariable ["rhs_ah64_cam",_videoFeedCam];

        // Set default view mode of R2T camera
        "rhs_ah64_videoFeed" setPiPEffect [0];
        _vehicle setUserMFDtext [0,"DTV"];

        // Check if EH already exist. If yes, then remove it
        if( not ( (uiNameSpace getVariable ["rhs_ah64d_videoKey_eh",-1]) isEqualTo -1))then
        {
            (findDisplay 46) displayRemoveEventHandler ["KeyUp", uiNameSpace getVariable "rhs_ah64d_videoKey_eh"];
        };

        // Add key event handler
        _id = (findDisplay 46) displayAddEventHandler ["KeyUp",
        {
            // Perform actions only in internal view
            if(cameraView isEqualTo "INTERNAL")then
            {
                // Change zoom
                if(inputAction "zeroingUp" > 0)then
                {
                    private _p            = call rhs_fnc_findPlayer;
                    private _vehicle      = vehicle _p;
                    private _videoFeedCam = _vehicle getVariable ["rhs_ah64_cam",objNull];
                    private _zoom         = (getUserMFDvalue _vehicle) # 9;
                    switch(_zoom)do
                    {
                        case 1:  { _zoom = 4; };
                        case 4:  { _zoom = 11; };
                    };
                    _videoFeedCam camSetFov (0.2/_zoom);
                    _vehicle setUserMFDvalue [9,_zoom];
                };
                if(inputAction "zeroingDown" > 0)then
                {
                    private _p            = call rhs_fnc_findPlayer;
                    private _vehicle      = vehicle _p;
                    private _videoFeedCam = _vehicle getVariable ["rhs_ah64_cam",objNull];
                    private _zoom         = (getUserMFDvalue _vehicle) # 9;
                    switch(_zoom)do
                    {
                        case 11:  { _zoom = 4; };
                        case 4:  { _zoom = 1; };
                    };
                    _videoFeedCam camSetFov (0.2/_zoom);
                    _vehicle setUserMFDvalue [9,_zoom];
                };
                // Change view mode
                if(inputAction "TransportNightVision" > 0)then
                {
                    private _p       = call rhs_fnc_findPlayer;
                    private _vehicle = vehicle _p;
                    private _mode    = (getUserMFDtext _vehicle) # 0;
                    switch(_mode)do
                    {
                        case "DTV": { "rhs_ah64_videoFeed" setPiPEffect [1]; _vehicle setUserMFDtext [0,"NVG"]; };
                        case "NVG": { "rhs_ah64_videoFeed" setPiPEffect [2]; _vehicle setUserMFDtext [0,"FLIR"]; };
                        default { "rhs_ah64_videoFeed" setPiPEffect [0]; _vehicle setUserMFDtext [0,"DTV"]; };
                    };
                };
            };
        }];
        uiNameSpace setVariable ["rhs_ah64d_videoKey_eh",_id];

        // Add loop
        ["rhs_ah64_videoFeed_pfh", "onEachFrame", {
            params["_vehicle","_videoFeedCam","_unit","_prevMode","_prevZoom","_camRestart"];

            // Adjust R2T camera
            if(cameraView isEqualTo "INTERNAL")then
            {
                // Restart camera
                /*if(_camRestart)then
                {
                    _videoFeedCam cameraeffect ["terminate","back","rhs_ah64_videoFeed"];
                    _videoFeedCam cameraEffect ["internal", "Back", "rhs_ah64_videoFeed"];
                };*/
                // Adjust camera vector
                _dir =
                    (_vehicle selectionPosition "gunnerview")
                        vectorFromTo
                    (_vehicle selectionPosition "gunnerview_dir");
                _videoFeedCam setVectorDirAndUp [
                    _dir,
                    _dir vectorCrossProduct [-(_dir select 1), _dir select 0, 0]
                ];
            };
            /*else
            {
                // Stop R2T operations when not in cockpit view
                if(!_camRestart)then
                {

                    _videoFeedCam cameraeffect ["terminate","back","rhs_ah64_videoFeed"];
                    _this set [5,true];
                };
            };*/


            // Check for camera changes
            if(cameraView isEqualTo "GUNNER")then
            {
                private _mode = currentVisionMode _unit;
                private _getZoom = {
                    (
                    [0.5,0.5]
                    distance2D
                    worldToScreen
                    positionCameraToWorld
                    [0,3,4]
                    ) * (
                    getResolution
                    select 5
                    ) / 2
                };
                private _zoom = (round(call _getZoom)) max 1;
                if(_mode != _prevMode)then
                {
                    switch(_mode)do
                    {
                        case 1: { "rhs_ah64_videoFeed" setPiPEffect [1]; _vehicle setUserMFDtext [0,"NVG"]; };
                        case 2: { "rhs_ah64_videoFeed" setPiPEffect [2]; _vehicle setUserMFDtext [0,"FLIR"]; };
                        default { "rhs_ah64_videoFeed" setPiPEffect [0]; _vehicle setUserMFDtext [0,"DTV"]; };
                    };
                    _this set [3,_mode];
                };
                if(_zoom != _prevZoom)then
                {
                    _videoFeedCam camSetFov (0.2/_zoom);
                    _this set [4,_zoom];
                    _vehicle setUserMFDvalue [9,_zoom];
                };
            };
        },[_vehicle,_videoFeedCam,_unit,0,0,false]] call BIS_fnc_addStackedEventHandler;
    };
    // Radar page
    case 5:
    {
        // Check if EH already exist. If yes, then remove it
        if( not ( (uiNameSpace getVariable ["rhs_ah64d_radarPage_eh",-1]) isEqualTo -1))then
        {
            (findDisplay 46) displayRemoveEventHandler ["KeyUp", uiNameSpace getVariable "rhs_ah64d_radarPage_eh"];
        };

        // Add key event handler
        _id = (findDisplay 46) displayAddEventHandler ["KeyUp",
        {
            // Perform actions only in internal view
            if(cameraView isEqualTo "INTERNAL")then
            {
                // Change zoom
                if(inputAction "user10" > 0)then
                {
                    private _vehicle = vehicle (call rhs_fnc_findPlayer);
                    if(getUserMFDValue _vehicle # 8 isEqualTo 0)then
                    {
                    // Turn on Air to Ground mode
                        _vehicle setUserMFDvalue [8,1];
                        _vehicle enableVehicleSensor ["ActiveRadarSensorComponent",false];
                        _vehicle enableVehicleSensor ["ActiveRadarSensorComponent_Air",true];
                    }else{
                    // Turn on Air to Air mode
                        _vehicle setUserMFDvalue [8,0];
                        _vehicle enableVehicleSensor ["ActiveRadarSensorComponent",true];
                        _vehicle enableVehicleSensor ["ActiveRadarSensorComponent_Air",false];
                    };
                };
            };
        }];
        uiNameSpace setVariable ["rhs_ah64d_radarPage_eh",_id];

        // Exit if picture in picture is disabled
        if(!isPipEnabled)exitWith{};

        _vehicle setObjectTexture [_mfdTextureIndex,_emptyScreen];
        private _textures = getObjectTextures _vehicle;
        // Deinitalization of TADS view
        if(
            ( _textures # ((_mfdCheck # 0) - 1) isEqualTo _emptyScreen) &&
            ( _textures # ((_mfdCheck # 1) - 1) isEqualTo _emptyScreen)
        )then
        {
            [_vehicle] call _destroyCam;
        };
    };
};
