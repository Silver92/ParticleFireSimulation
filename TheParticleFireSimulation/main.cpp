//
//  main.cpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-05.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.hpp"
#include <string.h>
using namespace std;
using namespace caveofprogramming;

int main() {
    
    Screen screen;
    
    if(screen.init() == false) {
        cout << "Error initialising SDL." << endl;
    }
    
    bool quit = false;
    
    
    while(!quit) {
        // Update particles
        // Draw particles
        // Check for messages/events
        
        if(!screen.processEvents()){
            break;
        }
    }
    
    screen.close();
    
    return 0;
}
