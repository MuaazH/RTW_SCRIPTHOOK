//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//


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