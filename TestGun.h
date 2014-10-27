#ifndef __Nameless__TestGun__
#define __Nameless__TestGun__

#include <stdio.h>
#include "Gun.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Shot.h"
#include "Player.h"
class Gun_TestGun : public Gun
{
public:
    Gun_TestGun(std::string texture, double xpos, double ypos, std::string name, int ID, float damage, float cooldown,  std::vector<Shot*> &shootvec, std::vector<sf::RectangleShape*> &mTestVector, Player& player);
    ~Gun_TestGun();
    void fire(sf::Vector2f playerpos, sf::Vector2f targetpos);
    void render(sf::RenderWindow& window);
    sf::RenderWindow* pRenderWindow;
    std::vector<sf::RectangleShape*> *mTestVector2;
    Player* pPlayer;
};
#endif /* defined(__Nameless__TestGun__) */
