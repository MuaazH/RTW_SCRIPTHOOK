// Created by MuaazH <muaaz.h.is@gmail.com> on 2024-01-22.
// This script is a cheat for testing purposes

#include <tccdefs.h>
#include <scripthook.h>

void on_city_population_stats(CityStats *pStats) {
    pStats->population.decline.plague = 0;
    pStats->population.decline.squalor = 0;
    pStats->population.decline.taxes = 0;
}

void on_city_order_stats(CityStats *pStats) {
    pStats->order.negative.squalor = 0;
    pStats->order.negative.taxes = 0;
    pStats->order.negative.culture = 0;
    pStats->order.negative.unrest = 0;
    pStats->order.negative.underpopulation = 0;
    pStats->order.negative.distanceToCapital = 0;
    pStats->order.negative.noGovernor = 0;
    pStats->order.negative.blockaded = 0;
    pStats->order.negative.besieged = 0;
}
