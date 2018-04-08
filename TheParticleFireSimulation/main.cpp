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
    
    
    while(true) {
        // Update particles
        
        // Draw particles
        for(int y=0; y < Screen::SCREEN_HEIGHT; y++) {
            for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }
        
        
        
        // Draw the screen
        screen.update();
        
        // Check for messages/events
        if(!screen.processEvents()){
            break;
        }
    }
    
    screen.close();
    
    return 0;
}
