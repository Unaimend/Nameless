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
#include "Testitem.h"
#include "SFML/Graphics.hpp"
#include  <vector>
#include "Player.h"
class ItemManger
{
public:
    ItemManger(Player &player);

    void setItemVektor(std::vector<Item> &itemvektor){mItemVektor = itemvektor;};
    void setInventoryVektor(std::vector<Item> &inventoryvektor){mInventoyVektor = inventoryvektor;};
    
    std::vector<Item> getItemVektor(){return mItemVektor;};
    std::vector<Item> getInventoryVektor(){return mInventoyVektor;};
    
    void update(Player &player);
    void render(sf::RenderWindow *window);
    void fixrender(sf::RenderWindow *window);
private:
    std::vector<Item> mItemVektor;
    std::vector<Item> mInventoyVektor;
    
    
    //Testcode
    bool mItemInvVis = false;
    Item *pTest;
    Item *pTest2;
    std::vector<Item> testvektor;
    std::vector<Item> Inventoryvektor;
    std::vector<Item>::iterator mtestiter2 = Inventoryvektor.begin();
    std::vector<Item>::iterator mtestiter = testvektor.begin();
    Player mPlayer;

};
#endif /* defined(__Nameless__ItemManger__) */
