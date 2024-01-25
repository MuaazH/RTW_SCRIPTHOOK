// Created by MuaazH <muaaz.h.is@gmail.com> on 2024-01-25.
// This mod makes generals people multiply like rabbits

#include <tccdefs.h>
#include <scripthook.h>

void on_init() {
    rtw_set_fertility_multiplier(50000.0f);
}

void on_destroy() {
    rtw_set_fertility_multiplier(1.0f);
}
