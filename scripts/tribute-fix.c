// Created by MuaazH <muaaz.h.is@gmail.com> on 2016-02-14.
// This script fixes tribute where the AI does not pay on
// the last turn, because the value is cleared (when the
// turns left is less than 1) before the payment is processed

// This mod is for 1.5, it does not work on 1.9 and I'm not sure if its needed anyway

#include <tccdefs.h>
#include <scripthook.h>

// Shit used for logging
static const char *SCRIPT = "tribute-fix.c";

//void check_tribute() {
//	FactionsData *pFactionData = rtw_get_faction_data();
//    int count = pFactionData->factionCount;
//    for (int i = 0; i < count; i++)
//        for (int j = 0; j < count; j++) {
//            if (i == j) continue; // Skip faction's relations to itself
//            Diplomacy *dip = rtw_get_diplomacy(i, j);
//            if (dip->receivedTribute.amount && dip->receivedTribute.turns < 1) {
//                dip->receivedTribute.amount = 0; // clear the amount now that it has been processed
//				pFactionData->sortedFactions[i]->outdatedTreasury = 1; // tell the game to update the projection report for both factions
//				pFactionData->sortedFactions[j]->outdatedTreasury = 1; // tell the game to update the projection report for both factions
//            }
//        }
//}

void on_init() {
//	// nop the instruction that clears the tribute before it has been processed
//    if (!rtw_update_mem((void *) 0x005AA60E, "C7 41 3C 00000000", "90 90 90 90909090")) { // patch game code
//        rtw_log(SCRIPT, "Failed to update memory");
//    }
    check_tribute();
}

void on_destroy() {
//    if (!rtw_update_mem((void *) 0x005AA60E, "90 90 90 90909090", "C7 41 3C 00000000")) { // restore original code
//        rtw_log(SCRIPT, "Failed to update memory");
//    }
}

void on_end_of_turn(GameDate *date) {
    check_tribute();
}
