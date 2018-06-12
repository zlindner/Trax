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

void Map::load_map(std::string filename, int width, int height) {
    char tile;
    std::fstream map;
    
    map.open(filename);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            map.get(tile);
            
            Trax::add_tile(atoi(&tile), x * 32, y * 32);
            
            map.ignore();
        }
    }
    
    map.close();
}
