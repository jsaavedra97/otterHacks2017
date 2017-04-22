//
//  RPG_Tutorial.cpp
//  SDL_Tutorial
//
//  ***************************************
//  Name: Window Creator
//
//  Description: Creates a Window that
//               could be exited & resized.
//  ***************************************
//
//  Created by Raymond Esteybar on 4/5/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

// #include "filename" = Programmer-defined header files
// #include <filename> = Built in libraries

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

#include <iostream>

int main(int argc, char *argv[])
{
    bool quit = false;
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = NULL;
    
    // >WINDOW CREATION<
    // SDL_CreateWindow("Title", x-coordinate, y-coordinate, width, height, flags)
    // flag = resize window, etc.
    window = SDL_CreateWindow("CSS-2A Project - Game", 100, 100, 600, 400, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    
    // Incase window cannot be opened
    if(window == NULL)
    {
        std::cout << "Error, window cannot be created. Program will now exit.\n";
        return 0;
    }
    
    SDL_Renderer* renderer = NULL;
    
    // SDL_CreateRenderer(SDL_Window Pointer, index, Uint32 flags)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    // Not updating Window Event - So do SDL_Event
    SDL_Event* mainEvent = new SDL_Event();
    
    // Created Sprite - Grass
    SDL_Texture* grass_image = NULL;
    grass_image = IMG_LoadTexture(renderer, "grass.bmp");
    
    if(grass_image == NULL)
    {
        std::cout << "Error, could not open grass.bmp.\n";
        return 0;
    }
    
    SDL_Rect grass_rect;
    grass_rect.x = 0;
    grass_rect.y = 0;
    grass_rect.w = 600;
    grass_rect.h = 400;
    
    // Created Sprite - Bob (Person)
    SDL_Texture* bob_image = NULL;
    bob_image = IMG_LoadTexture(renderer, "bob.png");
    
    if(bob_image == NULL)
    {
        std::cout << "Error, could not open bob.png.\n";
        return 0;
    }
    
    SDL_Rect bob_rect;
    bob_rect.x = 300;
    bob_rect.y = 250;
    bob_rect.w = 80;
    bob_rect.h = 50;
    
    // !quit =  while loop to keep the window opened
    // mainEvent -> type != SDL_Quit() = If player hasn't quit, press x button around the game.
    //                                   If player did, then it would "return 0".
    while(!quit && mainEvent -> type != SDL_QUIT)
    {
        SDL_PollEvent(mainEvent);
        // Update renderer - Clears the screen
        SDL_RenderClear(renderer);
        
        // SDL_RenderCopy(SDL_Renderer*, SDL_Texture*, Cropping/Animation, Position/Size of Sprite using values from x, y, w, h on SDL_Rect)
        // NULL = not doing anything with it
        // &grass_rect = pass by reference b/c it is a pointer
        SDL_RenderCopy(renderer, grass_image, NULL, &grass_rect); // Grass
        SDL_RenderCopy(renderer, bob_image, NULL, &bob_rect);     // Bob (Person)
        
        SDL_RenderPresent(renderer);
    }
    
    // Deleting the Dynamic Memory from the Pointers created from:
    //      1) SDL_Window* window
    //      2) SDL_Renderer* renderer
    SDL_DestroyTexture(grass_image);
    SDL_DestroyTexture(bob_image);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete mainEvent;
    
    return 0;
}
