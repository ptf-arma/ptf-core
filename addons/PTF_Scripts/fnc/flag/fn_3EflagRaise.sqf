params["_vehicle"];

if (isNil "_vehicle")
   exitWith{true};
if ((getForcedFlagTexture _vehicle) == "\z\PTF\addons\PTF_Textures\Flags\3Eflag.paa")
   exitWith{true};

_vehicle forceFlagTexture "\z\PTF\addons\PTF_Textures\Flags\3Eflag.paa";

true;
