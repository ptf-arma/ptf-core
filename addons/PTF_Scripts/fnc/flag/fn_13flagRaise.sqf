params["_vehicle"];

if (isNil "_vehicle")
   exitWith{true};
if ((getForcedFlagTexture _vehicle) == "\z\PTF\addons\PTF_Textures\Flags\13flag.paa")
   exitWith{true};

_vehicle forceFlagTexture "\z\PTF\addons\PTF_Textures\Flags\13flag.paa";

true;
