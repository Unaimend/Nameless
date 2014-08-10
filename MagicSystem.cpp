//
//  MagicSystem.cpp
//  Nameless
//
//  Created by Thomas Dost on 09.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "MagicSystem.h"
#include "cmath"
MagicSystem::MagicSystem(Player player)
{
    
    mPlayer = player;
    mClock.getElapsedTime().asSeconds();
    SpellClock.getElapsedTime().asSeconds();
    addSpells();
    
   
   
    pSpell3 = new sf::RectangleShape();
    pSpell3->setSize(sf::Vector2f(10,10));
    pSpell3->setOutlineColor(sf::Color::Blue);
    pSpell3->setOutlineThickness(2);
    

    font.loadFromFile("sansation.ttf");
    mCoolDownString = std::to_string(mClock.getElapsedTime().asSeconds()) ;
    mCoolDownText.setFont(font);
    mCoolDownText.setCharacterSize(20);
    mCoolDownText.setPosition(0, 80);
    mCoolDownText.setString(mCoolDownString);


};

MagicSystem::~MagicSystem()
{
    
};

void MagicSystem::render(sf::RenderWindow &window)
{
    mWindow = &window;
    
    

    if (renderMagic == true) {
        mWindow->draw(*pSpell3);
    }
    mWindow->draw(mCoolDownText);
   // std::cout << SpellClock.getElapsedTime().asSeconds() << std::endl;
};

void MagicSystem::update()
{
        mCoolDownString = std::to_string(SpellClock.getElapsedTime().asSeconds()) ;
    mCoolDownText.setString(mCoolDownString);
    if (renderMagic == true) {
        pSpell3->move(1, 0);
    }
    if (mClock.getElapsedTime().asSeconds() > 4.5)
    {
        delete pSpell3;
        pSpell3 = nullptr;
        renderMagic = false;
        pSpell3 = new sf::RectangleShape();
        pSpell3->setSize(sf::Vector2f(10,10));
        pSpell3->setOutlineColor(sf::Color::Blue);
        pSpell3->setOutlineThickness(2);
        mClock.restart();
        std::cout << "|";
    }
    
};

void MagicSystem::cast()
{
    
    SpellClock.getElapsedTime().asSeconds();
 
    if ((mMana > 0 && SpellClock.getElapsedTime().asSeconds() > 5 )|| (mFirstSpell == true && mMana > 0))
    {
        pSpell3 = new sf::RectangleShape();
        pSpell3->setSize(sf::Vector2f(10,10));
        pSpell3->setOutlineColor(sf::Color::Blue);
        pSpell3->setOutlineThickness(2);
        renderMagic = true;
        mFirstSpell = false;
        pSpell3->setPosition(mPlayer.getPlayerSpritePosX(),mPlayer.getPlayerSpritePosY());
        SpellClock.restart();
        mMana = mMana - 50;
        mPlayer.setMagicka(mMana);
    }

};

void MagicSystem::setSpell(sf::Event event)
{
    
    if ((event.type == sf::Event::KeyPressed   && event.key.code == sf::Keyboard::M) )
    {
        mSpellIterator++;
      
    }
    else if ((event.type == sf::Event::KeyPressed   && event.key.code == sf::Keyboard::N) && mSpellIterator > 0)
    {
        mSpellIterator--;
    }
    else if ((event.type == sf::Event::KeyPressed   && event.key.code == sf::Keyboard::B) )
    {
        mMana = mMana + 200;
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


  
    
   
};