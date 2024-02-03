// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-01-25.
// This mod makes generals give birth to boys only
// This allows you to keep power within your family
// And also allows you to keep the clan name (last name) alive

#include <scripthook.h>

int on_baby_gender_coin_flip(Character *father) {
    return OPTION_BOY;
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_baby_gender_coin_flip);
}
