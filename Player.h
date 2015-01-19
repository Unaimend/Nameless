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
#include "Parser.h"
class Player : Sprites
{
public:
    Player();
    ~Player();
    sf::FloatRect getPlayerBoundingBoxes(){return pPlayerAnimation->mGetAnimBoundingBoxes();}
    sf::Event getPlayerEvent(){return mEvent;};
    void render(sf::RenderWindow  *window);
    void fixrender(sf::RenderWindow &window);
    void update(double frametime);
    void eventHandling(sf::Event event);
    void setMagicka(const  int magicka){this->mMagica = magicka;};
    void setAuflösungsHöhe(const float höhe){mResY = höhe;};
    void setAuflösungsBreite(float breite){mResX = breite;};
    void setStartPos(sf::Vector2f startpos){mPlayerPositionX = startpos.x; mPlayerPositionY = startpos.y;};
    float getPlayerSpritePosX(){return pPlayerAnimation->getAnimationSpritePosX();};
    float getPlayerSpritePosY(){return pPlayerAnimation->getAnimationSpritePosY();};
    
    float getInvPosX(){return mInventory.getInventoryPos().x;};
    float getInvPosY(){return mInventory.getInventoryPos().y;};
    bool getIsGoingRight(){return mIsGoingRight;};
    bool getIsGoingLeft(){return mIsGoingLeft;};
    bool getIsGoingUp(){return mIsGoingUp;};
    bool getIsGoingDown(){return mIsGoingDown;};
    bool getInventoryVis(){return mInventory.getInvVisibility();};
    int getMagicka(){return mMagica;};
    float       mXmovement;
    float       mYmovement;
    float       mTarXDistance;
    float       mTarYDistance;
    float       mPlayTarDistance;
    int test1;
private:
    
    
    Parser mParser;
    Animation *pPlayerAnimation;
  
    Inventory mInventory;
    sf::Event mEvent;
    sf::Sprite PlayerPointer;
    sf::View mView;
    sf::View mFixed;
    sf::Vector2i        mMousePos;
    sf::Vector2f        mRealMousePos;
    sf::RectangleShape  mMousRec;
    sf::Font mFont;
    float mPlayerPositionX      = 100;
    float mPlayerPositionY      = 100;
    double mFrametime;
    int mResY, mResX;
    bool  mShowInventory        = false;
    bool        mIsStanding     = false;
    bool        mIsGoingRight;
    bool        mIsGoingLeft;
    bool        mIsGoingUp;
    bool        mIsGoingDown;
    int         mLife           = 100;
    std::string mLifeString;
    sf::Text    mLifeText;
    int         mMagica         = 100;
    std::string mMagicaString;
    sf::Text    mMagicaText;
    
    int         mEndurance = 100 ;
    std::string mEnduranceString;
    sf::Text    mEnduranceText;
    sf::Clock   mEnduranceCLock;
   
    
    //sf::RectangleShape mTestShape;
    bool        mShoot = false;
    bool        mCalc = false;

};
#endif /* defined(__Nameless__Player__) */
