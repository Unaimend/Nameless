#ifndef __Nameless__Zombie__
#define __Nameless__Zombie__

#include <iostream>
#include "Enemy.h"
#include "NpcAnimation.h"
#include "Sprites.h"
#include "Player.h"

class Zombie : public Enemy,Sprites
{
public:
    Zombie(sf::Sprite sprite, Player &player, std::string name, int life, int xpos, int ypos,  int maxrigth, int maxup, int maxdown, float aggrorange, float aggrotime);
    ~Zombie();
    sf::FloatRect getBounds(){return pAnimation->getEnemyBoundingBoxes();};
    void render(sf::RenderWindow *window) override;
    virtual void update(double frametime);
    void attack()const ;
private:
    NpcAnimation *pAnimation;
    Player      *mPlayer;
 
};
#endif /* defined(__Nameless__Zombie__) */
