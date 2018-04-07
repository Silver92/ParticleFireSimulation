//
//  Screen.cpp
//  TheParticleFireSimulation
//
//  Created by Silver on 2018-04-05.
//  Copyright © 2018 Wen Xiao. All rights reserved.
//

#include "Screen.hpp"

namespace caveofprogramming {
    Screen::Screen():  m_window(nullptr), m_renderer(nullptr),
    m_texture(nullptr), m_buffer(nullptr) {
       
    }
    
    bool Screen::init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }
        
        m_window = SDL_CreateWindow("Particle Fire Ecplosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        
        if(m_window == NULL) {
            SDL_Quit();
            return false;
        }
        
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
        
        if(m_renderer == NULL) {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        
        if(m_texture == NULL) {
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        
        Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
        
        memset(buffer, 0, SCREEN_HEIGHT*SCREEN_WIDTH*sizeof(Uint32));
        
        
        for(int i=0; i<SCREEN_HEIGHT*SCREEN_WIDTH; i++) {
            buffer[i] = 0xFFFFFFFF;
        }
        
        SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
        
        return true;
    }
    
    bool Screen::processEvents() {
        SDL_Event event;
        
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                return false;
            }
        }
        return true;
    }
    
    void Screen::close() {
        
        delete [] m_buffer;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        
    }
}





