//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

enum {
    BUILDING_TYPE_CORE = 0,
    BUILDING_TYPE_WALL,
    BUILDING_TYPE_BARRACKS,
    BUILDING_TYPE_MARKET = 5,
    BUILDING_TYPE_PORT = 7,
    BUILDING_TYPE_SEWERS,
    BUILDING_TYPE_FARM,
    BUILDING_TYPE_ROAD,
    BUILDING_TYPE_COUNT = 64
};

enum {
    RECRUITMENT_TYPE_ARMY_UNIT = 1,
    RECRUITMENT_TYPE_AGENT = 2
};

struct BuildingTypeList {
    BuildingType *array;                  // offset 0x00
    BuildingTypeList *next;               // offset 0x04
    BuildingTypeList *parent;             // offset 0x08
    int capacity;                         // offset 0x0C
    int size;                             // offset 0x10
};

struct BuildingLevel { // size 1E0 = 480
    int unknown0[0x71];
    void *restrictions;    // offset 0x1C4
    unsigned short cost;   // offset 0x1C8
    unsigned short turns;  // offset 0x1CA
    int requiredCityLevel; // offset 0x1CC
    int unknown1;
    RecruitmentCapability *recruitmentCapability;
    int unknown2[2];
};

struct RecruitmentCapability {
    /**
     * can be RECRUITMENT_TYPE_UNIT or RECRUITMENT_TYPE_AGENT
     */
    int type;
    int unknown04;
    int unknown08;
    int unknown0C;
    union {
        int unitTypeIndex;
        int agentRole;
    };
    void *condition;
    RecruitmentCapability *next;
};

struct BuildingType { // size 0x84 = 132
    void *_cpp_class;       // offset 0x00 (I should've done this with everything instead of calling it unknown)
    int unknown0[4];
    int type;               // offset 0x14  see BUILDING_TYPE_*
    int unknown1[17];
    char isWall;
    char isPort;
    char isCore;
    int unknown2;
    int unknown3;
    const char *name;       // offset 0x68
    int unknown4;
    BuildingLevel *levels;  // offset 0x70
    void *restrictions;     // offset 0x74
    int levelCount;         // offset 0x78
    int unknown5[2];
};

struct Building {
    int unknown0[11];
    BuildingType *type;        // offset 0x2C
    unsigned char level;       // offset 0x30
    int unknown1[5];
    int buildByFaction;        // offset 0x48
    int health;                // offset 0x4C
    int unknown2[4];
    Settlement *settlement;    // offset 0x60
};