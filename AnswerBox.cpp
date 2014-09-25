//
//  AnswerBox.cpp
//  Nameless
//
//  Created by Thomas Dost on 25.09.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#include "AnswerBox.h"

AnswerBox::AnswerBox()
{
    mAnswerBox.setPosition(1680/2, 1200);
    
    mAnswerBox.setFillColor(sf::Color::Blue);
};

AnswerBox::AnswerBox(int heigth, int width, int posx, int posy, sf::Color color)
: mPosX(posx), mPosY(posy), mColor(color), mWidth(width), mHeigth(heigth)
{
    mAnswerBox.setOrigin(sf::Vector2f(mWidth/2, mHeigth/2));
    mAnswerBox.setSize(sf::Vector2f(mWidth ,mHeigth));
    mAnswerBox.setPosition(mPosX, mPosY);
    mAnswerBox.setFillColor(mColor);
};


AnswerBox::~AnswerBox()
{

};

void AnswerBox::render(sf::RenderWindow &window)
{
    window.draw(mAnswerBox);

};

void AnswerBox::update()
{

};