_scenes = ["intro.ogv"];
while {true} do
{
	enableEnvironment false;
	showCinemaBorder false;
	_random = _scenes select floor random count _scenes;
	_random = _scenes call BIS_fnc_selectRandom;
	_random = selectRandom _scenes;
	cutText ["", "BLACK FADED", 0];
    _video = [_random] spawn BIS_fnc_playVideo;
	waitUntil {scriptDone _video};
};