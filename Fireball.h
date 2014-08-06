//
//  Fireball.h
//  Nameless
//
//  Created by Thomas Dost on 06.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Fireball__
#define __Nameless__Fireball__

#include <iostream>
#include "SFML/Graphics.hpp"

#include "Zombie.h"
template<class T>
class Fireball 
{
public:
    Fireball(Player &player, T &target);
    ~Fireball();
    bool hasBeenHit();
    void render(sf::RenderWindow *window);
    void update();
   // void cast();
protected:
private:
    T *pEnemy;
    Player *pPlayer;
    sf::RectangleShape mFireBall;
 
};

#include "Fireball.inl"
#endif /* defined(__Nameless__Fireball__) */
