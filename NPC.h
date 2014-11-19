//
//  NPC.h
//  Nameless
//
//  Created by Thomas Dost on 31.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__NPC__
#define __Nameless__NPC__

#include <iostream>
#include "DialogSystem.h"
#include "Player.h"

class NPC
{
public:
    NPC( Player &player , sf::Sprite sprite, float xpos , float ypos , std::string text = "0", std::string text2 = "0", std::string text3 = "0",std::string text4 = "0", std::string text5 = "0", std::string name = "defaultname", std::string wielctext = "Ahh du bists wieder");
    void render(sf::RenderWindow *window);
    void nonfixrender(sf::RenderWindow *window);
    void update(double frametime);
    void setEvent(sf::Event event);
private:
    DialogSystem    *NpcDialog;
    Player          *mPlayer;
    sf::Sprite      mNpcSprite;
    sf::Event       mEvent;
    std::string     mNPCtext;
    std::string     mNpcText1;
    std::string     mNpcText2;
    std::string     mNpcText3;
    std::string     mNpcText4;
    std::string     mNpcText5;
    
    std::string     mWelctText = "WTF!!!";
    float           mNpcPosX = 0;
    float           mNpcPosY = 0;
    bool            mSchonGetroffen = false;
    bool            mShowDialog = false;
    bool            mShowAnswerBox = false;
    bool            mShowAnswerBox1 = false;
    bool            mShowAnswerBox2 = false;
    bool            mShowAnswerBox3 = false;
    bool            mShowAnswerBox4 = false;
    
};
#endif /* defined(__Nameless__NPC__) */
