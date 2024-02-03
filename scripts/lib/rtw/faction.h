//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

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
    FactionInfo *info;                // offset 0x00B4
    int isPlayer;                     // offset 0x00B8
    int unknown2[4];
    ArrayList(void) unknown3;
    int unknown4[2];
    ArrayList(Person) persons;
    ArrayList(Character) characters;
    ArrayList(Army) armies;
    ArrayList(int) regions;
    ArrayList(Settlement) settlements;
    ArrayList(Fort) forts;
    ArrayList(void) watchtowers;
    ArrayList(Seaport) ports;
    int unknown5;
    ArrayList(void) unknown6;
    int unknown7;
    int unknown8;
    ArrayList(void) unknown9;
    ArrayList(void) unknown10;
    int unknown11[5];
    void *fogOfWar;
    ArrayList(void) missions;
    ArrayList(void) unknown12;
    int unknown13[3];
    ArrayList(void) unknown14;
    ArrayList(void) unknown15;
    ArrayList(void) rankingHistory;
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

typedef Diplomacy FactionDiplomacy[21];

struct FactionInfo {
    int unknown;
    const char *name;
};
