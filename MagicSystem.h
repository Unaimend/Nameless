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
    MagicSystem(Player &player);
    ~MagicSystem();
    void render(sf::RenderWindow *window);
    void update();
   
    void cast();
    void setSpell(sf::Event events);
    void addSpells();
    void changeSpell();
protected:
private:
    Player  mPlayer;
    Enemy   mEnemy;
    std::vector<sf::RectangleShape> mSpellVector;
    std::vector<sf::RectangleShape> mCurrentSpellVector;
    int mSpellIterator = 0;
    sf::RectangleShape mSpell1;
    sf::RectangleShape mSpell2;
    sf::RectangleShape mSpell3;
    
};
#endif /* defined(__Nameless__MagicSystem__) */
