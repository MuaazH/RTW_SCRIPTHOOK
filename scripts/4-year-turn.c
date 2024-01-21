// Created by MuaazH <muaaz.h.is@gmail.com> on 2018-01-06.
// This scripts adds 4 more years to each turn
// Requested by: Sarmatian Smilodon

#include <tccdefs.h>
#include <scripthook.h>
#include <str_builder.h>

static const char *SCRIPT = "scripts/4-year-turn.c";
static const int turn = 4;

void on_init() {
    char buf[128];
    StrBuilder sb = NEW_STRING_BUILDER(buf, sizeof(buf));

    FactionsData *pData = rtw_get_faction_data();
    if (!pData)
        return;

    for (int i = 0; i < pData->factionCount; ++i) {
        Faction *pFaction = pData->sortedFactions[i];
        if (!pFaction)
            continue;
        int peopleCount = pFaction->persons.size;

        sb_reset(&sb);
        sb_str(&sb, pFaction->info->name);
        sb_str(&sb, ", ");
        sb_i32(&sb, peopleCount);
        rtw_log(SCRIPT, buf);

        for (int j = 0; j < peopleCount; ++j) {
            if (!pFaction->persons.buffer) {
                rtw_log(SCRIPT, "Null buffer found");
                continue;
            }

            Person *pPerson = pFaction->persons.buffer[j];
                pPerson->age -= 20;

            sb_reset(&sb);
            sb_str(&sb, "    ");
            sb_i32(&sb, pPerson->age);
            rtw_log(SCRIPT, buf);
        }
    }
}

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

