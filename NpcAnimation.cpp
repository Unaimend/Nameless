//
//  NpcAnimation.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "NpcAnimation.h"
NpcAnimation::NpcAnimation(sf::Sprite Spritesheet, int SpriteHeigth, int SpriteWidth, int xpos, int ypos, int maxleft, int maxrigth, int maxup, int maxdown)
{
    mSpriteSheet    = Spritesheet;
    mSubRect.left   = 32;
    mSubRect.top    = 64;
    mSubRect.width  = SpriteWidth;
    mSubRect.height = SpriteHeigth;
    mMaxLeftPos     = maxleft;
    mMaxRightPos    = maxrigth;
    mMaxUpPos       = maxup;
    mMaxDownPos     = maxdown;
    
    mSpriteSheet.setTextureRect(mSubRect);
    mCurrentSprite.setPosition(0, 0);
    mSpriteSheet.setPosition(xpos, ypos);
};


void NpcAnimation::move(double frametime, int Endurance)
{
    mClock.getElapsedTime().asSeconds();
    
    mLPosX = mSpriteSheet.getPosition().x;
    mLPosY = mSpriteSheet.getPosition().y;
    if   (mSpriteSheet.getPosition().x > mMaxLeftPos -mSpriteSheet.getScale().x && mSpriteSheet.getPosition().x < mMaxRightPos && mGoRight == true)
    {
          mSpriteSheet.move(50*frametime,0);
    }
    else
    {
        mGoRight = false;
        mGoLeft = true;
    }
    if (mSpriteSheet.getPosition().x > mMaxLeftPos && mGoLeft)
    {
         mSpriteSheet.move(-50*frametime,0);
    }
    else
    {
        mGoRight = true;
        mGoLeft = false;
    }
    mCPosX = mSpriteSheet.getPosition().x;
    mCPosY = mSpriteSheet.getPosition().y;
    
    if (mLPosY < mCPosY)
    {
        mSubRect.left = 32;
        mSubRect.top = 64;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.3f)
        {
            mSubRect.left = 0;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
            
        }
        if (mClock.getElapsedTime().asSeconds() > 0.6f)
        {
            mSubRect.left = 64;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }        
    }
    else if (mLPosY > mCPosY)
    {
 
        mSubRect.left = 32;
        mSubRect.top = 0;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.3f)
        {
            mSubRect.left = 0;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
            
        }
        if (mClock.getElapsedTime().asSeconds() > 0.6f)
        {
            mSubRect.left = 64;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
    }

    else if (mLPosX > mCPosX)
    {
        mSubRect.left = 32;
        mSubRect.top = 96;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.3f)
        {
            mSubRect.left = 0;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
            
        }
        if (mClock.getElapsedTime().asSeconds() > 0.6f)
        {
            mSubRect.left = 64;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
    }
    else if (mLPosX < mCPosX)
    {
        mSubRect.left = 32;
        mSubRect.top = 32;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.3f)
        {
            mSubRect.left = 0;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
        }
        if (mClock.getElapsedTime().asSeconds() > 0.6f)
        {
            mSubRect.left = 64;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
    }

};

void NpcAnimation::render(sf::RenderWindow *window)
{
    window->draw(mSpriteSheet);
};