//
// Created by MUAAZ on 2014-12-30.
//

#ifndef RTW_SCRIPT_HOOK_H
#define RTW_SCRIPT_HOOK_H

#ifdef SCRIPTHOOK_ASI
#define SCRIPTHOOK_API __declspec(dllexport)
#else
#define SCRIPTHOOK_API extern

// debug functions
extern int sprintf_s(char *_DstBuf, unsigned int _DstSize, const char *_Format, ...);
extern void rtw_log(const char *script, const char *msg);

#endif

#define SCRIPTHOOK_VERSION_MAJOR 2
#define SCRIPTHOOK_VERSION_MINOR 0
#define SCRIPTHOOK_VERSION_PATCH 1

#define OPTION_DEFAULT 0
#define OPTION_ALLOW 1
#define OPTION_PREVENT 2

typedef unsigned short WCHAR;
typedef struct Character Character;
typedef struct Settlement Settlement;
typedef struct Region Region;
typedef struct UnitType UnitType;
typedef struct SoliderUpgrades SoliderUpgrades;
typedef struct Army Army;
typedef struct ArmyUnit ArmyUnit;
typedef struct ArrayList ArrayList;
typedef struct ArmyUnitArrayList ArmyUnitArrayList;
typedef struct RegionArrayList RegionArrayList;
typedef struct ArmyArrayList ArmyArrayList;
typedef struct CharacterArrayList CharacterArrayList;
typedef struct SettlementArrayList SettlementArrayList;
typedef struct FactionsData FactionsData;
typedef struct Diplomacy Diplomacy;
typedef struct GameDate GameDate;
typedef struct Faction Faction;
typedef struct Treasury Treasury;
typedef struct RecruitmentSlot RecruitmentSlot;
typedef struct RecruitmentQueue RecruitmentQueue;
typedef struct ConstructionSlot ConstructionSlot;
typedef struct ConstructionQueue ConstructionQueue;
typedef struct Building Building;
typedef struct BuildingType BuildingType;
typedef struct BuildingLevel BuildingLevel;
typedef struct BuildingTypeList BuildingTypeList;
typedef struct CityBuildings CityBuildings;
typedef struct City City;
typedef struct CityStats CityStats;
typedef struct CultureData CultureData;
typedef struct CultureModels CultureModels;
typedef struct CultureCityModel CultureCityModel;
typedef struct PopulationLimits PopulationLimits;
typedef struct Dictionary Dictionary;
typedef struct Seaport Seaport;
typedef struct Person Person;
typedef struct Fort Fort;
typedef WCHAR **PTextEntry;

static Dictionary *sharedDictionary = (Dictionary *) 0x0275E518; // 1.9
static Dictionary *battleDictionary = (Dictionary *) 0x0275E51C; // 1.9
static Dictionary *diplomacyDictionary = (Dictionary *) 0x0275E524; // 1.9
static Dictionary *stratDictionary = (Dictionary *) 0x0275E520; // 1.9
static Dictionary *battleEdDictionary = (Dictionary *) 0x0275E528; // 1.9
static Dictionary *tooltipsDictionary = (Dictionary *) 0x0275E530; // 1.9
static Dictionary *menuEnglishDictionary = (Dictionary *) 0x0275E540; // 1.9
static Dictionary *extendedBiDictionary = (Dictionary *) 0x0275E544; // 1.9

enum {
    DS_ALLIED = 0,
    DS_SUSPICIOUS = 100,
    DS_NEUTRAL = 200,
    DS_HOSTILE = 400,
    DS_AT_WAR = 600
};

enum {
    ORIENTATION_EAST = 0xC000,
    ORIENTATION_SOUTH = 0x0000,
    ORIENTATION_WEST = 0x4000,
    ORIENTATION_NORTH = 0x8000
};

typedef int Season;

static const Season WINTER = 0;
static const Season SUMMER = 2;


enum {
    CULTURE_ROMAN = 0,
    CULTURE_BARBARIAN,
    CULTURE_CARTHAGINIAN,
    CULTURE_GREEK,
    CULTURE_EGYPTIAN,
    CULTURE_EASTERN,
    CULTURE_COUNT
};

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

