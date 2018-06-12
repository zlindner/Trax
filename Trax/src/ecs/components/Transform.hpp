//
//  Transform.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include "Component.hpp"
#include "Vector2D.hpp"

class Transform : public Component {
    
public:
    Vector2D pos;
    Vector2D vel;
    
    int speed = 3;
    int height = 32;
    int width = 32;
    int scale = 1;
    
    Transform();
    
    Transform(int s);
    
    Transform(float x, float y);
    
    Transform(float x, float y, int w, int h, int s);
    
    void init() override;
    void update() override;
};

#endif /* Transform_hpp */
