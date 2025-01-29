#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "Console.h"
#include "game.h"

import SYSTEM System;

int main(void){ 
    Game game = new_Game();
    boolean isPlay = true;

    for(;isPlay;isPlay = game.play(&game));

    game.delete(&game);
    
    return 0;
}