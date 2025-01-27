#include "main.h"

#ifndef __GAME_H
#define __GAME_H

#pragma pack(push, 1)
typedef struct POSITION {
    size_t x;
    size_t y;
} Position;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct GAME {
    uint64_t** gameBord;
    void (*init)(struct GAME*);
    void (*play)(struct GAME*);
    void (*stop)(struct GAME*);
    void (*delete)(struct GAME*);
} Game;
#pragma pack(pop)


#endif