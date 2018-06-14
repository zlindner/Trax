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
#include "Collider.hpp"
#include "Collision.hpp"
#include "Map.hpp"
#include "Tank.hpp"

SDL_Renderer *Trax::renderer;
SDL_Event Trax::event;

Manager manager;

std::vector<Collider *> Trax::colliders;

Tank *tank;

auto &tiles(manager.get_group(Trax::TILE));
auto &obstacles(manager.get_group(Trax::OBSTACLE));
auto &tanks(manager.get_group(Trax::TANK));

Trax::Trax() {
    
}

Trax::~Trax() {
    
}

void Trax::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow("Trax", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 1024, 0);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            
            // render hints
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        }
        
        is_running = true;
    } else {
        is_running = false;
    }
    
    Map::load("assets/map/map.json", manager);
    
    tank = new Tank(manager);
    manager.add_entity(tank);
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
    Vector2D tank_pos = tank->get_component<Transform>().pos;
    
    manager.refresh();
    manager.update();
    
    //TODO create separate vector for obstacles? don't add tank to vector?
    for (auto c : colliders) {
        if (c->tag == "tank") {
            continue;
        }
        
        //TODO redo collision -> rotated rects
        if (Collision::AABB(tank->get_component<Collider>(), *c)) {
            tank->get_component<Transform>().pos = tank_pos;
        }
    }
}

void Trax::render() {
    SDL_RenderClear(renderer);
    
    for (auto &t : tiles) {
        t->draw();
    }
    
    for (auto &o : obstacles) {
        o->draw();
    }
    
    for (auto &t : tanks) {
        t->draw();
    }
    
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
