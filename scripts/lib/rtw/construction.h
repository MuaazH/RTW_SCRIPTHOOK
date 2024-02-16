//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

struct Construction {
    int unknown0;             // 0x00
    int unknown1;             // 0x04
    int unknown2;             // 0x08
    Settlement *settlement;   // 0x0C
    int unknown3;             // 0x10
    int unknown4;             // 0x14
    int unknown5;             // 0x18
    int unknown6;             // 0x1C
    int turnsRequired;        // 0x20
    int turnsCompleted;       // 0x24
    int percentage;           // 0x28
    int unknown7;             // 0x2C
    int unknown8;             // 0x30
    int unknown9;             // 0x34
};

struct ConstructionQueue {
    Construction queue[6];
    int head;
    int tail;
    int size;
};
