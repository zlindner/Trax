//
//  Tile.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Tile.hpp"
#include "Entity.hpp"
#include "ECS.hpp"

Tile::Tile(int x, int y, int width, int height, int id) {
    tile.x = x;
    tile.y = y;
    tile.w = width;
    tile.h = height;
    tile_id = id;
    
    switch(id) {
        case 1:
            filename = "assets/textures/dirt.png";
            break;
        case 2:
            filename = "assets/textures/grass.png";
            break;
        case 3:
            filename = "assets/textures/sand.png";
            break;
        default:
            break;
    }    
}

void Tile::init() {
    entity->add_component<Transform>((float) tile.x, (float) tile.y, tile.w, tile.h, 1);
    transform = &entity->get_component<Transform>();
    
    entity->add_component<Sprite>(filename);
    sprite = &entity->get_component<Sprite>();
}
