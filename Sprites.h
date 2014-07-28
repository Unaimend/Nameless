//
//  Sprites.h
//  Nameless
//
//  Created by Thomas Dost on 28.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Sprites__
#define __Nameless__Sprites__

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Logfile.h"

class Sprites
{
public:
     Sprites();
    virtual ~Sprites();
protected:
    
    Logfile *pLog;
 
    
    sf::Texture WasserTexture;
    sf::Texture WegTexture;
    sf::Texture PlayerTexture;
    sf::Texture InventoryTexture;
    
    
    sf::Sprite  WasserSprite;
    sf::Sprite  WegSprite;
    sf::Sprite  PlayerSprite;
    sf::Sprite InventorySprite;
};
#endif /* defined(__Nameless__Sprites__) */
