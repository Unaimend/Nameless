#ifndef __Nameless__Enemy__
#define __Nameless__Enemy__

#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>
#include "Player.h"
class Enemy
{
public:
  
    Enemy();
    virtual ~Enemy();
    sf::FloatRect getBoundingBoxes(){return mEnemySprite.getGlobalBounds();};
protected:
    
    virtual void render(sf::RenderWindow *window) const = 0;
    virtual void update(double frametime) const = 0;
    void setSprite(sf::Sprite sprite){mEnemySprite = sprite;};
    void setLife(int life){mLife = life;};
    void setName(std::string name){mName = name;};
    void setPlayer(Player player){mPlayer = player;};
    void setxPos(int xpos){mXpos = xpos;};
    void setyPos(int ypos){mYpos = ypos;};
    
    virtual void attack() const = 0;
    
    int mXpos;
    int mYpos;
    int mLife;
    int mMaxLeft;
    int mMaxRigth;
    std::string mLifeString;
    std::string mName;
    Player mPlayer;
    sf::Sprite mEnemySprite;
    int mMaxUp;
    int mMaxDown;
private:
     NpcAnimation *pAnimation;
};
#endif /* defined(__Nameless__Enemy__) */
