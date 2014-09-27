//
//  DialogSystem.h
//  Nameless
//
//  Created by Thomas Dost on 31.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__DialogSystem__
#define __Nameless__DialogSystem__
#include <iostream>
#include "SFML/Graphics.hpp"
#include "AnswerBox.h"

class DialogSystem
{
public:
    DialogSystem(std::string text1, int xpos, int ypos, unsigned int ChraracterSize);
    ~DialogSystem();
    void setText(std::string Text){mText.setString(Text);};
    void render(sf::RenderWindow *window);
     void answerboxrender(sf::RenderWindow *window);
    
    bool getAnswer1(){return pAnswerBox->getAnswer1();};
    bool getAnswer2(){return pAnswerBox->getAnswer2();};
    bool getAnswer3(){return pAnswerBox->getAnswer3();};
    bool getAnswer4(){return pAnswerBox->getAnswer4();};
    
    void setAnswer1(bool answerstat){pAnswerBox->setAnswer1(answerstat);};
    void setAnswer2(bool answerstat){pAnswerBox->setAnswer2(answerstat);};
    void setAnswer3(bool answerstat){pAnswerBox->setAnswer3(answerstat);};
    void setAnswer4(bool answerstat){pAnswerBox->setAnswer4(answerstat);};
 

    void update();
protected:
private:
    sf::Text mText;
    sf::Font mFont;
    sf::RectangleShape mTextBox;
    AnswerBox   *pAnswerBox;
    
  
    

};
#endif /* defined(__Nameless__DialogSystem__) */
