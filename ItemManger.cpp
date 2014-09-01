//
//  ItemManger.cpp
//  Nameless
//
//  Created by Thomas Dost on 30.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "ItemManger.h"
ItemManger::ItemManger(Player& player)
{
    mPlayer = player;
    pTest = new Testitem();
    pTest2 = new Testitem();
    pTest2->setPositiond(sf::Vector2f(mPlayer.getInvPosX(),mPlayer.getInvPosY()));
    pTest2->setScale(2, 2);

    pTest->setOnGound(true);
    pTest2->setOnGound(false);
    pTest->setOirigin(32/2, 32/2);
    mAllItems.push_back(*pTest);
    mAllItems.push_back(*pTest2);
};

void ItemManger::update(Player *player, double frametime)
{
    mPlayer = *player;
    mFrametime = frametime;
};

void ItemManger::render(sf::RenderWindow *window)
{
    mItemInvVis = mPlayer.getInventoryVis();
    for (mItemsIter = mAllItems.begin(); mItemsIter != mAllItems.end(); mItemsIter++)
    {
        if (mItemsIter->getOnGround() == true)
        {
            mItemsIter->render(window);
        }
    }
};

void ItemManger::fixrender(sf::RenderWindow *window)
{
    mItemInvVis = mPlayer.getInventoryVis();
    for (mItemsIter = mAllItems.begin(); mItemsIter != mAllItems.end(); mItemsIter++)
    {
        if (mItemsIter->getOnGround() == false)
        {
            if (mItemInvVis)
            {
                  mItemsIter->render(window);
            }
        }
    }
    
};

void ItemManger::eventHandling(sf::Event event)
{
    mEvent = event;
    pTest->update(mFrametime);
  
    //std::cout << "ITEMMANAGER" << std::endl;
    for (mItemsIter = mAllItems.begin(); mItemsIter != mAllItems.end(); mItemsIter++)
    {
        if ((mItemsIter->getPositionX() - mPlayer.getPlayerSpritePosX() <24 && mItemsIter->getPositionX() - mPlayer.getPlayerSpritePosX() > -24) && (mItemsIter->getPositionY() - mPlayer.getPlayerSpritePosY() < 24 && mItemsIter->getPositionY() - mPlayer.getPlayerSpritePosY()  > - 24))
        {
            if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::E)
            {
                //std::cout << "LÖSCH MOCH BITCH"<< std::endl;
                mIventoryCounter++;
                std::cout <<"HI" << std::endl;
                mItemsIter->setOnGound(false);
//                switch (mIventoryCounter)
//                {
//                    case 1:
//                       
//                        break;
//                    case 2:
//                        break;
//                    case 3:
//                        break;
//                    case 4:
//                        break;
//                    case 5:
//                        break;
//                    default:
//                        break;
//                }
                
            }
        }
        
    }

   

};