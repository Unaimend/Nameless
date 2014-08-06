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
#include "Zombie.h"
class Fireball : public Spell
{
public:
    Fireball(Player &player, Zombie &target);
    ~Fireball();
    void castSpell();
    bool hasBeenHit();
    void render(sf::RenderWindow *window);
    void update();
protected:
private:
    Zombie *pEnemy;
    Player *pPlayer;
 
};
#endif /* defined(__Nameless__Fireball__) */
