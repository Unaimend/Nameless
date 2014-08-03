//
//  NPC.cpp
//  Nameless
//
//  Created by Thomas Dost on 31.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "NPC.h"
NPC::NPC(std::string text, Player player, sf::Sprite sprite)
{
    
    mNPCtext = text;
    mPlayer = player;
    
    mNpcSprite = sprite;
    
    mNpc.setPosition(230, 100);
    mNpc.setSize(sf::Vector2f(20,20));
    mNpc.setOrigin(mNpc.getScale().x/2, mNpc.getScale().y/2);
    NpcDialog = new DialogSystem(mNPCtext, mNpc.getPosition().x, mNpc.getPosition().y - 10,100);
};

void NPC::render(sf::RenderWindow *window)
{   std::cout << mNpc.getPosition().x - mPlayer.getPlayerSpritePosX()<< std::endl;
    std::cout << mNpc.getPosition().y - mPlayer.getPlayerSpritePosY()<< std::endl;
    
    
    if (((mNpc.getPosition().x - mPlayer.getPlayerSpritePosX() < 100 && mNpc.getPosition().x - mPlayer.getPlayerSpritePosX() > -100) && ((mNpc.getPosition().y - mPlayer.getPlayerSpritePosY() < 100) && mNpc.getPosition().y - mPlayer.getPlayerSpritePosY() > -100)) && mShowDialog == true )  {
        NpcDialog->render(window);
    }
    
    window->draw(mNpc);
};



void NPC::setEvent(sf::Event event)
{
    mEvent = event;
    if (mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
        if (mShowDialog == true) {
            mShowDialog = false;
        }
        else
        {
            mShowDialog = true;
        }
    }
    
};