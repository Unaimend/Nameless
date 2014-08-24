#include <SFML/Graphics.hpp>
#include <iostream>
#include "Logfile.h"
#include "Player.h"
#include "Maploader.h"
#include <vector>
#include "NPC.h"
#include "Zombie.h"
#include "MagicSystem.h"
#ifndef Neues_SFML_Projekt_Framework_hpp
#define Neues_SFML_Projekt_Framework_hpp


class Framework : Sprites
{
private:
    sf::RenderWindow *pRenderWindow;
    sf::Event   *pMainEvent;
    sf::Clock   *pClock;
    sf::Clock clock2;
    
    Logfile     *pLog;
    Player      mPlayer1;
    Maploader   *pMap;
    NPC         *pNPC_01;
    MagicSystem mPlayerMagicSystem;
    Zombie      *pZombie;

    double      mFrameTime;
    bool        mRun;
    int         Mapheigth;
    int         Mapwidth;
    int         mAuflösungsBreite;
    int         mAuflösungsHöhe;


    void Update(double frametime);
    void EventHandling();
    void Render();
    float GetFrameTime();
    void Quit();

 
    
    
public:
    //Konstruktor
    Framework();
    //Destruktor
    ~Framework();
    //UpdateFunktion in der alles Zusammengeführt wird, wird pro Frame aufgerufen,
    void Run();
    
    int getAuflösungsHöhe(){return mAuflösungsHöhe;};
    int getAuflösungsBreite(){return mAuflösungsBreite;};
};


#endif
