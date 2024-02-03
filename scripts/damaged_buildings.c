// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03
// This mod destroys buildings that have taken 100% damage

#include <scripthook.h>
//#include <str_builder.h>
//const char *SCRIPT = "damaged-buildings.c";

struct Building *queued = 0;

void destroy_queued() {
    if (!queued)
        return;
    rtw_building_destroy(queued);
    queued = 0;
}

void on_building_take_damage(Building *building) {
    // We can't destroy the building right here, we must wait for other functions to return
    destroy_queued();
    if (building->health == 0)
        queued = building;
}

void on_campaign_tick() {
    destroy_queued();
}

//void on_end_of_turn() {
//    Regions *pRegions = rtw_get_regions();
//    int count = pRegions->regionsCount;
//
//    for (int i = 0; i < count; ++i) {
//        Settlement *pSettlement = pRegions->regions[i].settlement;
//        if (!pSettlement)
//            continue; // The sea has no settlement
//        for (int j = 0; j < BUILDING_TYPE_COUNT; ++j) {
//            Building *pBuilding = pSettlement->buildings.list[j];
//            if (!pBuilding)
//                break;
//            if (pBuilding->health)
//                continue;
//            rtw_building_destroy(pBuilding);
//            j--;
//        }
//    }
//}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_building_take_damage);
    EXPORT_HOOK(on_campaign_tick);
}
