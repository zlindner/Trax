
//
//  TextureManager.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "TextureManager.hpp"
#include "Trax.hpp"
#include <SDL2_image/SDL_image.h>

SDL_Texture *TextureManager::load_texture(std::string filename) {
    SDL_Surface *surface = IMG_Load(&filename[0u]);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Trax::renderer, surface);
    SDL_FreeSurface(surface);
    
    return texture;
};

void TextureManager::draw(SDL_Texture *texture, SDL_Rect source, SDL_Rect dest, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Trax::renderer, texture, &source, &dest, NULL, NULL, flip);
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect source, SDL_Rect dest, double angle) {
    SDL_RenderCopyEx(Trax::renderer, texture, &source, &dest, angle, NULL, SDL_FLIP_NONE);
}
