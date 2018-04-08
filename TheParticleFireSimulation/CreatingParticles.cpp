//
//  CreatingParticles.cpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-08.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#include "CreatingParticles.hpp"
#include <math.h>
#include <stdlib.h>

namespace caveofprogramming {
    Particle::Particle(): m_x(0), m_y(0) {
        m_direction = 2.0 * M_PI * rand()/RAND_MAX;
        m_speed = 0.001 * rand()/RAND_MAX;
    }
    
    Particle::~Particle() {
        
    }
    
    void Particle::update() {
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * sin(m_direction);
        
        m_x += xspeed;
        m_y += yspeed;
    }
    
}
