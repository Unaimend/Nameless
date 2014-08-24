//
//  Inventory.cpp
//  Nameless
//
//  Created by Thomas Dost on 24.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Inventory.h"
Inventory::Inventory()
{
   
    mInventorySprite = Sprites::InventorySprite;
    mInventorySprite.setScale(3,3);
    
};
void Inventory::render(sf::RenderWindow *window)
{    if (mShowInventory == true)
     {
        window->draw(mInventorySprite);
     }
    
};

void Inventory::update()
{
    mInventorySprite.setPosition(mInventoryPosition);
   
};