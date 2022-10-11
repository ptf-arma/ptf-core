class WideNGS
{
   opticsDisplayName = "W";
   initAngleX = 0;
   minAngleX = -80;
   maxAngleX = 20;
   initAngleY = 0;
   minAngleY = -100;
   maxAngleY = 100;
   initFov = 1;
   minFov = 1;
   maxFov = 1;
   visionMode[] = {"Normal", "Ti"};
   thermalMode[] = {0, 1};
   gunnerOpticsColor[] = {1, 0, 0, 0};
   gunnerOpticsModel = "a3\weapons_f\Reticle\Optics_Gunner_AAA_01_w_F.p3d";
   directionStabilized = 1;
   stabilizedInAxes = 3;
};
class Wide
{
   opticsDisplayName = "W";
   initAngleX = 0;
   minAngleX = -80;
   maxAngleX = 20;
   initAngleY = 0;
   minAngleY = -100;
   maxAngleY = 100;
   initFov = 0.466;
   minFov = 0.466;
   maxFov = 0.466;
   visionMode[] = {"Normal", "Ti"};
   thermalMode[] = {0, 1};
   gunnerOpticsColor[] = {1, 0, 0, 0};
   gunnerOpticsModel = "a3\weapons_f\Reticle\Optics_Gunner_AAA_01_m_F.p3d";
   directionStabilized = 1;
   stabilizedInAxes = 3;
};
class WideL : Wide
{
   opticsDisplayName = "WL";
   visionMode[] = {"Normal"};
   initFov = 0.2;
   minFov = 0.2;
   maxFov = 0.2;
   directionStabilized = 1;
   stabilizedInAxes = 3;
};
class Medium : Wide
{
   opticsDisplayName = "M";
   visionMode[] = {"Normal"};
   initFov = 0.1;
   minFov = 0.1;
   maxFov = 0.1;
   directionStabilized = 1;
   stabilizedInAxes = 3;
};
class Narrow : Wide
{
   opticsDisplayName = "N";
   visionMode[] = {"Normal"};
   initFov = 0.02;
   minFov = 0.02;
   maxFov = 0.02;
   directionStabilized = 1;
   stabilizedInAxes = 3;
};
class Narrower : Wide
{
   opticsDisplayName = "N";
   visionMode[] = {"Normal"};
   initFov = 0.01;
   minFov = 0.01;
   maxFov = 0.01;
   directionStabilized = 1;
   stabilizedInAxes = 3;
};
