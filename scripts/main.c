// This script fixes tribute where the AI does not pay on
// the last turn, because the value is cleared (when the turns left is less than 1) before the payment is proccessed
// Author: MuaazH

#include <tccdefs.h>

const char *active_scripts[] = {
//        "scripts/tribute-fix.c",
//        "scripts/total-piss.c",
//        "scripts/war-on-trespassing.c",
//        "scripts/damaged-buildings.c",
//        "scripts/city-model-fix.c",
//        "scripts/debts.c",
//        "scripts/over-population.c",
//        "scripts/blockade.c",
//        "scripts/demolition.c",
//        "scripts/building-maintenance.c",
//        "scripts/no-taxes.c",
//        "scripts/one-sided-love.c",
//        "scripts/city-stats.c"
        "scripts/dbg-building-types.c"
};

int get_script_count() {
    return sizeof(active_scripts) / sizeof(void *);
}

const char *get_script(int index) {
    return active_scripts[index];
}
