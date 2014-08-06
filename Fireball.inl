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
    mFireBall.setSize(sf::Vector2f(10,10));
    mFireBall.setOrigin(10/2, 10/2);
   
};
template<class T>
Fireball<T>::~Fireball()
{
    
};
//template<class T>
//void Fireball<T>::cast()
//{
//     mFireBall.setPosition(pPlayer->getPlayerSpritePosX(), pPlayer->getPlayerSpritePosY());
//};
template<class T>
bool Fireball<T>::hasBeenHit()
{
    sf::FloatRect meb = pEnemy->getBounds();
    sf::FloatRect mpb = pPlayer->getPlayerBoundingBoxes();
    if (mpb.intersects(meb))
    {
        std::cout << "boom" << std::endl;
        return true;
    }
    else
    {
        return false;
    }

};
template<class T>
void Fireball<T>::render(sf::RenderWindow *window)
{
   window->draw(mFireBall);
};
template<class T>
void Fireball<T>::update()
{
    hasBeenHit();
};

