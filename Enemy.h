#ifndef __Nameless__Enemy__
#define __Nameless__Enemy__

#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>
//#include "Player.h"

class Enemy
{
public:
  
    Enemy();
    virtual ~Enemy();
    virtual void render(sf::RenderWindow *window);
    virtual void update(double frametime);
    void setSprite(sf::Sprite sprite){mEnemySprite = sprite;};
    void setLife(int life){mLife = life;};
    void setName(std::string name){mName = name;};
    //void setPlayer(Player player){mPlayer = player;};
    void setxPos(int xpos){mXpos = xpos;};
    void setyPos(int ypos){mYpos = ypos;};
    

    
protected:
        std::string mLifeString;
    std::string mName;
    sf::Sprite  mEnemySprite;
    int         mXpos;
    int         mYpos;
    int         mLife;
    int         mMaxLeft;
    int         mMaxRigth;
    int         mMaxUp;
    int         mMaxDown;
    float       mAggrotime;
    float       mAggroRange;
};
#endif /* defined(__Nameless__Enemy__) */
