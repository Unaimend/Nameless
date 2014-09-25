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

class DialogSystem
{
public:
    DialogSystem(std::string text1, int xpos, int ypos, unsigned int ChraracterSize);
    ~DialogSystem();
    void setText(std::string Text){mText.setString(Text);};
    void render(sf::RenderWindow *window);
 

    void update();
protected:
private:
    sf::Text mText;
    sf::Font mFont;
    sf::RectangleShape mTextBox;
    
  
    

};
#endif /* defined(__Nameless__DialogSystem__) */
