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
#include "Animation.hpp"

class Sprite : public Component {
    
public:
    int index = 0; // animation index
    std::map<std::string, Animation> animations;
    
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    
    Sprite() = default;
    
    Sprite(std::string filename);
    
    Sprite(std::string filename, bool is_animated);
    
    ~Sprite();
    
    void init() override;
    void update() override;
    void draw() override;
    void play(std::string name);
    
    void set_texture(std::string filename);
    
private:
    Transform *transform;
    SDL_Texture *texture;
    SDL_Rect source;
    SDL_Rect dest;
    
    bool animated = false;
    int frames = 0;
    int speed = 100;
};

#endif /* Sprite_hpp */
