//
//  Window.hpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/22/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Window{
public:
    SDL_Window *window = NULL;
    
    Window();
    ~Window();
};

#endif /* Window_hpp */
