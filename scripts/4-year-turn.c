// Created by MuaazH <muaaz.h.is@gmail.com> on 2018-01-06.
// This scripts adds 4 more years to each turn
// Requested by: Sarmatian Smilodon

#include <tccdefs.h>
#include <scripthook.h>

static const int turn = 4;

void age_people() {
    // age characters
    FactionsData *pData = rtw_get_faction_data();
    for (int i = 0; i < pData->factionCount; ++i) {
        Faction *pFaction = pData->sortedFactions[i];
        int count = pFaction->persons.size;
        for (int j = 0; j < count; ++j) {
            Person *pPerson = pFaction->persons.buffer[j];
            if (pPerson->isAlive)
                pPerson->age += turn;
        }
    }
}

void on_end_of_turn(GameDate *date) {
    // move time forward
    date->year += turn;
    age_people();
}

