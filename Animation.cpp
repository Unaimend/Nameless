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


void Animation::move(sf::Keyboard::Key PressedKey, double frametime)
{   mClock.getElapsedTime().asSeconds();
    if (PressedKey == sf::Keyboard::W)
    {
        mSpriteSheet.move(0,-100*frametime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            mSpriteSheet.move(0,-200*frametime);
        }
        mSubRect.left = 32;
        mSubRect.top = 0;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.2f) {
            mSubRect.left = 0;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
            
        }
        if (mClock.getElapsedTime().asSeconds() > 0.4f) {
            mSubRect.left = 64;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
    }
    else if (PressedKey == sf::Keyboard::S)
    {
        mSpriteSheet.move(0,100*frametime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            mSpriteSheet.move(0,200*frametime);
        }
        mSubRect.left = 32;
        mSubRect.top = 64;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.2f) {
           
            mSubRect.left = 0;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
            
        }
        if (mClock.getElapsedTime().asSeconds() > 0.4f) {
            mSubRect.left = 64;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
            
        }
       
    }
    else if (PressedKey == sf::Keyboard::A)
    {
        mSpriteSheet.move(-100*frametime, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            mSpriteSheet.move(-200*frametime, 0);
        }
        mSubRect.left = 32;
        mSubRect.top = 96;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.2f) {
            mSubRect.left = 0;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
        
        }
       if (mClock.getElapsedTime().asSeconds() > 0.4f) {
            mSubRect.left = 64;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
        
    }
    else if (PressedKey == sf::Keyboard::D)
    {
        mSpriteSheet.move(100*frametime, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            mSpriteSheet.move(200*frametime, 0);
        }
        mSubRect.left = 32;
        mSubRect.top = 32;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.2f) {
            mSubRect.left = 0;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
           
        }
        if (mClock.getElapsedTime().asSeconds() > 0.4f) {
            mSubRect.left = 64;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
            mClock.restart();
        }
    }
    mSubRect.left = 32;
    mSubRect.top = 0;
    mSpriteSheet.setTextureRect(mSubRect);
    
};

void Animation::render(sf::RenderWindow *window)
{
    window->draw(mSpriteSheet);
};