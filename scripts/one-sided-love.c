// Created by MUAAZ on 2024-01-07
// One sided love from the gauls to the julii
// This love will be reset every end of turn to full allied status

#include <tccdefs.h>
#include <scripthook.h>

static int julii = -1;
static int gauls = -1;

void loveJ() {
    if (julii < 0 || gauls < 0) return;
    Diplomacy * gaulsDiplomacy = rtw_get_diplomacy(gauls, julii);
    gaulsDiplomacy->hate = 0; // tho shall love red idiots
    gaulsDiplomacy->relationship = 0; // allied
}

void on_init() {
    julii = rtw_faction_get_by_name("romans_julii")->id;
    gauls = rtw_faction_get_by_name("gauls")->id;
	loveJ();
}

void on_advance_time(GameDate *date) {
	loveJ();
}
