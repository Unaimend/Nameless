//
//  GuiSystem.h
//  Nameless
//
//  Created by Thomas Dost on 28.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__GuiSystem__
#define __Nameless__GuiSystem__
#include "SFML/Graphics.hpp"
#include "Sprites.h"
class GuiSystem : Sprites
{
public:
    GuiSystem();
    void render();
    void update();
protected:
private:

};
#endif /* defined(__Nameless__GuiSystem__) */
