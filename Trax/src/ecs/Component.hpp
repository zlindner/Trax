//
//  Component.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

class Entity;

class Component {
    
public:
    Entity *entity;
    
    virtual ~Component() {}
    
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
};

#endif /* Component_hpp */
