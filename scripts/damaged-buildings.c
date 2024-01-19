// Created by MuaazH <muaaz.h.is@gmail.com> on 2016-02-14.
// This mod destroys buildings with 100% damage (Except city walls)

#include <tccdefs.h>
#include <scripthook.h>

const char *SCRIPT = "scripts/damaged-buildings.c";

/**
 * Called from scripthook.asi
 */
void on_end_of_turn(GameDate *pDate) {
    Region *region = rtw_get_region(48);
    if (!region) {
        return;
    }
    Settlement *settlement = region->settlement;
    if (!region->settlement)
        return;
    Building *barracks = settlement->buildings.byType[BUILDING_TYPE_BARRACKS];
    if (!barracks)
        return;
    rtw_building_destroy(barracks);
}
