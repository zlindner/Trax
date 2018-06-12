//
//  Collider.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Collider.hpp"
#include "ECS.hpp"
#include "Entity.hpp"
#include "Trax.hpp"

Collider::Collider(std::string t) {
    tag = t;
}

void Collider::init() {
    if (!entity->has_component<Transform>()) {
        entity->add_component<Transform>();
    }
    
    transform = &entity->get_component<Transform>();
    
    Trax::colliders.push_back(this);
}

void Collider::update() {
    collider.x = static_cast<int> (transform->pos.x);
    collider.y = static_cast<int> (transform->pos.y);
    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
}
