//
//  StraßenTile.h
//  Nameless
//
//  Created by Thomas Dost on 24.01.15.
//  Copyright (c) 2015 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Stra_enTile__
#define __Nameless__Stra_enTile__

#include <stdio.h>
#include "Tiles.h"
class StraßenTile : public Tile
{
public:
    ~StraßenTile(){};
    StraßenTile(bool isdoor, int xtele, int ytele, int xpos, int ypos, bool iscollider, sf::Sprite sprite);
    virtual void    render(sf::RenderWindow& window);
    virtual void    update();
    float   getPosX();
    float   getPosY();
    bool    getIsCollission();
    

};
#endif /* defined(__Nameless__Stra_enTile__) */
