// Release counterpart of post_build/01_pbo_names.rhai: after signing,
// strip the generated "PTF_" prefix from each PBO and its .bisign so the
// released files keep their historical "<folder>.pbo" names. Signatures
// stay valid because a .bisign covers the PBO contents, not its filename —
// only the .pbo/.bisign name pairing must be kept consistent.
let addons = HEMTT_OUT.join("addons");
for entry in addons.list() {
    if entry.is_file() {
        let name = entry.file_name();
        if name.contains(".pbo") && name.starts_with("PTF_") {
            let new_name = name.sub_string(4);
            entry.move(addons.join(new_name));
            print("renamed " + name + " -> " + new_name);
        }
    }
}
