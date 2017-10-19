//
//  SDL_Setup.h
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/10/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#ifndef SDL_Setup_h
#define SDL_Setup_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

#include <iostream>

class SDL_Setup
{
private:
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event* mainEvent;
    
public:
    // Constructor + Destructor
    SDL_Setup(bool* quit, int screenWidth, int screenHeight);
    ~SDL_Setup();
    
    // Getters - Accessors
    SDL_Renderer* getRenderer() {return renderer;}
    SDL_Event* getEvent() {return mainEvent;}
    
    // SDL_Setup Methods
    void begin();
    void end();
};

#endif /* SDL_Setup_h */
