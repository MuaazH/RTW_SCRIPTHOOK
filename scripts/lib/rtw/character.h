//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

enum {
    ROLE_SPY = 0,
    ROLE_ASSASSIN = 1,
    ROLE_DIPLOMAT = 2,
    ROLE_ADMIRAL = 3,
    ROLE_CAPTAIN = 4,
    ROLE_FAMILY_MEMBER = 5
};

struct CharacterType {
    int role;
    // todo: find-out more
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
