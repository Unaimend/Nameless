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
#include "SFML/Graphics.hpp"

class NpcAnimation
{
public:
    NpcAnimation(sf::Sprite SpriteSheet, int SpriteHeigth, int SpriteWidth);
    void move(double frametime, int Endurance);
    void render(sf::RenderWindow *window);
    sf::Sprite getSprite(){return mSpriteSheet;};
    float getAnimationSpritePosX(){return mSpriteSheet.getPosition().x;};
    float getAnimationSpritePosY(){return mSpriteSheet.getPosition().y;};
protected:
private:
    sf::Sprite mSpriteSheet;
    sf::IntRect mSubRect;
    sf::Sprite mCurrentSprite;
    sf::Clock mClock;
    
    
};
#endif /* defined(__Nameless__NpcAnimation__) */
