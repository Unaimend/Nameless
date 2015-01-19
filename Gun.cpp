#include "Gun.h"


Gun::Gun(std::string texture, double xpos, double ypos, std::string name, int ID, float damage, float cooldown,  std::vector<Shot*> shootvec)
{
    mTexture.loadFromFile(texture);
    mSprite.setTexture(mTexture);
    xPos = xpos;
    yPos = ypos;
    mSprite.setPosition(xpos, ypos);
    mID = ID;
    mName = name;
    mDamage = damage;
    mCooldown = cooldown;
    
    
};

Gun::~Gun()
{

};

void Gun::render(sf::RenderWindow *window)
{
    window->draw(mSprite);
    
};

void Gun::update(double frametime)
{
    
};

void Gun::fire(sf::Vector2f playerpos, sf::Vector2f targetpos)
{

};