// Created by MuaazH <muaaz.h.is@gmail.com> on 2023-10-07 (A happy day)
// This mod enables demolition for all buildings (except roads & mines)
// Maybe I'll add mines later when I've figured out how to fix the visuals

#include <scripthook.h>
#include <str_builder.h>

const char *SCRIPT = "scripts/demolition.c";

/**
 * Called from scripthook.asi
 */
int on_demolition_check(Building *building) {
    if (!building->type)
        return OPTION_DEFAULT; // I ain't touch this shit

    BuildingType *type = building->type;

    // walls & core
    if (type->isWall || type->isCore)
        return OPTION_ALLOW;

    // farms
    if (type->type == BUILDING_TYPE_FARM)
        return OPTION_ALLOW;

    return OPTION_DEFAULT;
}

/**
 * Called from scripthook.asi
 */
void on_demolition(Settlement *settlement, Building *building) {
    // todo: remove me. I'm used for debug only
    char buf[128];
    StrBuilder sb = NEW_STRING_BUILDER(buf, sizeof(buf));
    sb_str(&sb, building->type->name);
    sb_str(&sb, " demolished in ");
    sb_str(&sb, settlement->name);
    rtw_log(SCRIPT, buf);
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_demolition_check);
    EXPORT_HOOK(on_demolition);
}

