// Created by MuaazH <muaaz.h.is@gmail.com> on 2024-01-25.
// This mod makes generals people multiply like rabbits

#include <scripthook.h>

void on_init() {
    rtw_set_fertility_multiplier(50000.0f);
}

void on_destroy() {
    rtw_set_fertility_multiplier(1.0f);
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_destroy);
    EXPORT_HOOK(on_init);
}
