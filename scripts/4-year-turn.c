// Created by MuaazH <muaaz.h.is@gmail.com> on 2024-01-18.
// This scripts adds 4 more years to each yearsInTurn
// Requested by: Sarmatian Smilodon

#include <tccdefs.h>
#include <scripthook.h>
//#include <str_builder.h>

//static const char *SCRIPT = "scripts/4-year-yearsInTurn.c";
static const int yearsInTurn = 4;

void age_people() {
    // age characters
    Campaign *pData = rtw_get_campaign();
    for (int i = 0; i < pData->factionCount; ++i) { // all factions
        Faction *pFaction = pData->sortedFactions[i];
        // pFaction->persons.size can change on births
        for (unsigned int j = 0; j < pFaction->persons.size; ++j) { // all people
            Person *pPerson = pFaction->persons.buffer[j];
            if (pPerson->health < 1)
                pPerson->health = 10; // this should make this man have more children, not sure about women tho
            if (pPerson->isAlive)
                rtw_person_age(pPerson, yearsInTurn);
        }
    }
}

// Hooks

void on_init() {
    rtw_set_instant_marriage(1);
    rtw_set_fertility_multiplier(4.0f);
}

void on_destroy() {
    rtw_set_fertility_multiplier(1.0f); // restore default value
}

void on_end_of_turn() {
    // move time forward
    rtw_get_campaign()->currentDate.year += yearsInTurn;
    // age clowns
    age_people();
}
