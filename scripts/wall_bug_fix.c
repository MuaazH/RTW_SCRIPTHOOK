// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03
// This script fixes the wall bug where cities with destroyed walls are rendered with walls

#include <scripthook.h>

void on_init() {
    Regions *pRegions = rtw_get_regions();
    int count = pRegions->regionsCount;
    for (int i = 0; i < count; ++i) {
        Settlement *pSettlement = pRegions->regions[i].settlement;
        if (!pSettlement)
            continue; // The sea has no settlement
        if (pSettlement->buildings.byType[BUILDING_TYPE_WALL])
            continue;
        pSettlement->wall3dModel = 0;
    }
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_init);
}