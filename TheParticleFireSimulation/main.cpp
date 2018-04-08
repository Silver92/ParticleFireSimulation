//
//  main.cpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-05.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.hpp"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Swarm.hpp"

using namespace std;
using namespace caveofprogramming;

int main() {
    
    srand(time(NULL));
    
    Screen screen;
    
    if(screen.init() == false) {
        cout << "Error initialising SDL." << endl;
    }
    
    Swarm swarm;
    
    while(true) {
        
        // Draw particles
        
        int elapsed = SDL_GetTicks();
        
        swarm.update(elapsed);
        
        unsigned char green = (unsigned char)((1 +sin(elapsed * 0.0001)) * 64);
        unsigned char red = (unsigned char)((1 +sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 +sin(elapsed * 0.0003)) * 100);
        
        const Particle * const pParticles = swarm.getParticles();
        
        for(int i=0; i<Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];
            
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;
            
            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.boxBlur();
        
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
