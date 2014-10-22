//
//  NpcAnimation.h
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__NpcAnimation__
#define __Nameless__NpcAnimation__

#include <iostream>
#include "Player.h"
#include "SFML/Graphics.hpp"

class NpcAnimation
{
public:
    NpcAnimation(sf::Sprite SpriteSheet, int SpriteHeigth, int SpriteWidth, int xpos, int ypos, int maxleft, int maxrigthm, int maxup, int maxdown, Player &player, bool follow, float aggrotime, float aggrorange);
    sf::Sprite      getSprite(){return mSpriteSheet;};
    sf::FloatRect   getEnemyBoundingBoxes(){return mSpriteSheet.getGlobalBounds();}
    void            move(double frametime, int Endurance);
    void            render(sf::RenderWindow *window);
    float           getAnimationSpritePosX(){return mSpriteSheet.getPosition().x;};
    float           getAnimationSpritePosY(){return mSpriteSheet.getPosition().y;};

private:
    sf::Sprite  mSpriteSheet;
    sf::IntRect mSubRect;
    sf::Sprite  mCurrentSprite;
    sf::Clock   mClock;
    Player      mPlayer;
    sf::Clock   mAggroTime;
    int         mCPosX;
    int         mCPosY;
    int         mLPosX;
    int         mLPosY;
    int         mMaxLeftPos;
    int         mMaxRightPos;
    int         mMaxUpPos;
    int         mMaxDownPos;
    bool        mGoRight = true;
    bool        mGoLeft = false;
    bool        mGoDown = true;
    bool        mGoUp = false;
    bool        mFollowLeft = false;
    bool        mFollowRight = false;
    bool        mFollowUp = false;
    bool        mFollowDown = false;
    bool        mShouldFollow = false;
    float       mAggroRange;
    float       mAggroDuration;
};
#endif /* defined(__Nameless__NpcAnimation__) */
