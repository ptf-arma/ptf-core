params ["_vehicle", ["_flag", ""]];

if (isNil "_vehicle")
   exitWith{true};

private _texture = if (_flag == "") then {""} else {"\z\PTF\addons\PTF_Textures\Flags\" + _flag};

if ((getForcedFlagTexture _vehicle) == _texture)
   exitWith{true};

_vehicle forceFlagTexture _texture;

true;
