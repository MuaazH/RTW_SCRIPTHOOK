// Created by MuaazH <muaaz.h.is@gmail.com> on 2016-02-14.
// This script is an epic prank that disbands all units for every one at
// the end of each the yearsInTurn, turning the game into total peace instead of total war
// Generals will be left alone to manage the cities, but also because i don't know
// what will the game do if you disband a general unit, i never tested it.

#include <tccdefs.h>
#include <scripthook.h>

void disband_faction_armies(Faction *pFaction) {
    unsigned int armiesCount = pFaction->armies.size;
    for (unsigned int j = 0; j < armiesCount; ++j) {
        Army *pArmy = pFaction->armies.buffer[j];

        for (unsigned int k = 0; k < pArmy->units.size; ++k) {
            ArmyUnit *pUnit = pArmy->units.buffer[k];
            if (pUnit->general) continue; // this is a general unit
            unsigned int n = pArmy->units.size;
            rtw_army_unit_disband(pUnit); // haha, so funny
            // check if the disband worked. Ships can't be disband at sea
            if (n > pArmy->units.size)
                k--;
        }

        if (armiesCount > pFaction->armies.size) { // an army has been disband (there was no generals in it)
            j--;
            armiesCount = pFaction->armies.size;
        }
    }
}

void on_end_of_turn() {
    Campaign *pCampaign = rtw_get_campaign();
    for (int i = 0; i < pCampaign->factionCount; ++i)
        disband_faction_armies(pCampaign->factions[i]);
}
