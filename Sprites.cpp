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
    pLog = new Logfile("Texture.log");
    
    
   
    if(WasserTexture.loadFromFile("wasser.png"))
        pLog->writeToFile("Wassertextur geladen");
    if(WegTexture.loadFromFile("weg01.png"))
        pLog->writeToFile("Wegtextur geladen");
    if(PlayerTexture.loadFromFile("player.png"))
        pLog->writeToFile("Spielertextur geladen");
    if(InventoryTexture.loadFromFile("inventar v01.png"))
        pLog->writeToFile("Inventartextur geladen");
    if(TileSet_ATexture.loadFromFile("Tileset A.png"))
        pLog->writeToFile("Tileset A geladen");


    
    WasserSprite.setTexture(WasserTexture);
    PlayerSprite.setTexture(PlayerTexture);
    InventorySprite.setTexture(InventoryTexture);
    mSubRect.left = 16; // of course, you'll have to fill it in with the right values...
    mSubRect.top = 16;
    mSubRect.width = 16;
    mSubRect.height = 16;
    pWegSprite = new sf::Sprite(TileSet_ATexture, mSubRect);
    mSubRect.left = 0; // of course, you'll have to fill it in with the right values...
    mSubRect.top = 48;
    mSubRect.width = 16;
    mSubRect.height = 16;
    pGrasSprite = new sf::Sprite(TileSet_ATexture, mSubRect);
    mSubRect.left = 0; // of course, you'll have to fill it in with the right values...
    mSubRect.top = 0;
    mSubRect.width = 16;
    mSubRect.height = 16;
    pGrasSpriteOL = new sf::Sprite(TileSet_ATexture, mSubRect);
    mSubRect.left = 16; // of course, you'll have to fill it in with the right values...
    mSubRect.top = 0;
    mSubRect.width = 16;
    mSubRect.height = 16;
    pGrasSpriteOBEN = new sf::Sprite(TileSet_ATexture, mSubRect);
    pLog->writeToFile("Alle Sprites geladen");
    pLog->closeFile();
    
    
}

Sprites::~Sprites()
{
   
};