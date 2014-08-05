//
//  Enemy.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Enemy.h"

Enemy::Enemy()
{
    mLife = 100;
    mLifeString = std::to_string(mLife);
    mName = "Gegner";
};

Enemy::~Enemy(){};