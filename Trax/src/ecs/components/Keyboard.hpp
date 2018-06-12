//
//  Keyboard.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Keyboard_hpp
#define Keyboard_hpp

#include "Component.hpp"

class Keyboard : public Component {
    
public:
    void init() override;
    void update() override;
};

#endif /* Keyboard_hpp */
