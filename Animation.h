//
//  Animation.h
//  Nameless
//
//  Created by Thomas Dost on 30.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Animation__
#define __Nameless__Animation__

#include <iostream>
#include "SFML/Graphics.hpp"

class Animation
{
public:
    Animation(sf::Sprite SpriteSheet, int SpriteHeigth, int SpriteWidth);
    void move(double frametime, int &Endurance);
    void render(sf::RenderWindow *window);
    sf::Sprite getSprite(){return mSpriteSheet;};
    sf::FloatRect mGetAnimBoundingBoxes(){return mSpriteSheet.getGlobalBounds();};
    float getAnimationSpritePosX(){return mSpriteSheet.getPosition().x;};
    float getAnimationSpritePosY(){return mSpriteSheet.getPosition().y;};
    
    bool getIsGoingRight(){return mIsGoingRight;};
    bool getIsGoingLeft(){return mIsGoingLeft;};
    bool getIsGoingUp(){return mIsGoingUp;};
    bool getIsGoingDown(){return mIsGoingDown;};
protected:
private:
    sf::Sprite mSpriteSheet;
    sf::IntRect mSubRect;
    sf::Sprite mCurrentSprite;
    sf::Clock mClock;
    
    int mCurrentXPos;
    int mLastXPos;
    int mCurrentYPos;
    int mLastYPos;
    bool mIsGoingRight;
    bool mIsGoingLeft;
    bool mIsGoingUp;
    bool mIsGoingDown;


};
#endif /* defined(__Nameless__Animation__) */
