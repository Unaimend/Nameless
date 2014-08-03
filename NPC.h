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
    NPC(std::string text, Player player);
    void render(sf::RenderWindow *window);
protected:
private:
    std::string mNPCtext;
    sf::RectangleShape mNpc;
    DialogSystem *NpcDialog;
   
};
#endif /* defined(__Nameless__NPC__) */
