//
//  Character.h
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/18/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#ifndef Character_h
#define Character_h

#include "Sprite.h"
#include "SDL_Setup.h"

class Character
{
private:
    Sprite* bob;
    int timeCheck;
    
    bool moveRight,
         moveLeft,
         moveUp,
         moveDown;
    
    // Set Up for Window
    SDL_Setup* setup;
        
public:
    // Constructors
    Character();
    Character(SDL_Setup* passedSetup);
    
    // Destructor
    ~Character();
    
    void update();
    void draw();
};

#endif /* Character_h */
