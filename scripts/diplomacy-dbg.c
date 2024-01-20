// Created by MuaazH <muaaz.h.is@gmail.com> on 2014-07-13.
// dbg

#include <tccdefs.h>
#include <scripthook.h>
#include <str_builder.h>

const char *SCRIPT = "scripts/diplomacy-dbg.c";

void pad(StrBuilder *sb, int len) {
    while (sb->cur < len)
        sb_chr(sb, ' ');
}

void logDiplomacy() {
    char buf[1024];
    StrBuilder sb = NEW_STRING_BUILDER(buf, sizeof(buf));

    rtw_log(SCRIPT, "============================");
    FactionsData *pData = rtw_get_faction_data();
    int player = pData->factions[0]->id;
    int count = pData->factionCount;
    for (int i = 0; i < count; ++i) {
        if (i == player) continue;
        Faction *faction = pData->sortedFactions[i];
        Diplomacy *diplomacy = rtw_get_diplomacy(i, player);
        sb_reset(&sb);
        sb_str(&sb, faction->info->name);
        int pos = 50;
        int *pVal = &diplomacy->hate;
        for (int j = 0; j < 24; ++j) {
            pad(&sb, pos);
            pos += 12;
            if (pVal[j])
                sb_i32(&sb, pVal[j]);
        }
        rtw_log(SCRIPT, buf);
    }
    rtw_log(SCRIPT, "============================");
}

void on_init() {
    logDiplomacy();
}

void on_end_of_turn(GameDate *date) {
    logDiplomacy();
}
