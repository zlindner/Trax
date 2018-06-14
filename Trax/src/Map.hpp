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

class Map {
    
public:
    Map();
    
    ~Map();
    
    static void load(std::string filename);
    
private:
    static void load_tiles(json j);
    static void load_obstacles(json j);
};

#endif /* Map_hpp */
