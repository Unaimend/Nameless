//
//  Fireball.cpp
//  Nameless
//
//  Created by Thomas Dost on 06.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Fireball.h"


Fireball::Fireball(Player& player, Zombie &target )
{
    pEnemy = &target;
    pPlayer = &player;
};

Fireball::~Fireball()
{

};

void Fireball::castSpell()
{
    
};

bool Fireball::hasBeenHit()
{
    
    sf::FloatRect meb = pEnemy->getBounds();
    sf::FloatRect mpb = pPlayer->getPlayerBoundingBoxes();
    std::cout << meb.left << std::endl;
    if (mpb.intersects(meb)) {
        std::cout << "boom" << std::endl;
    }

};

void Fireball::render(sf::RenderWindow *window)
{
   //window->draw(mFireball);
};

void Fireball::update()
{
    hasBeenHit();
};