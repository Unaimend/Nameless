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
#include "Shot.h"
#include "Gun.h"
#include "TestGun.h"
class ItemManger
{
public:
    ItemManger(Player& player);

    void setItemVektor(std::vector<Item> &itemvektor){mItemVektor = itemvektor;};
    void setInventoryVektor(std::vector<Item> &inventoryvektor){mInventoyVektor = inventoryvektor;};
    
    std::vector<Item> getItemVektor(){return mItemVektor;};
    std::vector<Item> getInventoryVektor(){return mInventoyVektor;};
    
    void update(Player &player, double frametime);
    void render(sf::RenderWindow *window);
    void fixrender(sf::RenderWindow *window);
    void eventHandling(sf::Event event);
    
private:
    void setItemPositions();
   
    
    
    //Testcode
    bool mItemInvVis = false;
    Item *pTest;
    Item *pTest2;
    Item *pTest3;
    Item *pTest4;
    Item *pTest5;
    Item *pTest6;
    Item *pTest7;
    Item *pTest8;
    Item *pTest9;
    Item *pTest10;
    Item *pTest11;
    Item *pTest12;
    Item *pTest13;
    Item *pTest14;
    Item *pTest15;
    Item *pTest16;
    Item *pTest17;
    Item *pTest18;
    Item *pTest19;
    Item *pTest20;
    Item *pTest21;
    Item *pTest22;
    Item *pTest23;
    Item *pTest24;
    Item *pTest25;
    Item *pTest26;
    Item *pTest27;
    Item *pTest28;
    Item *pTest29;
    Item *pTest30;
    Item *pTest31;
    
    Gun_TestGun *pTestGun;
    Player mPlayer;
    sf::Event mEvent;
    int mIventoryCounterX = 0;
    int mIventoryCounterY = 0;
    int mIvenCOunterAll = 0;
    double mFrametime = 0;
    std::vector<Item> mAllItems;
    std::vector<Item> mItemVektor;
    std::vector<Item> mInventoyVektor;
    std::vector<Item>::iterator mItemsIter = mAllItems.begin();
    std::vector<Shot*> mShootVector;
    std::vector<sf::RectangleShape*> mTestVector;
    std::vector<int> testvec = {0,1};
    int test = 0;
};
#endif /* defined(__Nameless__ItemManger__) */
