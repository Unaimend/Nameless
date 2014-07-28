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

    
    WasserSprite.setTexture(WasserTexture);
    WegSprite.setTexture(WegTexture);
    PlayerSprite.setTexture(PlayerTexture);
    InventorySprite.setTexture(InventoryTexture);
    pLog->writeToFile("Alle Sprites geladen");
    pLog->closeFile();
    
    
}

Sprites::~Sprites()
{
   
};