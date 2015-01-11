//
//  Zombie.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Zombie.h"
Zombie::Zombie(sf::Sprite sprite, Player &player, std::string name, int life, int xpos, int ypos, int maxrigth, int maxup, int maxdown,float aggrotime, float aggrorange)
{
    mEnemySprite    = sprite;
    mLife           = life;
    mPlayer         = &player;
    mName           = name;
    mXpos           = xpos;
    mYpos           = ypos;
    mMaxRigth       = maxrigth;
    mAggroRange     = aggrorange;
    mAggrotime      = aggrotime;
    pAnimation      = new NpcAnimation(mEnemySprite, 32,32, xpos,ypos,mMaxLeft, mMaxRigth,mMaxUp,mMaxDown, player, true,mAggrotime, mAggroRange );
    mEnemySprite.setPosition(mXpos, mYpos);
   
    
    //TESTCODDE
    mFont.loadFromFile("sansation.ttf");
    test2.setPosition(0, 0);
    test2.setCharacterSize(48);
    test2.setScale(0.125, 0.125);
    test2.setColor(sf::Color::Red);
    test2.setFont(mFont);
    
   
    mHitBox.setSize(sf::Vector2f(12,32));
    mHitBox.setFillColor(sf::Color(255,0,0,64));
    
   
};
Zombie::~Zombie(){};

void Zombie::render(sf::RenderWindow *window)
{
    test2.setString(mLifeString);
    window->draw(test2);
    pAnimation->render(window);
    window->draw(mHitBox);
   
};

void Zombie::update(double frametime)
{
    pAnimation->move(frametime, 100);
    mHitBox.setPosition(pAnimation->getSprite().getPosition().x + 10, pAnimation->getSprite().getPosition().y);
    test2.setPosition(pAnimation->getAnimationSpritePosX() +  6,pAnimation->getAnimationSpritePosY() - 15);
   // mLife = mLife - 0.1;
    mLifeString = std::to_string(mLife);
};

void Zombie::attack() const
{};