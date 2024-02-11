//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2014-12-30.
//

#ifndef RTW_SCRIPT_HOOK_H
#define RTW_SCRIPT_HOOK_H

#define SCRIPTHOOK_VERSION_MAJOR 2
#define SCRIPTHOOK_VERSION_MINOR 15
#define SCRIPTHOOK_VERSION_PATCH 0


#ifdef SCRIPTHOOK_ASI
#define SCRIPTHOOK_API __declspec(dllexport)
#else
#include <tccdefs.h>
#define SCRIPTHOOK_API extern

// debug functions
extern void rtw_log(const char *script, const char *msg);
#endif


#define OPTION_DEFAULT 0
#define OPTION_ALLOW 1
#define OPTION_PREVENT 2

#define OPTION_BOY 1
#define OPTION_GIRL 2

#define MAX_REGION_COUNT 200

typedef unsigned short WCHAR;
typedef struct Character Character;
typedef struct CharacterType CharacterType;
typedef struct TrainableUnit TrainableUnit;
typedef struct TrainableAgent TrainableAgent;
typedef struct SettlementCapabilities SettlementCapabilities;
typedef struct Settlement Settlement;
typedef struct Region Region;
typedef struct Regions Regions;
typedef struct UnitType UnitType;
typedef struct SoliderUpgrades SoliderUpgrades;
typedef struct Army Army;
typedef struct ArmyUnit ArmyUnit;
typedef struct Campaign Campaign;
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
typedef struct RecruitmentCapability RecruitmentCapability;
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
typedef struct FactionInfo FactionInfo;
typedef struct MapPixel MapPixel;
typedef WCHAR **PTextEntry;

#include "rtw/common.h"
#include "rtw/text.h"

#define ArrayList(type) struct { type **buffer; unsigned int capacity; unsigned int size; }

#include "rtw/date.h"
#include "rtw/person.h"
#include "rtw/character.h"
#include "rtw/recruitment.h"
#include "rtw/construction.h"
#include "rtw/city_stats.h"
#include "rtw/building.h"
#include "rtw/city.h"
#include "rtw/recruitment_capabilities.h"
#include "rtw/settlement.h"
#include "rtw/world_map.h"
#include "rtw/region.h"
#include "rtw/regions.h"
#include "rtw/unit_type.h"
#include "rtw/army_unit.h"
#include "rtw/army.h"
#include "rtw/diplomacy.h"
#include "rtw/faction.h"
#include "rtw/campaign.h"
#include "rtw/culture.h"
#include "rtw/population_limits.h"
#include "rtw/seaport.h"
#include "rtw/fort.h"

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
 * Updates memory after checking its value to avoid conflicts and errors
 * @param address address of the first byte
 * @param old the current unsigned int value
 * @param newValue the new unsigned int value
 * @return non-zero on success, 0 if the old value does not match actual memory
 */
SCRIPTHOOK_API int rtw_update_mem_u32(unsigned int *address, unsigned int old, unsigned int newValue);


/**
 * Returns a pointer to campaign data
 * @return pointer to Campaign
 * @see Campaign
 */
SCRIPTHOOK_API Campaign *rtw_get_campaign(void);

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
SCRIPTHOOK_API int rtw_rand_s();

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
 * Returns the list of building types loaded from export_descr_buildings.txt
 * @return A linked list with arrays as sub-lists on every node
 */
SCRIPTHOOK_API BuildingTypeList *rtw_get_building_types();

/**
 * Returns the list of unit types loaded from export_descr_units.txt
 * @return An array of UnitType
 */
UnitType *rtw_get_unit_types();

/**
 * Returns the number of unit types loaded from export_descr_units.txt
 * @return The number of loaded unit types
 */
int rtw_get_unit_types_count();

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
 * Returns a region by id
 * @param id
 * @return null if the id is not valid
 */
SCRIPTHOOK_API Region *rtw_get_region(int id);

/**
 * Returns a pointer to the regions data
 * @param id
 * @return a pointer to regions data
 */
