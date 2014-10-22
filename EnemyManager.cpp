
#include "EnemyManager.h"

EnemyManager::EnemyManager(Player& player)
{
    mPlayer = player;
    pTest = new Zombie(Sprites::NPCZombieSprite, mPlayer, "Zombie", 1250,0,500,500, 0, 1000, 75, 5);
    pTest2 = new Zombie(Sprites::NPCZombieSprite, mPlayer, "Zombie", 100,200,500,500, 0, 1000, 75, 5);
    mEnemyVector.push_back(pTest);
    mEnemyVector.push_back(pTest2);
};

EnemyManager::~EnemyManager(){};

void EnemyManager::render(sf::RenderWindow *window)
{

    for(auto it : mEnemyVector)
    {
        it->render(window);
    };
   


};

void EnemyManager::update(double frametime)
{
    for(auto it : mEnemyVector)
    {
        it->update(frametime);
    };
};