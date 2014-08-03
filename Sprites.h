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
 
    sf::IntRect mSubRect;
    

    sf::Texture WasserTexture;
    sf::Texture WegTexture;
    sf::Texture PlayerTexture;
    sf::Texture InventoryTexture;
    sf::Texture TileSet_ATexture;
    sf::Texture NPCHolzfällerTexture;
    sf::Texture Hazs1;
    sf::Texture Haus2;
    
    sf::Sprite  WasserSprite;
    sf::Sprite  *pWegSprite;
    sf::Sprite  *pGrasSprite;
    sf::Sprite  *pGrasSpriteOL;
    sf::Sprite  *pGrasSpriteOBEN;
    sf::Sprite  *pGrasSpriteUNTEN;
    sf::Sprite  InventorySprite;
    sf::Sprite  Tileset_ASprite;
    sf::Sprite *pPlayerSprite;
    sf::Sprite *pNPCHolzfällerSprite;
    
    sf::Sprite  Haus1s;
    sf::Sprite  Haus2s;
    
};
#endif /* defined(__Nameless__Sprites__) */
