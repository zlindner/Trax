//
//  Entity.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Entity.hpp"
#include "Component.hpp"
#include "ECS.hpp"

Entity::Entity(Manager &m) : manager(m) {
    
}

void Entity::update() {
    for (auto &c : components) {
        c->update();
    }
}

void Entity::draw() {
    for (auto &c : components) {
        c->draw();
    }
}

void Entity::destroy() {
    active = false;
}

bool Entity::is_active() {
    return active;
}
