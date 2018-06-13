//
//  Keyboard.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include <iostream>

#include "Keyboard.hpp"
#include "Trax.hpp"
#include "ECS.hpp"
#include "Entity.hpp"

void Keyboard::init() {
    transform = &entity->get_component<Transform>();
    sprite = &entity->get_component<Sprite>();
}

void Keyboard::update() {
    keystates = SDL_GetKeyboardState(NULL);
}
