//
//  TextureManager.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <string>
#include <SDL2/SDL.h>

class TextureManager {

public:
    static SDL_Texture *load_texture(std::string filename);
    static void draw(SDL_Texture *texture, SDL_Rect source, SDL_Rect dest, SDL_RendererFlip flip);
};

#endif /* TextureManager_hpp */
