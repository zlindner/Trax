//
//  Trax.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Trax.hpp"
#include "Manager.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "Keyboard.hpp"
#include "Sprite.hpp"
#include "Transform.hpp"

SDL_Renderer *Trax::renderer;
SDL_Event Trax::event;

Manager manager;

auto &player(manager.add_entity());

Trax::Trax() {
    
}

Trax::~Trax() {
    
}

void Trax::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow("Trax", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        
        is_running = true;
    } else {
        is_running = false;
    }
    
    player.add_component<Transform>(2);
    player.add_component<Sprite>("assets/tank.png");
}

void Trax::events() {
    SDL_PollEvent(&event);
    
    switch(event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
    }
}

void Trax::update() {
    manager.refresh();
    manager.update();
    
    //TODO update colliders
}

void Trax::render() {
    SDL_RenderClear(renderer);
    
    //TODO grouping
    manager.draw();
    
    SDL_RenderPresent(renderer);
}

void Trax::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Trax::running() {
    return is_running;
}
