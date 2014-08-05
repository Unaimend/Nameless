//
//  Zombie.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Zombie.h"
Zombie::Zombie(sf::Sprite sprite, Player player, std::string name, int life)
{
    mEnemySprite = sprite;
    mLife = life;
    mPlayer = player;
    mName = name;
    mLife = life;
};