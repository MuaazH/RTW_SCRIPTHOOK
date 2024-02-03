//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

struct Army {
    int unknown0[0x15];
    Faction *faction;
    int unknown1;
    ArrayList(ArmyUnit) units;
    int unknown3[34];
    Character *character;
    int unknown4[6];
    ArrayList(void) agents;
};
