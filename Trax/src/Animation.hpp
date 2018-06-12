//
//  Animation.hpp
//  Trax
//
//  Created by Zach Lindner on 2018-06-12.
//  Copyright © 2018 Zach Lindner. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

class Animation {
    
public:
    int index;
    int frames;
    int speed;
    
    Animation();
    
    Animation(int i, int f, int s);
};

#endif /* Animation_hpp */
