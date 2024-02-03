// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-01-26.
// This mod makes generals with higher command live longer

#include <scripthook.h>

int on_character_death_check(Character *character) {
    if (!character->person)
        return OPTION_DEFAULT; // no person pointer? I can't handle this

    if (character->person->age >= 120)
        return OPTION_ALLOW; // FORCE DEATH, this fool too old

    switch (character->type->role) {
        case ROLE_FAMILY_MEMBER:
            if (character->person->age < 70 + 3 * character->person->command + 2 * character->person->management)
                return OPTION_PREVENT;
            break;
        case ROLE_ASSASSIN:
        case ROLE_SPY:
            if (character->person->age < 65 + 4 * character->person->subterfuge)
                return OPTION_PREVENT;
            break;
        case ROLE_DIPLOMAT:
            if (character->person->age < 60 + 3 * character->person->influence)
                return OPTION_PREVENT;
            break;
    }
    return OPTION_DEFAULT;
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_character_death_check);
}
