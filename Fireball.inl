//
//  Fireball.cpp
//  Nameless
//
//  Created by Thomas Dost on 06.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Fireball.h"

template<class T>
Fireball<T>::Fireball(Player& player, T &target )
{
    pEnemy = &target;
    pPlayer = &player;
};
template<class T>

Fireball<T>::~Fireball()
{

};
template<class T>
void Fireball<T>::castSpell()
{
    
};
template<class T>
bool Fireball<T>::hasBeenHit()
{
    
    sf::FloatRect meb = pEnemy->getBounds();
    sf::FloatRect mpb = pPlayer->getPlayerBoundingBoxes();
       if (mpb.intersects(meb)) {
           std::cout << "boom" << std::endl;
           return true;
    }

};
template<class T>
void Fireball<T>::render(sf::RenderWindow *window)
{
   //window->draw(mFireball);
};
template<class T>
void Fireball<T>::update()
{
    hasBeenHit();
};