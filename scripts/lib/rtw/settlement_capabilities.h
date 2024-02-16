//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-10.
//

struct TrainableUnit {
    int unitIndex;
    int startingXp;
};

struct TrainableAgent {
    /**
     * -1 = not trainable, 0 = trainable
     */
    short trainable;
    short unknown;
};

struct SettlementCapabilities {
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0C;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1C;
    short foodProduction;
    short unknown22;
    int unknown24;
    int unknown28;
    int unknown2C;
    int unknown30;
    int unknown34;
    int armorLevel;
    int unknown3C;
    int unknown40;
    int unknown44;
    short lightWeaponsLevel;
    short unknown4A;
    short missilesLevel;
    short unknown4E;
    short heavyWeaponsLevel;
    short unknown52;
    int unknown54;
    int unknown58;
    int unknown5C;
    int unknown60;
    int unknown64;
    int unknown68;
    int unknown6C;
    int unknown70;
    int unknown74;
    int unknown78;
    int unknown7C;
    int unknown80;
    int unknown84;
    int unknown88;
    int unknown8C;
    TrainableAgent trainableAgents[9];
    TrainableUnit trainableUnits[64];
    int unitsCount;
    int unknown2B8;
    int unknown2BC;
    int unknown2C0;
    int unknown2C4;
    int unknown2C8;
    int unknown2CC;
    int unknown2D0;
    int unknown2D4;
    int unknown2D8;
    int unknown2DC;
    int unknown2E0;
    int unknown2E4;
    int unknown2E8;
    int unknown2EC;
    int unknown2F0;
    int unknown2F4;
    int unknown2F8;
    int unknown2FC;
    int unknown300;
    int unknown304;
    int unknown308;
};