struct ArrayList {
    void **buffer;           // A pointer to pointers
    int capacity;            // how much is allocated
    int size;                // how many are in the list
};

struct ArmyUnitArrayList {
    ArmyUnit **buffer;       // A pointer to pointers
    int capacity;            // how much is allocated
    int size;                // how many are in the list
};

struct RegionArrayList {
    Region **buffer;         // A pointer to pointers
    int capacity;            // how much is allocated
    int size;                // how many are in the list
};

struct ArmyArrayList {
    Army **buffer;           // A pointer to pointers
    int capacity;            // how much is allocated
    int size;                // how many are in the list
};

struct CharacterArrayList {
    Character **buffer;      // A pointer to pointers
    int capacity;            // how much is allocated
    int size;                // how many are in the list
};

struct SettlementArrayList {
    Settlement **buffer;     // A pointer to pointers
    int capacity;            // how much is allocated
    int size;                // how many are in the list
};

struct GameDate {
    int year;
    Season season;
};

struct FactionInfo {
    int unknown;
    const char *name;
};

struct Person {
    int unknown0;
    PTextEntry *name;
    int unknown1[9];
    int command;
    int influence;
    int management;
    int subterfuge;
    int unknown2[53];
    ArrayList retinue;
    int unknown3[23];
    GameDate birthDate;
    int unknown4[24];
    struct {
        int unknown5: 6;
        int age: 7;
    };
};

struct Character {
    int unknown0[3];
    int positionX;     // offset 0x00C
    int positionY;     // offset 0x010
    int unknown1;
    char isVisible;    // offset 0x018
    float opacity;     // offset 0x01C   0 to 1
    int unknown2[22];
    struct TextEntryData *name; // offset 0x078
    int unknown3[18];
    float movementPoints; // offset 0x0C4 (read only)
    int unknown4[7];
    Army *army;           // offset 0x0E4
    int unknown5[22];
    unsigned short orientation;
    int unknown6;
    float maxMovementPoints; // offset 0x0148
};

struct RecruitmentSlot {
    UnitType *type;
    int unknown0;
    Settlement *settlement;
    unsigned char turnsCompleted;
    unsigned char percentageCompleted;
    unsigned char turnsRequired;
    unsigned char unknown1;
    int unknown2[4];
};

struct RecruitmentQueue {
    RecruitmentSlot queue[9];
    int head;
    int tail;
    int size;
};

struct ConstructionSlot {
    int unknown0;             // 0x00
    int unknown1;             // 0x04
    int unknown2;             // 0x08
    Settlement *settlement;   // 0x0C
    int unknown3;             // 0x10
    int unknown4;             // 0x14
    int unknown5;             // 0x18
    int unknown6;             // 0x1C
    int turnsRequired;        // 0x20
    int turnsCompleted;       // 0x24
    int percentage;           // 0x28
    int unknown7;             // 0x2C
    int unknown8;             // 0x30
    int unknown9;             // 0x34
};

struct ConstructionQueue {
    ConstructionSlot queue[6];
    int head;
    int tail;
    int size;
};

struct CityStats {
    Settlement *settlement;
    struct {
        struct {
            int baseFarmingLevel;
            int farmUpgrades;
            int foodImports;
            int health;
            int buildings;
            int taxes;
            int unitDisbands;
            int slavery;
        } growth;
        struct {
            int squalor;
            int plague;
            int taxes;
            int disaster;
            int taxes2;
            int taxes3;
            int draft;
            int taxes4;
        } decline;
        int count;
    } population;
    struct {
        struct {
            int garrison;
            int law;
            int entertainmentBuildings;
            int governorInfluence;
            int taxes;
            int triumph;
            int wonder;
            int populationBoom;
            int entertainment;
            int health;
        } positive;
        struct {
            int squalor;
            int distanceToCapital;
            int culture;
            int noGovernor;
            int taxes;
            int unrest;
            int underpopulation;
            int besieged;
            int blockaded;
            int recession;
            int governorReligion;
            int factionLeaderReligion;
            int notUsed1;
            int notUsed2;
            int notUsed3;
        } negative;
        int value; // percentage like seen in the game ui
    } order;
    struct {
        int farms;
        int taxes;
        int mining;
        int trade;
        int diplomacy;
        int demolition;
        int looting;
        int buildings;
        int admin;
    } income;
    struct {
        int salaries;
        int army;
        int construction;
        int recruitment;
        int diplomacy;
        int corruption;
        int entertainment;
        int devastation;
    } spending;
};

