// Created by MuaazH (muaaz.h.is@gmail.com) on 2023-10-07.
// This mod does to the world what jews do to Gaza

#include <scripthook.h>

/**
 * Called from scripthook.asi
 */
void on_end_of_turn() {
    for (int i = 0;; ++i) {
        Region *region = rtw_get_region(i);
        if (!region)
            break;
        Settlement *settlement = region->settlement;
        if (!region->settlement)
            continue;
        // destroy everything, vile animals.
        for (int j = BUILDING_TYPE_CORE; j < BUILDING_TYPE_COUNT; ++j) {
            Building *b = settlement->buildings.byType[j];
            if (b)
                rtw_building_destroy(b); // serves you right! 76 years of occupation and still going strong!
        }
    }
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_end_of_turn);
}
