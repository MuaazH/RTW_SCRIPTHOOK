// Created by MuaazH <muaaz.h.is@gmail.com> on 2010-02-14.
// this is the main script, it's a unique script used to loader other scripts
// it is recompiled and called everytime you start/load a campaign game

#include <tccdefs.h>

const char *active_scripts[] = {
        "scripts/sticky-fort.c",
        "scripts/tribute-fix.c",
//        "scripts/4-year-turn.c",
        "scripts/larger-population.c",
        "scripts/no-taxes.c",
        "scripts/demolition.c",
        "scripts/happy_cities_cheat.c",
        "scripts/marriage_at_17.c",
        "scripts/boys_only.c",
        "scripts/long_life.c",
//        "scripts/rabbits.c",







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