struct City {
    Faction *faction;                    // offset in settlement is 0x0DD8
    Settlement *settlement;
    int farmingLevel;
    int unknown0[0xB];
    int prjSpendingSalaries;             // offset in settlement is 0x0E10
    int prjSpendingArmy;                 // offset in settlement is 0x0E14
    int unknown1[0x05];
    Settlement *settlement2;
    int unknown[0x6F];
    CityStats stats;
};

struct CityBuildings {
    Building *byType[BUILDING_TYPE_COUNT];
    Building *list[BUILDING_TYPE_COUNT];  // offset 0x0604  list of all buildings in order of construction
    int count;                            // offset 0x0704
};

struct Settlement {
    int unknown0[3];
    int posX;
    int posY;
    int unknown1[74];
    void *city3dModel;                // offset 0x013C
    void *wall3dModel;                // offset 0x0140
    int unknown2[16];
    Seaport *port;                    // offset 0x0184
    const char *name;                 // offset 0x0188
    int unknown3[2];
    Faction *faction;                 // offset 0x0194
    int unknown4[7];
    int level;                        // offset 0x01B4
    int culture;                      // offset 0x01B8
    int unknown5[9];
    RecruitmentQueue recruitmentQueue; // offset 0x01E0
    int unknown6[36];
    ConstructionQueue constructionQueue; // offset 0x039C
    int unknown7[3];
    CityBuildings buildings;
    int unknown8[240];
    int taxRate;                         // offset 0x0AC8
    int unknown9[195];
    City city;                           // offset 0x0DD8
};

struct Region {
    int unknown0[0x1C];
    const char *name;
    int unknown1;
    const char *settlementName;
    int unknown2[79];
    Settlement *settlement;
    int unknown3[7];
};

struct UnitType {
    const char *type; // type from export_descr_unit
    int unknown0;
    int unknown1;
    int unknown2;
    const char *tga0;
    int unknown3;
    const char *tga1;
    int unknown4[36];
    const char *dictionary; // dictionary from export_descr_unit
    int unknown5[4];
    int menCount; // offset 0xC0 not scaled
    int unknown6[3];
    union {
        struct {
            unsigned char flags;
            unsigned char priAttack;
            unsigned char priAttackCharge;
        };
        struct {
            int unknownFlag0: 1;
            int hasMelee: 1;
            int hasChargeBonus: 1;
            int unknownFlag3: 1;
            int hasMelee2: 1;
            int unknownFlag5: 1;
            int unknownFlag6: 1;
            int unknownFlag7: 1;
        };
    };
    int unknown7[3];
    int primaryWeapon; // offset 0x0E0    0 = light, 1 = missile, 2 = heavy
    int unknown8[3];
    unsigned char unknown9;
    unsigned char unknown10;
    unsigned char secAttack;
    unsigned char secAttackCharge;
};

struct SoliderUpgrades {
    unsigned int unknown0: 12;
    unsigned int xp: 4;
    unsigned int unknown1: 7;
    unsigned int armor: 3;
    unsigned int weapons: 3;
    unsigned int unknown2: 3;
};

struct ArmyUnit {
    int unknown0[0x10];
    Army *army;
    int unknown1[3];
    UnitType *unitType;
    int unknown2[136];
    int calculatedXP;     // offset 0x274 read only
    Character *general;   // offset 0x278 (Family members only)
    float movementPoints; // offset 0x27C
    int soliderCount;     // offset 0x280
    int unknown3[5];
    int hasOfficer[4];    // offset 0x298
    int unknown4[23];
    union {
        int calculatedUpgrades;    // read only - cache
        struct {
            int unknown5: 8;
            int weapons: 2;       // read only - cache
            int unknown6: 3;
            int armor: 2;         // read only - cache
            int unknown7: 17;
        };
    };
    int unknown8;
    SoliderUpgrades *upgrades;       // xp, armor, weapons
};

