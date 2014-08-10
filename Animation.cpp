//
//  Animation.cpp
//  Nameless
//
//  Created by Thomas Dost on 30.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Animation.h"

Animation::Animation(sf::Sprite Spritesheet, int SpriteHeigth, int SpriteWidth)
{
    mSpriteSheet = Spritesheet;
    mSubRect.left = 32;
    mSubRect.top = 64;
    mSubRect.width = SpriteWidth;
    mSubRect.height = SpriteHeigth;
    mSpriteSheet.setTextureRect(mSubRect);
    mCurrentSprite.setPosition(0, 0);
 
    
};


void Animation::move(double frametime, int &Endurance)
{   mClock.getElapsedTime().asSeconds();
    mLastXPos = mSpriteSheet.getPosition().x;
    mLastYPos = mSpriteSheet.getPosition().y;
    
    //std::cout << "TEST1 "  <<mLastXPos<< std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        mSpriteSheet.move(0,-50*frametime);
     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && Endurance > 0) {
            mSpriteSheet.move(0,-100*frametime);
            
        }
        mSubRect.left = 32;
        mSubRect.top = 0;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.3f) {
            mSubRect.left = 0;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
            
        }
        if (mClock.getElapsedTime().asSeconds() > 0.6f) {
            mSubRect.left = 64;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        mSpriteSheet.move(0,50*frametime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && Endurance > 0) {
            mSpriteSheet.move(0,100*frametime);
        }
        mSubRect.left = 32;
        mSubRect.top = 64;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.3f) {
           
            mSubRect.left = 0;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
            
        }
        if (mClock.getElapsedTime().asSeconds() > 0.6f) {
            mSubRect.left = 64;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
            
        }
       
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) )
    {
        mSpriteSheet.move(-50*frametime, 0);
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)&& Endurance > 0) {
            mSpriteSheet.move(-100*frametime, 0);
        }
        mSubRect.left = 32;
        mSubRect.top = 96;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.3f) {
            mSubRect.left = 0;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
        
        }
       if (mClock.getElapsedTime().asSeconds() > 0.6f) {
            mSubRect.left = 64;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        mSpriteSheet.move(50*frametime, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && Endurance > 0) {
            mSpriteSheet.move(100*frametime, 0);
            
        }
        mSubRect.left = 32;
        mSubRect.top = 32;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.3f) {
            mSubRect.left = 0;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
           
        }
        if (mClock.getElapsedTime().asSeconds() > 0.6f) {
            mSubRect.left = 64;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
    }
    
    mCurrentXPos = mSpriteSheet.getPosition().x;
    mCurrentYPos = mSpriteSheet.getPosition().y;
    if (mCurrentXPos > mLastXPos)
    {
        mIsGoingRight = true;
    }
    else
    {
        mIsGoingRight = false;
    }
    
    if (mCurrentXPos < mLastXPos)
    {
        mIsGoingLeft = true;
    }
    else
    {
        mIsGoingLeft = false;
    }
    
    if (mCurrentYPos < mLastYPos)
    {
        mIsGoingUp = true;
        //std::cout << "OBEN" << std::endl;
    }
    else
    {
        mIsGoingUp = false;
    }
    
    if (mCurrentYPos > mLastYPos)
    {
        mIsGoingDown = true;
        //std::cout << "UNTEN" << std::endl;
    }
    else
    {
        mIsGoingDown = false;
    }
};

void Animation::render(sf::RenderWindow *window)
{
    window->draw(mSpriteSheet);
};