//
//  Fireball.cpp
//  Nameless
//
//  Created by Thomas Dost on 06.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Fireball.h"


Fireball::Fireball(Player& player, Enemy &target )
{
    mFireball.setPosition(player.getPlayerSpritePosX(), player.getPlayerSpritePosY());
    mEnemyGlobalBounds = target.getBoundingBoxes();
    mPlayerGlobalBounds = player.getPlayerBoundingBoxes();
};

Fireball::~Fireball()
{

};

void Fireball::castSpell()
{
    
};

bool Fireball::hasBeenHit()
{
    

};