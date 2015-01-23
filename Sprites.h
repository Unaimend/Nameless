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
    sf::Texture &TileSet_ATextureRef = TileSet_ATexture;
    sf::Texture NPCHolzfällerTexture;
    sf::Texture NPCZombieTexture;
    sf::Texture BlackTexture;
    sf::Texture mStraßenTexture;
    sf::Texture mBetonTexture;
    sf::Texture mMittelSauber;
    sf::Texture mWohnBlock_01;
    
    sf::Sprite  NPCZombieSprite;
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
    sf::Sprite BlackSprite;
    sf::Sprite  *pStraßenSprite;
    sf::Sprite *pBeton;
    sf::Sprite *pMittelSauberSprite;
    sf::Sprite *pMittelHochSauberSprite;
    sf::Sprite *pBürgerSteigObenMitte;
    sf::Sprite *pBürgerSteigUntenMitte;
    sf::Sprite  *pKreuzung;
    sf::Sprite  *pWohnBlock_01;
    sf::Sprite  *pBürgerSteigLinks;
    sf::Sprite  *pBürgerSteigRechts;
    sf::Sprite  *pKurveLinks;
    sf::Sprite  *pKurveRechts;
  

};
#endif /* defined(__Nameless__Sprites__) */
