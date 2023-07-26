params["_vehicle"];

if (isNil "_vehicle")
   exitWith{true};
if ((getForcedFlagTexture _vehicle) == "\PTF_Textures\Flags\14flag.paa")
   exitWith{true};

_vehicle forceFlagTexture "\PTF_Textures\Flags\14flag.paa";

true;
