//
//  Zombie.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Zombie.h"
Zombie::Zombie(sf::Sprite sprite, Player &player, std::string name, int life, int xpos, int ypos, int maxrigth, int maxup, int maxdown, float aggrorange, float aggrotime)
{
    mEnemySprite    = sprite;
    mLife           = life;
    mLifeString     = std::to_string(mLife);
    mPlayer         = player;
    mName           = name;
    mLife           = life;
    mXpos           = xpos;
    mYpos           = ypos;
    mMaxRigth       = maxrigth;
    mAggroRange     = aggrorange;
    mAggrotime      = aggrotime;
    pAnimation      = new NpcAnimation(mEnemySprite, 32,32, 50,0,xpos, mMaxRigth,mMaxUp,mMaxDown, player, true, mAggroRange, mAggrotime);
    mEnemySprite.setPosition(mXpos, mYpos);
};
Zombie::~Zombie(){};

void Zombie::render(sf::RenderWindow *window) const
{
    pAnimation->render(window);
};

void Zombie::update(double frametime) const
{
    pAnimation->move(frametime, 100);
};

void Zombie::attack() const
{};