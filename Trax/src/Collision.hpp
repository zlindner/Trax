//
//  Collision.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <SDL2/SDL.h>

class Collider;

class Collision {
    
public:
    static bool AABB(const SDL_Rect &a, const SDL_Rect &b);
    static bool AABB(const Collider &a, const Collider &b);
    
};

#endif /* Collision_hpp */
