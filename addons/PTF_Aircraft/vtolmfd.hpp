borderLeft = 0.09;
borderRight = 0.02;
borderTop = 0.02;
borderBottom = 0.1;
class MFD1
{
   topLeft = "HUD LH1";
   topRight = "HUD PH1";
   bottomLeft = "HUD LD1";
   borderLeft = 0;
   borderRight = 0;
   borderTop = 0;
   borderBottom = 0;
   color[] = {0, 1, 0, 0.1};
   class Pos10Vector
   {
      type = "vector";
      pos0[] = {0.5, 0.27};
      pos10[] = {"0.5+0.9", "0.27+0.7"};
   };
   class Bones
   {
   };
   class Draw
   {
      alpha = 0.9;
      color[] = {0, 1, 0};
      clipTL[] = {0.0, 0.0};
      clipBR[] = {1.0, 1.0};
      condition = "on";
      class Altitude
      {
         type = "text";
         align = "left";
         scale = 1;
         source = "altitudeASL";
         sourceScale = 1;
         pos[] = {{0.28, 0.042}, 1};
         right[] = {{0.32000002, 0.042}, 1};
         down[] = {{0.28, 0.082}, 1};
      };
      class Altitude2
      {
         type = "text";
         align = "left";
         scale = 1;
         source = "altitudeAGL";
         sourceScale = 1;
         pos[] = {{0.45, 0.042}, 1};
         right[] = {{0.49, 0.042}, 1};
         down[] = {{0.45, 0.082}, 1};
      };
      class RPM
      {
         type = "text";
         align = "left";
         scale = 1;
         source = "rpm";
         sourceScale = 100;
         pos[] = {{0.63, 0.18}, 1};
         right[] = {{0.67, 0.18}, 1};
         down[] = {{0.63, 0.22}, 1};
      };
      class RPM2
      {
         type = "text";
         align = "left";
         scale = 1;
         source = "rpm";
         sourceScale = 100;
         pos[] = {{0.802, 0.18}, 1};
         right[] = {{0.842, 0.18}, 1};
         down[] = {{0.802, 0.22}, 1};
      };
      class Fuel
      {
         type = "text";
         align = "left";
         scale = 1;
         source = "fuel";
         sourceScale = 100;
         pos[] = {{0.63, 0.42499998}, 1};
         right[] = {{0.67, 0.42499998}, 1};
         down[] = {{0.63, 0.465}, 1};
      };
      class Fuel2
      {
         type = "text";
         align = "left";
         scale = 1;
         source = "fuel";
         sourceScale = 100;
         pos[] = {{0.802, 0.42499998}, 1};
         right[] = {{0.842, 0.42499998}, 1};
         down[] = {{0.802, 0.465}, 1};
      };
      class Speed
      {
         type = "text";
         align = "left";
         scale = 1;
         source = "speed";
         sourceScale = 2.2369363;
         pos[] = {{0.28, 0.22500001}, 1};
         right[] = {{0.32000002, 0.22500001}, 1};
         down[] = {{0.28, 0.26500002}, 1};
      };
   };
};
class MV22_HMD
{
   topLeft = "HUD_top_left";
   topRight = "HUD_top_right";
   bottomLeft = "HUD_bottom_left";
   borderLeft = 0;
   borderRight = 0;
   borderTop = 0;
   borderBottom = 0;
   enableParallax = 0;
   color[] = {0.15, 1, 0.15, 1};
   class Bones
   {
      class speedL0
      {
         type = "linear";
         source = "speed";
         sourceScale = 3.6;
         min = -600;
         max = 600;
         minPos[] = {0.13, 2};
         maxPos[] = {0.13, -1};
      };
      class vSpeedRot
      {
         type = "rotational";
         source = "vspeed";
         center[] = {0.5, 0.5};
         min = -50;
         max = 50;
         minAngle = -180;
         maxAngle = 180;
         aspectRatio = 1;
      };
      class vSpeedRotP5 : vSpeedRot
      {
         minAngle = "-180 - 18";
         maxAngle = "180 - 18";
      };
      class vSpeedRotM5 : vSpeedRot
      {
         minAngle = "-180 + 18";
         maxAngle = "180 + 18";
      };
      class vSpeedRotP10 : vSpeedRot
      {
         minAngle = "-180 - 36";
         maxAngle = "180 - 36";
      };
      class vSpeedRotM10 : vSpeedRot
      {
         minAngle = "-180 + 36";
         maxAngle = "180 + 36";
      };
      class vSpeedRotP15 : vSpeedRot
      {
         minAngle = "-180 - 54";
         maxAngle = "180 - 54";
      };
      class vSpeedRotM15 : vSpeedRot
      {
         minAngle = "-180 + 54";
         maxAngle = "180 + 54";
      };
      class vSpeedRotP20 : vSpeedRot
      {
         minAngle = "-180 - 72";
         maxAngle = "180 - 72";
      };
      class vSpeedRotM20 : vSpeedRot
      {
         minAngle = "-180 + 72";
         maxAngle = "180 + 72";
      };
      class vSpeedRotP25 : vSpeedRot
      {
         minAngle = "-180 - 90";
         maxAngle = "180 - 90";
      };
      class vSpeedRotM25 : vSpeedRot
      {
         minAngle = "-180 + 90";
         maxAngle = "180 + 90";
      };
      class vSpeedRotP30 : vSpeedRot
      {
         minAngle = "-180 - 108";
         maxAngle = "180 - 108";
      };
      class vSpeedRotM30 : vSpeedRot
      {
         minAngle = "-180 + 108";
         maxAngle = "180 + 108";
      };
      class vSpeedRotP1 : vSpeedRot
      {
         minAngle = "-180 - 3.6";
         maxAngle = "180 - 3.6";
      };
      class vSpeedRotP2 : vSpeedRot
      {
         minAngle = "-180 - 7.2";
         maxAngle = "180 - 7.2";
      };
      class vSpeedRotP3 : vSpeedRot
      {
         minAngle = "-180 - 10.8";
         maxAngle = "180 - 10.8";
      };
      class vSpeedRotP4 : vSpeedRot
      {
         minAngle = "-180 - 14.4";
         maxAngle = "180 - 14.4";
      };
      class vSpeedRotM1 : vSpeedRot
      {
         minAngle = "-180 + 3.6";
         maxAngle = "180 + 3.6";
      };
      class vSpeedRotM2 : vSpeedRot
      {
         minAngle = "-180 + 7.2";
         maxAngle = "180 + 7.2";
      };
      class vSpeedRotM3 : vSpeedRot
      {
         minAngle = "-180 + 10.8";
         maxAngle = "180 + 10.8";
      };
      class vSpeedRotM4 : vSpeedRot
      {
         minAngle = "-180 + 14.4";
         maxAngle = "180 + 14.4";
      };
      class HorizonBankRot
      {
         type = "rotational";
         source = "horizonBank";
         center[] = {0.5, 0.5};
         min = -3.1416;
         max = 3.1416;
         minAngle = -180;
         maxAngle = 180;
         aspectRatio = 1;
      };
      class VtolRot
      {
         type = "rotational";
         source = "vtolvectoring";
         center[] = {0.03, 0.15};
         min = 0;
         max = 1;
         minAngle = 90;
         maxAngle = 0;
         aspectRatio = 1;
      };
      class Level0
      {
         type = "horizontoview";
         pos0[] = {0.5, 0.5};
         pos10[] = {0.78, 0.78};
         angle = 0;
      };
      class LevelP5 : Level0
      {
         angle = 5;
      };
      class LevelP2 : Level0
      {
         angle = 2.5;
      };
      class LevelM5 : Level0
      {
         angle = -5;
      };
      class LevelM2 : Level0
      {
         angle = -2.5;
      };
      class LevelP10 : Level0
      {
         angle = 10;
      };
      class LevelM10 : Level0
      {
         angle = -10;
      };
      class LevelP15 : Level0
      {
         angle = 15;
      };
      class LevelM15 : Level0
      {
         angle = -15;
      };
      class LevelP20 : Level0
      {
         angle = 20;
      };
      class LevelM20 : Level0
      {
         angle = -20;
      };
      class LevelP25 : Level0
      {
         angle = 25;
      };
      class LevelM25 : Level0
      {
         angle = -25;
      };
      class LevelP30 : Level0
      {
         angle = 30;
      };
      class LevelM30 : Level0
      {
         angle = -30;
      };
      class LevelP35 : Level0
      {
         angle = 35;
      };
      class LevelM35 : Level0
      {
         angle = -35;
      };
      class LevelP40 : Level0
      {
         angle = 40;
      };
      class LevelM40 : Level0
      {
         angle = -40;
      };
      class LevelP45 : Level0
      {
         angle = 45;
      };
      class LevelM45 : Level0
      {
         angle = -45;
      };
      class LevelP50 : Level0
      {
         angle = 50;
      };
      class LevelM50 : Level0
      {
         angle = -50;
      };
      class LevelP55 : Level0
      {
         angle = 55;
      };
      class LevelM55 : Level0
      {
         angle = -55;
      };
      class LevelP60 : Level0
      {
         angle = 60;
      };
      class LevelM60 : Level0
      {
         angle = -60;
      };
      class LevelP65 : Level0
      {
         angle = 65;
      };
      class LevelM65 : Level0
      {
         angle = -65;
      };
      class LevelP70 : Level0
      {
         angle = 70;
      };
      class LevelM70 : Level0
      {
         angle = -70;
      };
      class LevelP75 : Level0
      {
         angle = 75;
      };
      class LevelM75 : Level0
      {
         angle = -75;
      };
      class LevelP80 : Level0
      {
         angle = 80;
      };
      class LevelM80 : Level0
      {
         angle = -80;
      };
      class LevelP85 : Level0
      {
         angle = 85;
      };
      class LevelM85 : Level0
      {
         angle = -85;
      };
      class LevelP90 : Level0
      {
         angle = 90;
      };
      class LevelM90 : Level0
      {
         angle = -90;
      };
   };
   class Draw
   {
      color[] = {"user0", "user1", "user2"};
      alpha = "user3";
      condition = "on";
      class PitchLadder
      {
         clipTL[] = {0.08, 0.2};
         clipBR[] = {1.0, 0.8};
         class Level0
         {
            width = 3;
            type = "line";
            points[] = {{"Level0", {-0.35, 0}, 1}, {"Level0", {-0.11, 0}, 1}, {}, {"Level0", {0.11, 0}, 1}, {"Level0", {0.35, 0}, 1}};
         };
         class PitchSteps
         {
            condition = "abs(cameraHeadingDiffX)<=5";
            class Leveld0
            {
               type = "line";
               points[] = {{"Level0", {-0.025, 0}, 1}, {"Level0", {0.025, 0}, 1}};
            };
            class Level2
            {
               type = "line";
               width = 2;
               points[] = {{"LevelP2", {-0.025, 0}, 1}, {"LevelP2", {0.025, 0}, 1}};
            };
            class Levelm2
            {
               type = "line";
               width = 2;
               points[] = {{"LevelM2", {-0.025, 0}, 1}, {"LevelM2", {0.025, 0}, 1}};
            };
            class Level5
            {
               type = "line";
               points[] = {{"LevelP5", {-0.025, 0}, 1}, {"LevelP5", {0.025, 0}, 1}};
            };
            class Levelm5
            {
               type = "line";
               points[] = {{"LevelM5", {-0.025, 0}, 1}, {"LevelM5", {0.025, 0}, 1}};
            };
            class Level10
            {
               type = "line";
               points[] = {{"LevelP10", {-0.025, 0}, 1}, {"LevelP10", {0.025, 0}, 1}};
            };
            class Levelm10
            {
               type = "line";
               points[] = {{"LevelM10", {-0.025, 0}, 1}, {"LevelM10", {0.025, 0}, 1}};
            };
            class Level15
            {
               type = "line";
               points[] = {{"LevelP15", {-0.025, 0}, 1}, {"LevelP15", {0.025, 0}, 1}};
            };
            class Levelm15
            {
               type = "line";
               points[] = {{"LevelM15", {-0.025, 0}, 1}, {"LevelM15", {0.025, 0}, 1}};
            };
            class Level20
            {
               type = "line";
               points[] = {{"LevelP20", {-0.025, 0}, 1}, {"LevelP20", {0.025, 0}, 1}};
            };
            class Levelm20
            {
               type = "line";
               points[] = {{"LevelM20", {-0.025, 0}, 1}, {"LevelM20", {0.025, 0}, 1}};
            };
            class Level25
            {
               type = "line";
               points[] = {{"LevelP25", {-0.025, 0}, 1}, {"LevelP25", {0.025, 0}, 1}};
            };
            class Levelm25
            {
               type = "line";
               points[] = {{"LevelM25", {-0.025, 0}, 1}, {"LevelM25", {0.025, 0}, 1}};
            };
            class Level30
            {
               type = "line";
               points[] = {{"LevelP30", {-0.025, 0}, 1}, {"LevelP30", {0.025, 0}, 1}};
            };
            class Levelm30
            {
               type = "line";
               points[] = {{"LevelM30", {-0.025, 0}, 1}, {"LevelM30", {0.025, 0}, 1}};
            };
            class Level35
            {
               type = "line";
               points[] = {{"LevelP35", {-0.025, 0}, 1}, {"LevelP35", {0.025, 0}, 1}};
            };
            class Levelm35
            {
               type = "line";
               points[] = {{"LevelM35", {-0.025, 0}, 1}, {"LevelM35", {0.025, 0}, 1}};
            };
            class Level40
            {
               type = "line";
               points[] = {{"LevelP40", {-0.025, 0}, 1}, {"LevelP40", {0.025, 0}, 1}};
            };
            class Levelm40
            {
               type = "line";
               points[] = {{"LevelM40", {-0.025, 0}, 1}, {"LevelM40", {0.025, 0}, 1}};
            };
            class Level45
            {
               type = "line";
               points[] = {{"LevelP45", {-0.025, 0}, 1}, {"LevelP45", {0.025, 0}, 1}};
            };
            class Levelm45
            {
               type = "line";
               points[] = {{"LevelM45", {-0.025, 0}, 1}, {"LevelM45", {0.025, 0}, 1}};
            };
            class Level50
            {
               type = "line";
               points[] = {{"LevelP50", {-0.025, 0}, 1}, {"LevelP50", {0.025, 0}, 1}};
            };
            class Levelm50
            {
               type = "line";
               points[] = {{"LevelM50", {-0.025, 0}, 1}, {"LevelM50", {0.025, 0}, 1}};
            };
            class Level55
            {
               type = "line";
               points[] = {{"LevelP55", {-0.025, 0}, 1}, {"LevelP55", {0.025, 0}, 1}};
            };
            class Levelm55
            {
               type = "line";
               points[] = {{"LevelM55", {-0.025, 0}, 1}, {"LevelM55", {0.025, 0}, 1}};
            };
         };
      };
      class aircraftLine
      {
         type = "line";
         width = 5;
         points[] = {{{0.38, 0.5}, 1}, {{0.46, 0.5}, 1}, {{0.46, 0.528}, 1}, {}, {{0.54, 0.528}, 1}, {{0.54, 0.5}, 1}, {{0.62, 0.5}, 1}};
      };
      class speedLabels
      {
         clipTL[] = {0, 0.4};
         clipBR[] = {1, 0.6};
         class Inner
         {
            class sText0
            {
               type = "text";
               source = "static";
               text = "0";
               align = "center";
               sourceScale = 1;
               scale = 1;
               pos[] = {"speedL0", {0, -0.02}, 1};
               right[] = {"speedL0", {0.04, -0.02}, 1};
               down[] = {"speedL0", {0, 0.02}, 1};
            };
            class sTextM20 : sText0
            {
               text = "-20";
               pos[] = {"speedL0", {0, 0.036}, 1};
               right[] = {"speedL0", {0.04, 0.036}, 1};
               down[] = {"speedL0", {0, 0.076}, 1};
            };
            class sTextM40 : sText0
            {
               text = "-40";
               pos[] = {"speedL0", {0, 0.091}, 1};
               right[] = {"speedL0", {0.04, 0.091}, 1};
               down[] = {"speedL0", {0, 0.131}, 1};
            };
            class sTextM60 : sText0
            {
               text = "-60";
               pos[] = {"speedL0", {0, 0.147}, 1};
               right[] = {"speedL0", {0.04, 0.147}, 1};
               down[] = {"speedL0", {0, 0.187}, 1};
            };
            class sTextM80 : sText0
            {
               text = "-80";
               pos[] = {"speedL0", {0, 0.202}, 1};
               right[] = {"speedL0", {0.04, 0.202}, 1};
               down[] = {"speedL0", {0, 0.242}, 1};
            };
            class sTextM100 : sText0
            {
               text = "-100";
               pos[] = {"speedL0", {0, 0.258}, 1};
               right[] = {"speedL0", {0.04, 0.258}, 1};
               down[] = {"speedL0", {0, 0.298}, 1};
            };
            class sText20 : sText0
            {
               text = "20";
               pos[] = {"speedL0", {0, -0.076}, 1};
               right[] = {"speedL0", {0.04, -0.076}, 1};
               down[] = {"speedL0", {0, -0.0355}, 1};
            };
            class sText40 : sText0
            {
               text = "40";
               pos[] = {"speedL0", {0, -0.131}, 1};
               right[] = {"speedL0", {0.04, -0.131}, 1};
               down[] = {"speedL0", {0, -0.091}, 1};
            };
            class sText60 : sText0
            {
               text = "60";
               pos[] = {"speedL0", {0, -0.187}, 1};
               right[] = {"speedL0", {0.04, -0.187}, 1};
               down[] = {"speedL0", {0, -0.147}, 1};
            };
            class sText80 : sText0
            {
               text = "80";
               pos[] = {"speedL0", {0, -0.242}, 1};
               right[] = {"speedL0", {0.04, -0.242}, 1};
               down[] = {"speedL0", {0, -0.202}, 1};
            };
            class sText100 : sText0
            {
               text = "100";
               pos[] = {"speedL0", {0, -0.298}, 1};
               right[] = {"speedL0", {0.04, -0.298}, 1};
               down[] = {"speedL0", {0, -0.258}, 1};
            };
            class sText120 : sText0
            {
               text = "120";
               pos[] = {"speedL0", {0, -0.353}, 1};
               right[] = {"speedL0", {0.04, -0.353}, 1};
               down[] = {"speedL0", {0, -0.313}, 1};
            };
            class sText140 : sText0
            {
               text = "140";
               pos[] = {"speedL0", {0, -0.409}, 1};
               right[] = {"speedL0", {0.04, -0.409}, 1};
               down[] = {"speedL0", {0, -0.369}, 1};
            };
            class sText160 : sText0
            {
               text = "160";
               pos[] = {"speedL0", {0, -0.464}, 1};
               right[] = {"speedL0", {0.04, -0.464}, 1};
               down[] = {"speedL0", {0, -0.424}, 1};
            };
            class sText180 : sText0
            {
               text = "180";
               pos[] = {"speedL0", {0, -0.52}, 1};
               right[] = {"speedL0", {0.04, -0.52}, 1};
               down[] = {"speedL0", {0, -0.48}, 1};
            };
            class sText200 : sText0
            {
               text = "200";
               pos[] = {"speedL0", {0, -0.576}, 1};
               right[] = {"speedL0", {0.04, -0.576}, 1};
               down[] = {"speedL0", {0, -0.536}, 1};
            };
            class sText220 : sText0
            {
               text = "220";
               pos[] = {"speedL0", {0, -0.631}, 1};
               right[] = {"speedL0", {0.04, -0.631}, 1};
               down[] = {"speedL0", {0, -0.591}, 1};
            };
            class sText240 : sText0
            {
               text = "240";
               pos[] = {"speedL0", {0, -0.687}, 1};
               right[] = {"speedL0", {0.04, -0.687}, 1};
               down[] = {"speedL0", {0, -0.647}, 1};
            };
            class sText260 : sText0
            {
               text = "260";
               pos[] = {"speedL0", {0, -0.742}, 1};
               right[] = {"speedL0", {0.04, -0.742}, 1};
               down[] = {"speedL0", {0, -0.702}, 1};
            };
            class sText280 : sText0
            {
               text = "280";
               pos[] = {"speedL0", {0, -0.798}, 1};
               right[] = {"speedL0", {0.04, -0.798}, 1};
               down[] = {"speedL0", {0, -0.758}, 1};
            };
            class sText300 : sText0
            {
               text = "300";
               pos[] = {"speedL0", {0, -0.853}, 1};
               right[] = {"speedL0", {0.04, -0.853}, 1};
               down[] = {"speedL0", {0, -0.813}, 1};
            };
            class sText320 : sText0
            {
               text = "320";
               pos[] = {"speedL0", {0, -0.909}, 1};
               right[] = {"speedL0", {0.04, -0.909}, 1};
               down[] = {"speedL0", {0, -0.869}, 1};
            };
            class sText340 : sText0
            {
               text = "340";
               pos[] = {"speedL0", {0, -0.964}, 1};
               right[] = {"speedL0", {0.04, -0.964}, 1};
               down[] = {"speedL0", {0, -0.924}, 1};
            };
            class sText360 : sText0
            {
               text = "360";
               pos[] = {"speedL0", {0, -1.02}, 1};
               right[] = {"speedL0", {0.04, -1.02}, 1};
               down[] = {"speedL0", {0, -0.98}, 1};
            };
            class sText380 : sText0
            {
               text = "380";
               pos[] = {"speedL0", {0, -1.076}, 1};
               right[] = {"speedL0", {0.04, -1.076}, 1};
               down[] = {"speedL0", {0, -1.036}, 1};
            };
            class sText400 : sText0
            {
               text = "400";
               pos[] = {"speedL0", {0, -1.131}, 1};
               right[] = {"speedL0", {0.04, -1.131}, 1};
               down[] = {"speedL0", {0, -1.091}, 1};
            };
            class sText420 : sText0
            {
               text = "420";
               pos[] = {"speedL0", {0, -1.187}, 1};
               right[] = {"speedL0", {0.04, -1.187}, 1};
               down[] = {"speedL0", {0, -1.147}, 1};
            };
            class sText440 : sText0
            {
               text = "440";
               pos[] = {"speedL0", {0, -1.242}, 1};
               right[] = {"speedL0", {0.04, -1.242}, 1};
               down[] = {"speedL0", {0, -1.202}, 1};
            };
            class sText460 : sText0
            {
               text = "460";
               pos[] = {"speedL0", {0, -1.298}, 1};
               right[] = {"speedL0", {0.04, -1.298}, 1};
               down[] = {"speedL0", {0, -1.258}, 1};
            };
            class sText480 : sText0
            {
               text = "480";
               pos[] = {"speedL0", {0, -1.353}, 1};
               right[] = {"speedL0", {0.04, -1.353}, 1};
               down[] = {"speedL0", {0, -1.313}, 1};
            };
            class sText500 : sText0
            {
               text = "500";
               pos[] = {"speedL0", {0, -1.409}, 1};
               right[] = {"speedL0", {0.04, -1.409}, 1};
               down[] = {"speedL0", {0, -1.369}, 1};
            };
            class sText520 : sText0
            {
               text = "520";
               pos[] = {"speedL0", {0, -1.464}, 1};
               right[] = {"speedL0", {0.04, -1.464}, 1};
               down[] = {"speedL0", {0, -1.424}, 1};
            };
         };
      };
      class SpeedIndicator
      {
         type = "line";
         width = 3;
         points[] = {{{0.095, 0.5}, 1}, {{0.08, 0.485}, 1}, {{0.08, 0.515}, 1}, {{0.095, 0.5}, 1}, {}};
      };
      class Digital_Speed_Number
      {
         type = "text";
         source = "speed";
         sourceScale = 3.6;
         scale = 1;
         align = "left";
         pos[] = {{0.07, 0.475}, 1};
         right[] = {{0.12, 0.475}, 1};
         down[] = {{0.07, 0.525}, 1};
      };
      class ClimbIndicator
      {
         type = "line";
         width = 3;
         points[] = {{{0.895, 0.5}, 1}, {{0.88, 0.485}, 1}, {{0.88, 0.515}, 1}, {{0.895, 0.5}, 1}, {}};
      };
      class Vtol_positive
      {
         condition = "vtolvectoring >= 0";
         class R_VTOL_Number
         {
            type = "text";
            source = "vtolvectoring";
            sourceScale = 90;
            align = "left";
            scale = 1;
            pos[] = {{0.065, 0.12}, 1};
            right[] = {{0.115, 0.12}, 1};
            down[] = {{0.065, 0.148}, 1};
         };
      };
      class Vtol_negative
      {
         condition = "0 > vtolvectoring";
         class R_VTOL_Number
         {
            type = "text";
            source = "static";
            text = "0";
            align = "left";
            scale = 1;
            pos[] = {{0.065, 0.12}, 1};
            right[] = {{0.115, 0.12}, 1};
            down[] = {{0.065, 0.148}, 1};
         };
      };
      class VTOL_Dir
      {
         type = "line";
         width = 4;
         points[] = {{"VtolRot", {0, 0.07}, 1}, {"VtolRot", {-0.01, 0.055}, 1}, {"VtolRot", {0.01, 0.055}, 1}, {"VtolRot", {0, 0.07}, 1}};
      };
      class VTOL_LineH
      {
         type = "line";
         width = 4;
         points[] = {{{0.03, 0.15}, 1}, {{0.08, 0.15}, 1}};
      };
      class VTOL_LineV
      {
         type = "line";
         width = 4;
         points[] = {{{0.03, 0.15}, 1}, {{0.02, 0.1025}, 1}};
      };
      class VTOL_pipR
      {
         type = "line";
         width = 4;
         points[] = {{{0.105, 0.15}, 1}, {{0.115, 0.15}, 1}};
      };
      class VTOL_pipT
      {
         type = "line";
         width = 4;
         points[] = {{{0.03, 0.065}, 1}, {{0.03, 0.075}, 1}};
      };
      class VTOL_pip3
      {
         type = "line";
         width = 4;
         points[] = {{{0.067499995, 0.0850481}, 1}, {{0.0725, 0.07638784}, 1}};
      };
      class VTOL_pip6
      {
         type = "line";
         width = 4;
         points[] = {{{0.0949519, 0.112500004}, 1}, {{0.10361216, 0.1075}, 1}};
      };
      class vSpeedRotor
      {
         clipTL[] = {0.8, 0.3};
         clipBR[] = {1.0, 0.7};
         class Inner
         {
            class vSpeedText
            {
               type = "text";
               source = "vspeed";
               align = "center";
               sourceScale = 1;
               scale = 1;
               pos[] = {{0.96, 0.48}, 1};
               right[] = {{1.0, 0.48}, 1};
               down[] = {{0.96, 0.52}, 1};
            };
            class Rot0
            {
               type = "line";
               points[] = {{"vSpeedRot", {0.4, 0}, 1}, {"vSpeedRot", {0.44, 0}, 1}};
            };
            class RotP1
            {
               type = "line";
               width = 3;
               points[] = {{"vSpeedRotP1", {0.4, 0}, 1}, {"vSpeedRotP1", {0.43, 0}, 1}};
            };
            class RotP2
            {
               type = "line";
               width = 3;
               points[] = {{"vSpeedRotP2", {0.4, 0}, 1}, {"vSpeedRotP2", {0.43, 0}, 1}};
            };
            class RotP3
            {
               type = "line";
               width = 3;
               points[] = {{"vSpeedRotP3", {0.4, 0}, 1}, {"vSpeedRotP3", {0.43, 0}, 1}};
            };
            class RotP4
            {
               type = "line";
               width = 3;
               points[] = {{"vSpeedRotP4", {0.4, 0}, 1}, {"vSpeedRotP4", {0.43, 0}, 1}};
            };
            class RotM1
            {
               type = "line";
               width = 3;
               points[] = {{"vSpeedRotM1", {0.4, 0}, 1}, {"vSpeedRotM1", {0.43, 0}, 1}};
            };
            class RotM2
            {
               type = "line";
               width = 3;
               points[] = {{"vSpeedRotM2", {0.4, 0}, 1}, {"vSpeedRotM2", {0.43, 0}, 1}};
            };
            class RotM3
            {
               type = "line";
               width = 3;
               points[] = {{"vSpeedRotM3", {0.4, 0}, 1}, {"vSpeedRotM3", {0.43, 0}, 1}};
            };
            class RotM4
            {
               type = "line";
               width = 3;
               points[] = {{"vSpeedRotM4", {0.4, 0}, 1}, {"vSpeedRotM4", {0.43, 0}, 1}};
            };
            class RotP5
            {
               type = "line";
               points[] = {{"vSpeedRotP5", {0.4, 0}, 1}, {"vSpeedRotP5", {0.44, 0}, 1}};
            };
            class RotM5
            {
               type = "line";
               points[] = {{"vSpeedRotM5", {0.4, 0}, 1}, {"vSpeedRotM5", {0.44, 0}, 1}};
            };
            class RotP10
            {
               type = "line";
               points[] = {{"vSpeedRotP10", {0.4, 0}, 1}, {"vSpeedRotP10", {0.44, 0}, 1}};
            };
            class RotM10
            {
               type = "line";
               points[] = {{"vSpeedRotM10", {0.4, 0}, 1}, {"vSpeedRotM10", {0.44, 0}, 1}};
            };
            class RotP15
            {
               type = "line";
               points[] = {{"vSpeedRotP15", {0.4, 0}, 1}, {"vSpeedRotP15", {0.44, 0}, 1}};
            };
            class RotM15
            {
               type = "line";
               points[] = {{"vSpeedRotM15", {0.4, 0}, 1}, {"vSpeedRotM15", {0.44, 0}, 1}};
            };
            class RotP20
            {
               type = "line";
               points[] = {{"vSpeedRotP20", {0.4, 0}, 1}, {"vSpeedRotP20", {0.44, 0}, 1}};
            };
            class RotM20
            {
               type = "line";
               points[] = {{"vSpeedRotM20", {0.4, 0}, 1}, {"vSpeedRotM20", {0.44, 0}, 1}};
            };
            class RotP25
            {
               type = "line";
               points[] = {{"vSpeedRotP25", {0.4, 0}, 1}, {"vSpeedRotP25", {0.44, 0}, 1}};
            };
            class RotM25
            {
               type = "line";
               points[] = {{"vSpeedRotM25", {0.4, 0}, 1}, {"vSpeedRotM25", {0.44, 0}, 1}};
            };
            class RotP30
            {
               type = "line";
               points[] = {{"vSpeedRotP30", {0.4, 0}, 1}, {"vSpeedRotP30", {0.44, 0}, 1}};
            };
            class RotM30
            {
               type = "line";
               points[] = {{"vSpeedRotM30", {0.4, 0}, 1}, {"vSpeedRotM30", {0.44, 0}, 1}};
            };
         };
      };
      class Baro_Altitude_Number
      {
         type = "text";
         source = "altitudeASL";
         sourceScale = 1;
         align = "left";
         scale = 1;
         pos[] = {{0.87, 0.48}, 1};
         right[] = {{0.91, 0.48}, 1};
         down[] = {{0.87, 0.52}, 1};
      };
      class HeadingArrow
      {
         type = "line";
         width = 7;
         points[] = {{{"0.5", "0.128 + 0.03"}, 1}, {{0.5, 0.128}, 1}};
      };
      class HeadingScale
      {
         class Heading_group
         {
            type = "scale";
            horizontal = 1;
            source = "heading";
            sourceScale = 0.1;
            NeverEatSeaWeed = 1;
            width = 5;
            top = 0.12;
            center = 0.5;
            bottom = 0.88;
            lineXleft = "0.03 + 0.085";
            lineYright = "0.02 + 0.085";
            lineXleftMajor = "0.03 + 0.085";
            lineYrightMajor = "0.015 + 0.085";
            majorLineEach = 3;
            numberEach = 3;
            step = 1;
            stepSize = "0.0344828*2";
            align = "center";
            scale = 1;
            pos[] = {0.12, "0.0 + 0.065"};
            right[] = {0.16, "0.0 + 0.065"};
            down[] = {0.12, "0.04 + 0.065"};
         };
      };
      class R_Altitude_Text
      {
         type = "text";
         source = "static";
         text = "R";
         align = "left";
         scale = 1;
         pos[] = {{0.95, 0.81}, 1};
         right[] = {{0.99, 0.81}, 1};
         down[] = {{0.95, 0.85}, 1};
      };
      class R_Altitude_Number
      {
         type = "text";
         source = "altitudeAGL";
         sourceScale = 1;
         align = "left";
         scale = 1;
         pos[] = {{0.92, 0.81}, 1};
         right[] = {{0.96, 0.81}, 1};
         down[] = {{0.92, 0.85}, 1};
      };
      class R_Collective_Text
      {
         type = "text";
         source = "static";
         text = "%";
         align = "left";
         scale = 1;
         pos[] = {{0.11, 0.81}, 1};
         right[] = {{0.15, 0.81}, 1};
         down[] = {{0.11, 0.85}, 1};
      };
      class R_Collective_Number
      {
         type = "text";
         source = "throttle";
         sourceScale = 100;
         align = "right";
         scale = 1;
         pos[] = {{0.04, 0.81}, 1};
         right[] = {{0.08, 0.81}, 1};
         down[] = {{0.04, 0.85}, 1};
      };
   };
   helmetMountedDisplay = 1;
   helmetPosition[] = {-0.04, 0.04, 0.1};
   helmetRight[] = {0.08, 0, 0};
   helmetDown[] = {0, -0.08, 0};
};