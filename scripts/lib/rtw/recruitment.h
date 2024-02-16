//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//


struct Recruitment {
    union {
        ArmyUnit *unit; // unit to be retrained
        UnitType *unitType;
        struct {
            int agentRole;
            int agentFaction;
        };
    };
    Settlement *settlement;
    unsigned char unknown1;
    unsigned char type; // 0 = new unit, 1 = new ship, 2 = new agent, 3 = retrain unit, 4 = retrain ship
    unsigned char xp;
    unsigned char armor;
    unsigned char weapons;
    unsigned char unknown011;
    unsigned char turnsCompleted;
    unsigned char percentageCompleted;
    unsigned char turnsRequired;
    unsigned char unknown015;
    unsigned char unknown016;
    unsigned char unknown017;
    unsigned short population;
    short unknown01A; // not used?
    char unknown01C; // not used?
};

struct RecruitmentQueue {
    Recruitment queue[9];
    int head;
    int tail;
    int size;
};