//
//  MagicSystem.h
//  Nameless
//
//  Created by Thomas Dost on 09.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__MagicSystem__
#define __Nameless__MagicSystem__

#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "SFML/Graphics.hpp"
#include <vector>
class MagicSystem
{
public:
    MagicSystem();
    ~MagicSystem();
    void render(sf::RenderWindow &window);
    void update();
   
    void cast();
    void setSpell(sf::Event events);
    void addSpells();
    void changeSpell();
    
    void setPlayer(Player &player){mPlayer = player;};
    Player getPlayer(){return mPlayer;};
    
    
protected:
private:
    Player  mPlayer;
    Enemy   mEnemy;
    sf::Font font;
    int mSpellIterator = 0;
    sf::RectangleShape mSpell1;
    sf::RectangleShape mSpell2;
    sf::RectangleShape *pSpell3;
    sf::RenderWindow *mWindow;
    sf::Clock mClock;
    sf::Clock SpellClock;
    std::string mCoolDownString;
    sf::Text mCoolDownText;
    bool renderMagic = false;
    bool mFirstSpell = true;
    int mMana;
};
#endif /* defined(__Nameless__MagicSystem__) */
