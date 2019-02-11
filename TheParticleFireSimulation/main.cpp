//
//  main.cpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-05.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#include "ParticleManager.hpp"

int main() {
    
    ParticleManager::GetInstance().ScreenInit();
    ParticleManager::GetInstance().Start();
    
    return 0;
}
