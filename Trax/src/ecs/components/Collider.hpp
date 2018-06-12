//
//  Collider.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Collider_hpp
#define Collider_hpp

#include <SDL2/SDL.h>
#include <string>

#include "Component.hpp"
#include "Transform.hpp"

class Collider : public Component {
    
public:
    SDL_Rect collider;
    std::string tag;
    
    Transform *transform;
    
    Collider(std::string t);
    
    void init() override;
    void update() override;
};

#endif /* Collider_hpp */
