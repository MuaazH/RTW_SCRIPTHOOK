// Created by MuaazH <muaaz.h.is@gmail.com> on 2024-01-19.
// This script prevents fort despawn
// Requested by: Solon de Atenas

#include <scripthook.h>

int on_fort_despawn(Fort *fort) {
	return OPTION_PREVENT; //
}

void init_hooks(Script *script) {
    EXPORT_HOOK(on_fort_despawn);
}