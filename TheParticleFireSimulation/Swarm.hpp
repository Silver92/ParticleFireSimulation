//
//  Swarm.hpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-08.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include "CreatingParticles.hpp"

namespace caveofprogramming {
    
    class Swarm {
    public:
        const static int NPARTICLES = 5000;
    private:
        Particle * m_pParticles;
        int lastTime;
    public:
        Swarm();
        virtual ~Swarm();
        void update(int elapsed);
        
        const Particle * const getParticles() { return m_pParticles; };
    };
}

#endif /* Swarm_hpp */
