//
//  Tank.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-13.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Tank.hpp"
#include "Trax.hpp"
#include "Manager.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "Keyboard.hpp"
#include "Collider.hpp"
#include "Vector2D.hpp"

Tank::Tank(Manager &m, std::size_t g) : Entity(m) {
    pos.zero();
    size = Vector2D(83, 78);
    vel.zero();
    rotation = 180.0;
    
    add_group(g); // move to entity class?
    
    add_component<Transform>(pos.x, pos.y, size.x, size.y, 1);
    transform = &get_component<Transform>();
    
    add_component<Sprite>("assets/tank_black.png");
    sprite = &get_component<Sprite>();
    
    add_component<Keyboard>();
    keyboard = &get_component<Keyboard>();
    
    add_component<Collider>("tank");
    collider = &get_component<Collider>();
    
    barrel = new Entity(m);
    m.add_entity(barrel);
    
    barrel->add_component<Transform>(0, 0, 24, 58, 1);
    (barrel->get_component<Transform>()).pos.x = pos.x + size.x / 2 - barrel->get_component<Transform>().width / 2;
    (barrel->get_component<Transform>()).pos.y = pos.y + size.y / 3;
    
    SDL_Point b_origin;
    b_origin.x = barrel->get_component<Transform>().width / 2;
    b_origin.y = 10;
    
    barrel->add_component<Sprite>("assets/barrel_black.png", b_origin);
    
    barrel->add_group(g);
}

Tank::~Tank() {
    
}

void Tank::update() {
    Entity::update();
    
    get_input();
    
    // update tank
    transform->vel = vel;
    sprite->angle = rotation; // todo add entity constructor with rotation
    pos = transform->pos;
    
    // update barrel
    barrel->get_component<Transform>().vel = vel;
    barrel->get_component<Sprite>().angle = rotation + 180;
}

void Tank::get_input() {
    const Uint8 *keystates = keyboard->keystates;
    
    if (!keystates[SDL_SCANCODE_W] && !keystates[SDL_SCANCODE_S]) {
        vel.zero();
    }
    
    if (keystates[SDL_SCANCODE_W]) {
        vel.x = sin(rotation * -0.0174532925) * -1;
        vel.y = cos(rotation * -0.0174532925) * -1;
    }
    
    if (keystates[SDL_SCANCODE_A]) {
        rotation -= 2;
    }
    
    if (keystates[SDL_SCANCODE_S]) {
        vel.x = sin(rotation * -0.0174532925);
        vel.y = cos(rotation * -0.0174532925);
    }
    
    if (keystates[SDL_SCANCODE_D]) {
        rotation += 2;
    }
}