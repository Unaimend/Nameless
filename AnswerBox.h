#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "vector"
class AnswerBox
{
public:
    AnswerBox();
    AnswerBox(int heigth, int width, int posx, int posy, sf::Color color);
    ~AnswerBox();
    void    render(sf::RenderWindow &window);
    void    update();
private:
    sf::RectangleShape mAnswerBox;
    int mHeigth = 0;
    int mWidth = 0;
    
    int mPosX = 0;
    int mPosY = 0;
    
    sf::Color mColor;
    
    sf::Text mText1;
    sf::Text mText2;
    sf::Text mText3;
    sf::Text mText4;
    
    sf::Font mFont;
    
    sf::Vector2i mMousePos;
    sf::Vector2f worldPos2 ;
    sf::RectangleShape mMousePOs;
    
    sf::FloatRect mMOuseBOund;
    
    sf::FloatRect mText1BB;
    sf::FloatRect mText2BB;
    sf::FloatRect mText3BB;
    sf::FloatRect mText4BB;
    
};
