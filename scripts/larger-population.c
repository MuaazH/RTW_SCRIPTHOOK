// Created by MuaazH <muaaz.h.is@gmail.com> on 2016-02-14.
// This mod makes cities x4 times larger in population
// This should make the game a bit slower since you can't grow a small town to huge city in five years


#include <scripthook.h>

const char *SCRIPT = "scripts/larger-population.c";
const int multiplier = 4;

float random() {
    return (float) (rtw_rand_s() & 0xFFFF) / 65535.0f;
}

int population_growth_total(CityStats *pStats) {
    return pStats->population.growth.health
           + pStats->population.growth.unitDisbands
           + pStats->population.growth.slavery
           + pStats->population.growth.foodImports
           + pStats->population.growth.farmUpgrades
           + pStats->population.growth.buildings
           + pStats->population.growth.baseFarmingLevel
           + pStats->population.growth.taxes;
}

int population_decline_total(CityStats *pStats) {
    return pStats->population.decline.squalor
           + pStats->population.decline.taxes
           + pStats->population.decline.taxes2
           + pStats->population.decline.taxes3
           + pStats->population.decline.taxes4
           + pStats->population.decline.disaster
           + pStats->population.decline.draft
           + pStats->population.decline.plague;
}

void on_init() {
    for (int i = 0; i < 6; ++i) {
        PopulationLimits *p = rtw_get_population_limits(i);
        p->overPopulationThreshold *= multiplier;
        p->nextLevel *= multiplier;
        p->levelMin *= multiplier;
    }
    PopulationLimits *lvl0 = rtw_get_population_limits(0);
    lvl0->levelMin = 400;
    lvl0->absoluteMinimum = 400;
}

void on_destroy() {
    for (int i = 0; i < 6; ++i) {
        PopulationLimits *p = rtw_get_population_limits(i);
        p->overPopulationThreshold /= multiplier;
        p->nextLevel /= multiplier;
        p->levelMin /= multiplier;
    }
}

void on_city_population_stats(CityStats *pStats) {
    if (!pStats->settlement) {
        return;
    }

    pStats->population.growth.health <<= 1; // times 2

    int level = pStats->settlement->level;
    PopulationLimits *limits = rtw_get_population_limits(level);

    // completely change the calculation function
    int penalty1 = (pStats->population.count * 8) / (limits->nextLevel);
    int penalty2 = (pStats->population.count * 10) / limits->overPopulationThreshold;
    int bonus1 = pStats->population.growth.health << 1;
    int squalor = (level - 1) + penalty1 + penalty2 - bonus1;
    pStats->population.decline.squalor = squalor < 0 ? 0 : squalor;

    // don't let the squalor blow up before reaching next level
    if (pStats->population.count < limits->nextLevel) {
        float scale = (float) pStats->population.count / (float) limits->nextLevel;
        // done this way to shut C-Lion up about clang bullshit without disabling warnings.
        pStats->population.decline.squalor = (int) ((float) pStats->population.decline.squalor * scale);
    }

}

void on_city_order_stats(CityStats *pStats) {
    pStats->order.negative.culture <<= 1; // times 2 if any
    pStats->order.negative.noGovernor <<= 2; // times 4 if any
    pStats->order.positive.health <<= 1; // times 2 if any
    pStats->order.negative.squalor = pStats->population.decline.squalor;
    if (pStats->order.negative.squalor < 0)
        pStats->order.negative.squalor = 0;
    if (pStats->order.negative.squalor > 10)
        pStats->order.negative.squalor = 10; // limit to 50%
}

//void dbg_growth(Settlement *pSettlement, int population, int percentage, int delta, int actual) {
//    char buf[128];
//    StrBuilder sb = NEW_STRING_BUILDER(buf, sizeof(buf));
//
//    sb_str(&sb, "Population of ");
//    if (pSettlement)
//        sb_str(&sb, pSettlement->name);
//    else
//        sb_str(&sb, "NULL");
//    sb_str(&sb, ": ");
//    sb_i32(&sb, population);
//    sb_str(&sb, " × ");
//    sb_i32(&sb, percentage >> 1);
//    if (percentage & 1)
//        sb_str(&sb, ".5 ");
//    sb_str(&sb, "% = ");
//    sb_i32(&sb, delta);
//    sb_str(&sb, " ; actual = ");
//    sb_i32(&sb, actual);
//    rtw_log(SCRIPT, buf);
//}

/**
 * called before a city increases it's population count
 * @return returns non-zero to block native function from being called
 */
int on_city_population_growth(CityStats *pStats) {
    // this is double the percentage because every 1 point is show as 0.5% in game
    int percentage = population_growth_total(pStats) - population_decline_total(pStats);

    // Cap max grow rate at 6%, as it is insane to have more than 6% grow rate
    int cappedPercentage = percentage > 12 ? 12 : percentage;
    int delta = (pStats->population.count * cappedPercentage) / 200;

    int guaranteed = (int) ((float) delta * 0.2f); // guarantee 20% of the change
    int chance = (int) ((float) (delta - guaranteed) * random()); // leave 80% to chance

    int total = guaranteed + chance;

//    dbg_growth(pStats->settlement, pStats->population.count, percentage, delta, total);
    pStats->population.count += total; // the plugin will cap the population to prevent issues

    return 1; // non-zero means don't call the native growth function
}


void init_hooks(Script *script) {
    EXPORT_HOOK(on_init);
    EXPORT_HOOK(on_destroy);
    EXPORT_HOOK(on_city_population_growth);
    EXPORT_HOOK(on_city_order_stats);
    EXPORT_HOOK(on_city_population_stats);
}
