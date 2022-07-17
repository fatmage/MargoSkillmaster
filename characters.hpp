#include "macros_types.hpp"

namespace msm {

class Player {

};

class Item {

    private:
    // general stats
    // offensive
    int crit;
    int skm;
    int skf;
    int slow;
    // defensive
    int health;
    int healing;
    int evasion;
    int block;
    int critred;
    int manaburn;
    int energyburn;

    // other
    int strength;
    int agility;
    int intellect;
    int attackspeed;
    int mana;
    int energy;

    public:
    void add_stats(Player *p);
};

class Weapon : Item {
    private:
    damage_t primary;
    int primarydmg;
    damage_t secondary;
    int secondarydmg;
    int counter;
};

class Armor : Item {
    private:
    int armor;
};

class Shield : Item {
    private:
    int armor;
    int penblock;
};






}