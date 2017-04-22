//
//  SDL_Setup_Implement.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/10/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "SDL_Setup.h"

SDL_Setup::SDL_Setup(bool* quit, int screenWidth, int screenHeight)
{
    window = NULL;
    window = SDL_CreateWindow("CSS-2A Project - Game", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    
    if(window == NULL)
    {
        std::cout << "Error, window cannot be created. Program will now exit.\n";
        *quit = true;
    }
    
    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    mainEvent = new SDL_Event();
}

SDL_Setup::~SDL_Setup()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete mainEvent;
}

void SDL_Setup::begin()
{
    SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer); // Update renderer - Clears the screen
}

void SDL_Setup::end()
{
    SDL_RenderPresent(renderer);
}
