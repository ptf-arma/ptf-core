params["_vehicle"];

if (isNil "_vehicle")
   exitWith{true};
if ((getForcedFlagTexture _vehicle) == "")
   exitWith{true};

_vehicle forceFlagTexture "";

true;
