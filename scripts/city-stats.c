// Created by MuaazH <muaaz.h.is@gmail.com> on 2018-01-06.
// This mod changes a few city stats

#include <tccdefs.h>
#include <scripthook.h>

//void on_city_population_stats(CityStats *pStats) {
//    if (pStats->population.decline.squalor >= 2)
//        pStats->population.decline.squalor -= 2;
//}

void on_city_order_stats(CityStats *pStats) {
    pStats->order.negative.culture <<= 1; // times 2 if any
    pStats->order.negative.noGovernor <<= 1; // times 2 if any
    pStats->order.positive.garrison <<= 2; // times 2
}

void on_city_income_stats(CityStats *pStats) {
    pStats->spending.devastation <<= 1; // times 2
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_city_order_stats);
    EXPORT_HOOK(on_city_income_stats);
}
