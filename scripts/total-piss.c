// This script is an epic prank that disbands all units for every one at
// the end of each the turn, turning the game into total peace instead of total war
// Generals will be left alone to manage the cities, also i don't know
// what will the game do if you disband a general unit

#include <tccdefs.h>
#include <scripthook.h>

void disband_faction_armies(Faction *pFaction) {
    ArmyArrayList *pArmyList = &pFaction->armies;
    int armiesCount = pArmyList->size;
    for (int j = 0; j < pArmyList->size; ++j) {
        Army *pArmy = pArmyList->buffer[j];

        for (int k = 0; k < pArmy->unitCount; ++k) {
            ArmyUnit *pUnit = pArmy->units[k];
            if (pUnit->general) continue; // this is a general unit
            int n = pArmy->unitCount;
            rtw_army_unit_disband(pUnit); // haha, so funny
            // check if the disband worked. Ships can't be disband at sea
            if (n > pArmy->unitCount)
                k--;
        }

        if (armiesCount > pArmyList->size) { // an army has been disband (there was no generals in it)
            j--;
            armiesCount = pArmyList->size;
        }
    }
}

void on_advance_time() {
    FactionsData *pData = rtw_get_faction_data();
    for (int i = 0; i < pData->factionCount; ++i)
        disband_faction_armies(pData->factions[i]);
}
