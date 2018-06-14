//
//  Obstacle.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-14.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Obstacle.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "Entity.hpp"
#include "Collider.hpp"

Obstacle::Obstacle(float x, float y, int width, int height, std::string name) {
    obstacle.x = x;
    obstacle.y = y;
    obstacle.w = width;
    obstacle.h = height;
    
    filename = name;
}

void Obstacle::init() {
    entity->add_component<Transform>(obstacle.x, obstacle.y, obstacle.w, obstacle.h, 1);
    entity->add_component<Sprite>("assets/textures/" + filename + ".png");
    entity->add_component<Collider>("obstacle");
}
