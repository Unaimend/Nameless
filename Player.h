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
#include "Inventory.h"

class Player : Sprites
{
public:
    Player();

    virtual ~Player();
    void render(sf::RenderWindow  *window);
    void update(double frametime);
    void eventHandling(sf::Event event);
  
    
    float getPlayerSpritePosX(){return pPlayerAnimation->getAnimationSpritePosX();};
    float getPlayerSpritePosY(){return pPlayerAnimation->getAnimationSpritePosY();};
    
    sf::FloatRect getPlayerBoundingBoxes(){return pPlayerAnimation->mGetAnimBoundingBoxes();}
    sf::Event getPlayerEvent(){return mEvent;};
    
    
    int getMagicka(){return mMagica;};
    void setMagicka(int magicka){this->mMagica = magicka;};
    bool getIsGoingRight(){return mIsGoingRight;};
    bool getIsGoingLeft(){return mIsGoingLeft;};
    bool getIsGoingUp(){return mIsGoingUp;};
    bool getIsGoingDown(){return mIsGoingDown;};
    
    void setAuflösungsHöhe(float höhe){mResY = höhe;};
    void setAuflösungsBreite(float breite){mResX = breite;};
    
    void setStartPos(sf::Vector2f startpos){mPlayerPositionX = startpos.x;
        mPlayerPositionY = startpos.y;
    };
protected:
private:
    float mPlayerPositionX = 0;
    float mPlayerPositionY = 0;
    bool  mShowInventory = false;
    double mFrametime;
    sf::View mView;
    sf::View mFixed;
    int mResY, mResX;
    sf::Event mEvent;
   // GuiSystem *pGUI;
    sf::Sprite PlayerPointer;
    Animation *pPlayerAnimation;
    Inventory mInventory;
    sf::Font mFont;
    

    int mLife = 100;
    std::string mLifeString;
    sf::Text mLifeText;
    
    
    int mMagica;
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
