//
//  Zombie.h
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Zombie__
#define __Nameless__Zombie__

#include <iostream>
#include "Enemy.h"
class Zombie : protected Enemy
{
public:
    Zombie(sf::Sprite sprite, Player player, std::string name, int life);
//    ~Zombie();
    void render(sf::RenderWindow *window);
    void update(double frametime);
//    void attack();
protected:
private:
    
};
#endif /* defined(__Nameless__Zombie__) */
