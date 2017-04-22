//
//  GameSetup.cpp
//  Seedvolution
//
//  Created by Raymond Esteybar on 4/22/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "Game_Setup.h"

GameSetup::GameSetup()
{
    quit = false;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = NULL;
    renderer = NULL;
    event = new SDL_Event();
    
    background = NULL;
    character = NULL;
    
    window = SDL_CreateWindow("Seedvolution", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    background = IMG_LoadTexture(renderer, "background.jpg");
    character = IMG_LoadTexture(renderer, "Sprite.jpg");
    
    if(window == NULL || character == NULL)
    {
        cout << "Error!\n";
        quit = true;
    }
    
    // Background Position + Size
    bgSize.x = 0;
    bgSize.y = 0;
    bgSize.w = WIDTH;
    bgSize.h = HEIGHT;
    
    // Character Position + Size
    charSize.x = 15;
    charSize.y = 15;
    charSize.w = 256;
    charSize.h = 256;
}

GameSetup::~GameSetup()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(character);
    delete event;
}

void GameSetup::run()
{
    while(!quit && event -> type != SDL_QUIT) // type = Type of Event, SDL_QUIT = Allows "Exit" Button
    {
        SDL_PollEvent(event);
        SDL_RenderClear(renderer); // Clears Screen
        SDL_RenderCopy(renderer, background, NULL, &bgSize);
        SDL_RenderCopy(renderer, character, NULL, &charSize);
        SDL_RenderPresent(renderer);
    }
}
