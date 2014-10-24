
#ifndef __Nameless__Gun__
#define __Nameless__Gun__

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Item.h"
#include "Shot.h"
class Gun : public Item
{
public:
    Gun(std::string texture, double xpos, double ypos, std::string name, int ID, float damage, float cooldown  );
    virtual ~Gun();
    virtual void render(sf::RenderWindow *window);
    virtual void update(double frametime);
    virtual void fire(sf::Vector2f playerpos, sf::Vector2f targetpos);
protected:
    int mDamage;
    float mCooldown;
private:



};
#endif /* defined(__Nameless__Gun__) */
