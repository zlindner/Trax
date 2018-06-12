//
//  Manager.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Manager_hpp
#define Manager_hpp

#include <vector>
#include <memory>
#include <array>

class Entity;

class Manager {
    
public:
    void update();
    void draw();
    void refresh();
    
    Entity &add_entity();
    
private:
    std::vector<std::unique_ptr<Entity>> entities;
    std::array<std::vector<Entity *>, 32> grouped_entities;
};

#endif /* Manager_hpp */
