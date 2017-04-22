//
//  Game_Setup.h
//  Seedvolution
//
//  Created by Raymond Esteybar on 4/22/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#ifndef Game_Setup_h
#define Game_Setup_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

#include <string>
#include <iostream>
using namespace std;

class GameSetup
{
private:
    bool quit;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event* event;
    
    SDL_Texture* background;
    SDL_Rect bgSize;          // To get our background's size
    SDL_Texture* character;
    SDL_Rect charSize;
    
public:
    // Constructor + Destructor
    GameSetup();
    ~GameSetup();
    
    void run();
    
    // Window Variables
    const int WIDTH = 600;
    const int HEIGHT = 400;
};

#endif /* Game_Setup_h */
