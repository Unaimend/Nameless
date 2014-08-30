//
//  ItemManger.cpp
//  Nameless
//
//  Created by Thomas Dost on 30.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "ItemManger.h"
ItemManger::ItemManger(Player &player)
{
    mPlayer = player;
    pTest = new Testitem();
    pTest2 = new Testitem();
    pTest2->setPositiond(sf::Vector2f(mPlayer.getInvPosX(),mPlayer.getInvPosY()));
    pTest2->setScale(2, 2);
    testvektor.push_back(*pTest);
    Inventoryvektor.push_back(*pTest2);

};

void ItemManger::update(Player &player)
{
    mItemInvVis = player.getInventoryVis();
};

void ItemManger::render(sf::RenderWindow *window)
{
    for (mtestiter = testvektor.begin(); mtestiter != testvektor.end(); mtestiter++)
    {
        mtestiter->render(window);
    }
};

void ItemManger::fixrender(sf::RenderWindow *window)
{
    
    if (mItemInvVis) {
        for(auto it : Inventoryvektor)
        {
            it.render(window);
        }
    }
    
};