//
//  RPG_Implement.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/6/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "RPG.h"

RPG::RPG(int passedWidth, int passedHeight)
{
    screenWidth = passedWidth;
    screenHeight = passedHeight;
    
    quit = false;
    
    setup = new SDL_Setup(&quit, screenWidth, screenHeight);
    grass = new Sprite(setup -> getRenderer(), "Town.gif", 0, 0, screenWidth, screenHeight);
    bob = new Sprite(setup -> getRenderer(), "Sprite.jpg", 300, 250, 30, 30);

    bob -> setUpAnimation(4, 4);
    
    timeCheck = SDL_GetTicks();
    
    moveRight = false;
    moveLeft = false;
    moveUp = false;
    moveDown = false;
}

RPG::~RPG()
{
    delete setup;
    delete grass;
}

void RPG::gameLoop(void)
{
    while(!quit && setup -> getEvent() -> type != SDL_QUIT)
    {
        setup -> begin();
        // SDL_RenderCopy(SDL_Renderer*, SDL_Texture*, Cropping/Animation, Position/Size of Sprite using values from x, y, w, h on SDL_Rect)
        // NULL = not doing anything with it
        // &grass_rect = pass by reference b/c it is a pointer
        
        grass -> draw();
        bob -> draw();
        
        switch(setup -> getEvent() -> type)
        {
            case SDL_KEYDOWN:
                
                switch(setup -> getEvent() -> key.keysym.sym)
            {
                case SDLK_w:
                    std::cout << "↑\n";
                    moveUp = true;
                    bob -> playAnimation(0, 3, 3, 100);
                    break;
                    
                case SDLK_a:
                    std::cout << "←\n";
                    moveLeft = true;
                    bob -> playAnimation(0, 3, 1, 100);
                    break;
                    
                case SDLK_d:
                    std::cout << "→\n";
                    moveRight = true;
                    bob -> playAnimation(0, 3, 2, 100);
                    break;
                    
                case SDLK_s:
                    std::cout << "↓\n";
                    moveDown = true;
                    bob -> playAnimation(0, 3, 0, 100);
                    break;
                    
                default:
                    break;
            }
                
                break;
                
            case SDL_KEYUP:
                switch(setup -> getEvent() -> key.keysym.sym)
            {
                case SDLK_w:
                    moveUp = false;
                    bob -> playAnimation(0, 0, 3, 100);
                    break;
                    
                case SDLK_a:
                    moveLeft = false;
                    bob -> playAnimation(0, 0, 1, 100);
                    break;
                    
                case SDLK_d:
                    moveRight = false;
                    bob -> playAnimation(0, 0, 2, 100);
                    break;
                    
                case SDLK_s:
                    moveDown = false;
                    bob -> playAnimation(0, 0, 0, 100);
                    break;
                    
                default:
                    break;
            }
                
                break;
                
            default:
                break;
        }
        
        if(timeCheck + 25 < SDL_GetTicks())
        {
            if(moveRight)
                bob -> setX(bob -> getX() + 2);
            
            else if(moveLeft)
                bob -> setX(bob -> getX() - 2);
            
            else if(moveDown)
                bob -> setY(bob -> getY() + 2);
            
            else if(moveUp)
                bob -> setY(bob -> getY() - 2);
            timeCheck = SDL_GetTicks();
        }
        
        setup -> end();
    }
}
