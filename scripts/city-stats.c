//
// Created by MUAAZ on 2018-01-06.
//

#include <tccdefs.h>
#include <scripthook.h>

void on_city_population_stats(City *pCity, CityStats *pStats) {
    if (pStats->population.decline.squalor >= 2)
        pStats->population.decline.squalor -= 2;
}

void on_city_order_stats(City *pCity, CityStats *pStats) {
    pStats->order.negative.culture <<= 1; // times 2 if any
    pStats->order.negative.noGovernor <<= 1; // times 2 if any
    pStats->order.negative.squalor >>= 2; // div 2
    pStats->order.positive.garrison <<= 2; // times 2
}

void on_city_income_stats(City *pCity, CityStats *pStats) {
    pStats->spending.devastation <<= 1; // times 2
    pCity->faction->outdatedTreasury = 1; // force the faction to update income & spending
}
