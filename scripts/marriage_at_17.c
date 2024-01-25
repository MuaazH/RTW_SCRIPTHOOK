// Created by MuaazH <muaaz.h.is@gmail.com> on 2024-01-25.
// This script forces every general to get married at the age of 17

#include <tccdefs.h>
#include <scripthook.h>

int on_marriage_coin_flip(Character *character) {
    return character->person->age >= 17
        ? OPTION_ALLOW
        : OPTION_PREVENT;
}
