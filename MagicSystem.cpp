//
//  MagicSystem.cpp
//  Nameless
//
//  Created by Thomas Dost on 09.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "MagicSystem.h"
MagicSystem::MagicSystem(Player &player)
{
    mPlayer = player;
    
    
    
    addSpells();
};

MagicSystem::~MagicSystem()
{
    
};

void MagicSystem::render(sf::RenderWindow *window)
{
    window->draw(mSpellVector[mSpellIterator]);
    
};

void MagicSystem::update()
{
    
};

void MagicSystem::cast()
{
    mSpellVector[mSpellIterator].setPosition(mPlayer.getPlayerSpritePosX(), mPlayer.getPlayerSpritePosY());
    
    //mCurrentSpellVector.push_back(*mSpellIterator);
};

void MagicSystem::setSpell(sf::Event event)
{
    
    if ((event.type == sf::Event::KeyPressed   && event.key.code == sf::Keyboard::M) && (mSpellIterator < mSpellVector.size() - 1 && mSpellIterator >= 0))
    {
        mSpellIterator++;
    }
    else if ((event.type == sf::Event::KeyPressed   && event.key.code == sf::Keyboard::N) && mSpellIterator > 0)
    {
        mSpellIterator--;
    }
};

void MagicSystem::addSpells()
{
    mSpell1.setSize(sf::Vector2f(10,10));
    mSpell1.setOutlineColor(sf::Color::Red);
    mSpell1.setOutlineThickness(2);
    mSpell2.setSize(sf::Vector2f(10,10));
    mSpell2.setOutlineColor(sf::Color::Green);
    mSpell2.setOutlineThickness(2);
    mSpell3.setSize(sf::Vector2f(10,10));
    mSpell3.setOutlineColor(sf::Color::Blue);
    mSpell3.setOutlineThickness(2);
    mSpellVector.push_back(mSpell1);
    mSpellVector.push_back(mSpell2);
    mSpellVector.push_back(mSpell3);
    std::cout << mSpellVector.size();
   
};