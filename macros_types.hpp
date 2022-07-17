#ifndef MACROS_TYPES_HPP
#define MACROS_TYPES_HPP

#define MOVE_INTERACTIVE

typedef enum {
    NONE      = 0,
    PHYSICAL  = 1,
    POISON    = 2,
    ICE       = 3,
    FIRE      = 4,
    LIGHTNING = 5,
    DEEPWOUND = 6
} damage_t;


typedef enum {
    RANDOM      = 0,
    INTERACTIVE = 1,
    POLICY      = 2
} movemode_t;

#define CAN_WEAR(a, b, c) ((a) & (c)) | ((a) & (b))

#endif