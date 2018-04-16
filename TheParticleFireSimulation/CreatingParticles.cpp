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

namespace ParticleFire {
    Particle::Particle(): m_x(0), m_y(0) {
        init();
    }
    
    void Particle::init() {
        m_direction = (2.0 * M_PI * rand())/RAND_MAX;
        m_speed = (0.01 * rand())/RAND_MAX;
        
        m_speed = m_speed * m_speed;
    }
    
    Particle::~Particle() {
        
    }
    
    void Particle::update(int interval) {
        
        m_direction += interval*0.0002;
        
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * sin(m_direction);
        
        m_x += xspeed * interval;
        m_y += yspeed * interval;
        
        if(m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
            init();
        }

        if(rand() < RAND_MAX/600) {
            init();
        }
    }
    
}
