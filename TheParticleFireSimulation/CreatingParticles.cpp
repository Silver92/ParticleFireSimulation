//
//  CreatingParticles.cpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-08.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#include "CreatingParticles.hpp"
#include <stdlib.h>

namespace caveofprogramming {
    Particle::Particle() {
        m_x = 2.0 * rand()/RAND_MAX - 1;
        m_y = 2.0 * rand()/RAND_MAX - 1;
    }
    
    Particle::~Particle() {
        
    }
}
