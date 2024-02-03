//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

struct UnitType { // size 0x20C = 524
    const char *type; // type from export_descr_unit
    int unknown004;
    int unknown008;
    int unknown00C;
    const char *tga0;
    int unknown014;
    const char *tga1;
    int unknown01C;
    int unknown020;
    int unknown024;
    int unknown028;
    int unknown02C;
    int unknown030;
    int unknown034;
    int unknown038;
    int unknown03C;
    int unknown040;
    int unknown044;
    int unknown048;
    int unknown04C;
    int unknown050;
    int unknown054;
    int unknown058;
    int unknown05C;
    int unknown060;
    int unknown064;
    int unknown068;
    int unknown06C;
    int unknown070;
    int unknown074;
    int unknown078;
    int unknown07C;
    int unknown080;
    int unknown084;
    int unknown088;
    int unknown08C;
    int unknown090;
    int unknown094;
    int unknown098;
    int unknown09C;
    int unknown0A0;
    int unknown0A4;
    int unknown0A8;
    const char *dictionary; // dictionary from export_descr_unit
    int unknown0B0;
    int unknown0B4;
    int unknown0B8;
    int unknown0BC;
    int menCount; // offset 0xC0 not scaled
    int unknown0C4;
    int unknown0C8;
    int unknown0CC;
    union {
        struct {
            unsigned char flags;
            unsigned char priAttack;
            unsigned char priAttackCharge;
        };
        struct {
            int unknownFlag0: 1;
            int hasMelee: 1;
            int hasChargeBonus: 1;
            int unknownFlag3: 1;
            int hasMelee2: 1;
            int unknownFlag5: 1;
            int unknownFlag6: 1;
            int unknownFlag7: 1;
        };
    };
    int unknown0D4;
    int unknown0D8;
    int unknown0DC;
    int primaryWeapon; // offset 0x0E0    0 = light, 1 = missile, 2 = heavy
    int unknown0E4;
    int unknown0E8;
    int unknown0EC;

    unsigned char unknown9;
    unsigned char unknown10;
    unsigned char secAttack;
    unsigned char secAttackCharge;

    int unknown0F4;
    int unknown0F8;
    int unknown0FC;
    int unknown100;
    int unknown104;
    int unknown108;
    int unknown10C;
    int unknown110;
    int unknown114;
    int unknown118;
    int unknown11C;
    int unknown120;
    int unknown124;
    int unknown128;
    int unknown12C;
    int unknown130;
    int unknown134;
    int unknown138;
    int unknown13C;
    int unknown140;
    int unknown144;
    int unknown148;
    int unknown14C;
    int unknown150;
    int unknown154;
    int unknown158;
    int unknown15C;
    int unknown160;
    int unknown164;
    int unknown168;
    int unknown16C;
    int unknown170;
    int unknown174;
    int unknown178;
    int unknown17C;
    int unknown180;
    int unknown184;
    int unknown188;
    int unknown18C;
    int unknown190;
    int unknown194;
    int unknown198;
    int unknown19C;
    int unknown1A0;
    int unknown1A4;
    int unknown1A8;
    int unknown1AC;
    int unknown1B0;
    int unknown1B4;
    int unknown1B8;
    int unknown1BC;
    int unknown1C0;
    int unknown1C4;
    int unknown1C8;
    int unknown1CC;
    int unknown1D0;
    int unknown1D4;
    int unknown1D8;
    int unknown1DC;
    int unknown1E0;
    int unknown1E4;
    int unknown1E8;
    int unknown1EC;
    int unknown1F0;
    int unknown1F4;
    int unknown1F8;
    int unknown1FC;
    int unknown200;
    int unknown204;
    int unknown208;
};

struct SoliderUpgrades {
    unsigned int unknown0: 12;
    unsigned int xp: 4;
    unsigned int unknown1: 7;
    unsigned int armor: 3;
    unsigned int weapons: 3;
    unsigned int unknown2: 3;
};
