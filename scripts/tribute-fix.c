// Created by MuaazH <muaaz.h.is@gmail.com> on 2016-02-14.
// This script fixes tribute where the AI does not pay on
// the last yearsInTurn, because the value is cleared (when the
// turns left is less than 1) before the payment is processed


#include <tccdefs.h>
#include <scripthook.h>

// Shit used for logging
static const char *SCRIPT = "tribute-fix.c";
static void *badCodeAddress = (void *) 0x005AC822;

void check_tribute() {
    Campaign *pCampaign = rtw_get_campaign();
    unsigned int count = pCampaign->factionCount;
    for (unsigned int i = 0; i < count; i++)
        for (unsigned int j = 0; j < count; j++) {
            if (i == j) continue; // Skip faction's relations to itself
            Diplomacy *dip = rtw_get_diplomacy((int) i, (int) j);
            if (dip->receivedTribute.amount && dip->receivedTribute.turns < 1) {
                dip->receivedTribute.amount = 0; // clear the amount now that it has been processed
                pCampaign->sortedFactions[i]->outdatedTreasury = 1; // tell the game to update the projection report for both factions
                pCampaign->sortedFactions[j]->outdatedTreasury = 1; // tell the game to update the projection report for both factions
            }
        }
}

void on_init() {
    // nop the instruction that clears the tribute before it has been processed
    if (!rtw_update_mem(badCodeAddress, "C7 41 3C 00000000", "90 90 90 90909090")) { // patch game code
        rtw_log(SCRIPT, "Failed to update memory");
    }
    check_tribute();
}

void on_destroy() {
    if (!rtw_update_mem(badCodeAddress, "90 90 90 90909090", "C7 41 3C 00000000")) { // restore original code
        rtw_log(SCRIPT, "Failed to update memory");
    }
}

void on_end_of_turn() {
    check_tribute();
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_init);
    EXPORT_HOOK(on_destroy);
    EXPORT_HOOK(on_end_of_turn);
}