#include "ItemManger.h"
ItemManger::ItemManger(Player& player)
{
    mPlayer = player;
    pTest = new Testitem();
    pTest->setPositiond(sf::Vector2f(50,50));
    pTest->setOnGound(true);
    
    pTest2 = new Testitem();
    pTest2->setPositiond(sf::Vector2f(50,100));
    pTest2->setScale(1, 1);
    pTest2->setOnGound(true);

    pTest3 = new Testitem();
    pTest3->setPositiond(sf::Vector2f(50,150));
    pTest3->setScale(1, 1);
    pTest3->setOnGound(true);
    
    pTest4 = new Testitem();
    pTest4->setPositiond(sf::Vector2f(50,200));
    pTest4->setScale(1, 1);
    pTest4->setOnGound(true);
    
    pTest5 = new Testitem();
    pTest5->setPositiond(sf::Vector2f(50,250));
    pTest5->setScale(1, 1);
    pTest5->setOnGound(true);
    
    pTest6 = new Testitem();
    pTest6->setPositiond(sf::Vector2f(50,300));
    pTest6->setScale(1, 1);
    pTest6->setOnGound(true);
    
    pTest7 = new Testitem();
    pTest7->setPositiond(sf::Vector2f(50,350));
    pTest7->setScale(1, 1);
    pTest7->setOnGound(true);
    
    pTest8 = new Testitem();
    pTest8->setPositiond(sf::Vector2f(50,400));
    pTest8->setScale(1, 1);
    pTest8->setOnGound(true);
    
    pTest9 = new Testitem();
    pTest9->setPositiond(sf::Vector2f(50,450));
    pTest9->setScale(1, 1);
    pTest9->setOnGound(true);
    
    pTest10 = new Testitem();
    pTest10->setPositiond(sf::Vector2f(50,500));
    pTest10->setScale(1, 1);
    pTest10->setOnGound(true);
    
    pTest11 = new Testitem();
    pTest11->setPositiond(sf::Vector2f(50,550));
    pTest11->setScale(1, 1);
    pTest11->setOnGound(true);
    
    pTest12 = new Testitem();
    pTest12->setPositiond(sf::Vector2f(50,600));
    pTest12->setScale(1, 1);
    pTest12->setOnGound(true);
    
    pTest13 = new Testitem();
    pTest13->setPositiond(sf::Vector2f(50,650));
    pTest13->setScale(1, 1);
    pTest13->setOnGound(true);
    
    pTest14 = new Testitem();
    pTest14->setPositiond(sf::Vector2f(50,700));
    pTest14->setScale(1, 1);
    pTest14->setOnGound(true);
    
    pTest15 = new Testitem();
    pTest15->setPositiond(sf::Vector2f(50,750));
    pTest15->setScale(1, 1);
    pTest15->setOnGound(true);
    
    pTest16 = new Testitem();
    pTest16->setPositiond(sf::Vector2f(50,800));
    pTest16->setScale(1, 1);
    pTest16->setOnGound(true);
    
    pTest17 = new Testitem();
    pTest17->setPositiond(sf::Vector2f(50,850));
    pTest17->setScale(1, 1);
    pTest17->setOnGound(true);
    
    pTest18 = new Testitem();
    pTest18->setPositiond(sf::Vector2f(50,900));
    pTest18->setScale(1, 1);
    pTest18->setOnGound(true);
    
    pTest19 = new Testitem();
    pTest19->setPositiond(sf::Vector2f(50,950));
    pTest19->setScale(1, 1);
    pTest19->setOnGound(true);
    
    pTest20 = new Testitem();
    pTest20->setPositiond(sf::Vector2f(50,950));
    pTest20->setScale(1, 1);
    pTest20->setOnGound(true);
    
    pTest21 = new Testitem();
    pTest21->setPositiond(sf::Vector2f(50,1000));
    pTest21->setScale(1, 1);
    pTest21->setOnGound(true);
    
    pTest22 = new Testitem();
    pTest22->setPositiond(sf::Vector2f(50,1050));
    pTest22->setScale(1, 1);
    pTest22->setOnGound(true);
    
    pTest23 = new Testitem();
    pTest23->setPositiond(sf::Vector2f(50,1100));
    pTest23->setScale(1, 1);
    pTest23->setOnGound(true);
    
    pTest24 = new Testitem();
    pTest24->setPositiond(sf::Vector2f(50,1150));
    pTest24->setScale(1, 1);
    pTest24->setOnGound(true);
    
    pTest25 = new Testitem();
    pTest25->setPositiond(sf::Vector2f(50,1200));
    pTest25->setScale(1, 1);
    pTest25->setOnGound(true);
    
    pTest26 = new Testitem();
    pTest26->setPositiond(sf::Vector2f(50,1250));
    pTest26->setScale(1, 1);
    pTest26->setOnGound(true);
    
    pTest27 = new Testitem();
    pTest27->setPositiond(sf::Vector2f(50,1300));
    pTest27->setScale(1, 1);
    pTest27->setOnGound(true);
    
    pTest28 = new Testitem();
    pTest28->setPositiond(sf::Vector2f(50,1350));
    pTest28->setScale(1, 1);
    pTest28->setOnGound(true);
    
    pTest29 = new Testitem();
    pTest29->setPositiond(sf::Vector2f(50,1400));
    pTest29->setScale(1, 1);
    pTest29->setOnGound(true);
    
    pTest30 = new Testitem();
    pTest30->setPositiond(sf::Vector2f(50,1450));
    pTest30->setScale(1, 1);
    pTest30->setOnGound(true);

    pTest31 = new Testitem();
    pTest31->setPositiond(sf::Vector2f(100,50));
    pTest31->setScale(1, 1);
    pTest31->setOnGound(true);

    
    mAllItems.push_back(*pTest);
    mAllItems.push_back(*pTest2);
    mAllItems.push_back(*pTest3);
    mAllItems.push_back(*pTest4);
    mAllItems.push_back(*pTest5);
    mAllItems.push_back(*pTest6);
    mAllItems.push_back(*pTest7);
    mAllItems.push_back(*pTest8);
    mAllItems.push_back(*pTest9);
    mAllItems.push_back(*pTest10);
    mAllItems.push_back(*pTest11);
    mAllItems.push_back(*pTest12);
    mAllItems.push_back(*pTest13);
    mAllItems.push_back(*pTest14);
    mAllItems.push_back(*pTest15);
    mAllItems.push_back(*pTest16);
    mAllItems.push_back(*pTest17);
    mAllItems.push_back(*pTest18);
    mAllItems.push_back(*pTest19);
    mAllItems.push_back(*pTest20);
    mAllItems.push_back(*pTest21);
    mAllItems.push_back(*pTest22);
    mAllItems.push_back(*pTest23);
    mAllItems.push_back(*pTest24);
    mAllItems.push_back(*pTest25);
    mAllItems.push_back(*pTest26);
    mAllItems.push_back(*pTest27);
    mAllItems.push_back(*pTest28);
    mAllItems.push_back(*pTest29);
    mAllItems.push_back(*pTest30);
    mAllItems.push_back(*pTest31);

    
    
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
    if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::M) {
        
        mIvenCOunterAll--;
        setItemPositions();
    }
    
    if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::N) {
        
        mIvenCOunterAll++;
    }

    for (mItemsIter = mAllItems.begin(); mItemsIter != mAllItems.end(); mItemsIter++)
    {
        if ((mItemsIter->getPositionX() - mPlayer.getPlayerSpritePosX() <24 && mItemsIter->getPositionX() - mPlayer.getPlayerSpritePosX() > -24) && (mItemsIter->getPositionY() - mPlayer.getPlayerSpritePosY() < 24 && mItemsIter->getPositionY() - mPlayer.getPlayerSpritePosY()  > - 24))
        {
            if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::E)
            {
                if (mIvenCOunterAll < 30)
                {
                    mItemsIter->setScale(2, 2);
                    mItemsIter->setOnGound(false);
                    
                    if (mItemsIter->getOnGround() == false)
                    {
                        mItemsIter->setPositiond(sf::Vector2f(mPlayer.getInvPosX() + 56 * (mIvenCOunterAll % 5)  ,mPlayer.getInvPosY() + 56 * int(mIvenCOunterAll / 5)));
                    }
                    mIvenCOunterAll++;
                }
            }
        }
    }
};


void ItemManger::setItemPositions()
{
    for (mItemsIter = mAllItems.begin(); mItemsIter != mAllItems.end(); mItemsIter++)
    {
       
           
                if (mIvenCOunterAll > 0)
                {
                    //mItemsIter->setScale(2, 2);
                    //mItemsIter->setOnGound(false);
                    
                    if (mItemsIter->getOnGround() == false)
                    {
                        mItemsIter->setPositiond(sf::Vector2f(mPlayer.getInvPosX() + 56 * (mIvenCOunterAll % 5)  ,mPlayer.getInvPosY() + 56 * int(mIvenCOunterAll / 5)));
                    }
                   
                }
    }
    
    std::cout << mIvenCOunterAll << std::endl;
};