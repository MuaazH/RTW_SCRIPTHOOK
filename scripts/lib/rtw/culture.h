//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

enum {
    CULTURE_ROMAN = 0,
    CULTURE_BARBARIAN,
    CULTURE_CARTHAGINIAN,
    CULTURE_GREEK,
    CULTURE_EGYPTIAN,
    CULTURE_EASTERN,
    CULTURE_COUNT
};

struct CultureCityModel { // size should be 180 = 0x6C
    struct {
        int unknown[4];
    } cityModel;
    struct {
        int unknown[4];
    } walls[5];
    struct {
        int unknown[3];
    } card;
};

struct CultureModels { // size should be 1176 = 0x498
    CultureCityModel cityModel[6]; // one for each level (village, town, l town, m city, l city, h city)
    int unknown[131];
    int maxCityLevel;
};

struct CultureData {
    int unknown[0x5B];
    CultureModels cultureModels[CULTURE_COUNT];
};
