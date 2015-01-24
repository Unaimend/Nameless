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
    
    Tile()
    {
    };
    Tile(bool isdoor, int xtele, int ytele, int xpos, int ypos, bool iscollider, sf::Sprite sprite) :
    mIsDoor(isdoor), mTeleportToX(xtele), mTeleportToY(ytele), mPosX(xpos), mPosY(ypos),
    mIsCollider(iscollider), mSprite(sprite)
    {
    };
    
    ~Tile(){};
    virtual void    render(sf::RenderWindow& window) = 0;
    virtual void    update() = 0;
    float           getPosX(){};
    float           getPosY(){};
    bool            getIsCollission(){};

    

private:
    bool        mIsDoor;
    int         mTeleportToX;
    int         mTeleportToY; //Die Koordinaten zu den telportiert wird, wenn's ne Tür ist
    float       mPosX;
    float       mPosY;
    bool        mIsCollider;
    sf::Sprite mSprite;
};
#endif /* defined(__Nameless__Tiles__) */
