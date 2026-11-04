/*
 * The texture string for a rack. People with the same ribbons share one display,
 * so a parade costs one drawing per distinct rack, not one per person. An empty
 * rack is still drawn, as bare cloth: an empty texture string does not hide the
 * selection here, it brings back the model's own vanilla ribbons.
 *
 * Params: [rack], "awardId:count" pairs as published by billet-link.
 */
params [["_rack", "", [""]]];

private _entry = PTF_Dress_racks getOrDefault [_rack, []];
if (_entry isEqualTo []) then {
    _entry = [format ["ptf_dress_rack_%1", count PTF_Dress_racks], false];
    PTF_Dress_racks set [_rack, _entry];
};
format ["#(rgb,1024,256,1)ui('RscDisplayEmpty','%1')", _entry select 0]
