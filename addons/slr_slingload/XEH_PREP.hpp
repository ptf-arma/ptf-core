// testing, update fncs on the fly
//#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }

PREP(addACEActions);
PREP(adjustRigging);
PREP(attachCargo);
PREP(canAttachCargo);
PREP(canAdjustRigging);
PREP(cancelPlacement);
PREP(canReleaseCargo);
PREP(canRemoveRigging);
PREP(canRigCargo);
PREP(canRigCargoAuto);
PREP(canRigCargoManual);
PREP(checkLoad);
PREP(createHookRopes);
PREP(createRope);
PREP(destroyRope);
PREP(getCargoLiftPoints);
PREP(getHookPositions);
PREP(handleScrollWheel);
PREP(hookConflict);
PREP(hookRefused);
PREP(pickUpFitting);
PREP(releaseCargo);
PREP(removeRigging);
PREP(rigCargo);
PREP(rigCargoAuto);
PREP(rigCargoManual);
PREP(takeOverRopes);
