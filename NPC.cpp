//
//  NPC.cpp
//  Nameless
//
//  Created by Thomas Dost on 31.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "NPC.h"
NPC::NPC( Player player, sf::Sprite sprite, float xpos, float ypos, std::string text)
{
    
    mNPCtext = text;
    mPlayer = player;
    mNpcPosX = xpos;
    mNpcPosY = ypos;
    mNpcSprite = sprite;
    
    mNpcSprite.setPosition(mNpcPosX, mNpcPosY);
    mNpcSprite.setOrigin(mNpcSprite.getScale().x/2, mNpcSprite.getScale().y/2);
    NpcDialog = new DialogSystem(mNPCtext, mNpcSprite.getPosition().x, mNpcSprite.getPosition().y - 10,100);
};

void NPC::render(sf::RenderWindow *window)
{   //std::cout << mNpc.getPosition().x - mPlayer.getPlayerSpritePosX()<< std::endl;
    //std::cout << mNpc.getPosition().y - mPlayer.getPlayerSpritePosY()<< std::endl;
    
    
    if (((mNpcSprite.getPosition().x - mPlayer.getPlayerSpritePosX() < 75 && mNpcSprite.getPosition().x - mPlayer.getPlayerSpritePosX() > -75) && ((mNpcSprite.getPosition().y - mPlayer.getPlayerSpritePosY() < 75) && mNpcSprite.getPosition().y - mPlayer.getPlayerSpritePosY() > -75)) && mShowDialog == true )  {
        NpcDialog->render(window);
    }
    
    window->draw(mNpcSprite);
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