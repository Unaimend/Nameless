//
//  ItemManger.h
//  Nameless
//
//  Created by Thomas Dost on 30.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__ItemManger__
#define __Nameless__ItemManger__

#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "SFML/Graphics.hpp"
#include  <vector>
class ItemManger
{
public:
    ItemManger(std::vector<Item> &itemvenktor, std::vector<Inventory> &inventoryvektor);
    
    void setItemVektor(std::vector<Item> &itemvektor){mItemVektor = itemvektor;};
    void setInventoryVektor(std::vector<Inventory> &inventoryvektor){mInventoyVektor = inventoryvektor;};
    
    std::vector<Item> getItemVektor(){return mItemVektor;};
    std::vector<Inventory> getInventoryVektor(){return mInventoyVektor;};
    
    void update();
    void render(sf::RenderWindow *window);
private:
    std::vector<Item> mItemVektor;
    std::vector<Inventory> mInventoyVektor;

};
#endif /* defined(__Nameless__ItemManger__) */
