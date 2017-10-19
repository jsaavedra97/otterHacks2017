//
//  Renderer.hpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/22/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Renderer{
public:
    SDL_Renderer *hwRend = NULL;
    
    Renderer();
    Renderer(SDL_Window *win);
    ~Renderer();
    
    void clear();
    void present();
};

#endif /* Renderer_hpp */
