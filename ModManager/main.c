// Created by MuaazH <muaaz.h.is@gmail.com> on 2024-02-01
// This file was generated by RTW ScriptHook Mod Manager
// DO NOT EDIT THIS FILE

#include <tccdefs.h>

const char *active_scripts[] = {
// BEGIN: SCRIPT LIST


















// END: SCRIPT LIST

        0 // THE LAST THING ON THE LIST, DO NOT REMOVE
};


int get_script_count() {
    int count = 0;
    while (active_scripts[count])
        count++;
    return count;
}

const char *get_script(int index) {
    return active_scripts[index];
}