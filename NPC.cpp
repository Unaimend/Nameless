//
//  NPC.cpp
//  Nameless
//
//  Created by Thomas Dost on 31.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "NPC.h"
NPC::NPC()
{

  
    
    hi.setPosition(100, 100);
    hi.setSize(sf::Vector2f(20,20));
    ptest = new DialogSystem("HI", 200, 200, 20 );
};

void NPC::render(sf::RenderWindow *window)
{
    ptest->render(window);
    window->draw(hi);
};