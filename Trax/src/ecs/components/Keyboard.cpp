//
//  Keyboard.cpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#include "Keyboard.hpp"

void Keyboard::update() {
    keystates = SDL_GetKeyboardState(NULL);
}
