//
//  App.hpp
//  Seedvolution
//
//  Created by Eros Gonzalez on 4/22/17.
//  Copyright © 2017 Eros Gonzalez. All rights reserved.
//

#ifndef App_hpp
#define App_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class App{
private:
    bool running = false;
public:
    App();
    ~App();
    
    bool isRunning();
    void exit();
};

#endif /* App_hpp */
