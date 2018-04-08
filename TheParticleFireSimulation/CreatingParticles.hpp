//
//  CreatingParticles.hpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-08.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#ifndef CreatingParticles_hpp
#define CreatingParticles_hpp

namespace caveofprogramming {
    class Particle {
    private:

    public:
        double m_x;
        double m_y;
        
        double m_speed;
        double m_direction;
        
        Particle();
        virtual ~Particle();
        void update();
    };
    
}

#endif /* CreatingParticles_hpp */
