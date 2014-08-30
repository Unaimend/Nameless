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
    mSprite.setPosition(10, 10);
    mSprite.setScale(1, 1);
   // mWindow = &window;
};

void Testitem::render(sf::RenderWindow *window)
{   std::cout << "RICHTIGER RENDER";
    window->draw(mSprite);
};

void Testitem::update(double frametime)
{
//    sf::FloatRect test;
//    sf::FloatRect test2(sf::Mouse::getPosition(*mWindow).x, sf::Mouse::getPosition(*mWindow).x, sf::Mouse::getPosition(*mWindow).x, sf::Mouse::getPosition(*mWindow).y);
//    test.intersects(test2);

};