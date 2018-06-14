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

//TODO needs rewrite
//TODO possibly move barrel and tracks to separate class
Tank::Tank(Manager &m) : Entity(m) {
    pos = Vector2D(100, 100);
    size = Vector2D(83, 78);
    vel.zero();
    rotation = 180.0;
    
    add_group(Trax::TANK);
    
    add_component<Transform>(pos.x, pos.y, size.x, size.y, 1);
    transform = &get_component<Transform>();
    
    add_component<Sprite>("assets/textures/tank_black.png");
    sprite = &get_component<Sprite>();
    
    add_component<Keyboard>();
    keyboard = &get_component<Keyboard>();
    
    add_component<Collider>("tank");
    collider = &get_component<Collider>();
    
    barrel = new Entity(m);
    m.add_entity(barrel);
    
    barrel->add_component<Transform>(0, 0, 24, 58, 1);
    barrel->get_component<Transform>().pos.x = pos.x + size.x / 2 - barrel->get_component<Transform>().width / 2;
    barrel->get_component<Transform>().pos.y = pos.y + size.y / 3;
    
    SDL_Point b_origin;
    b_origin.x = barrel->get_component<Transform>().width / 2;
    b_origin.y = 10;
    
    barrel->add_component<Sprite>("assets/textures/barrel_black.png", b_origin);
    
    barrel->add_group(Trax::TANK);
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
    barrel->get_component<Transform>().pos.x = pos.x + size.x / 2 - barrel->get_component<Transform>().width / 2;
    barrel->get_component<Transform>().pos.y = pos.y + size.y / 3;
    //barrel->get_component<Sprite>().angle = rotation + 180;
}

void Tank::get_input() {
    const Uint8 *keystates = keyboard->keystates;
    
    // tank
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
        vel.x = sin(rotation * -0.0174532925) * 0.75;
        vel.y = cos(rotation * -0.0174532925) * 0.75;
    }
    
    if (keystates[SDL_SCANCODE_D]) {
        rotation += 2;
    }
    
    // barrel
    if (keystates[SDL_SCANCODE_Q]) {
        barrel->get_component<Sprite>().angle -= 2;
    }
    
    if (keystates[SDL_SCANCODE_E]) {
        barrel->get_component<Sprite>().angle += 2;
    }
    
    if (keystates[SDL_SCANCODE_SPACE]) {
        std::cout << "bang\n";
    }
}
