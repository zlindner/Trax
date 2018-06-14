//
//  Keyboard.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Keyboard_hpp
#define Keyboard_hpp

#include <SDL2/SDL.h>
#include "Component.hpp"

class Keyboard : public Component {
    
public:
    const Uint8 *keystates;
    
    /**
     * Updates the keystates for all keys
     */
    void update() override;
};

#endif /* Keyboard_hpp */
