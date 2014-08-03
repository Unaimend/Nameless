//
//  NPC.cpp
//  Nameless
//
//  Created by Thomas Dost on 31.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "NPC.h"
NPC::NPC(std::string text, Player player)
{
    
    mNPCtext = text;
    
    mNpc.setPosition(230, 100);
    mNpc.setSize(sf::Vector2f(20,20));
    NpcDialog = new DialogSystem(mNPCtext, mNpc.getPosition().x, mNpc.getPosition().y - 10,100);
};

void NPC::render(sf::RenderWindow *window)
{
    NpcDialog->render(window);
    window->draw(mNpc);
};