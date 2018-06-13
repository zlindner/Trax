//
//  Tank.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-13.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Tank_hpp
#define Tank_hpp

#include "Entity.hpp"
#include "Component.hpp"
#include "Vector2D.hpp"

class Transform;
class Sprite;
class Keyboard;
class Collider;

class Tank : public Entity {
    
public:
    Tank(Manager &m, std::size_t g);
    
    ~Tank();
    
    void update() override;
    
    void get_input();
        
private:
    Transform *transform;
    Sprite *sprite;
    Keyboard *keyboard;
    Collider *collider;
    
    Vector2D pos;
    Vector2D size;
    Vector2D vel;
    double rotation;
    
    Entity *barrel;
};

#endif /* Tank_hpp */