struct Army {
    int unknown0[0x15];
    Faction *faction;
    int unknown1;
    ArmyUnitArrayList units;
    int unknown3[34];
    Character *character;
    int unknown4[6];
    ArrayList agents;
};

struct Treasury {
    Faction *faction;
    int gold; // current money
// Not valid for 1.9
//    int unknown;
//    struct {
//        int farming;
//        int taxes;
//        int mining;
//        int trade;
//        int construction;
//        int corruption;
//        int senateTransactions;
//        int diplomacy;
//        int diplomacy2; // SuperFaction?
//        int other;
//    } income;
//    struct {
//        int wages;
//        int army;
//        int construction;
//        int construction2;
//        int recruitment;
//        int recruitment2;
//        int senateTransactions;
//        int diplomacy;
//        int diplomacy2; // SuperFaction?
//        int corruption;
//        int entertainment;
//        int other;
//    } spending;
};

struct Faction {
    int unknown0[0x28];
    int id;                           // offset 0x00A0
    int culture;                      // offset 0x00A4
    Settlement *capital;              // offset 0x00A8
    Person *pLeaderName;              // offset 0x00AC   (+0x04 => +0x00 => 0x06 = WCHAR name)
    Person *pHeirName;                // offset 0x00B0   (+0x04 => +0x00 => 0x06 = WCHAR name)
    struct FactionInfo *pName;        // offset 0x00B4
    int isPlayer;                     // offset 0x00B8
    int unknown2[4];
    ArrayList unknown3;
    int unknown4[5];
    CharacterArrayList characters;
    ArmyArrayList armies;
    RegionArrayList regions;
    SettlementArrayList settlements;
    ArrayList forts;
    ArrayList watchtowers;
    ArrayList ports;
    int unknown5;
    ArrayList unknown6;
    int unknown7;
    int unknown8;
    ArrayList unknown9;
    ArrayList unknown10;
    int unknown11[5];
    void *fogOfWar;
    ArrayList missions;
    ArrayList unknown12;
    int unknown13[3];
    ArrayList unknown14;
    ArrayList unknown15;
    ArrayList rankingHistory;
    int unknown16[2];
    union {
        int flags;
        struct {
            char autoManageEverything;
            char unknown0;
            char unknown1;
            char autoManageTaxesOnly;
            float spendingPolicy;
        };
    } managementSettings;
    int unknown17[0xC2];
    int outdatedTreasury;             // offset 0x04E8    0 or 1
    int startingMoney;                // offset 0x04EC Gold at the start of turn
    int unknown18[5];
    Treasury treasury;
};

struct Diplomacy {
    int unknown0;

    /**
     * 0 = ALLIED, 100 = SUSPICIOUS, 200 = NEUTRAL, 400 = HOSTILE, 600 = AT_WAR
     * Only accepts these values, some of them are not used in game, like 100 and 400
     * This value is your standing alone. You can declare war on someone who thinks you are their ally
     * if you put a value not on this list, the game text may say ally, even if it's 599
     */
    int relationship; // offset 0x04

    union {
        unsigned int receivedAgreements;
        struct {
            unsigned int tradeRights: 1; // if your bit is set you have tr
            unsigned int militaryAccess: 1; // if your bit is set, you have mc
        };
    }; // offset 0x08

    union {
        unsigned int unknownFlags; // offset 0x0C
        struct {
            unsigned int unknownFlag00: 1;
            unsigned int unknownFlag01: 1;
            unsigned int unknownFlag02: 1;
            unsigned int protector: 1;         // if your bit is set, you are the slave
        };
    };

    // Hate from 0 to 1000, (AKA core_attitudes, wait? is AKA involved with KKK?)
    // How much do you hate?
    int hate; // offset 0x10

    int unknown1;

    /**
     * How many cumulative turns have you been in alliance for since start of game
     */
    int allianceTurns;

    /**
     * How many cumulative turns have you been at war for since start of game
     */
    int hostilityTurns;

