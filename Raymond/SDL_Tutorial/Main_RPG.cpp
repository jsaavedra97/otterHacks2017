//
//  Main_RPG.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/6/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "RPG.h"

int main(int argc, char *argv[])
{
    RPG* main = new RPG(600, 500);
    
    main -> gameLoop();
    
    delete main;
    
    return 0;
}