SCRIPTHOOK_API Regions *rtw_get_regions();

/**
 * Processes (marriage & having children) a person and ages them if the season
 * is right. To avoid errors, the age limit is 126. If the person has a character
 * and they reaches this age they will be killed with natural causes
 * @param person the person to age
 */
SCRIPTHOOK_API void rtw_person_age(Person *person);

/**
 * Kills a character, don't forget to set the cause of death to character->person
 * @param character the character to kill
 */
SCRIPTHOOK_API void rtw_character_die(Character *character);

/**
 * Returns a multiplier that controls how likely children
 * are to be born. Default is 1.0f
 * @return the multiplier value
 */
SCRIPTHOOK_API float rtw_get_fertility_multiplier();

/**
 * Sets a multiplier that controls how likely children
 * are to be born. Default is 1.0f
 * @param value the multiplier value, must be greater that zero
 */
SCRIPTHOOK_API void rtw_set_fertility_multiplier(float value);

/**
 * Advances time to the next season. This only affects the
 * year & date, nothing is affected by this time change
 * (i.e. people don't age, queue are not processed, ...etc)
 * @param date the date to change
 */
SCRIPTHOOK_API void rtw_date_next_season(GameDate *date);

/**
 * Updates upgrades cache the weapons, armor, and xp for this unit
 * @param unit the unit to update
 */
void rtw_unit_update_upgrades_cache(ArmyUnit *unit);

// ===========================================
// END OF GAME RELATED CRAP
// ===========================================

typedef struct Script Script;

struct Script {
    /**
     * called when a game is started/loaded
     */
    void (*on_init)();

    /**
     * called when a game is closed
     */
    void (*on_destroy)();

    /**
     * called at the end of each turn
     */
    void (*on_end_of_turn)();

    /**
     * called after a city updates it's population stats
     */
    void (*on_city_population_stats)(CityStats *);

    /**
     * called before a city increases it's population count
     * @return returns non-zero to block native function from being called
     */
    int (*on_city_population_growth)(CityStats *);

    /**
     * called after a city updates it's order stats
     */
    void (*on_city_order_stats)(CityStats *);

    /**
     * called after a city updates it's income stats
     */
    void (*on_city_income_stats)(CityStats *);

    /**
     * called to check whether a building can be demolished
     * @return OPTION_DEFAULT for default game behavior, OPTION_ALLOW to allow demolition, OPTION_PREVENT to forbid demolition
     */
    int (*on_demolition_check)(Building *);

    /**
     * called to check whether an abandoned fort can despawn or not
     * @return OPTION_DEFAULT for default game behavior, OPTION_PREVENT to keep the abandoned fort
     */
    int (*on_fort_despawn)(Fort *);

    /**
     * called to check whether a general should get married this turn
     * @param general the general
     * @return OPTION_DEFAULT for default game behavior, OPTION_ALLOW to force marriage, OPTION_PREVENT to prevent marriage
     */
    int (*on_marriage_coin_flip)(Character *general);

    /**
     * called to choose the gender of the baby born to a general
     * @param father the father
     * @return OPTION_DEFAULT for default game behavior of randomness, OPTION_BOY for boy OPTION_GIRL for girl
     */
    int (*on_baby_gender_coin_flip)(Character *father);

    /**
     * called to after a building has been demolished
     */
    void (*on_demolition)(Settlement *, Building *);

    /**
     * called when a character is over 60 and is flipping
     * a coin to die
     * @return OPTION_DEFAULT for default game behavior, OR OPTION_PREVENT OR OPTION_ALLOW
     */
    int (*on_character_death_check)(Character *);

    /**
     * Called when a building is damaged by sabotage (or something else)
     */
    void (*on_building_take_damage)(Building *);

    /**
     * Called every game tick while on the campaign map
     */
    void (*on_campaign_tick)();
};

#define EXPORT_HOOK(x) script-> x = x;

#endif // RTW_SCRIPT_HOOK_H
