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
    NPC( Player &player , sf::Sprite sprite, float xpos , float ypos , std::string text = "0", std::string text2 = "0", std::string text3 = "0", std::string name = "defaultname");
    void render(sf::RenderWindow *window);
    void update();
    void setEvent(sf::Event event);
    
 
protected:
private:
    std::string mNPCtext;

    sf::Sprite mNpcSprite;
    float mNpcPosX = 0;
    float mNpcPosY = 0;
    DialogSystem *NpcDialog;
    Player mPlayer;
    sf::Event mEvent;
    bool mShowDialog = false;
    std::string mNpcText1;
    std::string mNpcText2;
    std::string mNpcText3;
};
#endif /* defined(__Nameless__NPC__) */