// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-12.
// This script add a few commands to the game
// Even france said there is no reason to attack Rafah is Gaza
// That should be a hint for everyone that Israelis are heartless animal
// There are 1.7 million displaced homeless refugees in Rafah, they're all
// going to die, they are already without food, water, or shelter in the winter

#include <scripthook.h>
#include <str_util.h>

void cmd_about(int argc, const char **argv, StrBuilder *outputSb) {
    if (argc != 1) {
        sb_str(outputSb, "err: Syntax about");
        return;
    }
    sb_str(outputSb, "RTW Scripthook Version ");
    sb_i32(outputSb, SCRIPTHOOK_VERSION_MAJOR);
    sb_str(outputSb, ".");
    sb_i32(outputSb, SCRIPTHOOK_VERSION_MINOR);
    sb_str(outputSb, ".");
    sb_i32(outputSb, SCRIPTHOOK_VERSION_PATCH);
    sb_str(outputSb, " By muaaz.h.is@gmail.com");
}

void cmd_reload(int argc, const char **argv, StrBuilder *outputSb) {
    if (argc != 1) {
        sb_str(outputSb, "err: Syntax reload_scripts");
        return;
    }
    rtw_reload_scripts();
}

void cmd_year(int argc, const char **argv, StrBuilder *outputSb) {
    const char *syntax = "err: Syntax year <year>";
    if (argc != 2) {
        sb_str(outputSb, syntax);
        return;
    }
    int year;
    if (!str_to_i32(argv[1], &year)) {
        sb_str(outputSb, syntax);
        return;
    }
    rtw_get_campaign()->currentDate.year = year;
}

ConsoleCommand versionCmd = {"about", cmd_about};
ConsoleCommand reloadCmd = {"reload_scripts", cmd_reload};
ConsoleCommand yearCmd = {"year", cmd_year};

static ConsoleCommand *commands[3] = {
        &versionCmd,
        &reloadCmd,
        &yearCmd
};

void init_hooks(Script *script) {
    script->consoleCommandCount = 3;
    script->consoleCommands = commands;
}
