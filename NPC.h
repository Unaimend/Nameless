//
//  NPC.h
//  Nameless
//
//  Created by Thomas Dost on 31.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__NPC__
#define __Nameless__NPC__

#include <iostream>
#include "DialogSystem.h"
#include "Player.h"

class NPC
{
public:
    NPC(std::string text, Player player, sf::Sprite sprite, float xpos, float ypos);
    void render(sf::RenderWindow *window);
    
    void setEvent(sf::Event event);
protected:
private:
    std::string mNPCtext;

    sf::Sprite mNpcSprite;
    float mNpcPosX = 0;
    float mNpcPosY = 0;
    DialogSystem *NpcDialog;
    Player mPlayer;
    sf::Event mEvent;
    bool mShowDialog = false;
};
#endif /* defined(__Nameless__NPC__) */
