// Author: MuaazH

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
