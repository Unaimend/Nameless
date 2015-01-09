#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <iostream>
#include <vector>
#include "Shot.h"
#include <math.h>

class Shot
{
public:
    Shot(sf::Vector2f direction, sf::Vector2f position, std::string texture, int speed, float winkel);
    ~Shot();
    void update(float frametime);
    void render(sf::RenderWindow &rw);
    const sf::Sprite &getSprite(){return *pSprite;};
    sf::Rect<float> getBound(){return pSprite->getGlobalBounds();}
    const bool getIsAlive(){return misAlive;};
    void setIsAlive(bool isAlive){misAlive = isAlive;};
    
    sf::FloatRect test;
private:
    sf::Vector2f mDirection;
    float mSpeed;
    bool misAlive;
    sf::Clock *pClock;
    sf::Sprite *pSprite;
    sf::Texture mTexture;
       
};
