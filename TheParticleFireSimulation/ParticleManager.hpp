//
//  ParticleManager.hpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2019-02-11.
//  Copyright © 2019 Wen Xiao. All rights reserved.
//

#ifndef ParticleManager_hpp
#define ParticleManager_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.hpp"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Swarm.hpp"

using namespace std;
using namespace ParticleFire;

class ParticleManager {
    Screen screen;
    Swarm swarm;
    
    ParticleManager() {}
    ParticleManager(ParticleManager const&);
    void operator=(ParticleManager const&);
    
public:
    static ParticleManager & GetInstance() {
        static ParticleManager particleManager;
        return particleManager;
    }
    
    void ScreenInit();
    void Start();
};

#endif /* ParticleManager_hpp */
