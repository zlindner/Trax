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
#include "ECS.hpp"
#include "Entity.hpp"

void Keyboard::init() {
    transform = &entity->get_component<Transform>();
    sprite = &entity->get_component<Sprite>();
}

void Keyboard::update() {
    if (Trax::event.type == SDL_KEYDOWN) {
        switch(Trax::event.key.keysym.sym) {
            case SDLK_w:
                transform->vel.y = -1;
                sprite->angle = 0;
                break;
            case SDLK_a:
                transform->vel.x = -1;
                sprite->angle = -90;
                break;
            case SDLK_s:
                transform->vel.y = 1;
                sprite->angle = 180;
                break;
            case SDLK_d:
                transform->vel.x = 1;
                sprite->angle = 90;
                break;
            default:
                break;
        }
    }
    
    if (Trax::event.type == SDL_KEYUP) {
        switch(Trax::event.key.keysym.sym) {
            case SDLK_w:
                transform->vel.y = 0;
                break;
            case SDLK_a:
                transform->vel.x = 0;
                break;
            case SDLK_s:
                transform->vel.y = 0;
                break;
            case SDLK_d:
                transform->vel.x = 0;
                break;
            default:
                break;
        }
    }
}
