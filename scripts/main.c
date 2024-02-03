// Created by MuaazH (muaaz.h.is@gmail.com) on 2010-02-14.
// this is the main script, it's a unique script used to loader other scripts
// it is recompiled and called everytime you start/load a campaign game

#include <tccdefs.h>

const char *active_scripts[] = {
        "sticky_fort.c",
        "tribute_fix.c",
        "larger_population.c",
        "no_taxes.c",
        "demolition.c",
        "happy_cities_cheat.c",
        "marriage_at_17.c",
        "boys_only.c",
        "long_life.c",
//        "golden_weapons.c",
        "damaged_buildings.c",
        "wall_bug_fix.c",







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
