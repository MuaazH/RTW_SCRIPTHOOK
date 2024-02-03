//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

enum {
    ROLE_SPY = 0,
    ROLE_ASSASSIN,
    ROLE_DIPLOMAT,
    ROLE_ADMIRAL,
    ROLE_CAPTAIN,
    ROLE_FAMILY_MEMBER
};

struct CharacterType {
    int role;
};

struct Character {
    int unknown0[3];
    int positionX;     // offset 0x00C
    int positionY;     // offset 0x010
    int unknown1;
    char isVisible;    // offset 0x018
    float opacity;     // offset 0x01C   0 to 1
    int unknown2[22];
    Person *person; // offset 0x078
    Faction *faction;
    CharacterType *type;
    int unknown4[16];
    float movementPoints; // offset 0x0C4 (read only)
    int unknown5[7];
    Army *army;           // offset 0x0E4
    int unknown6[22];
    unsigned short orientation;
    int unknown7;
    float maxMovementPoints; // offset 0x0148
};
