// Created by MuaazH <muaaz.h.is@gmail.com> on 2017-05-20.
// This mod is a example on how to iterate building type declared in export_descr_buildings

#include <tccdefs.h>
#include <scripthook.h>
#include <str_builder.h>

static const char *SCRIPT = "dbg-building-types.c";

void on_init() {
    char buf[128];
    StrBuilder sb = NEW_STRING_BUILDER(buf, sizeof(buf));

    LinkedBuildingTypeList *list = rtw_get_building_types();
    while (list) {
        BuildingType *type = list->array;
        for (int i = 0; i < list->size; ++i, type++) {
            // format text
            sb_reset(&sb);
            sb_str(&sb, "Building type: ");
            sb_str(&sb,type->name);
            // print building name
            rtw_log(SCRIPT, buf);
        }
        list = list->next;
    }
}
