//
//  App.cpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/22/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#include "App.hpp"

App::App()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        
    }
}
App::~App()
{
    SDL_Quit();
}

bool App::isRunning()
{
    return running;
}
void App::exit()
{
    running = false;
}
