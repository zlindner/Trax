//
//  Transform.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Transform.hpp"

Transform::Transform() {
    pos.zero();
}

Transform::Transform(int s) {
    pos.zero();
    scale = s;
}

Transform::Transform(float x, float y) {
    pos.x = x;
    pos.y = y;
}

Transform::Transform(float x, float y, int w, int h, int s) {
    pos.x = x;
    pos.y = y;
    width = w;
    height = h;
    scale = s;
}

void Transform::init() {
    vel.zero();
}

void Transform::update() {
    pos.x += vel.x * speed;
    pos.y += vel.y * speed;
}
