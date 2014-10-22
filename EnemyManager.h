
#ifndef __Nameless__EnemyManager__
#define __Nameless__EnemyManager__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Zombie.h"
#include <string>
#include <vector>
#include "Player.h"
#include "Sprites.h"
class EnemyManager : Sprites
{
public:
    EnemyManager(Player& player);
    ~EnemyManager();
    void render(sf::RenderWindow *window);
    void update(double frametime);
private:
    std::vector<Enemy*> mEnemyVector;
    Player mPlayer;
    Zombie *pTest;
    Zombie *pTest2;
    
};

#endif /* defined(__Nameless__EnemyManager__) */
