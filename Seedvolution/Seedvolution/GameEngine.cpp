//
//  GameEngine.cpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/22/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#include "GameEngine.hpp"

GameEngine::GameEngine()
{
    rend = new Renderer(win.window);
    
}
GameEngine::~GameEngine()
{
    delete rend;
}
void GameEngine::draw()
{
    rend-> clear();
    
    rend->present();
    
    drawCount++;
}
