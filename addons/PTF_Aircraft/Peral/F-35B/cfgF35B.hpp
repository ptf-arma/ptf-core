class Peral_F35B;

class PTF_F35B_VIS : Peral_F35B
{
    scope = 2;
    editorCategory = "PTF";
    editorSubcategory = "PTF_Air";
    ace_cargo_hasCargo = 0;
    faction = "BLU_F";
    side = 1;
    author = "Peral";
    displayName = "F-35B (VIS) [MAG36]";
    AL_canBeMoved = 1;
    AL_CraneAttachpoint[] = {0,0.25,0.45};
    class pilotCamera
    {
        class OpticsIn
        {
            class Wide
            {
                opticsDisplayName = "TGT";
                initAngleX = 0;
                minAngleX = 0;
                maxAngleX = 0;
                initAngleY = 0;
                minAngleY = 0;
                maxAngleY = 0;
                initFov = "(20/120)";
                minFov = "(0.15/120)";
                maxFov = "(40/120)";
                directionStabilized = 1;
                visionMode[] = {"Normal","NVG","Ti"};
                thermalMode[] = {0,1};
                gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
            };

            showMiniMapInOptics = 1;
            showUAVViewInOptics = 0;
            showSlingLoadManagerInOptics = 0;
        };
        minTurn = -180;
        maxTurn = 180;
        initTurn = 0;
        minElev = -10;
        maxElev = 90;
        initElev = 0;
        maxXRotSpeed = 0.7;
        maxYRotSpeed = 0.7;
        maxMouseXRotSpeed = 0.7;
        maxMouseYRotSpeed = 0.7;
        pilotOpticsShowCursor = 1;
        controllable = 1;
    };
};
