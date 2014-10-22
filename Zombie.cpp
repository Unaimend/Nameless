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
    
    mFont.loadFromFile("sansation.ttf");
    mLifeText.setFont(mFont);
    mLifeText.setCharacterSize(70);
    mLifeText.setPosition(0, 30);
    mLifeText.setColor(sf::Color::Blue);
    
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
};
Zombie::~Zombie(){};

void Zombie::render(sf::RenderWindow *window)
{
    pAnimation->render(window);
    mLifeString = std::to_string(mLife);
    mLifeText.setString(mLifeString);
    window->draw(mLifeText);
    std::cout << mLife << std::endl;
};

void Zombie::update(double frametime)
{
    pAnimation->move(frametime, 100);
   //mLifeString.setPosition(pAnimation->getAnimationSpritePosX(), pAnimation->getAnimationSpritePosY());
    mLifeText.setPosition(0,0 );
    std::cout << "RICHTUIG" << std::endl;
};

void Zombie::attack() const
{};