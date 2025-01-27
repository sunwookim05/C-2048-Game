#include "game.h"
#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "console.h"

import SYSTEM System;


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

    for(;!((pos1.x ^ pos2.x) ^ (pos1.y ^ pos2.y));  pos2 = randomPosition());

    srand(time(null));
    game->gameBord = (uint64_t**)malloc(4 * sizeof(uint64_t*));\
    for(size_t i = 0; i < 4; i++){
        *(game->gameBord + i) = (uint64_t*)malloc(4 * sizeof(uint64_t));
        for(size_t j = 0; j < 4; j++){
            *(*(game->gameBord + i) + j) = 0;
        }
    }
}

void play(Game* game){
    
}

void stop(Game* game){
    for(size_t i = 0; i < 4; i++){
        free(*(game->gameBord + i));
    }
    free(game->gameBord);
}

void delete(Game* game){
    stop(game);
    free(game);
}

Game new_Game(void){
    Game game;
    game.init = init;
    game.play = play;
    game.stop = stop;
    game.delete = delete;
    return game;
}

