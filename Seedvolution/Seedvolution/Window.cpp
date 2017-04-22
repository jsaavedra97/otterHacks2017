//
//  Window.cpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/22/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#include "Window.hpp"

Window::Window()
{
    window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);
}
Window::~Window()
{
    SDL_DestroyWindow(window);
    window = NULL;
}
