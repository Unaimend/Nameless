//
//  NpcAnimation.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "NpcAnimation.h"
NpcAnimation::NpcAnimation(sf::Sprite Spritesheet, int SpriteHeigth, int SpriteWidth, int xpos, int ypos, int maxleft, int maxrigth, int maxup, int maxdown, Player &player, bool follow, float aggrotime, float aggrorange)
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
    mPlayer = player;
    mShouldFollow = follow;
    mAggroRange = aggrorange;
    mAggroDuration = 10;
};


void NpcAnimation::move(double frametime, int Endurance)
{
    mClock.getElapsedTime().asSeconds();
    
    mLPosX = mSpriteSheet.getPosition().x;
    mLPosY = mSpriteSheet.getPosition().y;

    if (((mSpriteSheet.getPosition().x - mPlayer.getPlayerSpritePosX() < 75 && mSpriteSheet.getPosition().x - mPlayer.getPlayerSpritePosX() > -75) && ((mSpriteSheet.getPosition().y - mPlayer.getPlayerSpritePosY() < 75) && mSpriteSheet.getPosition().y - mPlayer.getPlayerSpritePosY() > -75)) )
    {
        mAggroTime.restart();
    }
    if (mShouldFollow) {
        if ((mSpriteSheet.getPosition().y - 150 > mPlayer.getPlayerSpritePosY() && mFollowDown == true) || mAggroTime.getElapsedTime().asSeconds() > mAggroDuration)
        {
            mFollowDown = false;
           // mSpriteSheet.move(0, -100 * frametime);
            
        }
        if ((mSpriteSheet.getPosition().y + 150 < mPlayer.getPlayerSpritePosY() && mFollowUp == true) || mAggroTime.getElapsedTime().asSeconds() > mAggroDuration)
        {
            mFollowUp = false;
            //mSpriteSheet.move(0, 100 * frametime);
        }
        if ((mSpriteSheet.getPosition().x + 150 < mPlayer.getPlayerSpritePosX() && mFollowLeft == true) || mAggroTime.getElapsedTime().asSeconds() > mAggroDuration)
        {
            //mSpriteSheet.move(100 * frametime, 0);
            mFollowLeft = false;
        }
        if ((mSpriteSheet.getPosition().x - 150 > mPlayer.getPlayerSpritePosX() &&  mFollowRight == true) || mAggroTime.getElapsedTime().asSeconds() > mAggroDuration)
        {
            
            //mSpriteSheet.move(-100 * frametime, 0);
            mFollowRight = false;
        }
        
        
        
        if (mSpriteSheet.getPosition().y - 50 < mPlayer.getPlayerSpritePosY() && mFollowDown == false && mAggroTime.getElapsedTime().asSeconds() < mAggroDuration)
        {
            mFollowDown = true;
           
        }
        if (mSpriteSheet.getPosition().y  + 50 > mPlayer.getPlayerSpritePosY() && mFollowUp == false && mAggroTime.getElapsedTime().asSeconds() < mAggroDuration)
        {
            mFollowUp = true;
           
        }
        if (mSpriteSheet.getPosition().x + 50 > mPlayer.getPlayerSpritePosX() && mFollowLeft == false && mAggroTime.getElapsedTime().asSeconds() < mAggroDuration)
        {
            mFollowLeft = true;
      
        }
        if (mSpriteSheet.getPosition().x - 50 < mPlayer.getPlayerSpritePosX()  && mFollowRight == false && mAggroTime.getElapsedTime().asSeconds() < mAggroDuration )
        {
            mFollowRight = true;

        }
        
        if (mFollowDown) {
            mSpriteSheet.move(0, 150 * frametime);
        }
        if (mFollowUp) {
            mSpriteSheet.move(0, -150 * frametime);
        }
        if (mFollowLeft) {
            mSpriteSheet.move(-150 * frametime, 0);
        }
        if (mFollowRight) {
            mSpriteSheet.move(150 * frametime, 0);
        }
    
        
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







//
//if (((mSpriteSheet.getPosition().x - mPlayer.getPlayerSpritePosX() < 75 && mSpriteSheet.getPosition().x - mPlayer.getPlayerSpritePosX() > -75) && ((mSpriteSheet.getPosition().y - mPlayer.getPlayerSpritePosY() < 75) && mSpriteSheet.getPosition().y - mPlayer.getPlayerSpritePosY() > -75)) )
//{
//    std::cout << "ALLE SIND COOL" << std::endl;
//}