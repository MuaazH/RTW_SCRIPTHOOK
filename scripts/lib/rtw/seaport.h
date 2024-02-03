//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

struct Seaport {
    int unknown0[3];
    int villagePosX;
    int villagePosY;
    int unknown1[7];
    Settlement *settlement;
    int region;
    unsigned short orientation;
    int level;
    int culture;
    int unknown2[3];
    int posX;
    int posY;
    int rallyPointX;
    int rallyPointY;
    int unknown3;
    Faction *faction;
    int unknown4[3];
    void *village3DModel;
    void *port3DModel;
};