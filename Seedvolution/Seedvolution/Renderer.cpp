//
//  Renderer.cpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/22/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#include "Renderer.hpp"

Renderer::Renderer(SDL_Window *win)
{
    hwRend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}
Renderer::~Renderer()
{
    SDL_DestroyRenderer(hwRend);
}
void Renderer::clear()
{
    SDL_SetRenderDrawColor(hwRend, 0, 0, 0, 255);
    SDL_RenderClear(hwRend);
}
void Renderer::present()
{
    SDL_RenderPresent(hwRend);
}
