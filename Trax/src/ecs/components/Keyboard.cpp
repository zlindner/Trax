//
//  Keyboard.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include <iostream>

#include "Keyboard.hpp"
#include "Trax.hpp"

void Keyboard::init() {
    
}

void Keyboard::update() {
    if (Trax::event.type == SDL_KEYDOWN) {
        switch(Trax::event.key.keysym.sym) {
            case SDLK_w:
                std::cout << "Hey" << std::endl;
                break;
            default:
                break;
        }
    }
    
    if (Trax::event.type == SDL_KEYUP) {
        switch(Trax::event.key.keysym.sym) {
            default:
                break;
        }
    }
}
