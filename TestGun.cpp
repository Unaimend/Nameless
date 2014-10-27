
#include "TestGun.h"
Gun_TestGun::Gun_TestGun(std::string texture, double xpos, double ypos, std::string name, int ID, float damage, float cooldown,  std::vector<Shot*> &shootvec, std::vector<sf::RectangleShape*> &mTestVector, Player &player) :
Gun(texture,xpos,ypos,name,ID,damage,cooldown,shootvec)
{
    mSprite.setScale(0.5,0.2);
    mTestVector2 = &mTestVector;
    pShootVector = &shootvec;
    pPlayer = &player;
};

Gun_TestGun::~Gun_TestGun()
{

};


void Gun_TestGun::render(sf::RenderWindow& window)
{
    window.draw(mSprite);
    pRenderWindow = &window;
};

void Gun_TestGun::fire(sf::Vector2f playerpos, sf::Vector2f targetpos)
{
    sf::RectangleShape *p = new sf::RectangleShape();
    p->setSize(sf::Vector2f(5,5));
    p->setPosition(pPlayer->getPlayerSpritePosX(), pPlayer->getPlayerSpritePosY());
    Shot *pp = new Shot(targetpos, playerpos,"Laser.png" ,100);
    mTestVector2->push_back(p);
    pShootVector->push_back(pp);
   
};