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

protected:
    
    void render(sf::RenderWindow *window);
    void update(double frametime);
    void setSprite(sf::Sprite sprite){mEnemySprite = sprite;};
    void setLife(int life){mLife = life;};
    void setName(std::string name){mName = name;};
    void setPlayer(Player player){mPlayer = player;};

    
    int mLife;
    std::string mLifeString;
    std::string mName;
    Player mPlayer;
    sf::Sprite mEnemySprite;
private:
    
};
#endif /* defined(__Nameless__Enemy__) */
