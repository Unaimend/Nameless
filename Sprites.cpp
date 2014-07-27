//
//  Sprites.cpp
//  Nameless
//
//  Created by Thomas Dost on 28.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Sprites.h"

Sprites::Sprites()
{
    WasserTexture.loadFromFile("wasser.png");
    WegTexture.loadFromFile("weg01.png");
    
    WasserSprite.setTexture(WasserTexture);
    WegSprite.setTexture(WegTexture);
}