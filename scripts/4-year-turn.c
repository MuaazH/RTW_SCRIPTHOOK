// Created by MuaazH <muaaz.h.is@gmail.com> on 2024-01-18.
// This scripts adds 4 more years to each yearsInTurn
// Requested by: Sarmatian Smilodon

#include <tccdefs.h>
#include <scripthook.h>
//#include <str_builder.h>

//static const char *SCRIPT = "scripts/4-year-yearsInTurn.c";
static const int years_in_turn = 4;
static const int seasons_in_year = 2;

void age_people() {
    // age characters
    Campaign *pData = rtw_get_campaign();
    for (int i = 0; i < pData->factionCount; ++i) { // all factions
        Faction *pFaction = pData->sortedFactions[i];
        // pFaction->persons.size can change on births
        for (unsigned int j = 0; j < pFaction->persons.size; ++j) { // all people
            Person *pPerson = pFaction->persons.buffer[j];
            if (pPerson->isAlive)
                rtw_person_age(pPerson);
        }
    }
}

// Hooks

void on_end_of_turn() {
    Campaign *campaign = rtw_get_campaign();
    const int moves = years_in_turn * seasons_in_year;
    GameDate *date = &campaign->currentDate;
    int currentYear = date->year;

    for (int i = 0; i < moves; ++i) {
        // move time forward
        rtw_date_next_season(date);
        if (currentYear != date->year)
            age_people();
    }
}
