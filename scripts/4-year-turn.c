// Created by MuaazH <muaaz.h.is@gmail.com> on 2018-01-06.
// This scripts adds 4 more years to each turn

#include <tccdefs.h>
#include <scripthook.h>

static const int turn = 4;

void age_characters() {
    // age characters
    FactionsData *pData = rtw_get_faction_data();
    for (int i = 0; i < pData->factionCount; ++i) {
        Faction *pFaction = pData->sortedFactions[i];
        int count = pFaction->characters.size;
        for (int j = 0; j < count; ++j) {
            Character *pChar = pFaction->characters.buffer[j];
            if (pChar->person)
                pChar->person->age += turn;
        }
    }
}

void on_end_of_turn(GameDate *date) {
    // move time forward
    date->year += turn;
    age_characters();
    // todo: age faction women (Find a better list)
    // todo: fix missions by moving their dates forward by the same amount, so that their length in turns remains the same
}

