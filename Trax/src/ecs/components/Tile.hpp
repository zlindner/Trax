//
//  Tile.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <SDL2/SDL.h>
#include <string>

#include "Component.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"

class Tile : public Component {
    
public:
    Transform *transform;
    Sprite *sprite;
    
    SDL_Rect tile;
    int tile_id;
    std::string filename;
      
    Tile(int x, int y, int width, int height, int id);
    
    void init() override;
};

#endif /* Tile_hpp */
