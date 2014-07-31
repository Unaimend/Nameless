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
    DialogSystem();
    ~DialogSystem();
    void setText(std::string Text){mText.setString(Text);};
protected:
private:
    sf::Text mText;
    sf::RectangleShape mTextBox;


};
#endif /* defined(__Nameless__DialogSystem__) */
