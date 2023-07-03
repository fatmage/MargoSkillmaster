#ifndef SKILLMASTER_H
#define SKILLMASTER_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum class {
    MAGE,
    PALADIN,
    TRACKER,
    BLADE_DANCER,
    WARRIOR,
    HUNTER
} class_t;

typedef struct player {
    // basic attributes
    char * name;
    class_t  class;
    uint16_t lvl;
    int16_t health;
    int16_t max_health;
    float    as;
    float    slow;
    float    healing;
    float    energy;
    float    mana;
    float    skf;
    float    skm;
    float    crit;

    // defensive attributes
    // Kolejność redukowania obrażeń: 
    // Pancerz -> Blok -> Absorpcja -> Odporność (Ochrona Żywiołów) -> Krytyczna Osłona -> Fizyczna Osłona
    float    armor;
    float    fire_res;
    float    lightning_res;
    float    ice_res;
    float    deepwound_res;
    float    poison_res;
    float    abs_f;
    float    abs_m;
    uint16_t block;
    uint16_t dodge;

    uint16_t strength;
    uint16_t agility;
    uint16_t intellect;


    uint16_t physical_damage;
    uint16_t fire_damage;

} player_t;

typedef struct turn {
    
} turn_t;





#endif