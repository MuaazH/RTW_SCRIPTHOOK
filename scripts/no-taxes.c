// Created by MUAAZ on 2018-02-14.
// This mod converts "Low tax Rate" into "No tax"

#include <tccdefs.h>
#include <scripthook.h>

static int taxOrderEffect[] = {
        4,  // low
        -2, // normal
        -5, // high
        -12 // very high
};

static int positive_only(int x) {
    return x < 0 ? 0 : x;
}

static int oldTaxMul;

/**
 * Called from scripthook.asi
 */
void on_init() {
    oldTaxMul = rtw_get_tax_multiplier(0);
    rtw_set_tax_multiplier(0, 0); // now low tax generates 0 dinarii
}

void on_destroy() {
    rtw_set_tax_multiplier(0, oldTaxMul); // restore the game to the way it was
}

void on_city_population_stats(CityStats *pStats) {
    if (!pStats->settlement)
        return;
    int taxRate = pStats->settlement->taxRate;
    if (taxRate)
        return; // on works when taxes is set to low
    pStats->population.growth.taxes = 4;
    pStats->population.decline.taxes = 0;
    pStats->population.decline.taxes2 = 0;
    pStats->population.decline.taxes3 = 0;
    pStats->population.decline.taxes4 = 0;
}

void on_city_order_stats(CityStats *pStats) {
    if (!pStats->settlement)
        return;
    int taxRate = pStats->settlement->taxRate;
    if (taxRate < 0 || 3 < taxRate)
        return; // out of supported range
    int effect = taxOrderEffect[taxRate];
    pStats->order.positive.taxes = positive_only(effect);
    pStats->order.negative.taxes = positive_only(-effect);
}

// not needed, see on_init and on destroy
//void on_city_income_stats(CityStats *pStats) {
//    if (!pStats->settlement)
//        return;
//    int taxRate = pStats->settlement->taxRate;
//    if (taxRate)
//        return; // on works when taxes is set to low
//    pStats->income.taxes = 0;
//}
