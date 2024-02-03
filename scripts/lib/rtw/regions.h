//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

struct Regions {
    int unknonw00;
    int unknonw04;
    int unknonw08;
    int unknonw0C;

    int unknonw10;
    int unknonw14;
    int unknonw18;
    int unknonw1C;

    int unknonw20;
    int unknonw24;
    int unknonw28;
    int mapLength;

    int mapWidth;
    int unknonw34;
    int unknonw38;
    int unknonw3C;

    int unknonw40;
    int unknonw44;
    MapPixel *mapPixels;
    int unknonw4C;

    int unknonw50;
    int unknonw54;
    int unknonw58;
    int unknonw5C;

    int unknonw60;
    int unknonw64;
    int unknonw68;
    int unknonw6C;

    Region regions[MAX_REGION_COUNT];
    int regionsCount; // how many are actually used
};
