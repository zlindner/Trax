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

class Map {
    
public:
    Map();
    
    ~Map();
    
    static void load_map(std::string filename, int width, int height);
};

#endif /* Map_hpp */
