
#include "EnemyManager.h"

EnemyManager::EnemyManager(Player& player)
{
//    mPlayer = &player;
//    pTest = new Zombie(Sprites::NPCZombieSprite, *mPlayer, "Zombie", 1250,0,500,500, 0, 1000, 75, 5);
//    pTest2 = new Zombie(Sprites::NPCZombieSprite, *mPlayer, "Zombie", 1000,200,500,500, 0, 1000, 75, 5);
//    mEnemyVector.push_back(pTest);
//    mEnemyVector.push_back(pTest2);
};

EnemyManager::EnemyManager(Player& player,std::vector<Shot*> *mShootVec)
{
    mPlayer = &player;
    pTest = new Zombie(Sprites::NPCZombieSprite, *mPlayer, "Zombie", 100,0,500,500, 0, 1000, 3, 150);
    pTest2 = new Zombie(Sprites::NPCZombieSprite, *mPlayer, "Zombie", 100,200,500,500, 0, 1000, 3, 150);
    pTest3 = new Zombie(Sprites::NPCZombieSprite, *mPlayer, "Zombie", 123,132,500,500, 0, 1000, 3, 150);
    mEnemyVector.push_back(pTest);
    mEnemyVector.push_back(pTest2);
    mEnemyVector.push_back(pTest3);
    ShootVec = mShootVec;
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
    
    for (auto it = mEnemyVector.begin(); it != mEnemyVector.end();)
    {
        if ((*it)->getLife() <= 0)
        {
            delete *it;
            
            it = mEnemyVector.erase(it);
        }
        else{it++;}
    }
    
    for (auto it = mEnemyVector.begin(); it != mEnemyVector.end(); ++it)
    {
        sf::FloatRect it4 = (*(*it)).getFloatRect();
        //std::cout <<  "NPC"<<(*(*it)).getSprite().getPosition().x << std::endl;
        for (auto it2 = ShootVec->begin(); it2!= ShootVec->end(); )
        {
            sf::FloatRect it3 = (*(*it2)).getSprite().getGlobalBounds();
            if (it4.intersects(it3)) {
                (*(*it)).setLife((*(*it)).getLife() - 1);
                delete *it2;
                it2 = ShootVec->erase(it2);
            }
            else{++it2;}
        }
     }
    
    
    
  
    ////            if((*it2)->test.intersects((*it)->getFloatRect()))
    ////            {
    ////
    ////                std::cout << "TREFFER" << std::endl;
    ////            }
    //
    //            
    

    
    
    for(auto it : mEnemyVector)
    {
        it->update(frametime);
    };


};