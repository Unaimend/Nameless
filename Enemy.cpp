//
//  Enemy.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Enemy.h"

Enemy::Enemy(sf::Sprite sprite, Player player)
{
    mPlayer = player;
    mEnemySprite = sprite;
    mLife = 100;
    mLifeString = std::to_string(mLife);
    mName = "Gegner";
};

Enemy::~Enemy(){};
void Enemy::render(sf::RenderWindow *window)
{
    window->draw(mEnemySprite);
};
void Enemy::update(double frametime)
{


};

void Enemy::attack(){};