    int unknonw2;
    int unknonw3;
    int unknonw4;
    int unknonw5;
    int unknonw6;
    int unknonw7;
    int unknonw8;

    struct {
        int amount; // offset 0x3C
        int turns; // offset 0x40
    } receivedTribute;

    int unknonw9;
    int unknonw10;
    int unknonw11;
    int unknonw12;
    int unknonw13;
    int unknonw14;
    int unknonw15;
    int unknonw16;
    int unknonw17;

    /**
     * turns since last diplomatic contact
     */
    int turnsSinceLastContact;

    /**
     * NEEDS MORE TESTING
     * Make a deal +1, cancel a deal -1, fail to reach deal -1.
     */
    int reputation;

    /**
     * related to reputation somehow, for good deals, it starts negative, for bad actions it's positive,
     * it loses value over time approaching zero
     * Anger?
     */
    int unknown18;
};

typedef Diplomacy FactionDiplomacy[21];

struct FactionsData {
    int unknown0[0x5A]; // offset 0 size 0x168
    Faction *factions[21]; // offset 0x168 size 0x54
    Faction *sortedFactions[21]; // offset 0x168 size 0x54
    int factionCount;
    int unknown1[0xC6];
    FactionDiplomacy diplomacy[21];
};

struct CultureCityModel { // size should be 180 = 0x6C
    struct {
        int unknown[4];
    } cityModel;
    struct {
        int unknown[4];
    } walls[5];
    struct {
        int unknown[3];
    } card;
};

struct CultureModels { // size should be 1176 = 0x498
    CultureCityModel cityModel[6]; // one for each level (village, town, l town, m city, l city, h city)
    int unknown[131];
    int maxCityLevel;
};

struct CultureData {
    int unknown[0x5B];
    CultureModels cultureModels[CULTURE_COUNT];
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
    void *RecruitmentCapabilities;
    int unknown2[2];
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

struct PopulationLimits {
    /**
     * Minimum required for this level
     */
    int levelMin;

    /**
     * How many idiot it takes to get to the next level
     */
    int nextLevel;

    /**
     * Population can't be less that this, and will jump to be equal at
     * the end of turn if it becomes smaller
     */
    int absoluteMinimum;

