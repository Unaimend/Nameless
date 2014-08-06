//
//  MagicSystem.h
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__MagicSystem__
#define __Nameless__MagicSystem__

#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Fireball.h"
#include "SFML/Graphics.hpp"
class MagicSystem
{
public:
    MagicSystem(Player &player, std::vector<Enemy> EnemyVector);
    ~MagicSystem();
    void SpawnSpell();
    void render(sf::RenderWindow *window);
    void update(double frametime);
protected:
private:
    Fireball<Enemy> *pFireBall;
};
#endif /* defined(__Nameless__MagicSystem__) */
