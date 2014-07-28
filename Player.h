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

class Player : Sprites
{
public:
    Player(sf::Vector2f playerPosition);
    void render(sf::RenderWindow  *window);
    void update(double frametime);
    
protected:
private:
    float mPlayerPositionX = 0;
    float mPlayerPositionY = 0;
    double mFrametime;
    sf::View mView;
};
#endif /* defined(__Nameless__Player__) */
