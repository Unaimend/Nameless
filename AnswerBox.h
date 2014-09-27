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
    
    bool getAnswer1(){return mText1Answer;};
    bool getAnswer2(){return mText2Answer;};
    bool getAnswer3(){return mText3Answer;};
    bool getAnswer4(){return mText4Answer;};
    

    void setAnswer1(bool answerstat){mText1Answer = answerstat;};
    void setAnswer2(bool answerstat){mText2Answer = answerstat;};
    void setAnswer3(bool answerstat){mText3Answer = answerstat;};
    void setAnswer4(bool answerstat){mText4Answer = answerstat;};
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
    
    bool mText1Answer = false, mText2Answer = false, mText3Answer =false, mText4Answer = false;
    
    
    
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
