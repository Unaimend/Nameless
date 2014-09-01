//
//  Testitem.cpp
//  Nameless
//
//  Created by Thomas Dost on 29.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "Testitem.h"

Testitem::Testitem()
{
    mTexture.loadFromFile("/Users/Thomas/Desktop/iron helmet.png");
    mSprite.setTexture(mTexture);
    mSprite.setPosition(50, 50);
    mSprite.setScale(1, 1);
    mID = 1000;
       // mWindow = &window;
};

void Testitem::render(sf::RenderWindow *window)
{
   // std::cout << "RICHTIGER RENDER" << std::endl;
    window->draw(mSprite);
};

void Testitem::update(double frametime)
{    // std::cout << "RICHTIGE UPDATE" << std::endl;
//    sf::FloatRect test;
//    sf::FloatRect test2(sf::Mouse::getPosition(*mWindow).x, sf::Mouse::getPosition(*mWindow).x, sf::Mouse::getPosition(*mWindow).x, sf::Mouse::getPosition(*mWindow).y);
//    test.intersects(test2);

};