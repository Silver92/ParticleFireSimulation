//
//  CreatingParticles.hpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-08.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#ifndef CreatingParticles_hpp
#define CreatingParticles_hpp

namespace ParticleFire {
    class Particle {
    // Public variables
    public:
        double m_x;
        double m_y;
    // Private variables
    private:
        double m_speed;
        double m_direction;
    // Public functions
    public:
        Particle();
        virtual ~Particle();
        void update(int interval);
    // Private functions
    private:
        void init();
    };
    
}

#endif /* CreatingParticles_hpp */
