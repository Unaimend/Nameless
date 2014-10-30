
#include "TestGun.h"
Gun_TestGun::Gun_TestGun(std::string texture, double xpos, double ypos, std::string name, int ID, float damage, float cooldown,  std::vector<Shot*> &shootvec, Player &player) :
Gun(texture,xpos,ypos,name,ID,damage,cooldown,shootvec)
{
    mSprite.setScale(0.5,0.2);
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

void Gun_TestGun::fire(sf::Vector2f playerpos, sf::Vector2f targetpos, float xdis, float ptdis)
{
    Shot *pp = new Shot(targetpos, playerpos,"Laser.png" ,100, sin(xdis/ptdis) * 180/3.141);
    pShootVector->push_back(pp);
   
};