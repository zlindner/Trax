//
//  Map.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include <fstream>

#include "Map.hpp"
#include "Trax.hpp"
#include "Manager.hpp"
#include "Entity.hpp"
#include "Tile.hpp"
#include "Obstacle.hpp"
#include "ECS.hpp"

void Map::load(std::string filename, Manager &m) {
    std::fstream map;
    json j;
    
    map.open(filename);
    map >> j;
    map.close();
    
    load_tiles(j, m);
    load_obstacles(j, m);
}

void Map::load_tiles(json j, Manager &m) {
    int width = j.at("width");
    int height = j.at("height");
    int tile_width = j.at("tilewidth");
    int tile_height = j.at("tileheight");
    
    int tile = 0;
    json tiles = j.at("layers")[0]["data"];
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            add_tile(x * tile_width, y * tile_height, tile_width, tile_height, tiles[tile], m);
            
            tile++;
        }
    }
}

void Map::add_tile(int x, int y, int width, int height, int id, Manager &m) {
    auto &tile(m.add_entity());
    tile.add_component<Tile>(x, y, width, height, id);
    tile.add_group(Trax::TILE);
}

void Map::load_obstacles(json j, Manager &m) {
    json obstacles = j.at("layers")[1]["objects"];
    
    for (auto &obstacle : obstacles) {
        float x = obstacle.at("x");
        float y = obstacle.at("y");
        int width = obstacle.at("width");
        int height = obstacle.at("height");
        std::string name = obstacle.at("name");
        
        add_obstacle(x, y, width, height, name, m);
    }
}

void Map::add_obstacle(float x, float y, int width, int height, std::string name, Manager &m) {
    auto &obstacle(m.add_entity());
    obstacle.add_component<Obstacle>(x, y, width, height, name);
    obstacle.add_group(Trax::OBSTACLE);
}
