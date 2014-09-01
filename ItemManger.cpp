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
    pTest2->setScale(5, 5);

    pTest->setOnGound(false);
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
    for (mItemsIter = mAllItems.begin(); mItemsIter != mAllItems.end(); mItemsIter++)
    {
     
        if (mItemsIter->getOnGround() == false)
        {
            mItemsIter->render(window);
        }
      
       
    }
};

void ItemManger::fixrender(sf::RenderWindow *window)
{
    
//    if (mItemInvVis) {
//        for(auto it : mAllItems)
//        {
//            if (it.getOnGround() == false)
//            {
//                it.render(window);
//            }
//            
//        }
//    }
    
};

void ItemManger::eventHandling(sf::Event event)
{
    mEvent = event;
    pTest->update(mFrametime);
    mItemInvVis = mPlayer.getInventoryVis();
    //std::cout << "ITEMMANAGER" << std::endl;
    for (mtestiter = mItemVektor.begin(); mtestiter != mItemVektor.end(); mtestiter++)
    {
        if ((mtestiter->getPositionX() - mPlayer.getPlayerSpritePosX() <24 && mtestiter->getPositionX() - mPlayer.getPlayerSpritePosX() > -24) && (mtestiter->getPositionY() - mPlayer.getPlayerSpritePosY() < 24 && mtestiter->getPositionY() - mPlayer.getPlayerSpritePosY()  > - 24))
        {
            if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::E)
            {
                //std::cout << "LÖSCH MOCH BITCH"<< std::endl;
                mIventoryCounter++;
                switch (mIventoryCounter)
                {
                    case 1:
                       
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:
                        break;
                }
                
            }
        }
        
    }

   

};