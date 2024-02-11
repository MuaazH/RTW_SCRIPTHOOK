//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

enum {
    DEATH_CAUSE_NATURAL = 1,
    DEATH_CAUSE_TRAGIC = 2,
    DEATH_CAUSE_BATTLE = 3,
    DEATH_CAUSE_ASSASSINATION = 4,
    DEATH_CAUSE_EXECUTION = 5,
    DEATH_CAUSE_PLAGUE = 7,
    DEATH_CAUSE_DESERTED = 12,
};

struct Person {
    int id;
    PTextEntry name;
    int unknown1[9];
    int command;
    int influence;
    int management;
    int subterfuge;
    int unknown2[25];
    int health; // health men have more children & live longer?
    int unknown3[27];
    ArrayList(void) retinue;
    int unknown4[20];
    Character *character;
    int unknown5[2];
    GameDate birthDate;
    GameDate deathDate;
    int childrenCount;
    Faction *faction;
    int factionID; // id of faction he was born into?
    int unknown7;
    Person *father;
    Person *spouse;
    Person *children[4];
    int unknown8[4];
    int causeOfDeath;
    void *portrait;
    int unknown9;
    void *largePortrait;
    int unknown10;
    int unknown12[3];
    struct {
        unsigned int isAlive: 1;
        unsigned int isMale: 1;
        unsigned int notGeneralYet: 1;
        unsigned int unknownFlag1: 1;
        unsigned int unknownFlag2: 1;
        unsigned int unknownFlag3: 1;
        unsigned int age: 7;
    };
};
