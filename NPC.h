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
#include "SFML/Graphics.hpp"
#include "DialogSystem.h"
class NPC
{
public:
    NPC();
    void render(sf::RenderWindow *window);
protected:
private:
    sf::RectangleShape hi;
    DialogSystem *ptest;
   
};
#endif /* defined(__Nameless__NPC__) */
