//
//  Sprite.hpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/12/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

#include <string>
#include <iostream>

class Sprite
{
private:
    SDL_Texture* image;
    SDL_Renderer* renderer;
    SDL_Rect rect;
    SDL_Rect crop;
    
    int imgWidth,
        imgHeight;
    int currentFrame;
    int animationDelay;
    
    int frameX,
        frameY;
    
public:
    // Constructor
    Sprite();
    Sprite(SDL_Renderer* passedRenderer, std::string FilePath, int x, int y, int w , int h);
    
    // Destructor
    ~Sprite();
    
    // Getters
    int getX()const {return rect.x;}
    int getY()const {return rect.y;}
    
    // Sprite Methods
    void draw();
    void setX(double x);
    void setY(double y);
    void setPos(double x, double y);
    void setUpAnimation(int passedX, int passedY);
    void playAnimation(int beginFrame, int endFrame, int row, int speed);
};

#endif /* Sprite_h */
