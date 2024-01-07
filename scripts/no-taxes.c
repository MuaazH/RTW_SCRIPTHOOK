// Created by MUAAZ on 2018-02-14.
// This mod converts "Low tax Rate" into "No tax"

#include <tccdefs.h>
#include <scripthook.h>

void on_city_population_stats(City *pCity, CityStats *pStats) {
    if (!pCity->settlement)
        return;
    int taxRate = pCity->settlement->taxRate;
    if (taxRate)
        return; // on works when taxes is set to low
    pStats->population.growth.taxes = 5;
    pStats->population.decline.taxes = 0;
    pStats->population.decline.taxes2 = 0;
    pStats->population.decline.taxes3 = 0;
    pStats->population.decline.taxes4 = 0;
}

void on_city_order_stats(City *pCity, CityStats *pStats) {
    if (!pCity->settlement)
        return;
    int taxRate = pCity->settlement->taxRate;
    if (taxRate)
        return; // on works when taxes is set to low
    pStats->order.positive.taxes = 20;
    pStats->order.negative.taxes = 0;
}

void on_city_income_stats(City *pCity, CityStats *pStats) {
    if (!pCity->settlement)
        return;
    int taxRate = pCity->settlement->taxRate;
    if (taxRate)
        return; // on works when taxes is set to low
    pStats->income.taxes = 0;
    pCity->faction->outdatedTreasury = 1; // tell RTW that there is a Windows Update I mean treasury update. wow this is a long comment. In one line. No breaks. Someone will read this crap one day. Email me if you have line-wrap turned off and you read all of this, muaaz.h.is@gmail.com
}