// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03
// This is a debug script that lists all units in the game

#include <scripthook.h>
#include <str_builder.h>

const char *SCRIPT = "unit_types.dbg.c";

void on_init() {
    char buf[128];
    StrBuilder sb = NEW_STRING_BUILDER(buf, sizeof(buf));
    int count = rtw_get_unit_types_count();
    UnitType *unitType = rtw_get_unit_types();
    for (int i = 0; i < count; ++i) {
        sb_reset(&sb);
        sb_i32(&sb, i);
        sb_str(&sb, " ");
        sb_str(&sb, unitType->type);
        rtw_log(SCRIPT, buf);
        unitType++;
    }
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_init);
}
