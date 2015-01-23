//
//  Tiles.h
//  Nameless
//
//  Created by Thomas Dost on 23.01.15.
//  Copyright (c) 2015 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Tiles__
#define __Nameless__Tiles__

#include <stdio.h>
#include "SFML/Graphics.hpp"
class Tile
{
public:
    Tile(bool isdoor, int xtele, int ytele, int xpos, int ypos, bool iscollider);
    virtual ~Tile();
    virtual void    render(sf::RenderWindow& window);
    virtual void    update();
    virtual int     getID();
    virtual float   getPosX();
    virtual float   getPosY();
    virtual bool    getIsCollission();

    

private:
    bool    mIsDoor;
    int     mTeleportToX;
    int     mTeleportToY; //Die Koordinaten zu den telportiert wird, wenn's ne Tür ist
    float   mPosX;
    float   mPosY;
    bool    mIsCollider;
    int     mID;
};
#endif /* defined(__Nameless__Tiles__) */
