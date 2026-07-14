// HEMTT names PBOs "{prefix}_{folder}.pbo", which would double the prefix on
// our already-prefixed folders (PTF_PTF_Aircraft.pbo) and rename the
// third-party PBOs (ctab.pbo -> PTF_ctab.pbo). Strip the added prefix so
// every PBO keeps its historical "<folder>.pbo" name. Runs before signing,
// so release signatures are generated against the final names.
let addons = HEMTT_OUT.join("addons");
for entry in addons.list() {
    if entry.is_file() {
        let name = entry.file_name();
        if name.ends_with(".pbo") && name.starts_with("PTF_") {
            let new_name = name.sub_string(4);
            entry.move(addons.join(new_name));
            print("renamed " + name + " -> " + new_name);
        }
    }
}
