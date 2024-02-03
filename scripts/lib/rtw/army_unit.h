//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

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
