#include "game.h"
#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "Console.h"

import SYSTEM System;

typedef enum Direction{
    STAND,
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef enum MODE{
    MENU,
    PLAY,
    HOWTOPLAY,
    EXIT,
    GAMEOVER
} Mode;

Position randomPosition(void){
    srand((unsigned int)time(null));
    Position pos;
    pos.x = rand() % 4;
    pos.y = rand() % 4;
    return pos;
}

void init(Game* game){
    Position pos1 = randomPosition();
    Position pos2 = randomPosition();
    
    for(;!((pos1.x ^ pos2.x) | (pos1.y ^ pos2.y)); pos2 = randomPosition());

    srand(time(null));
    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++)
            *(*(game->gameBord + i) + j) = !((pos1.x ^ i) | (pos1.y ^ j)) | !((pos2.x ^ i) | (pos2.y ^ j)) ? rand() % 2 ? 2 : 4 : 0;
    }
}

Mode menu(Console cmd, Direction direction){
    
}

boolean play(Game* game){
    static Console cmd = new_Console();
    static boolean isInit = false;
    static boolean isPlay = true;
    static Mode mode = MENU;
    static Direction direction = STAND;

    if(!isInit){
        init(game);
        isInit = true;
    }
    if(cmd.kbhit()){
        char input = getch();
        direction = !((input | 0x20) ^ 'w') ? UP : !((input | 0x20) ^ 's') ? DOWN : !((input | 0x20) ^ 'a') ? LEFT : !((input | 0x20) ^ 'd') ? RIGHT : STAND;
        if(!(mode ^ MENU)) mode = menu(cmd, direction);
    }
    
    return isPlay;
}

void delete(Game* game){
    for(size_t i = 0; i < 4; i++)
        free(*(game->gameBord + i));
    free(game->gameBord);
    free(game);
}

Game new_Game(void){
    Game game;
    game.gameBord = (uint64_t**)malloc(4 * sizeof(uint64_t*));
    for(size_t i = 0; i < 4; i++) *(game.gameBord + i) = (uint64_t*)malloc(4 * sizeof(uint64_t));
    game.play = play;
    game.delete = delete;
    return game;
}

