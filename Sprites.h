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

class Sprites
{
public:
    Sprites();
  
protected:
    sf::Texture WasserTexture;
    sf::Texture WegTexture;
    
    sf::Sprite  WasserSprite;
    sf::Sprite  WegSprite;
  
};
#endif /* defined(__Nameless__Sprites__) */
