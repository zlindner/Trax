//
//  Sprite.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include <string>

#include "Sprite.hpp"
#include "TextureManager.hpp"
#include "ECS.hpp"
#include "Entity.hpp"

Sprite::Sprite(std::string filename) {
    set_texture(filename);
}

Sprite::Sprite(std::string filename, bool is_animated) {
    set_texture(filename);
    
    animated = is_animated;
    
    // setup animations
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::init() {
    transform = &entity->get_component<Transform>();
    
    source.x = 0;
    source.y = 0;
    source.w = transform->width;
    source.h = transform->height;
    
    dest.w = transform->width * transform->scale;
    dest.h = transform->height * transform->scale;
}

void Sprite::update() {
    if (animated) {
        source.x = source.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
    }
    
    source.y = index * transform->height;
    
    dest.x = static_cast<int>(transform->pos.x);
    dest.y = static_cast<int>(transform->pos.y);
    dest.w = transform->width * transform->scale;
    dest.h = transform->height * transform->scale;
}

void Sprite::draw() {
    TextureManager::draw(texture, source, dest, flip);
}

void Sprite::play(std::string name) {
    frames = animations[name].frames;
    index = animations[name].index;
    speed = animations[name].speed;
}

void Sprite::set_texture(std::string filename) {
    texture = TextureManager::load_texture(filename);
}
