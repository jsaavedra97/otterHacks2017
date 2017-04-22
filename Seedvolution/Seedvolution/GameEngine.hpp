//
//  GameEngine.hpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/22/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <stdio.h>
#include "Window.hpp"
#include "Renderer.hpp"

class GameEngine{
private:
    Window win;
    Renderer *rend = NULL;
    SDL_Event e;
    
    Uint32 drawCount = 0;
    
public:
    GameEngine();
    ~GameEngine();
    
    void draw();
    
    
};

#endif /* GameEngine_hpp */
