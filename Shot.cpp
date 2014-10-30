#include "SFML/Graphics.hpp"
#include "Shot.h"

Shot::Shot(sf::Vector2f direction, sf::Vector2f position, std::string texture, int speed, float winkel)
{
    mTexture.loadFromFile(texture);
    pSprite = new sf::Sprite;
    pSprite->setTexture(mTexture);
    pSprite->setScale(0.1, 1);
    pSprite->setOrigin(mTexture.getSize().x/2, mTexture.getSize().y/2);
    pSprite->setPosition(position);
    
   
    mDirection = direction;
    pClock = new sf::Clock;
    setIsAlive(true);
    mSpeed = speed;
  
    //pSprite->setRotation(winkel);
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
    std::cout <<"ROT" <<pSprite->getRotation() << std::endl;
    
    if (pClock->getElapsedTime().asSeconds() > 3.0f) {
        setIsAlive(false);
    }
    
}

void Shot::render(sf::RenderWindow &rw)
{
    rw.draw(*pSprite);
}