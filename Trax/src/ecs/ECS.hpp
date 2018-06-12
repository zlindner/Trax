//
//  ECS.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef ECS_hpp
#define ECS_hpp

#include <iostream>

inline std::size_t get_new_component_type_id() {
    static std::size_t id = 0u;
    
    return id++;
}

template <typename T> inline std::size_t get_component_type_id() noexcept {
    static std::size_t type_id = get_new_component_type_id();
    
    return type_id;
}

#endif /* ECS_hpp */
