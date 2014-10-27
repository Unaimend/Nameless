#include "SFML/Graphics.hpp"
#include "Shot.h"

Shot::Shot(sf::Vector2f direction, sf::Vector2f position, std::string texture, int speed)
{
    mTexture.loadFromFile(texture);
    pSprite = new sf::Sprite;
    pSprite->setTexture(mTexture);
    pSprite->setOrigin(mTexture.getSize().x/2, mTexture.getSize().y/2);
    pSprite->setPosition(position);
    //    pSprite->setRotation(direction);
    pSprite->setScale(0.2, 0.2);
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

void Shot::render(sf::RenderWindow &rw)
{
    rw.draw(*pSprite);
}