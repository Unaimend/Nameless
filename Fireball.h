#ifndef __Nameless__Fireball__
#define __Nameless__Fireball__

#include <iostream>
#include "SFML/Graphics.hpp"

#include "Zombie.h"
template<class T>
class Fireball 
{
public:
    Fireball(Player &player);
    ~Fireball();
    bool hasBeenHit();
    void render(sf::RenderWindow *window);
    void update();
   
protected:
private:
    T *pEnemy;
    Player *pPlayer;
    sf::RectangleShape mFireBall;
 
};

#include "Fireball.inl"
#endif /* defined(__Nameless__Fireball__) */
