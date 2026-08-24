/*
	Adds the ACE "Cut loudspeaker power" interaction to the physical speaker
	object a broadcast is bound to. The server loop remoteExecs this to all
	machines (JIP-queued, so late joiners get it too); ACE interaction
	actions are local to each machine.

	Five seconds of interaction, then the module is deleted where it is
	local - the server loop notices, kills the say3D emitter, and the audio
	stops mid-play. A quiet alternative to shooting the speaker.

	[_speaker, _logic] call PTF_Sound_fnc_addCutAction;
*/
params ["_speaker", "_logic"];

if (!hasInterface) exitWith {};
if (isNull _speaker || {isNull _logic}) exitWith {};
if (!isClass (configFile >> "CfgPatches" >> "ace_interact_menu")) exitWith {};
if (_speaker getVariable ["PTF_Sound_cutAction", false]) exitWith {};
_speaker setVariable ["PTF_Sound_cutAction", true];

private _action = [
	"PTF_Sound_cutPower",
	"Cut loudspeaker power",
	"",
	{
		params ["_target", "_player", "_args"];
		_args params ["_logic"];
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
		params ["_target", "_player", "_args"];
		!isNull (_args select 0)
	},
	{},
	[_logic]
] call ace_interact_menu_fnc_createAction;

[_speaker, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;
