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
    mSprite.setPosition(100, 100);
    mSprite.setScale(3, 3);
};

void Testitem::render(sf::RenderWindow *window)
{
    window->draw(mSprite);
};

void Testitem::update(double frametime){};