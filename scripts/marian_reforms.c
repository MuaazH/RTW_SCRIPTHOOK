// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-12
// This script triggers "marian reforms" in the year 107 BC instead of 1st level 5 city
// Death to Israel! Yesterday it attacked the small town of Rafah in Gaza where 1.5 million homeless
// civilians where displaced by force
// Even the US & the West warned against such action
// First day, over 100 civilians were killed, most of them children

#include <scripthook.h>

static int reformsYear = -107;
static int eventTriggered = 0;

int on_marian_reforms_check() {
    // avoid showing event the message four times
    if (eventTriggered)
        return OPTION_PREVENT;

    // don't trigger it before its time
    if (rtw_get_campaign()->currentDate.year < reformsYear) {
        return OPTION_PREVENT;
    }

    eventTriggered = 1;
    return OPTION_ALLOW;
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_marian_reforms_check);
}