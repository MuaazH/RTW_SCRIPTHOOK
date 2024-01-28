// Created by MuaazH <muaaz.h.is@gmail.com> on 2016-02-14.
// This script gives all units full upgrades at the end of turn

#include <scripthook.h>

void upgrade_armies(Faction *pFaction) {
    unsigned int armiesCount = pFaction->armies.size;
    for (unsigned int j = 0; j < armiesCount; ++j) {
        Army *pArmy = pFaction->armies.buffer[j];

        for (unsigned int k = 0; k < pArmy->units.size; ++k) {
            ArmyUnit *pUnit = pArmy->units.buffer[k];
            int men = pUnit->soliderCount;
            SoliderUpgrades *ug = pUnit->upgrades;
            for (int i = 0; i < men; ++i) {
                ug->armor = 3;
                ug->weapons = 3;
                ug->xp = 9;
                ug++;
            }
            rtw_unit_update_upgrades_cache(pUnit);
        }
    }
}

void on_end_of_turn() {
    Campaign *pCampaign = rtw_get_campaign();
    for (int i = 0; i < pCampaign->factionCount; ++i)
        upgrade_armies(pCampaign->factions[i]);
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_end_of_turn);
}