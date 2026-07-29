/*
PTF_fnc_uh1_toggleCam
toggle flir cam in UH1

a: reyhard (RHS Original), A.Nilsen (PTF Modifications)
*/
private _p = call rhsusf_fnc_findPlayer;
private _v = vehicle _p;

if(_p == driver _v)then{
    if(_v animationPhase "pip2_on" >0)then{
        _v animate ["pip2_on",0];
    }else{
        _v animate ["pip2_on",1];
        /*
            camera restart
        */
        // Cam is only created once the flir display has been opened, so it can be nil here
        if(!isNil "PTF_uh1_cam")then{
            PTF_uh1_cam cameraeffect ["terminate","back"];
            PTF_uh1_cam cameraEffect ["internal", "Back", "rendertarget0"];
            //mode reset
            private _mode=_v getVariable ["PTF_uh1_mode",0];
            "rendertarget0" setPiPEffect [_mode];
            //zoom reset
            private _n=(_v getVariable ["PTF_uh1_zoom",42])/40;
            PTF_uh1_cam camSetFov (0.7/_n);
        };
    };
}else{
    if(_p == _v turretUnit [0])then{
        if(_v animationPhase "pip1_on" >0)then{
            _v animate ["pip1_on",0];
        }else{
            _v animate ["pip1_on",1];
            /*
                camera restart
            */
            // Cam is only created once the flir display has been opened, so it can be nil here
            if(!isNil "PTF_uh1_cam")then{
                PTF_uh1_cam cameraeffect ["terminate","back"];
                PTF_uh1_cam cameraEffect ["internal", "Back", "rendertarget0"];
                //mode reset
                private _mode=_v getVariable ["PTF_uh1_mode",0];
                "rendertarget0" setPiPEffect [_mode];
                //zoom reset
                private _n=(_v getVariable ["PTF_uh1_zoom",42])/40;
                PTF_uh1_cam camSetFov (0.7/_n);
            };
        };
    };
};
