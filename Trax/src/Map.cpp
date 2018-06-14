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

Map::Map() {
    
}

Map::~Map() {
    
}

void Map::load(std::string filename) {
    std::fstream map;
    json j;
    
    map.open(filename);
    map >> j;
    map.close();
    
    load_tiles(j);
    load_obstacles(j);
}

void Map::load_tiles(json j) {
    int width = j.at("width");
    int height = j.at("height");
    int tile_width = j.at("tilewidth");
    int tile_height = j.at("tileheight");
    
    int tile = 0;
    json tiles = j.at("layers")[0]["data"];
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Trax::add_tile(x * tile_width, y * tile_height, tile_width, tile_height, tiles[tile]);
            
            tile++;
        }
    }
}

void Map::load_obstacles(json j) {
    json obstacles = j.at("layers")[1]["objects"];
    
    for (auto &obstacle : obstacles) {
        float x = obstacle.at("x");
        float y = obstacle.at("y");
        int width = obstacle.at("width");
        int height = obstacle.at("height");
        std::string name = obstacle.at("name");
        
        Trax::add_obstacle(x, y, width, height, name);        
    }
}
