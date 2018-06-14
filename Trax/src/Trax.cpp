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
#include "Collider.hpp"
#include "Collision.hpp"
#include "Map.hpp"
#include "Tile.hpp"
#include "Tank.hpp"
#include "Obstacle.hpp"

SDL_Renderer *Trax::renderer;
SDL_Event Trax::event;

Manager manager;

std::vector<Collider *> Trax::colliders;

Tank *tank;

enum groups : std::size_t {
    GROUP_TILE,
    GROUP_OBSTACLE,
    GROUP_PLAYER
};

auto &tiles(manager.get_group(GROUP_TILE));
auto &obstacles(manager.get_group(GROUP_OBSTACLE));
auto &players(manager.get_group(GROUP_PLAYER));

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
    
    Map::load("assets/map/map.json");
    
    tank = new Tank(manager, GROUP_PLAYER);
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
    
    for (auto &p : players) {
        p->draw();
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

void Trax::add_tile(int x, int y, int width, int height, int id) {
    auto &tile(manager.add_entity());
    tile.add_component<Tile>(x, y, width, height, id);
    tile.add_group(GROUP_TILE);
}

void Trax::add_obstacle(float x, float y, int width, int height, std::string name) {
    auto &obstacle(manager.add_entity());
    obstacle.add_component<Obstacle>(x, y, width, height, name);
    obstacle.add_group(GROUP_OBSTACLE);
}
