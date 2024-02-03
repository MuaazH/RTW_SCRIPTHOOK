// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-01-07
// This mod is a prank
// One sided love from the gauls to the julii
// This love will be reset every end of yearsInTurn to full allied status

#include <scripthook.h>

static int julii = -1;
static int gauls = -1;

static void loveJulii() {
    if (julii < 0 || gauls < 0) return;
    Diplomacy *gaulsDiplomacy = rtw_get_diplomacy(gauls, julii);
    gaulsDiplomacy->hate = 0; // tho shall love red idiots
    gaulsDiplomacy->relationship = 0; // allied
    Diplomacy *juliiDiplomacy = rtw_get_diplomacy(julii, gauls);
    juliiDiplomacy->tradeRights = 1;
    juliiDiplomacy->militaryAccess = 1;
    juliiDiplomacy->receivedTribute.amount = 2000;
    juliiDiplomacy->receivedTribute.turns = 20;
}

static int get_faction_id(const char *name) {
    Faction *faction = rtw_faction_get_by_name(name);
    return faction ? faction->id : -1;
}

/**
 * Called from scripthook.asi
 */
void on_init() {
    julii = get_faction_id("romans_julii");
    gauls = get_faction_id("gauls");
    loveJulii();
}

/**
 * Called from scripthook.asi
 */
void on_end_of_turn() {
    loveJulii();
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_end_of_turn);
    EXPORT_HOOK(on_init);
}