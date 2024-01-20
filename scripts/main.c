// Created by MuaazH <muaaz.h.is@gmail.com> on 2010-02-14.
// this is the main script, it's a unique script use to loader other scripts
// it is recompiled and called everytime you start/load a campaign game

#include <tccdefs.h>

const char *active_scripts[] = {
        "scripts/sticky-fort.c",
        "scripts/tribute-fix.c",
//        "scripts/larger-population.c",
//        "scripts/no-taxes.c",
//        "scripts/demolition.c",
//        "scripts/diplomacy-dbg.c",
//        "scripts/damaged-buildings.c"
//        "scripts/gaza.c"
//        "scripts/total-piss.c",
//        "scripts/war-on-trespassing.c",
//        "scripts/debts.c",
//        "scripts/blockade.c",
//        "scripts/demolition.c",
//        "scripts/building-maintenance.c",
//        "scripts/one-sided-love.c",
//        "scripts/city-stats.c",
//        "scripts/dbg-building-types.c",







// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT
// DO NOT EDIT ANYTHING AFTER THIS COMMENT



        0 // THE LAST THING ON THE LIST, DO NOT REMOVE
};


int get_script_count() {
//    return sizeof(active_scripts) / sizeof(void *);
    int count = 0;
    while (active_scripts[count])
        count++;
    return count;
}

const char *get_script(int index) {
    return active_scripts[index];
}
