// Created by MuaazH <muaaz.h.is@gmail.com> on 2016-02-14.
// This mod makes cities x4 times larger in population
// This should make the game a bit slower since you can't
// grow a small town to huge city in five years

#include <tccdefs.h>
#include <scripthook.h>
//#include <str_builder.h>

//const char *SCRIPT = "larger-population.c";
const int multiplier = 4;

void on_init() {
//    char buf[128];
//    StrBuilder sb = NEW_STRING_BUILDER(buf, sizeof(buf));

    for (int i = 0; i < 6; ++i) {
        PopulationLimits *p = rtw_get_population_limits(i);
        p->overPopulationThreshold *= multiplier;
        p->nextLevel *= multiplier;
        p->levelMin *= multiplier;
//        sb_reset(&sb);
//        sb_str(&sb, ">> LEVEL ");
//        sb_i32(&sb,i);
//        sb_str(&sb, ": ");
//        sb_i32(&sb,p->levelMin);
//        sb_str(&sb, " ");
//        sb_i32(&sb,p->nextLevel);
//        sb_str(&sb, " ");
//        sb_i32(&sb,p->absoluteMinimum);
//        sb_str(&sb, " ");
//        sb_i32(&sb,p->overPopulationThreshold);
//        rtw_log(SCRIPT, buf);
    }
}

void on_destroy() {
    for (int i = 0; i < 6; ++i) {
        PopulationLimits *p = rtw_get_population_limits(i);
        p->overPopulationThreshold /= multiplier;
        p->nextLevel /= multiplier;
        p->levelMin /= multiplier;
    }
}