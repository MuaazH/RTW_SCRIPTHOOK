//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

enum {
    LOW_TAX_RATE = 0,
    NORMAL_TAX_RATE,
    HIGH_TAX_RATE,
    VERY_HIGH_TAX_RATE,

    YEARLY_GAMES = 0,
    MONTHLY_GAMES,
    DAILY_GAMES,
    YEARLY_RACES,
    MONTHLY_RACES,
    DAILY_RACES,
    YEARLY_GAMES_N_RACES,
    MONTHLY_GAMES_N_RACES,
    DAILY_GAMES_N_RACES,
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
    int unknown3[1];
    PTextEntry wEntry;
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
    int unknown8[223];
    int gamesPolicy;                     // offset 0x0A84 = 2692
    int unknown9[16];
    int taxRate;                         // offset 0x0AC8 = 2760
    SettlementCapabilities capabilities; // offset 0x0ACC
    City city;                           // offset 0x0DD8
};
