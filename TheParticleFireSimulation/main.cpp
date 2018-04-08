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
    
    
    Screen screen;
    
    if(screen.init() == false) {
        cout << "Error initialising SDL." << endl;
    }
    
    Swarm swarm;
    
    while(true) {
        // Update particles
        
        // Draw particles
        
        int elapsed = SDL_GetTicks();
        
        screen.clear();
        swarm.update();
        
        unsigned char green = (1 +cos(elapsed * 0.001)) * 128;
        unsigned char red = (1 +sin(elapsed * 0.002)) * 128;
        unsigned char blue = (1 +cos(elapsed * 0.003)) * 128;
        
        const Particle * const pParticles = swarm.getParticles();
        
        for(int i=0; i<Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];
            
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;
            
            screen.setPixel(x, y, red, green, blue);
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
