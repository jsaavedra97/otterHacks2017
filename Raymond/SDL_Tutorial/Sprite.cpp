//
//  Sprite.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/12/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* passedRenderer, std::string FilePath, int x, int y, int w , int h)
{
    renderer = passedRenderer;
    image = NULL;
    image = IMG_LoadTexture(renderer, FilePath.c_str());
    
    if(image == NULL)
        std::cout << "Error, could not open " << FilePath.c_str() << std::endl;
    
    this -> rect.x = x;
    this -> rect.y = y;
    this -> rect.w = w;
    this -> rect.h = h;

    SDL_QueryTexture(image, NULL, NULL, &imgWidth, &imgHeight);
    
    crop.x = 0;
    crop.y = 0;
    crop.w = imgWidth;
    crop.h = imgHeight;
    
    currentFrame = 0;
    frameX = 0;
    frameY = 0;
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(image);
}

void Sprite::setUpAnimation(int passedX, int passedY)
{
    this -> frameX = passedX;
    this -> frameY = passedY;
}

void Sprite::playAnimation(int beginFrame, int endFrame, int row, int speed)
{
    if(animationDelay + speed < SDL_GetTicks())
    {
        if(endFrame <= currentFrame)
            currentFrame = beginFrame;
        else
            currentFrame++;
        
        crop.x = currentFrame * (imgWidth/frameX);
        crop.y = row * (imgHeight/frameY);
        crop.w = imgWidth/frameX;
        crop.h = imgHeight/frameY;
        
        animationDelay = SDL_GetTicks();
    }
}

void Sprite::draw()
{
    SDL_RenderCopy(renderer, image, &crop, &rect); // Grass
}

void Sprite::setX(double x)
{
    this -> rect.x = x;
}

void Sprite::setY(double y)
{
    this -> rect.y = y;
}

void Sprite::setPos(double x, double y)
{
    this -> rect.x = x;
    this -> rect.y = y;
}










