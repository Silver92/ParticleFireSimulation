//
//  main.cpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-05.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL init failed." << endl;
        return 1;
    }
    
    cout << "SDL Init succeeded." << endl;
    
    SDL_Quit();
    return 0;
}
