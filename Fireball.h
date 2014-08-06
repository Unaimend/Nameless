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
#include "Spell.h"

class Fireball :  Spell
{
public:
    Fireball(Player &player, Enemy &target);
    ~Fireball();
    void castSpell();
    bool hasBeenHit();
protected:
private:
    sf::RectangleShape mFireball;
    sf::FloatRect mEnemyGlobalBounds;
    sf::FloatRect mPlayerGlobalBounds;

};
#endif /* defined(__Nameless__Fireball__) */
