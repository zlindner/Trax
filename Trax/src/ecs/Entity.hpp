//
//  Entity.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-11.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <vector>
#include <memory>
#include <bitset>
#include <array>

#include "ECS.hpp"

class Manager;
class Component;

class Entity {
    
public:
    Entity(Manager &m);
    
    void update();
    void draw();
    
    void destroy();
    bool is_active();
    
    template <typename T>
    bool has_component() {
        return component_bitset[get_component_type_id<T>()];
    }
    
    template <typename T, typename... T_args>
    T &add_component(T_args&&... args) {
        T *c(new T(std::forward<T_args>(args)...));
        
        c->entity = this;
        std::unique_ptr<Component> u_ptr {c};
        components.emplace_back(std::move(u_ptr));
        
        component_array[get_component_type_id<T>()] = c;
        component_bitset[get_component_type_id<T>()] = true;
        
        c->init();
        
        return *c;
    }
    
    template <typename T>
    T &get_component() {
        auto ptr(component_array[get_component_type_id<T>()]);
        
        return *static_cast<T *>(ptr);
    }
    
private:
    Manager &manager;
    std::vector<std::unique_ptr<Component>> components;
    bool active = true;
    
    std::bitset<32> component_bitset;
    std::bitset<32> group_bitset;
    std::array<Component *, 32> component_array;
};

#endif /* Entity_hpp */
