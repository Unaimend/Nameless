
#ifndef __Nameless__EnemyManager__
#define __Nameless__EnemyManager__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Zombie.h"
#include <string>
#include <vector>
class EnemyManager
{
public:
    EnemyManager();
    ~EnemyManager();
    void render();
    void update();
private:
    std::vector<Enemy> mEnemyVector;
};

#endif /* defined(__Nameless__EnemyManager__) */
