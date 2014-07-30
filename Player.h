//
//  Player.h
//  Nameless
//
//  Created by Thomas Dost on 28.07.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Player__
#define __Nameless__Player__

#include <iostream>
#include "Sprites.h"
#include "SFML/Graphics.hpp"
#include "GuiSystem.h"
#include "Animation.h"
class Player : Sprites
{
public:
    Player(sf::Vector2f playerPosition, double resX, double resY);
    ~Player();
    void render(sf::RenderWindow  *window);
    void update(double frametime);
    void setEvent(sf::Event event);
    
    
protected:
private:
    float mPlayerPositionX = 0;
    float mPlayerPositionY = 0;
    bool  mShowInventory = true;
    double mFrametime;
    sf::View mView;
    sf::View mFixed;
    int mResY, mResX;
    sf::Event mEvent;
    GuiSystem *pGUI;
    sf::Sprite PlayerPointer;
    Animation *pPlayerAnimation;
};
#endif /* defined(__Nameless__Player__) */
