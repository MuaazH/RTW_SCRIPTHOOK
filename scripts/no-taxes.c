// Created by MuaazH <muaaz.h.is@gmail.com> on 2016-02-14.
// This mod converts "Low tax Rate" into "No tax"

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

static const WCHAR *oldDescription = L"Low tax rate";
static const WCHAR *newDescription = L"No taxes"; // MUST be shorter or equal to original
static PTextEntry *pDescription = 0;


/**
 * Called from scripthook.asi
 */
void on_init() {
    pDescription = rtw_translate(stratDictionary, "SMT_TAX_LEVEL_LOW");
    if (pDescription && *pDescription) {
        rtw_update_text(pDescription, newDescription);
    }

    oldTaxMul = rtw_get_tax_multiplier(0);
    rtw_set_tax_multiplier(0, 0); // now low tax generates 0 dinarii
}

/**
 * Just trying to be fancy and restoring the game to original state
 */
void on_destroy() {
    if (pDescription)
        rtw_update_text(pDescription, oldDescription);
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

void init_hooks(Script *script) {
    EXPORT_HOOK(on_city_order_stats);
    EXPORT_HOOK(on_city_population_stats);
    EXPORT_HOOK(on_destroy);
    EXPORT_HOOK(on_init);
}
