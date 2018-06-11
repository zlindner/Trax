//
//  Trax.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Trax.hpp"

int main(int argc, const char *argv[]) {
    const int fps = 60;
    const int frame_delay = 1000 / fps;
    Uint32 frame_start;
    int frame_time;
    
    Trax *trax = new Trax();
    trax->init();
    
    while (trax->running()) {
        frame_start = SDL_GetTicks();
        
        trax->events();
        trax->update();
        trax->render();
        
        frame_time = SDL_GetTicks() - frame_start;
        
        if (frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }
    
    trax->clean();
    
    return 0;
}
