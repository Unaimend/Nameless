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
   
};

Enemy::~Enemy(){};

void Enemy::render(sf::RenderWindow *window){std::cout << "ENEMy RENDER" << std::endl;};

void Enemy::update(double frametime){std::cout <<"FL`LASCH" << std::endl;};
