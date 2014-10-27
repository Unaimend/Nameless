#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <iostream>
#include <vector>
#include "Shot.h"

class Shot
{
public:
    Shot(sf::Vector2f direction, sf::Vector2f position, std::string texture, int speed);
    ~Shot();
    void update(float frametime);
    void render(sf::RenderWindow &rw);
    const sf::Sprite &getSprite(){return *pSprite;};
    const bool getIsAlive(){return misAlive;};
    void setIsAlive(bool isAlive){misAlive = isAlive;};
private:
    sf::Vector2f mDirection;
    float mSpeed;
    bool misAlive;
    sf::Clock *pClock;
    sf::Sprite *pSprite;
    sf::Texture mTexture;
    
};
