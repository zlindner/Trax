//
//  Manager.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Manager.hpp"
#include "Entity.hpp"
#include "Component.hpp"

void Manager::update() {
    for (auto &e : entities) {
        e->update();
    }
}

void Manager::draw() {
    for (auto &e : entities) {
        e->draw();
    }
}

void Manager::refresh() {
    for (auto i(0u); i < 32; i++) {
        auto &v(grouped_entities[i]);
        v.erase(std::remove_if(std::begin(v), std::end(v), [i](Entity *e) {
            return !e->is_active() || !e->has_group(i);
        }), std::end(v));
    }
    
    entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &e) {
        return !e->is_active();
    }), std::end(entities));
}

Entity &Manager::add_entity() {
    Entity *e = new Entity(*this);
    
    std::unique_ptr<Entity> u_ptr {e};
    entities.emplace_back(std::move(u_ptr));
    
    return *e;
}

void Manager::add_entity(Entity *e) {
    std::unique_ptr<Entity> u_ptr {e};
    entities.emplace_back(std::move(u_ptr));
}

void Manager::add_to_group(Entity *e, std::size_t g) {
    grouped_entities[g].emplace_back(e);
}

std::vector<Entity *> &Manager::get_group(std::size_t g) {
    return grouped_entities[g];
}
