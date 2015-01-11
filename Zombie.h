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
    Zombie(sf::Sprite sprite, Player &player, std::string name, int life, int xpos, int ypos,  int maxrigth, int maxup, int maxdown,float aggrotime, float aggrorange);
    ~Zombie();
    sf::FloatRect getFloatRect(){return mHitBox.getGlobalBounds();};
    void render(sf::RenderWindow *window) override;
    virtual void update(double frametime);
    void attack()const ;
    sf::Sprite getSprite(){return  pAnimation->getSprite();};
private:
    NpcAnimation *pAnimation;
    Player      *mPlayer;
    
 
};
#endif /* defined(__Nameless__Zombie__) */
