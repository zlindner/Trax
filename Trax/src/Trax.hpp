//
//  Trax.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Trax_hpp
#define Trax_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <vector>
#include "Collider.hpp"

class Trax {

public:
    static SDL_Renderer *renderer;
    static SDL_Event event;
    
    static std::vector<Collider *> colliders;
    
    Trax();
    ~Trax();
    
    void init();
    void events();
    void update();
    void render();
    void clean();
    
    bool running();
    
    static void add_tile(int x, int y, int width, int height, int id);
    static void add_obstacle(float x, float y, int width, int height, std::string name);
    
private:
    SDL_Window *window;
    
    bool is_running;
};

#endif /* Trax_hpp */
