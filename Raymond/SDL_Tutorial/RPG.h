//
//  RPG.h
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/6/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#pragma once

#ifndef RPG_h
#define RPG_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

#include "SDL_Setup.h"
#include "Sprite.h"
//#include "Character.h"

#include <iostream>

class RPG
{
private:
    bool quit;
    
    int screenWidth,
        screenHeight;

    int timeCheck;
    
    bool moveRight,
    moveLeft,
    moveUp,
    moveDown;
    
    Sprite* grass;
    Sprite* bob;
    
    // Set Up for Window
    SDL_Setup* setup;
    
public:
    // Constructor
    RPG(int passedWidth, int passedHeight);
    
    // Destructor
    ~RPG();
    
    // Other Methods
    void gameLoop();
};

#endif /* RPG_h */
