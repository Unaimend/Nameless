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
    
};
