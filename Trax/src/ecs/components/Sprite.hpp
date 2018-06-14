//
//  Sprite.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <string>
#include <map>
#include <SDL2/SDL.h>

#include "Component.hpp"
#include "Transform.hpp"

class Sprite : public Component {
    
public:
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    double angle = 0.0;
    SDL_Point origin;
        
    Sprite(std::string filename);
    
    Sprite(std::string filename, SDL_Point o);
    
    ~Sprite();
    
    void init() override;
    void update() override;
    void draw() override;
    
    void set_texture(std::string filename);
    
private:
    Transform *transform;
    SDL_Texture *texture;
    SDL_Rect source;
    SDL_Rect dest;
    
    bool default_origin = true;
};

#endif /* Sprite_hpp */
