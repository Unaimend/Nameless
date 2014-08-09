//
//  Player.h
//  Nameless
//
//  Created by Thomas Dost on 28.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Player__
#define __Nameless__Player__

#include <iostream>
#include "Sprites.h"
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Logfile.h"
#include "MagicSystem.h"
class Player : Sprites
{
public:
    Player(sf::Vector2f playerPosition, double resX, double resY);
    Player(){};
    virtual ~Player();
    void render(sf::RenderWindow  *window);
    void update(double frametime);
    void setEvent(sf::Event event);
    void closePlayer(){this->~Player();};

    float getPlayerSpritePosX(){return pPlayerAnimation->getAnimationSpritePosX();};
    float getPlayerSpritePosY(){return pPlayerAnimation->getAnimationSpritePosY();};
    
    sf::FloatRect getPlayerBoundingBoxes(){return pPlayerAnimation->mGetAnimBoundingBoxes();}
    sf::Event getPlayerEvent(){return mEvent;};
    
    bool getIsGoingRight(){return mIsGoingRight;};
    bool getIsGoingLeft(){return mIsGoingLeft;};
    bool getIsGoingUp(){return mIsGoingUp;};
    bool getIsGoingDown(){return mIsGoingDown;};
protected:
private:
    float mPlayerPositionX = 0;
    float mPlayerPositionY = 0;
    bool  mShowInventory = true;
    double mFrametime;
    sf::View mView;
    sf::View mFixed;
    int mResY, mResX;
    sf::Event mEvent;
   // GuiSystem *pGUI;
    sf::Sprite PlayerPointer;
    Animation *pPlayerAnimation;
    sf::Font mFont;
    

    int mLife = 100;
    std::string mLifeString;
    sf::Text mLifeText;
    
    
    int mMagica = 100;
    std::string mMagicaString;
    sf::Text mMagicaText;
    int mEndurance = 100;
    std::string mEnduranceString;
    sf::Text mEnduranceText;
    sf::Clock mEnduranceCLock;
    bool mIsStanding = false;
    bool mIsGoingRight;
    bool mIsGoingLeft;
    bool mIsGoingUp;
    bool mIsGoingDown;
    //sf::Clock mRefillEnduranceClock;
    
  
    
};
#endif /* defined(__Nameless__Player__) */
