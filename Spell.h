//
//  Spell.h
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Spell__
#define __Nameless__Spell__

#include <iostream>
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "Enemy.h"
class Spell
{

public:
    Spell();
    virtual ~Spell();
    virtual void castSpell() = 0;
protected:
private:
    int mManaCost = 0;
    sf::Clock mRefillTime;
};

#endif /* defined(__Nameless__Spell__) */
