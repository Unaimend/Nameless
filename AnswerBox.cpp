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
    
    
    mFont.loadFromFile("sansation.ttf");
    mText1.setFont(mFont);
    mText1.setCharacterSize(30);
    mText1.setPosition(mPosX - mWidth/2 + 5, mPosY - mHeigth/2 + 5);
    mText1.setColor(sf::Color::Yellow);
    mText1.setString("Was ist deine Aufgabe hier?");
    
    mText2.setFont(mFont);
    mText2.setCharacterSize(30);
    mText2.setPosition((mPosX - mWidth/2 + 5), (mPosY - mHeigth/2 + 5) + 32 );
    mText2.setColor(sf::Color::Yellow);
    mText2.setString("Welches Dorf, hier sind gar keine Haeuser.");
    
    mText3.setFont(mFont);
    mText3.setCharacterSize(30);
    mText3.setPosition((mPosX - mWidth/2 + 5), (mPosY - mHeigth/2 + 5)+ 32 * 2);
    mText3.setColor(sf::Color::Yellow);
    mText3.setString("Wo ist der Schmied?");
    
    mText4.setFont(mFont);
    mText4.setCharacterSize(30);
    mText4.setPosition((mPosX - mWidth/2 + 5), (mPosY - mHeigth/2 + 5) + 32 * 3);
    mText4.setColor(sf::Color::Yellow);
    mText4.setString("Hallooo");

    
    mMousePOs.setOrigin(sf::Vector2f(20/2, 20/2));
    mMousePOs.setSize(sf::Vector2f(20 ,20));
  
    mMousePOs.setFillColor(sf::Color::Red);
};


AnswerBox::~AnswerBox()
{
    
};

void AnswerBox::render(sf::RenderWindow &window)
{
    mMousePos = sf::Mouse::getPosition(window);
    worldPos2 = window.mapPixelToCoords(mMousePos);
    mMousePOs.setPosition(worldPos2.x, worldPos2.y);
    
    
    window.draw(mAnswerBox);
    window.draw(mText1);
    
    window.draw(mText2);
    window.draw(mText3);
    window.draw(mText4);
    
    window.draw(mMousePOs);

};

void AnswerBox::update()
{
    mMOuseBOund = mMousePOs.getGlobalBounds() ;
    
    mText1BB = mText1.getGlobalBounds();
    mText2BB = mText2.getGlobalBounds();
    mText3BB = mText3.getGlobalBounds();
    mText4BB = mText4.getGlobalBounds();
    
    if (mText1BB.intersects(mMOuseBOund))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::cout << "TEXT 1 IM VISIER" << std::endl;
            mText1Answer = true;
            mText2Answer = false;
            mText3Answer = false;
            mText4Answer = false;
        }
    }
    else if(mText2BB.intersects(mMOuseBOund))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::cout << "TEXT 2" << std::endl;
            mText2Answer = true;
            mText1Answer = false;
            mText3Answer = false;
            mText4Answer = false;
        }
    }
    else if(mText3BB.intersects(mMOuseBOund))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::cout << "TEXT 3" << std::endl;
            mText3Answer = true;
            mText2Answer = false;
            mText4Answer = false;
            mText1Answer = false;
        }
    }
    else if (mText4BB.intersects(mMOuseBOund))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::cout << "TEXT 4" << std::endl;
            mText4Answer = true;
            mText1Answer = false;
            mText2Answer = false;
            mText3Answer = false;
        }
    }
};