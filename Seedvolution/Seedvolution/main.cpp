//
//  main.cpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/21/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#include <iostream>
#include "GameEngine.hpp"
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, const char * argv[]) {
    /*SDL_Window *window;
    SDL_Surface *surface;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_SHOWN);
    
    if (window == NULL)
    {
        cout << "Window could not be created " << SDL_GetError();
        return -1;
    }
    
    SDL_Delay(30000);
    
    SDL_DestroyWindow(window);
    
    SDL_Quit();*/
    
    GameEngine game;
    
    return 0;
}
