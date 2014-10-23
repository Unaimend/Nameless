//
//  Zombie.cpp
//  Nameless
//
//  Created by Thomas Dost on 05.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Zombie.h"
Zombie::Zombie(sf::Sprite sprite, Player &player, std::string name, int life, int xpos, int ypos, int maxrigth, int maxup, int maxdown, float aggrorange, float aggrotime)
{
    mEnemySprite    = sprite;
    mLife           = life;
    mPlayer         = player;
    mName           = name;
    mXpos           = xpos;
    mYpos           = ypos;
    mMaxRigth       = maxrigth;
    mAggroRange     = aggrorange;
    mAggrotime      = aggrotime;
    pAnimation      = new NpcAnimation(mEnemySprite, 32,32, xpos,ypos,mMaxLeft, mMaxRigth,mMaxUp,mMaxDown, player, true, mAggroRange, mAggrotime);
    mEnemySprite.setPosition(mXpos, mYpos);
    
    
    //TESTCODDE
    mFont.loadFromFile("sansation.ttf");
    mLifeText.setPosition(0, 0);
    mLifeText.setCharacterSize(12);
    mLifeText.setColor(sf::Color::Red);
    mLifeText.setFont(mFont);
   
   
};
Zombie::~Zombie(){};

void Zombie::render(sf::RenderWindow *window)
{
    mLifeText.setString(mLifeString);
    window->draw(mLifeText);
    pAnimation->render(window);
   
};

void Zombie::update(double frametime)
{
    pAnimation->move(frametime, 100);

    mLifeText.setPosition(pAnimation->getAnimationSpritePosX() +  6,pAnimation->getAnimationSpritePosY() - 15);
    mLifeString = std::to_string(mLife);
};

void Zombie::attack() const
{};