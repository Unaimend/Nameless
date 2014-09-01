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
    mItemVektor.push_back(*pTest);
    mInventoyVektor.push_back(*pTest2);
    pTest->setOirigin(32/2, 32/2);
    

};

void ItemManger::update(Player *player, double frametime)
{
    mPlayer = *player;
    mFrametime = frametime;
};

void ItemManger::render(sf::RenderWindow *window)
{
    for (mtestiter = mItemVektor.begin(); mtestiter != mItemVektor.end(); mtestiter++)
    {
        mtestiter->render(window);
    }
};

void ItemManger::fixrender(sf::RenderWindow *window)
{
    
    if (mItemInvVis) {
        for(auto it : mInventoyVektor)
        {
            it.render(window);
        }
    }
    
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
                std::cout << "LÖSCH MOCH BITCH"<< std::endl;
                mIventoryCounter++;
                switch (mIventoryCounter)
                {
                    case 1:
                        pTest3 = new Testitem();
                        pTest3->setPositiond(sf::Vector2f(mPlayer.getInvPosX() + 56 * 1 ,mPlayer.getInvPosY()  ));
                        pTest3->setScale(2, 2);
                        mInventoyVektor.push_back(*pTest3);
                        break;
                    case 2:
                        pTest3 = new Testitem();
                        pTest3->setPositiond(sf::Vector2f(mPlayer.getInvPosX() + 56.5  * 2,mPlayer.getInvPosY()  ));
                        pTest3->setScale(2, 2);
                        mInventoyVektor.push_back(*pTest3);
                        break;
                    case 3:
                        pTest3 = new Testitem();
                        pTest3->setPositiond(sf::Vector2f(mPlayer.getInvPosX() + 56.33 * 3,mPlayer.getInvPosY()  ));
                        pTest3->setScale(2, 2);
                        mInventoyVektor.push_back(*pTest3);
                        break;
                    case 4:
                        pTest3 = new Testitem();
                        pTest3->setPositiond(sf::Vector2f(mPlayer.getInvPosX() + 56.25 * 4,mPlayer.getInvPosY()  ));
                        pTest3->setScale(2, 2);
                        mInventoyVektor.push_back(*pTest3);
                        break;
                    case 5:
                        pTest3 = new Testitem();
                        pTest3->setPositiond(sf::Vector2f(mPlayer.getInvPosX() + 56  * 0,mPlayer.getInvPosY() + 56 ));
                        pTest3->setScale(2, 2);
                        mInventoyVektor.push_back(*pTest3);
                        break;
                    default:
                        break;
                }
                
            }
        }
        
    }

   

};