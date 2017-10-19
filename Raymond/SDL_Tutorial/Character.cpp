//
//  Character.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/21/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "Character.h"

Character::Character(SDL_Setup* passedSetup)
{
    moveLeft = false;
    moveRight = false;
    moveUp = false;
    moveDown = false;
    
    bob = new Sprite(setup -> getRenderer(), "Sprite.jpg", 300, 250, 30, 30);
    
    bob -> setUpAnimation(4, 4);
}

Character::~Character()
{
    delete bob;
}

void Character::update()
{
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

}

void Character::draw()
{
    
}
