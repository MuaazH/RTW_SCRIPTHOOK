//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

enum {
    DS_ALLIED = 0,
    DS_SUSPICIOUS = 100,
    DS_NEUTRAL = 200,
    DS_HOSTILE = 400,
    DS_AT_WAR = 600
};

struct Diplomacy {
    int unknown0;

    /**
     * 0 = ALLIED, 100 = SUSPICIOUS, 200 = NEUTRAL, 400 = HOSTILE, 600 = AT_WAR
     * Only accepts these values, some of them are not used in game, like 100 and 400
     * This value is your standing alone. You can declare war on someone who thinks you are their ally
     * if you put a value not on this list, the game text may say ally, even if it's 599
     */
    int relationship; // offset 0x04

    union {
        unsigned int receivedAgreements;
        struct {
            unsigned int tradeRights: 1; // if your bit is set you have tr
            unsigned int militaryAccess: 1; // if your bit is set, you have mc
        };
    }; // offset 0x08

    union {
        unsigned int unknownFlags; // offset 0x0C
        struct {
            unsigned int unknownFlag00: 1;
            unsigned int unknownFlag01: 1;
            unsigned int unknownFlag02: 1;
            unsigned int protector: 1;         // if your bit is set, you are the slave
        };
    };

    // Hate from 0 to 1000, (AKA core_attitudes, wait? is AKA involved with KKK?)
    // How much do you hate?
    int hate; // offset 0x10

    int unknown1;

    /**
     * How many cumulative turns have you been in alliance for since start of game
     */
    int allianceTurns;

    /**
     * How many cumulative turns have you been at war for since start of game
     */
    int hostilityTurns;

    int unknonw2;
    int unknonw3;
    int unknonw4;
    int unknonw5;
    int unknonw6;
    int unknonw7;
    int unknonw8;

    struct {
        int amount; // offset 0x3C
        int turns; // offset 0x40
    } receivedTribute;

    int unknonw9;
    int unknonw10;
    int unknonw11;
    int unknonw12;
    int unknonw13;
    int unknonw14;
    int unknonw15;
    int unknonw16;
    int unknonw17;

    /**
     * turns since last diplomatic contact
     */
    int turnsSinceLastContact;

    /**
     * NEEDS MORE TESTING
     * Make a deal +1, cancel a deal -1, fail to reach deal -1.
     */
    int reputation;

    /**
     * related to reputation somehow, for good deals, it starts negative, for bad actions it's positive,
     * it loses value over time approaching zero
     * Anger?
     */
    int unknown18;
};