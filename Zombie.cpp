//
//  Zombie.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Zombie.h"
Zombie::Zombie(sf::Sprite sprite, Player player, std::string name, int life, int xpos, int ypos)
{
    mEnemySprite = sprite;
    mLife = life;
    mLifeString = std::to_string(mLife);
    mPlayer = player;
    mName = name;
    mLife = life;
    mXpos = xpos;
    mYpos = ypos;
    mEnemySprite.setPosition(mXpos, mYpos);

    pAnimation = new NpcAnimation(Sprites::NPCZombieSprite, 32,32, 50,0);
};
Zombie::~Zombie(){};

void Zombie::render(sf::RenderWindow *window)
{
    pAnimation->render(window);
    //window->draw(mEnemySprite);
};

void Zombie::update(double frametime)
{
    pAnimation->move(frametime, 100);
};

void Zombie::attack(){};