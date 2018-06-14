//
//  Obstacle.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-14.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <string>
#include <SDL2/SDL.h>

#include "Component.hpp"

class Obstacle : public Component {
    
public:
    SDL_Rect obstacle;
    std::string filename;
        
    Obstacle(float x, float y, int width, int height, std::string name);
    
    void init() override;
};

#endif /* Obstacle_hpp */
