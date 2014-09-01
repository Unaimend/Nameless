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
    ItemManger(Player& player);

    void setItemVektor(std::vector<Item> &itemvektor){mItemVektor = itemvektor;};
    void setInventoryVektor(std::vector<Item> &inventoryvektor){mInventoyVektor = inventoryvektor;};
    
    std::vector<Item> getItemVektor(){return mItemVektor;};
    std::vector<Item> getInventoryVektor(){return mInventoyVektor;};
    
    void update(Player *player, double frametime);
    void render(sf::RenderWindow *window);
    void fixrender(sf::RenderWindow *window);
    void eventHandling(sf::Event event);
private:
    
   
    
    
    //Testcode
    bool mItemInvVis = false;
    Item *pTest;
    Item *pTest2;
  

    Player mPlayer;
    sf::Event mEvent;
    int mIventoryCounter = 0;
    double mFrametime = 0;
    std::vector<Item> mAllItems;
    std::vector<Item> mItemVektor;
    std::vector<Item> mInventoyVektor;
    
    std::vector<Item>::iterator mItemsIter = mAllItems.begin();
    
    std::vector<int> testvec = {0,1};
    int test = 0;
};
#endif /* defined(__Nameless__ItemManger__) */
