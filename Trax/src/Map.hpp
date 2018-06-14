//
//  Map.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Manager;

class Map {
    
public:
    
    /**
     * Parses and loads a .json Tiled map
     *
     * @param filename the path of the map file being loaded
     * @param m the game manager
     */
    static void load(std::string filename, Manager &m);
    
private:
    
    /**
     * Iterates through the tile data, calling Map::add_tile() for
     * each tile
     *
     * @param j the json object created from Map::load()
     * @param m the game manager
     */
    static void load_tiles(json j, Manager &m);
    
    /**
     * Adds a new tile to the game represented by the passed arguments
     *
     * @param x the tile's x position
     * @param y the tile's y position
     * @param width the width of the tile
     * @param height the height of the tile
     * @param id the tile's id
     * @param m the game manager
     */
    static void add_tile(int x, int y, int width, int height, int id, Manager &m);
    
    /**
     * Iterates through the obstacle data, calling Map::add_obstacle() for
     * each obstacle
     *
     * @param j the json object created from Map::load()
     * @param m the game manager
     */
    static void load_obstacles(json j, Manager &m);
    
   /**
    * Adds a new obstacle to the game represented by the passed arguments
    *
    * @param x the obstacle's x position
    * @param y the obstacle's y position
    * @param width the width of the obstacle
    * @param height the height of the obstacle
    * @param name the obstacle's name
    * @param m the game manager
    */
    static void add_obstacle(float x, float y, int width, int height, std::string name, Manager &m);
};

#endif /* Map_hpp */
