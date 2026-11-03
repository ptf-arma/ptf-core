/*
	Adds the ACE "Cut loudspeaker power" interaction to a physical speaker
	object. remoteExec'd (JIP-queued per speaker) by the server loop; ACE
	actions are local to each machine.

	The action reads the CURRENTLY bound module live from the speaker's
	PTF_Sound_logic variable (maintained by the server loop), so one action
	per speaker serves every module that ever binds to it, hides itself
	whenever nothing is bound, and can never cut a module that has moved to
	a different prop.

	Five seconds of interaction, then the module is deleted where it is
	local - the server loop notices and the say3D emitter dies with the
	audio mid-play. The quiet alternative to shooting the speaker.

	[_speaker] call PTF_Sound_fnc_addCutAction;
*/
params ["_speaker"];

if (!hasInterface) exitWith {};
if (isNull _speaker) exitWith {};
if (!isClass (configFile >> "CfgPatches" >> "ace_interact_menu")) exitWith {};
if (_speaker getVariable ["PTF_Sound_cutAction", false]) exitWith {};
_speaker setVariable ["PTF_Sound_cutAction", true];

private _action = [
	"PTF_Sound_cutPower",
	"Cut loudspeaker power",
	"",
	{
		params ["_target", "_player"];
		private _logic = _target getVariable ["PTF_Sound_logic", objNull];
		if (isNull _logic) exitWith {};
		[
			5,
			[_logic],
			{
				(_this select 0) params ["_logic"];
				if (!isNull _logic) then {
					_logic remoteExec ["deleteVehicle", _logic];
				};
			},
			{},
			"Cutting loudspeaker power...",
			{true}
		] call ace_common_fnc_progressBar;
	},
	{
		params ["_target", "_player"];
		!isNull (_target getVariable ["PTF_Sound_logic", objNull])
	}
] call ace_interact_menu_fnc_createAction;

[_speaker, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;
