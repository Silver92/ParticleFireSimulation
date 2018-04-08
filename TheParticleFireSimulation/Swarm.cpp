//
//  Swarm.cpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-08.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#include "Swarm.hpp"

namespace caveofprogramming {
    Swarm::Swarm() {
        m_pParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm() {
        delete [] m_pParticles;
    }
    
    void Swarm::update() {
        for(int i=0; i<Swarm::NPARTICLES; i++) {
            m_pParticles[i].update();
        }
    }
}