    /**
     * Squalor will increase significantly if this threshold is exceeded
     */
    int overPopulationThreshold;
};

struct Seaport {
    int unknown0[3];
    int villagePosX;
    int villagePosY;
    int unknown1[7];
    Settlement *settlement;
    int region;
    unsigned short orientation;
    int level;
    int culture;
    int unknown2[3];
    int posX;
    int posY;
    int rallyPointX;
    int rallyPointY;
    int unknown3;
    Faction *faction;
    int unknown4[3];
    void *village3DModel;
    void *port3DModel;
};

struct Fort {
    int unknown0[3];
    int posX;
    int posY;
    int unknown1[11];
    Army *army;
    int unknown2[40];
    int region;
    Faction *faction;
};

/**
 *  initializes scripthook & native functions
 */
SCRIPTHOOK_API void rtw_scripthook_init();

/**
 * Writes bytes to memory
 * @param address address of the first byte
 * @param hex a null-terminated string hex to write to the memory. (space is ignored)
 * @return non-zero on success
 */
SCRIPTHOOK_API int rtw_write_mem(void *address, const char *hex);

/**
 * Updates memory after checking its value to avoid conflicts and errors
 * @param address address of the first byte
 * @param oldHex the current bytes in this address
 * @param hex a null-terminated string hex to write to the memory. (space is ignored)
 * @return non-zero on success, 0 if the oldHex is the the actual value before updating
 */
SCRIPTHOOK_API int rtw_update_mem(void *address, const char *oldHex, const char *hex);

/**
 * Returns a pointer to faction data bullshit
 * @return pointer to FactionData
 * @see FactionData
 */
SCRIPTHOOK_API FactionsData *rtw_get_faction_data(void);

/**
 * gets faction pointer from it's id
 * @param id faction id or index (0 to N)
 * @return faction pointer
 */
SCRIPTHOOK_API Faction *rtw_faction_get_by_id(int id);

/**
 * gets faction pointer from it's name
 * @param name faction name from descr_strat.txt
 * @return faction pointer or null of no names matches
 */
SCRIPTHOOK_API Faction *rtw_faction_get_by_name(const char *name);

/**
 * Returns a pointer to the diplomacy structure of what A thinks of B, used for reading & writing
 * you should set outdatedTreasury to 1 for both factions after updating
 * @param to the receiving faction id
 * @param from the giving faction id
 * @return pointer to tribute
 */
SCRIPTHOOK_API Diplomacy *rtw_get_diplomacy(int A, int B);

/**
 * Disbands a unit
 * @param unit the unit to disband
 */
SCRIPTHOOK_API void rtw_army_unit_disband(ArmyUnit *unit);

/**
 * Generates a secure random int using rand_s
 * @return a random int
 */
SCRIPTHOOK_API int rtw_random();

/**
 * Returns the global tax multiplier used in calculating taxes
 * @return the multiplier
 */
SCRIPTHOOK_API float rtw_get_global_tax_multiplier();

/**
 * Sets the global tax multiplier used in calculating taxes
 * @param value the new multiplier
 */
SCRIPTHOOK_API void rtw_set_global_tax_multiplier(float value);

/**
 * Returns the tax multiplier used in calculating taxes
 * @param rate 0 for low, 1 for normal, 2 for high, 3 for very high
 * @return the multiplier
 */
SCRIPTHOOK_API int rtw_get_tax_multiplier(int rate);

/**
 * Changes the tax multiplier used in calculating taxes
 * @param rate 0 for low, 1 for normal, 2 for high, 3 for very high
 * @param value new value
 */
SCRIPTHOOK_API void rtw_set_tax_multiplier(int rate, int value);

/**
 * Returns a pointer to the city model that should be used for a city
 * @param culture the target culture, usually the culture of the core building, or the founder faction
 * @param level the level of the city
 * @return pointer to the model that can be assigned to <code>Settlement.city3dModel</code>
 */
SCRIPTHOOK_API void *rtw_city_get_3D_model(int culture, int level);

/**
 * Returns a pointer to the wall model that should be used for a city
 * @param culture the target culture, usually the culture of the core building, or the founder faction
 * @param cityLevel the level of the city
 * @param wallLevel the level of the wall
 * @return pointer to the model that can be assigned to <code>Settlement.wall3dModel</code>
 */
SCRIPTHOOK_API void *rtw_city_get_wall_3D_model(int culture, int cityLevel, int wallLevel);

/**
 * Returns the list of building types from export_descr_buildings.txt
 * @return A linked list with arrays as sub-lists on every node
 */
SCRIPTHOOK_API BuildingTypeList *rtw_get_building_types();

/**
 * Returns a pointer to the global limits on population. Changing
 * this will not effect cities until the next end of turn or a recalculation
 * is forced because of some other updates
 * @param cityLevel from 0 to 5 (inclusive)
 * @return pointer to population limits
 */
SCRIPTHOOK_API PopulationLimits *rtw_get_population_limits(int cityLevel);

/**
 * Calls native game cpp function to translate a key string to a localized text
 * @param dictionary the dictionary containing the key, dictionaries are named after files in data/text
 * @param key key without the braces {}
 * @return a pointer to the localized text in game memory
 */
SCRIPTHOOK_API PTextEntry *rtw_translate(Dictionary *dictionary, const char *key);

/**
 * UNSAFE, new text MUST be shorter or equal to original
 * @param entry entry to update
 * @param text new text
 */
SCRIPTHOOK_API void rtw_update_text(PTextEntry *entry, const WCHAR *text);

/**
 * Destroys a building, use carefully, core buildings are related to
 * city level, you need to reset it after destroying a core building
 * @param pBuilding the building to be destroyed
 */
SCRIPTHOOK_API void rtw_building_destroy(Building *building);

/**
 * Returns a region
 * @param id
 * @return null if the id is not valid
 */
SCRIPTHOOK_API Region *rtw_get_region(int id);

#endif // RTW_SCRIPT_HOOK_H
