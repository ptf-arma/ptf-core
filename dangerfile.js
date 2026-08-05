// PTF Core PR hygiene bot (Danger). It posts ONE friendly comment on each PR
// with gentle reminders — it does NOT block merging (that's what CI + review
// are for). Aimed at helping newer contributors get PRs review-ready.
//
// Runs in CI via .github/workflows/pr-checks.yml. Edit the rules below freely.

const pr = danger.github.pr;
const body = pr.body || "";
const touched = danger.git.modified_files
  .concat(danger.git.created_files)
  .concat(danger.git.deleted_files);

const touches = (re) => touched.some((f) => re.test(f));

// 1. Describe the change. A blank/one-word description makes review slow.
if (body.replace(/<!--[\s\S]*?-->/g, "").trim().length < 20) {
  warn(
    "The PR description looks empty. A sentence or two on **what** changed and " +
      "**why** helps reviewers a lot — see the template headings."
  );
}

// 2. Link the issue so it auto-closes and reviewers have context.
if (!/#\d+/.test(body)) {
  warn(
    "No issue linked. If this addresses one, add `Closes #123` so it links up " +
      "and closes automatically when merged."
  );
}

// 3. Keep PRs small and focused — easier and faster to review.
const size = pr.additions + pr.deletions;
if (pr.changed_files > 30 || size > 800) {
  warn(
    `This is a large PR (${pr.changed_files} files, ~${size} lines). If it's ` +
      "doing more than one thing, splitting it makes review much easier."
  );
}

// 4. Visual changes need a screenshot to review without loading the game.
const visual = /addons\/PTF_(Textures|Clothes|Helmets|Models|Vehicles|Aircraft|Utility)\//;
if (touches(visual) && !/!\[|<img/i.test(body)) {
  warn(
    "This touches visual content (uniform/vehicle/model/texture) but I don't " +
      "see a screenshot. Please paste a before/after so it can be reviewed."
  );
}

// 5. Build output should never be committed — it's rebuilt from source.
const pbo = danger.git.created_files.filter((f) => /\.pbo$/i.test(f));
if (pbo.length) {
  fail(
    "A `.pbo` build artifact was committed:\n" +
      pbo.map((f) => `- \`${f}\``).join("\n") +
      "\nRemove it — PBOs are built by HEMTT, not tracked in git."
  );
}

// 6. Base branch sanity: feature PRs go into develop, not master.
if (pr.base.ref === "master" && pr.head.ref !== "develop") {
  warn(
    "This PR targets **master**. Feature work should target **develop** — " +
      "`master` is only updated by a develop→master release merge."
  );
}
