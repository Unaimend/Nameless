#include "SFML/Graphics.hpp"
#include "Shot.h"

Shot::Shot(sf::Vector2f direction, sf::Vector2f position, sf::Texture *texture, int speed)
{
    pSprite = new sf::Sprite;
    pSprite->setTexture(*texture);
    pSprite->setOrigin(texture->getSize().x/2, texture->getSize().y/2);
    pSprite->setPosition(position);
    //    pSprite->setRotation(direction);
    pSprite->setScale(0.1, 0.8);
    mDirection = direction;
    pClock = new sf::Clock;
    setIsAlive(true);
    mSpeed = speed;
    
    pClock->restart();
}

Shot::~Shot()
{
    delete pClock;
    pClock = nullptr;
    delete pSprite;
    pSprite = nullptr;
    
}

void Shot::update(float frametime)
{
    
    pSprite->move(mDirection * mSpeed * frametime);
    if (pClock->getElapsedTime().asSeconds() > 3.0f) {
        setIsAlive(false);
    }
    
}

void Shot::render(sf::RenderWindow *rw)
{
 
}